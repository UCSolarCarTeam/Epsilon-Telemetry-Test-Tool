#include "AuxBmsReporting.h"
#include "AuxBmsData.h"
#include "../UILayer/Packet/AuxBmsTab.h"

AuxBmsReporting::AuxBmsReporting(AuxBmsData& auxBmsPacket0,
                                 AuxBmsData& auxBmsPacket1,
                                 AuxBmsTab& auxBmsTab)
    : auxBmsPacket0_(auxBmsPacket0)
    , auxBmsPacket1_(auxBmsPacket1)
    , auxBmsTab_(auxBmsTab)
{
}

void AuxBmsReporting::setData(int packetNum)
{
    AuxBmsData* auxBmsData_;
    if (packetNum == 0)
    {
        auxBmsData_ = &auxBmsPacket0_;
    }
    else
    {
        auxBmsData_ = &auxBmsPacket1_;
    }
    auxBmsData_->setAuxBmsAlive(auxBmsTab_.auxBMSAlive().isChecked());
    auxBmsData_->setStrobeBmsLight(auxBmsTab_.strobeBmsLight().isChecked());
    auxBmsData_->setAllowCharge(auxBmsTab_.allowCharge().isChecked());
    auxBmsData_->setContactorError(auxBmsTab_.contactorError().isChecked());
    auxBmsData_->setHighVoltageEnable(auxBmsTab_.highVoltageEnable().isChecked());
    auxBmsData_->setAuxVoltage(auxBmsTab_.auxVoltage().value());
    auxBmsData_->setPrechargeStateJSON(auxBmsTab_.prechargeState().currentText());
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
