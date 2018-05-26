#include "AuxBmsData.h"

AuxBmsData::AuxBmsData()
        : prechargeState_(PrechargeState::OFF)
        , prechargeStateJSON_("OFF")
        , auxVoltage_(13)
        , auxBmsAlive_(true)
        , strobeBmsLight_(true)
        , allowCharge_(true)
        , contactorError_(true)
        , highVoltageEnable_(true)
{
}

AuxBmsData::~AuxBmsData()
{
}

PrechargeState AuxBmsData::prechargeState() const
{
    return prechargeState_;
}

QString AuxBmsData::prechargeStateJSON() const
{
    return prechargeStateJSON_;
}

unsigned char AuxBmsData::auxVoltage() const
{
    return auxVoltage_;
}

bool AuxBmsData::auxBmsAlive() const
{
    return auxBmsAlive_;
}

bool AuxBmsData::strobeBmsLight() const
{
    return strobeBmsLight_;
}

bool AuxBmsData::allowCharge() const
{
    return allowCharge_;
}

bool AuxBmsData::contactorError() const
{
    return contactorError_;
}

bool AuxBmsData::highVoltageEnable() const
{
    return highVoltageEnable_;
}

void AuxBmsData::setPrechargeState(PrechargeState prechargeState)
{
    prechargeState_ = prechargeState;
}

void AuxBmsData::setPrechargeStateJSON(QString prechargeStateJSON)
{
    prechargeStateJSON_ = prechargeStateJSON;
}

void AuxBmsData::setAuxVoltage(const unsigned char& auxVoltage)
{
    auxVoltage_ = auxVoltage;
}

void AuxBmsData::setAuxBmsAlive(const bool& auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
}

void AuxBmsData::setStrobeBmsLight(const bool& strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
}

void AuxBmsData::setAllowCharge(const bool& allowCharge)
{
    allowCharge_ = allowCharge;
}

void AuxBmsData::setContactorError(const bool& contactorError)
{
    contactorError_ = contactorError;
}

void AuxBmsData::setHighVoltageEnable(const bool& highVoltageEnable)
{
    highVoltageEnable_ = highVoltageEnable;
}
