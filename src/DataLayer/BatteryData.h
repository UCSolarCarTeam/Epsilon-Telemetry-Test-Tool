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
        , prechargeStateJSON("Enable Pack")
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
    const char* prechargeStateJSON;
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

    /*
     BatteryData()
        : alive(true)
        , bmsRelayStatus(1)
        , populatedCells(2)
        , inputVoltage12V(12.33f)
        , fanVoltage(12.33f)
        , packCurrent(33.33f)
        , packStateOfCharge(88)
        , packAmpHours(32.33f)
        , packDepthOfDischarge(77)
        , highTemperature(60)
        , highThermistorId(1)
        , lowTemperature(44)
        , lowThermistorId(2)
        , averageTemperature(52)
        , internalTemperature(55)
        . fanSpeed(43)
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
    unsigned char bmsRelayStatus;
    unsinged char populatedCells;
    float inputVoltage12V;
    float fanVoltage;
    float packCurrent;
    float packStateOfCharge;
    float packAmphours;
    float packDepthOfDischarge;
    unsigned char highTemperature;
    unsigned char highThermistorId;
    unsigned char lowTemperature;
    unsigned char lowThermistorId;
    unsigned char averageTemperature;
    unsigned char internalTemperature;
    unsigned char fanSpeed;
    unsigned char requestedFanSpeed;
    unsigned short int lowCellVoltage;
    unsigned char lowCellVoltageId;
    unsigned short int highCellVoltage;
    unsigned char highCellVoltageId;
    unsigned short int averageCellVoltage;
    PrechargeState prechargeState;
    const char* prechargeStateJSON;
    unsigned char auxVoltage;
    unsigned char auxBmsAlive;
  */
};
