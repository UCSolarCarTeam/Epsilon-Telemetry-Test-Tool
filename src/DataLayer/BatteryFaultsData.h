#pragma once

struct BatteryFaultsData
{
    BatteryFaultsData()
        : cellOverVoltage(true)
        , cellUnderVoltage(false)
        , cellOverTemperature(true)
        , measurementUntrusted(false)
        , cmuCommTimeout(true)
        , vehicleCommTimeout(false)
        , bmuInSetupMode(true)
        , cmuCanBusPowerStatus(false)
        , packIsolationTestFailure(true)
        , softwareOverCurrent(false)
        , can12VSupplyLow(true)
        , contactorStuck(false)
        , cmuDetectedExtraCellPresent(false)
    {}

    bool cellOverVoltage;
    bool cellUnderVoltage;
    bool cellOverTemperature;
    bool measurementUntrusted;
    bool cmuCommTimeout;
    bool vehicleCommTimeout;
    bool bmuInSetupMode;
    bool cmuCanBusPowerStatus;
    bool packIsolationTestFailure;
    bool softwareOverCurrent;
    bool can12VSupplyLow;
    bool contactorStuck;
    bool cmuDetectedExtraCellPresent;
};
