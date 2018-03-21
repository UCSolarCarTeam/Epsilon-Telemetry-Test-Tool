#include "BatteryData.h"
#include <QDebug>
BatteryData::BatteryData()
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

unsigned char BatteryData::prechargeState() const
{
    return prechargeState_;
}

const char* BatteryData::prechargeStateJSON() const
{
    return prechargeStateJSON_;
}

unsigned char BatteryData::auxVoltage() const
{
    return auxVoltage_;
}

bool BatteryData::auxBmsAlive() const
{
    return auxBmsAlive_;
}

bool BatteryData::strobeBmsLight() const
{
    return strobeBmsLight_;
}

bool BatteryData::allowCharge() const
{
    return allowCharge_;
}

bool BatteryData::contactorError() const
{
    return contactorError_;
}

void BatteryData::setAlive(const bool& alive = true)
{
    alive_ = alive;
}

void BatteryData::setDischargeRelayEnabled(const bool& dischargeRelayEnabled = true)
{
    dischargeRelayEnabled_ = dischargeRelayEnabled;
}

void BatteryData::setChargeRelayEnabled(const bool& chargeRelayEnabled = false)
{
    chargeRelayEnabled_ = chargeRelayEnabled;
}

void BatteryData::setChargerSafetyEnabled(const bool& chargerSafetyEnabled = true)
{
    chargerSafetyEnabled_ = chargerSafetyEnabled;
}

void BatteryData::setMalfunctionIndicatorActive(const bool& malfunctionIndicatorActive = true)
{
    malfunctionIndicatorActive_ = malfunctionIndicatorActive;
}

void BatteryData::setMultiPurposeInputSignalStatus(const bool& multiPurposeInputSignalStatus = true)
{
    multiPurposeInputSignalStatus_ = multiPurposeInputSignalStatus;
}

void BatteryData::setAlwaysOnSignalStatus(const bool& alwaysOnSignalStatus = false)
{
    alwaysOnSignalStatus_ = alwaysOnSignalStatus;
}

void BatteryData::setIsReadySignalStatus(const bool& isReadySignalStatus = true)
{
    isReadySignalStatus_ = isReadySignalStatus;
}

void BatteryData::setIsChargingSignalStatus(const bool& isChargingSignalStatus = true)
{
    isChargingSignalStatus_ = isChargingSignalStatus;
}

void BatteryData::setPopulatedCells(const unsigned char& populatedCells = 2)
{
    populatedCells_ = populatedCells;
}

void BatteryData::setInputVoltage12V(const float& inputVoltage12V = 12.33f)
{
    inputVoltage12V_ = inputVoltage12V;
}

void BatteryData::setFanVoltage(const float& fanVoltage = 12.33f)
{
    fanVoltage_ = fanVoltage;
}

void BatteryData::setPackCurrent(const float& packCurrent = 33.33f)
{
    packCurrent_ = packCurrent;
}

void BatteryData::setPackVoltage(const float& packVoltage = 12.33f)
{
    packVoltage_ = packVoltage;
}

void BatteryData::setPackStateOfCharge(const float& packStateOfCharge = 88)
{
    packStateOfCharge_ = packStateOfCharge;
}

void BatteryData::setPackAmpHours(const float& packAmpHours = 32.33f)
{
    packAmpHours_ = packAmpHours;
}

void BatteryData::setPackDepthOfDischarge(const float& packDepthOfDischarge = 77)
{
    packDepthOfDischarge_ = packDepthOfDischarge;
}

void BatteryData::setHighTemperature(const unsigned char& highTemperature = 60)
{
    highTemperature_ = highTemperature;
}

void BatteryData::setHighThermistorId(const unsigned char& highThermistorId = 1)
{
    highThermistorId_ = highThermistorId;
}

void BatteryData::setLowTemperature(const unsigned char& lowTemperature = 44)
{
    lowTemperature_ = lowTemperature;
}

void BatteryData::setLowThermistorId(const unsigned char& lowThermistorId = 2)
{
    lowThermistorId_ = lowThermistorId;
}

void BatteryData::setAverageTemperature(const unsigned char& averageTemperature = 52)
{
    averageTemperature_ = averageTemperature;
}

void BatteryData::setInternalTemperature(const unsigned char& internalTemperature = 55)
{
    internalTemperature_ = internalTemperature;
}

void BatteryData::setFanSpeed(const unsigned char& fanSpeed = 43)
{
    fanSpeed_ = fanSpeed;
}

void BatteryData::setRequestedFanSpeed(const unsigned char& requestedFanSpeed = 45)
{
    requestedFanSpeed_ = requestedFanSpeed;
}

void BatteryData::setLowCellVoltage(const unsigned short& lowCellVoltage = 10)
{
    lowCellVoltage_ = lowCellVoltage;
}

void BatteryData::setLowCellVoltageId(const unsigned char& lowCellVoltageId = 0)
{
    lowCellVoltageId_ = lowCellVoltageId;
}

void BatteryData::setHighCellVoltage(const unsigned short& highCellVoltage = 14)
{
    highCellVoltage_ = highCellVoltage;
}

void BatteryData::setHighCellVoltageId(const unsigned char& highCellVoltageId = 1)
{
    highCellVoltageId_ = highCellVoltageId;
}

void BatteryData::setAverageCellVoltage(const unsigned short& averageCellVoltage = 12)
{
    averageCellVoltage_ = averageCellVoltage;
}

void BatteryData::setPrechargeState(const QString& prechargeState = "EnablePack")
{
    unsigned char pState;

    if  (prechargeState == "Idle")
    {
        pState = 0;
    }
    if (prechargeState == "Precharge")
    {
        pState = 1;
    }
    if (prechargeState == "Measure")
    {
        pState = 2;
    }
    if (prechargeState == "EnablePack")
    {
        pState = 3;
    }
    else
    {
        pState = 4;
    }

    prechargeState_ = pState;
}

void BatteryData::setAuxVoltage(const unsigned char& auxVoltage = 13)
{
    auxVoltage_ = auxVoltage;
}

void BatteryData::setAuxBmsAlive(const bool& auxBmsAlive = true)
{
    auxBmsAlive_ = auxBmsAlive;
}

void BatteryData::setStrobeBmsLight(const bool& strobeBmsLight = true)
{
    strobeBmsLight_ = strobeBmsLight;
}

void BatteryData::setAllowCharge(const bool& allowCharge = true)
{
    allowCharge_ = allowCharge;
}

void BatteryData::setContactorError(const bool& contactorError = true)
{
    contactorError_ = contactorError;
}
