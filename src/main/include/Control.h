#pragma once

#include <iostream>
#include <vector>
#include "ctre/Phoenix.h"

class Control
{
 public:
  Control();
  void dashboard_init();
  void read_dashboard();
  void fore_port(std::vector<double> &target);
  void fore_starboard(std::vector<double> &target);
  void aft_port(std::vector<double> &target);
  void aft_starboard(std::vector<double> &target);

  ~Control();

private:

  struct PidCoeff {
    double kP,
      double kI,
      double kD,
      double kIz,
      double kFF,
      double kMaxOutput,
      double kMinOutput};

  WPI_talonFX m_FORE_PORT_SPIN_MOTOR {};
  WPI_talonFX m_FORE_STARBOARD_SPIN_MOTOR {};
  WPI_talonFX m_AFT_PORT_SPIN_MOTOR {};
  WPI_talonFX m_AFT_STARBOARD_SPIN_MOTOR {};

  WPI_talonFX m_FORE_PORT_TURN_MOTOR {};
  WPI_talonFX m_FORE_STARBOARD_TURN_MOTOR {};
  WPI_talonFX m_AFT_PORT_TURN_MOTOR {};
  WPI_talonFX m_AFT_STARBOARD_TURN_MOTOR {};

  //FP stands for Fore Port
  //FS stands for Fore Starboard
  //AP stands for Aft Port
  //AS stands for Aft Starboard
  PidCoeff m_FP_SPIN_PID_COEF{};
  PidCoeff m_FS_SPIN_PID_COEF{};
  PidCoeff m_AP_SPIN_PID_COEF{};
  PidCoeff m_AS_SPIN_PID_COEF{};

  PidCoeff m_FP_TURN_PID_COEF{};
  PidCoeff m_FS_TURN_PID_COEF{};
  PidCoeff m_AP_TURN_PID_COEF{};
  PidCoeff m_AS_TURN_PID_COEF{};

  static const double m_SPIN_RPM_MAP;
  static const double m_TURN_ENCODER_MAP;
};
