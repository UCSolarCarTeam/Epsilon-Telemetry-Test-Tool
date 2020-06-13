#include "AuxBmsReporting.h"
#include "AuxBmsData.h"
#include "../UILayer/Packet/AuxBmsTab.h"

AuxBmsReporting::AuxBmsReporting(AuxBmsTab& auxBmsTab)
    : auxBmsTab_(auxBmsTab)
{
}

void AuxBmsReporting::setData(AuxBmsData& auxBmsData)
{
    AuxBmsData* auxBmsData_ = &auxBmsData;
    auxBmsData_->setAuxBmsAlive(auxBmsTab_.auxBMSAlive().isChecked());
    auxBmsData_->setStrobeBmsLight(auxBmsTab_.strobeBmsLight().isChecked());
    auxBmsData_->setAllowCharge(auxBmsTab_.allowCharge().isChecked());
    auxBmsData_->setAuxVoltage(auxBmsTab_.auxVoltage().value());
    auxBmsData_->setPrechargeStateJSON(auxBmsTab_.prechargeState().currentText());
    auxBmsData_->setHighVoltageEnableState(auxBmsTab_.highVoltageEnableState().isChecked());
    auxBmsData_->setAllowDischarge(auxBmsTab_.allowDischarge().isChecked());
    auxBmsData_->setOrionCanReceivedRecently(auxBmsTab_.orionCanReceivedRecently().isChecked());
    auxBmsData_->setChargeContactorError(auxBmsTab_.chargeContactorError().isChecked());
    auxBmsData_->setDischargeContactorError(auxBmsTab_.dischargeContactorError().isChecked());
    auxBmsData_->setCommonContactorError(auxBmsTab_.commonContactorError().isChecked());
    auxBmsData_->setDischargeShouldTrip(auxBmsTab_.dischargeShouldTrip().isChecked());
    auxBmsData_->setChargeShouldTrip(auxBmsTab_.chargeShouldTrip().isChecked());
    auxBmsData_->setChargeOpenButShouldBeClosed(auxBmsTab_.chargeOpenButShouldBeClosed().isChecked());
    auxBmsData_->setDischargeOpenButShouldBeClosed(auxBmsTab_.dischargeOpenButShouldBeClosed().isChecked());
    auxBmsData_->setChargeTripDueToHighCellVoltage(auxBmsTab_.chargeTripDueToHighCellVoltage().isChecked());
    auxBmsData_->setChargeTripDueToHighTemperatureAndCurrent(auxBmsTab_.chargeTripDueToHighTemperatureAndCurrent().isChecked());
    auxBmsData_->setDischargeTripDueToHighTemperatureAndCurrent(auxBmsTab_.dischargeTripDueToHighTemperatureAndCurrent().isChecked());
    auxBmsData_->setChargeTripDueToPackCurrent(auxBmsTab_.chargeTripDueToPackCurrent().isChecked());
    auxBmsData_->setDischargeTripDueToLowCellVoltage(auxBmsTab_.dischargeTripDueToLowCellVoltage().isChecked());
    auxBmsData_->setDischargeTripDueToPackCurrent(auxBmsTab_.dischargeTripDueToPackCurrent().isChecked());
    auxBmsData_->setProtectionTrip(auxBmsTab_.protectionTrip().isChecked());

    if (auxBmsTab_.prechargeState().currentText() == "OFF")
    {
        auxBmsData_->setPrechargeState(PrechargeState::OFF);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "COMMON_ENGAGED")
    {
        auxBmsData_->setPrechargeState(PrechargeState::COMMON_ENGAGED);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "CHARGE_ENGAGED")
    {
        auxBmsData_->setPrechargeState(PrechargeState::CHARGE_ENGAGED);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "DISCHARGE_ENGAGED")
    {
        auxBmsData_->setPrechargeState(PrechargeState::DISCHARGE_ENGAGED);
    }
    else
    {
        auxBmsData_->setPrechargeState(PrechargeState::ALL_ENGAGED);
    }
}
