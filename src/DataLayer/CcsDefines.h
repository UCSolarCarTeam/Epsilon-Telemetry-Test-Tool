#pragma once

namespace CcsDefines
{
   const int KEY_MOTOR_PKG_ID = 1;
   const int MOTOR_DETAILS_0_PKG_ID = 2;
   const int MOTOR_DETAILS_1_PKG_ID = 3;
   const int DRIVER_CONTROLS_PKG_ID = 4;
   const int MOTOR_FAULTS_PKG_ID = 5;
   const int BATTERY_FAULTS_PKG_ID = 6;
   const int CMU_PKG_ID = 8;
   const int MPPT_PKG_ID = 9;
   const int LIGHTS_PKG_ID = 10;

   const int MPPT_COUNT = 3;
   const int CMU_COUNT = 4;

   // Control parameters
   // Wavesculptor 22 requires velocity in RPM
   const int MAX_FORWARD_RPM = 1000; //Was 1298 on old system
   const int MAX_REVERSE_RPM = -200;
   const float MAX_BATTERY_CURRENT_DRAIN = -99.0f;
   const float MAX_BATTERY_CURRENT_CHARGE = 60.0f;
   const float MAX_CURRENT_AMPS = 70.0;
   const float REGEN_INPUT_SCALING = 0.5f;
   //RPM to Kph is wheel diameter * pi * 60 s / 1000 m
   const float RPM_TO_KPH_CONVERSION = 0.545 * 3.14159265358979323 * 60.0 / 1000.0;
   const float RPM_TO_MPS_CONVERSION = 0.545 * 3.14159265358979323 / 60.0;
   const float MPS_KPH_CONVERSION = 3.6;
   // These number masks out all the errors that don't really matter
   const unsigned int MAJOR_BMU_ERROR_MASK = 0x1C37;
   const unsigned int MAJOR_MC_ERROR_MASK = 0xFF;
}
