#include "AuxBmsData.h"

AuxBmsData::AuxBmsData()
    : prechargeState_(PrechargeState::OFF)
    , prechargeStateJSON_("OFF")
    , auxVoltage_(13)
    , auxBmsAlive_(true)
    , strobeBmsLight_(true)
    , allowCharge_(true)
    , highVoltageEnableState_(true)
    , allowDischarge_(true)
    , orionCanReceivedRecently_(true)
    , chargeContactorError_(true)
    , dischargeContactorError_(true)
    , commonContactorError_(true)
    , dischargeShouldTrip_(true)
    , chargeShouldTrip_(true)
    , chargeOpenButShouldBeClosed_(true)
    , dischargeOpenButShouldBeClosed_(true)
    , chargeTripDueToHighCellVoltage_(true)
    , chargeTripDueToHighTemperatureAndCurrent_(true)
    , dischargeTripDueToHighTemperatureAndCurrent_(true)
    , chargeTripDueToPackCurrent_(true)
    , dischargeTripDueToLowCellVoltage_(true)
    , dischargeTripDueToPackCurrent_(true)
    , protectionTrip_(true)
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

bool AuxBmsData::highVoltageEnableState() const
{
    return highVoltageEnableState_;
}

bool AuxBmsData::allowDischarge() const
{
    return allowDischarge_;
}
bool AuxBmsData::orionCanReceivedRecently() const
{
    return orionCanReceivedRecently_;
}
bool AuxBmsData::chargeContactorError() const
{
    return chargeContactorError_;
}
bool AuxBmsData::dischargeContactorError() const
{
    return dischargeContactorError_;
}
bool AuxBmsData::commonContactorError() const
{
    return commonContactorError_;
}
bool AuxBmsData::dischargeShouldTrip() const
{
    return dischargeShouldTrip_;
}
bool AuxBmsData::chargeShouldTrip() const
{
    return chargeShouldTrip_;
}
bool AuxBmsData::chargeOpenButShouldBeClosed() const
{
    return chargeOpenButShouldBeClosed_;
}
bool AuxBmsData::dischargeOpenButShouldBeClosed() const
{
    return dischargeOpenButShouldBeClosed_;
}
bool AuxBmsData::chargeTripDueToHighCellVoltage() const
{
    return chargeTripDueToHighCellVoltage_;
}
bool AuxBmsData::chargeTripDueToHighTemperatureAndCurrent() const
{
    return chargeTripDueToHighTemperatureAndCurrent_;
}
bool AuxBmsData::dischargeTripDueToHighTemperatureAndCurrent() const
{
    return dischargeTripDueToHighTemperatureAndCurrent_;
}
bool AuxBmsData::chargeTripDueToPackCurrent() const
{
    return chargeTripDueToPackCurrent_;
}
bool AuxBmsData::dischargeTripDueToLowCellVoltage() const
{
    return dischargeTripDueToLowCellVoltage_;
}
bool AuxBmsData::dischargeTripDueToPackCurrent() const
{
    return dischargeTripDueToPackCurrent_;
}
bool AuxBmsData::protectionTrip() const
{
    return protectionTrip_;
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

void AuxBmsData::setHighVoltageEnableState(const bool highVoltageEnableState)
{
    highVoltageEnableState_ = highVoltageEnableState;
}
void AuxBmsData::setAllowDischarge(const bool allowDischarge)
{
    allowDischarge_ = allowDischarge;
}
void AuxBmsData::setOrionCanReceivedRecently(const bool orionCanReceivedRecently)
{
    orionCanReceivedRecently_ = orionCanReceivedRecently;
}
void AuxBmsData::setChargeContactorError(const bool chargeContactorError)
{
    chargeContactorError_ = chargeContactorError;
}
void AuxBmsData::setDischargeContactorError(const bool dischargeContactorError)
{
    dischargeContactorError_ = dischargeContactorError;
}
void AuxBmsData::setCommonContactorError(const bool commonContactorError)
{
    commonContactorError_ = commonContactorError;
}
void AuxBmsData::setDischargeShouldTrip(const bool dischargeShouldTrip)
{
    dischargeShouldTrip_ = dischargeShouldTrip;
}
void AuxBmsData::setChargeShouldTrip(const bool chargeShouldTrip)
{
    chargeShouldTrip_ = chargeShouldTrip;
}
void AuxBmsData::setChargeOpenButShouldBeClosed(const bool chargeOpenButShouldBeClosed)
{
    chargeOpenButShouldBeClosed_ = chargeOpenButShouldBeClosed;
}
void AuxBmsData::setDischargeOpenButShouldBeClosed(const bool dischargeOpenButShouldBeClosed)
{
    dischargeOpenButShouldBeClosed_ = dischargeOpenButShouldBeClosed;
}
void AuxBmsData::setChargeTripDueToHighCellVoltage(const bool chargeTripDueToHighCellVoltage)
{
    chargeTripDueToHighCellVoltage_ = chargeTripDueToHighCellVoltage;
}
void AuxBmsData::setChargeTripDueToHighTemperatureAndCurrent(const bool chargeTripDueToHighTemperatureAndCurrent)
{
    chargeTripDueToHighTemperatureAndCurrent_ = chargeTripDueToHighTemperatureAndCurrent;
}
void AuxBmsData::setDischargeTripDueToHighTemperatureAndCurrent(const bool dischargeTripDueToHighTemperatureAndCurrent)
{
    dischargeTripDueToHighTemperatureAndCurrent_ = dischargeTripDueToHighTemperatureAndCurrent;
}
void AuxBmsData::setChargeTripDueToPackCurrent(const bool chargeTripDueToPackCurrent)
{
    chargeTripDueToPackCurrent_ = chargeTripDueToPackCurrent;
}
void AuxBmsData::setDischargeTripDueToLowCellVoltage(const bool dischargeTripDueToLowCellVoltage)
{
    dischargeTripDueToLowCellVoltage_ = dischargeTripDueToLowCellVoltage;
}
void AuxBmsData::setDischargeTripDueToPackCurrent(const bool dischargeTripDueToPackCurrent)
{
    dischargeTripDueToPackCurrent_ = dischargeTripDueToPackCurrent;
}
void AuxBmsData::setProtectionTrip(const bool protectionTrip)
{
    protectionTrip_ = protectionTrip;
}
