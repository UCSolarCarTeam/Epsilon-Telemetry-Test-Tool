#include "AuxBmsTab.h"
#include "ui_AuxBmsTab.h"

AuxBmsTab::AuxBmsTab()
    : ui_(new Ui::AuxBmsTab)
{
    ui_->setupUi(this);
}

AuxBmsTab::~AuxBmsTab()
{
    delete ui_;
}

QCheckBox& AuxBmsTab::allowCharge()
{
    return *ui_->allowCharge;
}

QCheckBox& AuxBmsTab::auxBMSAlive()
{
    return *ui_->auxBmsAlive;
}

QCheckBox& AuxBmsTab::strobeBmsLight()
{
    return *ui_->strobeBmsLight;
}

QCheckBox& AuxBmsTab::contactorError()
{
    return *ui_->contactorError;
}

QCheckBox& AuxBmsTab::highVoltageEnable()
{
    return *ui_->highVoltageEnable;
}

QComboBox& AuxBmsTab::prechargeState()
{
    return *ui_->prechargeState;
}

QSpinBox& AuxBmsTab::auxVoltage()
{
    return *ui_->auxVoltage;
}
