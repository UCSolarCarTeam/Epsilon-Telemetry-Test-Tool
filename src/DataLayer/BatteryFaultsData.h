#pragma once

struct BatteryFaultsData
{
    BatteryFaultsData()
    : cellOverVoltage_(true)
    , cellUnderVoltage_(false)
    , cellOverTemperature_(true)
    , measurementUntrusted_(false)
    , cmuCommTimeout_(true)
    , vehicleCommTimeout_(false)
    , bmuInSetupMode_(true)
    , cmuCanBusPowerStatus_(false)
    , packIsolationTestFailure_(true)
    , softwareOverCurrent_(false)
    , can12VSupplyLow_(true)
    , contactorStuck_(false)
    , cmuDetectedExtraCellPresent_(false)
    {}

    bool cellOverVoltage_;
    bool cellUnderVoltage_;
    bool cellOverTemperature_;
    bool measurementUntrusted_;
    bool cmuCommTimeout_;
    bool vehicleCommTimeout_;
    bool bmuInSetupMode_;
    bool cmuCanBusPowerStatus_;
    bool packIsolationTestFailure_;
    bool softwareOverCurrent_;
    bool can12VSupplyLow_;
    bool contactorStuck_;
    bool cmuDetectedExtraCellPresent_;
}
