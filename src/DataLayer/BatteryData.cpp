#include "BatteryData.h"

BatteryData::BatteryData()
    : alive_(true)
    , dischargeRelayEnabled_(true)
    , chargeRelayEnabled_(false)
    , chargerSafetyEnabled_(true)
    , malfunctionIndicatorActive_(true)
    , multiPurposeInputSignalStatus_(true)
    , alwaysOnSignalStatus_(false)
    , isReadySignalStatus_(true)
    , isChargingSignalStatus_(true)
    , populatedCells_(2)
    , inputVoltage12V_(12.33f)
    , fanVoltage_(12.33f)
    , packCurrent_(33.33f)
    , packVoltage_(12.33f)
    , packStateOfCharge_(88)
    , packAmpHours_(32.33f)
    , packDepthOfDischarge_(77)
    , highTemperature_(60)
    , highThermistorId_(1)
    , lowTemperature_(44)
    , lowThermistorId_(2)
    , averageTemperature_(52)
    , internalTemperature_(55)
    , fanSpeed_(43)
    , requestedFanSpeed_(45)
    , lowCellVoltage_(10)
    , lowCellVoltageId_(0)
    , highCellVoltage_(14)
    , highCellVoltageId_(1)
    , averageCellVoltage_(12)
{
}

BatteryData::~BatteryData()
{
}

bool BatteryData::alive() const
{
    return alive_;
}

bool BatteryData::dischargeRelayEnabled() const
{
    return dischargeRelayEnabled_;
}

bool BatteryData::chargeRelayEnabled() const
{
    return chargeRelayEnabled_;
}

bool BatteryData::chargerSafetyEnabled() const
{
    return chargerSafetyEnabled_;
}

bool BatteryData::malfunctionIndicatorActive() const
{
    return malfunctionIndicatorActive_;
}

bool BatteryData::multiPurposeInputSignalStatus() const
{
    return multiPurposeInputSignalStatus_;
}

bool BatteryData::alwaysOnSignalStatus() const
{
    return alwaysOnSignalStatus_;
}

bool BatteryData::isReadySignalStatus() const
{
    return isReadySignalStatus_;
}

bool BatteryData::isChargingSignalStatus() const
{
    return isChargingSignalStatus_;
}

unsigned char BatteryData::populatedCells() const
{
    return populatedCells_;
}

float BatteryData::inputVoltage12V() const
{
    return inputVoltage12V_;
}

float BatteryData::fanVoltage() const
{
    return fanVoltage_;
}

float BatteryData::packCurrent() const
{
    return packCurrent_;
}

float BatteryData::packVoltage() const
{
    return packVoltage_;
}

float BatteryData::packStateOfCharge() const
{
    return packStateOfCharge_;
}

float BatteryData::packAmpHours() const
{
    return packAmpHours_;
}

float BatteryData::packDepthOfDischarge() const
{
    return packDepthOfDischarge_;
}

unsigned char BatteryData::highTemperature() const
{
    return highTemperature_;
}

unsigned char BatteryData::highThermistorId() const
{
    return highThermistorId_;
}

unsigned char BatteryData::lowTemperature() const
{
    return lowTemperature_;
}

unsigned char BatteryData::lowThermistorId() const
{
    return lowThermistorId_;
}

unsigned char BatteryData::averageTemperature() const
{
    return averageTemperature_;
}

unsigned char BatteryData::internalTemperature() const
{
    return internalTemperature_;
}

unsigned char BatteryData::fanSpeed() const
{
    return fanSpeed_;
}

unsigned char BatteryData::requestedFanSpeed() const
{
    return requestedFanSpeed_;
}

unsigned short BatteryData::lowCellVoltage() const
{
    return lowCellVoltage_;
}

unsigned char BatteryData::lowCellVoltageId() const
{
    return lowCellVoltageId_;
}

unsigned short BatteryData::highCellVoltage() const
{
    return highCellVoltage_;
}

unsigned char BatteryData::highCellVoltageId() const
{
    return highCellVoltageId_;
}

unsigned short BatteryData::averageCellVoltage() const
{
    return averageCellVoltage_;
}

void BatteryData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void BatteryData::setDischargeRelayEnabled(const bool& dischargeRelayEnabled)
{
    dischargeRelayEnabled_ = dischargeRelayEnabled;
}

