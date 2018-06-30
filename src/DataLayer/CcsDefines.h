#pragma once

namespace CcsDefines
{
    // Refer to https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0
    const unsigned char KEY_MOTOR_PKG_ID = 1;
    const unsigned char MOTOR_DETAILS_0_PKG_ID = 2;
    const unsigned char MOTOR_DETAILS_1_PKG_ID = 3;
    const unsigned char DRIVER_CONTROLS_PKG_ID = 4;
    const unsigned char MOTOR_FAULTS_PKG_ID = 5;
    const unsigned char BATTERY_FAULTS_PKG_ID = 6;
    const unsigned char BATTERY_PKG_ID = 7;
    const unsigned char MPPT_PKG_ID = 9;
    const unsigned char LIGHTS_PKG_ID = 10;
    const unsigned char AUX_BMS_PKG_ID = 11;
    const int MPPT_COUNT = 4;

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

    //This is used as a filler in the BatteryFaultsData limit flags array for entries that do not contain any data
    const bool NO_DATA = 0;
}
