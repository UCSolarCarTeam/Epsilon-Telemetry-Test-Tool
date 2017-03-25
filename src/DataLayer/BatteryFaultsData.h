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

    /*
    BatteryFaultsData()
        : internalCommFault(true)
        , internalConversionFault(false)
        , weakCellFault(true)
        , lowCellVoltageFault(false)
        , openWiringFault(true)
        , currentSensorFault(false)
        , packVoltageSensorFault(true)
        , weakPackFault(false)
        , voltageRedundancyFault(true)
        , fanMonitorFault(false)
        , thermistorFault(true)
        , canbusCommsFault(false)
        , highVoltageIsolationFault(false)
        , dclReducedLowSoc(true)
        , dclReducedLowTemp(false)
        , dclReducedLowCellVoltage(true)
        , dclReducedLowPackVoltage(false)
        , dclCclReducedVoltageFailsafe(true)
        , dclCclReducedCommsFailsafe(false)
        , cclReducedHighSoc(true)
        , cclReducedHighCellResist(false)
        , cclReducedTemperature(true)
        , cclReducedHighCellVoltage(false)
        , cclReducelACLimit(true)
    {}

    bool internalCommFault;
    bool internalConversionFault;
    bool weakCellFault;
    bool lowCellVoltageFault;
    bool openWiringFault;
    bool currentSensorFault;
    bool packVoltageSensorFault;
    bool weakPackFault;
    bool voltageRedundancyFault;
    bool fanMonitorFault;
    bool thermistorFault;
    bool canbusCommsFault;
    bool highVoltageIsolationFault;
    bool dclReducedLowSoc;
    bool dclReducedLowTemp;
    bool dclReducedLowCellVoltage;
    bool dclReducedLowPackVoltage;
    bool dclCclReducedVoltageFailsafe;
    bool dclCclReducedCommsFailsafe;
    bool cclReducedHighSoc;
    bool cclReducedHighCellResist;
    bool cclReducedTemperature;
    bool cclReducedHighCellVoltage;
    bool cclReducelACLimit;
  */
};