void BatteryData::setChargeRelayEnabled(const bool& chargeRelayEnabled)
{
    chargeRelayEnabled_ = chargeRelayEnabled;
}

void BatteryData::setChargerSafetyEnabled(const bool& chargerSafetyEnabled)
{
    chargerSafetyEnabled_ = chargerSafetyEnabled;
}

void BatteryData::setMalfunctionIndicatorActive(const bool& malfunctionIndicatorActive)
{
    malfunctionIndicatorActive_ = malfunctionIndicatorActive;
}

void BatteryData::setMultiPurposeInputSignalStatus(const bool& multiPurposeInputSignalStatus)
{
    multiPurposeInputSignalStatus_ = multiPurposeInputSignalStatus;
}

void BatteryData::setAlwaysOnSignalStatus(const bool& alwaysOnSignalStatus)
{
    alwaysOnSignalStatus_ = alwaysOnSignalStatus;
}

void BatteryData::setIsReadySignalStatus(const bool& isReadySignalStatus)
{
    isReadySignalStatus_ = isReadySignalStatus;
}

void BatteryData::setIsChargingSignalStatus(const bool& isChargingSignalStatus)
{
    isChargingSignalStatus_ = isChargingSignalStatus;
}

void BatteryData::setPopulatedCells(const unsigned char& populatedCells)
{
    populatedCells_ = populatedCells;
}

void BatteryData::setInputVoltage12V(const float& inputVoltage12V)
{
    inputVoltage12V_ = inputVoltage12V;
}

void BatteryData::setFanVoltage(const float& fanVoltage)
{
    fanVoltage_ = fanVoltage;
}

void BatteryData::setPackCurrent(const float& packCurrent)
{
    packCurrent_ = packCurrent;
}

void BatteryData::setPackVoltage(const float& packVoltage)
{
    packVoltage_ = packVoltage;
}

void BatteryData::setPackStateOfCharge(const float& packStateOfCharge)
{
    packStateOfCharge_ = packStateOfCharge;
}

void BatteryData::setPackAmpHours(const float& packAmpHours)
{
    packAmpHours_ = packAmpHours;
}

void BatteryData::setPackDepthOfDischarge(const float& packDepthOfDischarge)
{
    packDepthOfDischarge_ = packDepthOfDischarge;
}

void BatteryData::setHighTemperature(const unsigned char& highTemperature)
{
    highTemperature_ = highTemperature;
}

void BatteryData::setHighThermistorId(const unsigned char& highThermistorId)
{
    highThermistorId_ = highThermistorId;
}

void BatteryData::setLowTemperature(const unsigned char& lowTemperature)
{
    lowTemperature_ = lowTemperature;
}

void BatteryData::setLowThermistorId(const unsigned char& lowThermistorId)
{
    lowThermistorId_ = lowThermistorId;
}

void BatteryData::setAverageTemperature(const unsigned char& averageTemperature)
{
    averageTemperature_ = averageTemperature;
}

void BatteryData::setInternalTemperature(const unsigned char& internalTemperature)
{
    internalTemperature_ = internalTemperature;
}

void BatteryData::setFanSpeed(const unsigned char& fanSpeed)
{
    fanSpeed_ = fanSpeed;
}

void BatteryData::setRequestedFanSpeed(const unsigned char& requestedFanSpeed)
{
    requestedFanSpeed_ = requestedFanSpeed;
}

void BatteryData::setLowCellVoltage(const unsigned short& lowCellVoltage)
{
    lowCellVoltage_ = lowCellVoltage;
}

void BatteryData::setLowCellVoltageId(const unsigned char& lowCellVoltageId)
{
    lowCellVoltageId_ = lowCellVoltageId;
}

void BatteryData::setHighCellVoltage(const unsigned short& highCellVoltage)
{
    highCellVoltage_ = highCellVoltage;
}

void BatteryData::setHighCellVoltageId(const unsigned char& highCellVoltageId)
{
    highCellVoltageId_ = highCellVoltageId;
}

void BatteryData::setAverageCellVoltage(const unsigned short& averageCellVoltage)
{
    averageCellVoltage_ = averageCellVoltage;
}
