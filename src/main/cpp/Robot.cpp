// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
  /* https://docs.google.com/presentation/d/1IBYSYjfh4JwQ7NEGU0dBCiW33O0HDwejURL-Y8JQ0Gg/edit#slide=id.g13ef22b85ee_2_50
     was used as a guide for this code.
  */
  /*
   Note that XY vectors are composed of two doubles of an x coordinate
   and a y coordinate respectively.
   The value of each double can range from -1 to 1 which correspond directly
   to throttle values.
  */
  double x_target = m_stick.GetLeftX();
  double y_target = m_stick.GetLeftY();
  double z_target = m_stick.GetRightY();

  std::vector<double> strafe_vector;
  std::vector<double> turn_vector;

  strafe_vector = get_strafe_vector(x_target, y_target);

  // tv means 'turn vector'
  std::vector<double> tv_fore_port = get_turn_vector(z_target,
                                                     Robot::FORE_PORT);
  std::vector<double> tv_aft_port = get_turn_vector(z_target,
                                                     Robot::AFT_PORT);

  std::vector<double> tv_fore_starboard = get_turn_vector(z_target,
                                                          Robot::FORE_STARBOARD);

  std::vector<double> tv_aft_starboard = get_turn_vector(z_target,
                                                         Robot::AFT_STARBOARD);

  // fv means final vector
//  final_vector = get_final_vector(strafe_vector, turn_vector, module)

  std::vector<double> fv_fore_port = get_final_vector(strafe_vector,
                                                      tv_fore_port);

  std::vector<double> fv_aft_port = get_final_vector(strafe_vector,
                                                     tv_aft_port);

  std::vector<double> fv_fore_starboard = get_final_vector(strafe_vector,
                                                           tv_fore_starboard);

  std::vector<double> fv_aft_starboard = get_final_vector(strafe_vector,
                                                          tv_aft_starboard);

}

/**
 * This function returns a XY vector given inputs for strafe.
 * An example of strafe vectors can be found here: https://0x0.st/oeqr.png
 * The vectors for strafing are the same for each wheel
 */
std::vector<double> Robot::get_strafe_vector(double &x_target, double &y_target)
{
  // There is a non-zero chance that I screwed this up remarkably.
  // This differs from the 4499 documentation but it makes more sense.
  std::vector<double> x_vector = {x_target, 0.0};
  std::vector<double> y_vector = {0.0, y_target};

  std::vector<double> return_vector;

  return_vector = { ( x_vector[0] + y_vector[0] ),
                    ( x_vector[1] + y_vector[1] ) };

  return return_vector;
}

std::vector<double> Robot::get_turn_vector(double &y_target,
                                           module_location module)
{

  /** Returns a ZM vector for turning.
   * The angle remains static regardless of the requested turn,
   * however the magnitude changes depending on the y input.
   */

  std::vector<double> turn_vector;

  switch (module)
    {
  case FORE_PORT:
    turn_vector[0] = FORE_PORT_TURN_ANGLE;
    break;

  case FORE_STARBOARD:
    turn_vector[0] = FORE_STARBOARD_TURN_ANGLE;
      break;

  case AFT_PORT:
       turn_vector[0] = AFT_PORT_TURN_ANGLE;
      break;

  case AFT_STARBOARD:
    turn_vector[0] = AFT_STARBOARD_TURN_ANGLE;
      break;

  default:
    std::cout << "ERROR: No module given for turn calculation." << "\n";
    return {0.0, 0.0};
    break;

  }

  turn_vector[1] = y_target;

  return turn_vector;
}

std::vector<double> Robot::xy_to_zm(std::vector<double> &in_vector) {
  /** Structure of a zm variable is composed of two doubles.
   * The first is the angle from straight forwards.
   * The second is a magnitude that ranges from 0 (no power) to 1 (full power)
   * It is possible that the current code could return a value larger than 0
   * such as sqrt(2).
   * It is unclear what should be done for that issue.
   */
  std::vector<double> out_vector;

  // Distance formula to determine magnitude.
  // Zeroes are included to stay true to the formula.

  out_vector[1] =
    ( std::sqrt( std::pow( ( in_vector[0] - 0.0 ), 2.0 ) +
                 std::pow( ( in_vector[1] - 0.0 ), 2.0 ) ) );

  // Now for the hard part, determining an angle given two points.
  // I do not understand how to do this, however, it looks like std::atan2 does

  //atan2 uses y,x
  // If the point is in quadrants III or IV it will return a negative value.
  // Said value is always the shortest angle from a ray that intersects 1,0

  out_vector[0] = std::atan2( in_vector[1], in_vector[0] );


  return out_vector;
}

std::vector<double> Robot::get_final_vector(std::vector<double> &strafe_vector, std::vector<double> &turn_vector) {

  std::vector<double> return_vector;
  return_vector[0] = ( (strafe_vector[0] + turn_vector[0]) / 2.0 );
  return_vector[1] = ( (strafe_vector[1] + turn_vector[0]) / 2.0 );

  return return_vector;
}


void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
