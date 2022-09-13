#include "Control.h"

Control::Control(){
  //Initalize PID Controlers

  //Restore to factory default to prevent UB
  m_FORE_PORT_SPIN_MOTOR.ConfigFactoryDefault();
  m_FORE_STARBOARD_SPIN_MOTOR.ConfigFactoryDefault();
  m_AFT_PORT_SPIN_MOTOR.ConfigFactoryDefault();
  m_AFT_STARBOARD_SPIN_MOTOR.ConfigFactoryDefault();

  m_FORE_PORT_TURN_MOTOR.ConfigFactoryDefault();
  m_FORE_STARBOARD_TURN_MOTOR.ConfigFactoryDefault();
  m_AFT_PORT_TURN_MOTOR.ConfigFactoryDefault();
  m_AFT_STARBOARD_TURN_MOTOR.ConfigFactoryDefault();

  //Configure Sensor Source
  m_FORE_PORT_SPIN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_FORE_STARBOARD_SPIN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_AFT_PORT_SPIN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_AFT_STARBOARD_SPIN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);


  m_FORE_PORT_TURN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_FORE_STARBOARD_TURN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_AFT_PORT_TURN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

  m_AFT_STARBOARD_TURN_MOTOR.ConfigSelectedFeedbackSensor(
                                      FeedbackDevice::IntegratedSensor, 0, 10);

    // Set the peak and nominal outputs
  m_FORE_PORT_SPIN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_PORT_SPIN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_FORE_PORT_SPIN_MOTOR.ConfigPeakOutputForward(m_FP_SPIN_PID_COEF.kMaxOutput, 10);
  m_FORE_PORT_SPIN_MOTOR.ConfigPeakOutputReverse(m_FP_SPIN_PID_COEF.kMinOutput, 10);

  m_FORE_PORT_TURN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_PORT_TURN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_FORE_PORT_TURN_MOTOR.ConfigPeakOutputForward(m_FP_TURN_PID_COEF.kMaxOutput, 10);
  m_FORE_PORT_TURN_MOTOR.ConfigPeakOutputReverse(m_FP_TURN_PID_COEF.kMinOutput, 10);

  m_FORE_STARBOARD_SPIN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_STARBOARD_SPIN_MOTOR.ConfigNominalOutputReverse(0, 10);

  m_FORE_STARBOARD_SPIN_MOTOR.ConfigPeakOutputForward(
                                                m_FS_SPIN_PID_COEF.kMaxOutput, 10);

  m_FORE_STARBOARD_SPIN_MOTOR.ConfigPeakOutputReverse(
                                                m_FS_SPIN_PID_COEF.kMinOutput, 10);

  m_FORE_STARBOARD_TURN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_STARBOARD_TURN_MOTOR.ConfigNominalOutputReverse(0, 10);

  m_FORE_STARBOARD_TURN_MOTOR.ConfigPeakOutputForward(m_FS_TURN_PID_COEF.kMaxOutput, 10);

  m_FORE_STARBOARD_TURN_MOTOR.ConfigPeakOutputReverse(m_FS_TURN_PID_COEF.kMinOutput, 10);


  m_AFT_PORT_SPIN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_PORT_SPIN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_PORT_SPIN_MOTOR.ConfigPeakOutputForward(m_AP_SPIN_PID_COEF.kMaxOutput, 10);
  m_AFT_PORT_SPIN_MOTOR.ConfigPeakOutputReverse(m_AP_SPIN_PID_COEF.kMinOutput, 10);

  m_AFT_PORT_TURN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_PORT_TURN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_PORT_TURN_MOTOR.ConfigPeakOutputForward(m_AP_TURN_PID_COEF.kMaxOutput, 10);
  m_AFT_PORT_TURN_MOTOR.ConfigPeakOutputReverse(m_AP_TURN_PID_COEF.kMinOutput, 10);


  m_AFT_STARBOARD_SPIN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.ConfigPeakOutputForward(m_AS_SPIN_PID_COEF.kMaxOutput, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.ConfigPeakOutputReverse(m_AS_SPIN_PID_COEF.kMinOutput, 10);

  m_AFT_STARBOARD_TURN_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_STARBOARD_TURN_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_STARBOARD_TURN_MOTOR.ConfigPeakOutputForward(m_AS_TURN_PID_COEF.kMaxOutput, 10);
  m_AFT_STARBOARD_TURN_MOTOR.ConfigPeakOutputReverse(m_AS_TURN_PID_COEF.kMinOutput, 10);

  // Tuning config
  m_FORE_PORT_SPIN_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_PORT_SPIN_MOTOR.Config_kF(0, m_FP_SPIN_PID_COEF.kFF, 10);
  m_FORE_PORT_SPIN_MOTOR.Config_kP(0, m_FP_SPIN_PID_COEF.kP, 10);
  m_FORE_PORT_SPIN_MOTOR.Config_kI(0, m_FP_SPIN_PID_COEF.kI, 10);
  m_FORE_PORT_SPIN_MOTOR.Config_kD(0, m_FP_SPIN_PID_COEF.kD, 10);

  m_FORE_PORT_TURN_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_PORT_TURN_MOTOR.Config_kF(0, m_FP_TURN_PID_COEF.kFF, 10);
  m_FORE_PORT_TURN_MOTOR.Config_kP(0, m_FP_TURN_PID_COEF.kP, 10);
  m_FORE_PORT_TURN_MOTOR.Config_kI(0, m_FP_TURN_PID_COEF.kI, 10);
  m_FORE_PORT_TURN_MOTOR.Config_kD(0, m_FP_TURN_PID_COEF.kD, 10);

  m_FORE_STARBOARD_SPIN_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_STARBOARD_SPIN_MOTOR.Config_kF(0, m_FS_SPIN_PID_COEF.kFF, 10);
  m_FORE_STARBOARD_SPIN_MOTOR.Config_kP(0, m_FS_SPIN_PID_COEF.kP, 10);
  m_FORE_STARBOARD_SPIN_MOTOR.Config_kI(0, m_FS_SPIN_PID_COEF.kI, 10);
  m_FORE_STARBOARD_SPIN_MOTOR.Config_kD(0, m_FS_SPIN_PID_COEF.kD, 10);

  m_FORE_STARBOARD_TURN_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_STARBOARD_TURN_MOTOR.Config_kF(0, m_FS_TURN_PID_COEF.kFF, 10);
  m_FORE_STARBOARD_TURN_MOTOR.Config_kP(0, m_FS_TURN_PID_COEF.kP, 10);
  m_FORE_STARBOARD_TURN_MOTOR.Config_kI(0, m_FS_TURN_PID_COEF.kI, 10);
  m_FORE_STARBOARD_TURN_MOTOR.Config_kD(0, m_FS_TURN_PID_COEF.kD, 10);

  m_AFT_PORT_SPIN_MOTOR.SelectProfileSlot(0, 0);
  m_AFT_PORT_SPIN_MOTOR.Config_kF(0, m_AP_SPIN_PID_COEF.kFF, 10);
  m_AFT_PORT_SPIN_MOTOR.Config_kP(0, m_AP_SPIN_PID_COEF.kP, 10);
  m_AFT_PORT_SPIN_MOTOR.Config_kI(0, m_AP_SPIN_PID_COEF.kI, 10);
  m_AFT_PORT_SPIN_MOTOR.Config_kD(0, m_AP_SPIN_PID_COEF.kD, 10);

  m_AFT_STARBOARD_SPIN_MOTOR.SelectProfileSlot(0, 0);
  m_AFT_STARBOARD_SPIN_MOTOR.Config_kF(0, m_AS_SPIN_PID_COEF.kFF, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.Config_kP(0, m_AS_SPIN_PID_COEF.kP, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.Config_kI(0, m_AS_SPIN_PID_COEF.kI, 10);
  m_AFT_STARBOARD_SPIN_MOTOR.Config_kD(0, m_AS_SPIN_PID_COEF.kD, 10);
}

void Control::dashboard_init() {

  frc::SmartDashboard::PutNumber("Fore Port Turn P Gain", m_FP_TURN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Fore Port Turn I Gain", m_FP_TURN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Fore Port Turn D Gain", m_FP_TURN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Fore Port Turn FF Gain", m_FP_TURN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Fore Port Spin P Gain", m_FP_SPIN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Fore Port Spin I Gain", m_FP_SPIN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Fore Port Spin D Gain", m_FP_SPIN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Fore Port Spin FF Gain", m_FP_SPIN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Fore Starboard Turn P Gain", m_FS_TURN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Fore Starboard Turn I Gain", m_FS_TURN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Fore Starboard Turn D Gain", m_FS_TURN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Fore Starboard Turn FF Gain", m_FS_TURN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Fore Starboard Spin P Gain", m_FS_SPIN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Fore Starboard Spin I Gain", m_FS_SPIN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Fore Starboard Spin D Gain", m_FS_SPIN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Fore Starboard Spin FF Gain", m_FS_SPIN_PID_COEF.kFF);


  frc::SmartDashboard::PutNumber("Aft Port Turn I Gain", m_AP_TURN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Aft Port Turn P Gain", m_AP_TURN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Aft Port Turn D Gain", m_AP_TURN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Aft Port Turn FF Gain", m_AP_TURN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Aft Port Spin P Gain", m_AP_SPIN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Aft Port Spin I Gain", m_AP_SPIN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Aft Port Spin D Gain", m_AP_SPIN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Aft Port Spin FF Gain", m_AP_SPIN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Aft Starboard Turn P Gain", m_AS_TURN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Aft Starboard Turn I Gain", m_AS_TURN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Aft Starboard Turn D Gain", m_AS_TURN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Aft Starboard Turn FF Gain", m_AS_TURN_PID_COEF.kFF);

  frc::SmartDashboard::PutNumber("Aft Starboard Spin P Gain", m_AS_SPIN_PID_COEF.kP);
  frc::SmartDashboard::PutNumber("Aft Starboard Spin I Gain", m_AS_SPIN_PID_COEF.kI);
  frc::SmartDashboard::PutNumber("Aft Starboard Spin D Gain", m_AS_SPIN_PID_COEF.kD);
  frc::SmartDashboard::PutNumber("Aft Starboard Spin FF Gain", m_AS_SPIN_PID_COEF.kFF);

}


void Control::read_dashboard()
{

  m_FP_TURN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Fore Port Turn P Gain", 0.0);
  m_FP_TURN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Fore Port Turn I Gain", 0.0);
  m_FP_TURN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Fore Port Turn D Gain", 0.0);
  m_FP_TURN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Fore Port Turn FF Gain", 0.0);

  m_FP_SPIN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Fore Port Spin P Gain", 0.0);
  m_FP_SPIN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Fore Port Spin I Gain", 0.0);
  m_FP_SPIN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Fore Port Spin D Gain", 0.0);
  m_FP_SPIN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Fore Port Spin FF Gain", 0.0);

  m_FS_TURN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Fore Starboard Turn P Gain", 0.0);
  m_FS_TURN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Fore Starboard Turn I Gain", 0.0);
  m_FS_TURN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Fore Starboard Turn D Gain", 0.0);
  m_FS_TURN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Fore Starboard Turn FF Gain", 0.0);

  m_FS_SPIN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Fore Starboard Spin P Gain", 0.0);
  m_FS_SPIN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Fore Starboard Spin I Gain", 0.0);
  m_FS_SPIN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Fore Starboard Spin D Gain", 0.0);
  m_FS_SPIN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Fore Starboard Spin FF Gain", 0.0);
/* --- */
  m_AP_TURN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Aft Port Turn P Gain", 0.0);
  m_AP_TURN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Aft Port Turn I Gain", 0.0);
  m_AP_TURN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Aft Port Turn D Gain", 0.0);
  m_AP_TURN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Aft Port Turn FF Gain", 0.0);

  m_AP_SPIN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Aft Port Spin P Gain", 0.0);
  m_AP_SPIN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Aft Port Spin I Gain", 0.0);
  m_AP_SPIN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Aft Port Spin D Gain", 0.0);
  m_AP_SPIN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Aft Port Spin FF Gain", 0.0);

  m_AS_TURN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Aft Starboard Turn P Gain", 0.0);
  m_AS_TURN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Aft Starboard Turn I Gain", 0.0);
  m_AS_TURN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Aft Starboard Turn D Gain", 0.0);
  m_AS_TURN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Aft Starboard Turn FF Gain", 0.0);

  m_AS_SPIN_PID_COEF.kP = frc::SmartDashboard::GetNumber("Aft Starboard Spin P Gain", 0.0);
  m_AS_SPIN_PID_COEF.kI = frc::SmartDashboard::GetNumber("Aft Starboard Spin I Gain", 0.0);
  m_AS_SPIN_PID_COEF.kD = frc::SmartDashboard::GetNumber("Aft Starboard Spin D Gain", 0.0);
  m_AS_SPIN_PID_COEF.kFF = frc::SmartDashboard::GetNumber("Aft Starboard Spin FF Gain", 0.0);
}

void Control::fore_port(std::vector<double> &target)
{
  m_FORE_PORT_SPIN_MOTOR.Set(ControlMode::Velocity, ( target[1] * m_SPIN_RPM_MAP ) );
  m_FORE_PORT_TURN_MOTOR.Set(ControlMode::Position, ( target[0] * m_TURN_ENCODER_MAP ));
}

void Control::fore_starboard(std::vector<double> &target)
{
  m_FORE_STARBOARD_SPIN_MOTOR.Set(ControlMode::Velocity, ( target[1] * m_SPIN_RPM_MAP ) );
  m_FORE_STARBOARD_TURN_MOTOR.Set(ControlMode::Position, ( target[0] * m_TURN_ENCODER_MAP ));
}

void Control::aft_port(std::vector<double> &target)
{
  m_AFT_PORT_SPIN_MOTOR.Set(ControlMode::Velocity, ( target[1] * m_SPIN_RPM_MAP ) );
  m_AFT_PORT_TURN_MOTOR.Set(ControlMode::Position, ( target[0] * m_TURN_ENCODER_MAP ));
}

void Control::aft_starboard(std::vector<double> &target)
{
  m_AFT_STARBOARD_SPIN_MOTOR.Set(ControlMode::Velocity, ( target[1] * m_SPIN_RPM_MAP ) );
  m_AFT_STARBOARD_TURN_MOTOR.Set(ControlMode::Position, ( target[0] * m_TURN_ENCODER_MAP ));
}

Control::~Control(){}
