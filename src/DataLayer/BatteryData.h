#pragma once

struct BatteryData
{
    BatteryData()
        : alive(true)
        , packSocAmpHours(32.23f)
        , packSocPercentage(33.33f)
        , packBalanceSoc(34.43f)
        , packBalanceSocPercentage(0.35)
        , chargingCellVoltageError(36)
        , cellTemperatureMargin(37)
        , dischargingCellVoltageError(36)
        , totalPackCapacity(37)
        , contactor0Errorstatus(true)
        , contactor1ErrorStatus(false)
        , contactor0Status(true)
        , contactor1Status(false)
        , contactor12VSupplyOk(true)
        , contactor2ErrorStatus(false)
        , contactor2Status(true)
        , prechargeState(PrechargeState::EnablePack)
        , prechargeTimerElapsed(false)
        , prechargeTimerNotElapsed(true)
        , prechargeTimerCount(38)
        , lowestCellVoltage(39)
        , lowestCellVoltageCmuNumber(0)
        , lowestCellVoltageCellNumber(1)
        , highestCellVoltage(40)
        , highestCellVoltageCmuNumber(1)
        , highestCellVoltageCellNumber(2)
        , lowestCellTemperature(41)
        , lowestCellTemperatureCmuNumber(2)
        , lowestCellTemperatureCellNumber(3)
        , highestCellTemperature(42)
        , highestCellTemperatureCmuNumber(3)
        , highestCellTemperatureCellNumber(4)
        , voltage(240)
        , current(1200)
        , fan0Speed(43)
        , fan1Speed(44)
        , fanContactors12VCurrentConsumption(45)
        , cmu12VCurrentConsumption(46)
        , bmsCanLockedOut(false)
    {}

    enum PrechargeState
    {
        Error = 0,
        Idle = 1,
        EnablePack = 5,
        Measure = 2,
        Precharge = 3,
        Run = 4,
    };

    bool alive;
    float packSocAmpHours;
    float packSocPercentage;
    float packBalanceSoc;
    float packBalanceSocPercentage;
    unsigned short chargingCellVoltageError;
    unsigned short cellTemperatureMargin;
    unsigned short dischargingCellVoltageError;
    unsigned short totalPackCapacity;
    bool contactor0Errorstatus;
    bool contactor1ErrorStatus;
    bool contactor0Status;
    bool contactor1Status;
    bool contactor12VSupplyOk;
    bool contactor2ErrorStatus;
    bool contactor2Status;
    PrechargeState prechargeState;
    bool prechargeTimerElapsed;
    bool prechargeTimerNotElapsed;
    unsigned short prechargeTimerCount;
    unsigned short lowestCellVoltage;
    unsigned char lowestCellVoltageCmuNumber;
    unsigned char lowestCellVoltageCellNumber;
    unsigned short highestCellVoltage;
    unsigned char highestCellVoltageCmuNumber;
    unsigned char highestCellVoltageCellNumber;
    unsigned short lowestCellTemperature;
    unsigned char lowestCellTemperatureCmuNumber;
    unsigned char lowestCellTemperatureCellNumber;
    unsigned short highestCellTemperature;
    unsigned char highestCellTemperatureCmuNumber;
    unsigned char highestCellTemperatureCellNumber;
    unsigned int voltage;
    unsigned int current;
    unsigned short fan0Speed;
    unsigned short fan1Speed;
    unsigned short fanContactors12VCurrentConsumption;
    unsigned short cmu12VCurrentConsumption;
    bool bmsCanLockedOut;
};
