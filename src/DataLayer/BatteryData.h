#pragma once

struct BatteryData
{
    BatteryData()
        : alive(true)
        , dischargeRelayEnabled(true)
        , chargeRelayEnabled(false)
        , chargerSafetyEnabled(true)
        , malfunctionIndicatorActive(true)
        , multiPurposeInputSignalStatus(true)
        , alwaysOnSignalStatus(false)
        , isReadySignalStatus(true)
        , isChargingSignalStatus(true)
        , populatedCells(2)
        , inputVoltage12V(12.33f)
        , fanVoltage(12.33f)
        , packCurrent(33.33f)
        , packVoltage(12.33f)
        , packStateOfCharge(88)
        , packAmpHours(32.33f)
        , packDepthOfDischarge(77)
        , highTemperature(60)
        , highThermistorId(1)
        , lowTemperature(44)
        , lowThermistorId(2)
        , averageTemperature(52)
        , internalTemperature(55)
        , fanSpeed(43)
        , requestedFanSpeed(45)
        , lowCellVoltage(10)
        , lowCellVoltageId(0)
        , highCellVoltage(14)
        , highCellVoltageId(1)
        , averageCellVoltage(12)
        , prechargeState(PrechargeState::EnablePack)
        , prechargeStateJSON("Enable Pack")
        , auxVoltage(13)
        , auxBmsAlive(true)
        , strobeBmsLight(true)
        , allowCharge(true)
        , contactorError(true)
    {}

    enum PrechargeState
    {
        Idle = 0,
        Precharge = 1,
        Measure = 2,
        EnablePack = 3,
        Run = 4,
    };

    bool alive;
    bool dischargeRelayEnabled;
    bool chargeRelayEnabled;
    bool chargerSafetyEnabled;
    bool malfunctionIndicatorActive;
    bool multiPurposeInputSignalStatus;
    bool alwaysOnSignalStatus;
    bool isReadySignalStatus;
    bool isChargingSignalStatus;
    unsigned char populatedCells;
    float inputVoltage12V;
    float fanVoltage;
    float packCurrent;
    float packVoltage;
    float packStateOfCharge;
    float packAmpHours;
    float packDepthOfDischarge;
    unsigned char highTemperature;
    unsigned char highThermistorId;
    unsigned char lowTemperature;
    unsigned char lowThermistorId;
    unsigned char averageTemperature;
    unsigned char internalTemperature;
    unsigned char fanSpeed;
    unsigned char requestedFanSpeed;
    unsigned short lowCellVoltage;
    unsigned char lowCellVoltageId;
    unsigned short highCellVoltage;
    unsigned char highCellVoltageId;
    unsigned short averageCellVoltage;
    PrechargeState prechargeState;
    const char* prechargeStateJSON;
    unsigned char auxVoltage;
    bool auxBmsAlive;
    bool strobeBmsLight;
    bool allowCharge;
    bool contactorError;
};
