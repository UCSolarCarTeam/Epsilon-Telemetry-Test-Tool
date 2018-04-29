#include "AuxBmsReporting.h"
#include "AuxBmsData.h"
#include "../UILayer/Packet/AuxBmsTab.h"

AuxBmsReporting::AuxBmsReporting(AuxBmsData& auxBmsData,
                                 AuxBmsTab& auxBmsTab)
    : auxBmsData_(auxBmsData)
    , auxBmsTab_(auxBmsTab)
{
}

void AuxBmsReporting::setData()
{
    auxBmsData_.setAuxBmsAlive(auxBmsTab_.auxBMSAlive().isChecked());
    auxBmsData_.setStrobeBmsLight(auxBmsTab_.strobeBmsLight().isChecked());
    auxBmsData_.setAllowCharge(auxBmsTab_.allowCharge().isChecked());
    auxBmsData_.setContactorError(auxBmsTab_.contactorError().isChecked());
    auxBmsData_.setAuxVoltage(auxBmsTab_.auxVoltage().value());
    auxBmsData_.setPrechargeStateJSON(auxBmsTab_.prechargeState().currentText());
    if (auxBmsTab_.prechargeState().currentText() == "OFF")
    {
        auxBmsData_.setPrechargeState(PrechargeState::OFF);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "COMMON_ENGAGED")
    {
        auxBmsData_.setPrechargeState(PrechargeState::COMMON_ENGAGED);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "CHARGE_ENGAGED")
    {
        auxBmsData_.setPrechargeState(PrechargeState::CHARGE_ENGAGED);
    }
    else if (auxBmsTab_.prechargeState().currentText() == "DISCHARGE_ENGAGED")
    {
        auxBmsData_.setPrechargeState(PrechargeState::DISCHARGE_ENGAGED);
    }
    else
    {
        auxBmsData_.setPrechargeState(PrechargeState::ALL_ENGAGED);
    }
}
