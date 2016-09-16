#pragma once

struct BatteryData
{
    BatteryData()
    : alive_(true)
    , packSocAmpHours_(32.23f)
    , packSocPercentage_(33.33f)
    , packBalanceSoc_(34.43f)
    , packBalanceSocPercentage_(35)
    , chargingCellVoltageError_(36)
    , totalPackCapacity_(37)
    , contactor0Errorstatus_(true)
    , contactor1ErrorStatus_(false)
    , contactor0Status_(true)
    , contactor1Status_(false)
    , contactor12VSupplyOk_(true)
    , contactor2ErrorStatus_(false)
    , contactor2Status_(true)
    , prechargeState_(PrechargeState::EnablePack)
    , perchargeTimerElapsed_(false)
    , perchargeTimerNotElapsed_(true)
    , prechargeTimerCount_(38)
    , lowestCellVoltage_(39)
    , lowestCellVoltageCmuNumber_(0)
    , lowestCellVoltageCellNumber_(1)
    , highestCellVoltage_(40)
    , highestCellVoltageCmuNumber_(1)
    , highestCellVoltageCellNumber_(2)
    , lowestCellTemperature_(41)
    , lowestCellTemperatureCmuNumber_(2)
    , lowestCellTemperatureCellNumber_(3)
    , highestCellTemperature_(42)
    , highestCellTemperatureCmuNumber_(3)
    , highestCellTemperatureCellNumber_(4)
    , fan0Speed_(43)
    , fan1Speed_(44)
    , fanContactors12VCurrentConsumption_(45)
    , cmu12VCurrentConsumption_(46)
    , bmsCanLockedOut_(false)
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

    bool alive_;
    float packSocAmpHours_;
    float packSocPercentage_;
    float packBalanceSoc_;
    short unsigned int packBalanceSocPercentage_;
    short unsigned int chargingCellVoltageError_;
    short unsigned int totalPackCapacity_;
    bool contactor0Errorstatus_;
    bool contactor1ErrorStatus_;
    bool contactor0Status_;
    bool contactor1Status_;
    bool contactor12VSupplyOk_;
    bool contactor2ErrorStatus_;
    bool contactor2Status_;
    PrechargeState prechargeState_;
    bool perchargeTimerElapsed_;
    bool perchargeTimerNotElapsed_;
    unsigned short prechargeTimerCount_;
    unsigned short lowestCellVoltage_;
    char lowestCellVoltageCmuNumber_;
    char lowestCellVoltageCellNumber_;
    unsigned short highestCellVoltage_;
    char highestCellVoltageCmuNumber_;
    char highestCellVoltageCellNumber_;
    unsigned short lowestCellTemperature_;
    char lowestCellTemperatureCmuNumber_;
    char lowestCellTemperatureCellNumber_;
    unsigned short highestCellTemperature_;
    char highestCellTemperatureCmuNumber_;
    char highestCellTemperatureCellNumber_;
    unsigned short fan0Speed_;
    unsigned short fan1Speed_;
    unsigned short fanContactors12VCurrentConsumption_;
    unsigned short cmu12VCurrentConsumption_;
    bool bmsCanLockedOut_;
}
