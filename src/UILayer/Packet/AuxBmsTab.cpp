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

QCheckBox& AuxBmsTab::highVoltageEnableState()
{
    return *ui_->highVoltageEnableState;
}

QCheckBox& AuxBmsTab::allowDischarge()
{
    return *ui_->allowDischarge;
}

QCheckBox& AuxBmsTab::orionCanReceivedRecently()
{
    return *ui_->orionCanReceivedRecently;
}

QCheckBox& AuxBmsTab::chargeContactorError()
{
    return *ui_->chargeContactorError;
}

QCheckBox& AuxBmsTab::dischargeContactorError()
{
    return *ui_->dischargeContactorError;
}

QCheckBox& AuxBmsTab::commonContactorError()
{
    return *ui_->commonContactorError;
}

QCheckBox& AuxBmsTab::dischargeShouldTrip()
{
    return *ui_->dischargeShouldTrip;
}

QCheckBox& AuxBmsTab::chargeShouldTrip()
{
    return *ui_->chargeShouldTrip;
}

QCheckBox& AuxBmsTab::protectionTrip()
{
    return *ui_->protectionTrip;
}

QCheckBox& AuxBmsTab::dischargeTripDueToPackCurrent()
{
    return *ui_->dischargeTripDueToPackCurrent;
}

QCheckBox& AuxBmsTab::dischargeTripDueToLowCellVoltage()
{
    return *ui_->dischargeTripDueToLowCellVoltage;
}

QCheckBox& AuxBmsTab::chargeTripDueToPackCurrent()
{
    return *ui_->chargeTripDueToPackCurrent;
}

QCheckBox& AuxBmsTab::dischargeTripDueToHighTemperatureAndCurrent()
{
    return *ui_->dischargeTripDueToHighTemperatureAndCurrent;
}

QCheckBox& AuxBmsTab::chargeTripDueToHighTemperatureAndCurrent()
{
    return *ui_->chargeTripDueToHighTemperatureAndCurrent;
}

QCheckBox& AuxBmsTab::chargeTripDueToHighCellVoltage()
{
    return *ui_->chargeTripDueToHighCellVoltage;
}

QCheckBox& AuxBmsTab::dischargeOpenButShouldBeClosed()
{
    return *ui_->dischargeOpenButShouldBeClosed;
}

QCheckBox& AuxBmsTab::chargeOpenButShouldBeClosed()
{
    return *ui_->chargeOpenButShouldBeClosed;
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

QComboBox& AuxBmsTab::prechargeState()
{
    return *ui_->prechargeState;
}

QSpinBox& AuxBmsTab::auxVoltage()
{
    return *ui_->auxVoltage;
}
