#include "BatteryTab.h"
#include "ui_BatteryTab.h"

BatteryTab::BatteryTab()
    : ui_(new Ui::BatteryTab)
{
    ui_->setupUi(this);
}

BatteryTab::~BatteryTab()
{
    delete ui_;
}

QCheckBox& BatteryTab::alive()
{
    return *ui_->alive;
}

QCheckBox& BatteryTab::alwaysOn()
{
    return *ui_->alwaysOn;
}

QCheckBox& BatteryTab::chargeRelay()
{
    return *ui_->chargeRelay;
}

QCheckBox& BatteryTab::chargerSafety()
{
    return *ui_->chargerSafety;
}

QCheckBox& BatteryTab::dischargeRelay()
{
    return *ui_->dischargeRelay;
}

QCheckBox& BatteryTab::isCharging()
{
    return *ui_->isCharging;
}

QCheckBox& BatteryTab::isReady()
{
    return *ui_->isReady;
}

QCheckBox& BatteryTab::malfunctionIndicator()
{
    return *ui_->malfunctionIndicator;
}

QCheckBox& BatteryTab::multipurposeInput()
{
    return *ui_->multipurposeInput;
}

QSpinBox& BatteryTab::averageCellVoltage()
{
    return *ui_->averageCellVoltage;
}

QSpinBox& BatteryTab::averageTemp()
{
    return *ui_->averageTemp;
}

QSpinBox& BatteryTab::fanSpeed()
{
    return *ui_->fanSpeed;
}

QDoubleSpinBox& BatteryTab::fanVoltage()
{
    return *ui_->fanVoltage;
}

QSpinBox& BatteryTab::highCellVoltage()
{
    return *ui_->highCellVoltage;
}

QSpinBox& BatteryTab::highCellVoltageId()
{
    return *ui_->highCellVoltageId;
}

QSpinBox& BatteryTab::highTemp()
{
    return *ui_->highTemp;
}

QSpinBox& BatteryTab::highThermistorId()
{
    return *ui_->highThermistorId;
}

QDoubleSpinBox& BatteryTab::inputVoltage12V()
{
    return *ui_->inputVoltage12V;
}

QSpinBox& BatteryTab::internalTemp()
{
    return *ui_->internalTemp;
}

QSpinBox& BatteryTab::lowCellVoltage()
{
    return *ui_->lowCellVoltage;
}

QSpinBox& BatteryTab::lowCellVoltageId()
{
    return *ui_->lowCellVoltageId;
}

QSpinBox& BatteryTab::lowTemp()
{
    return *ui_->lowTemp;
}

QSpinBox& BatteryTab::lowThermistorId()
{
    return *ui_->lowThermistorId;
}

QDoubleSpinBox& BatteryTab::packAmphours()
{
    return *ui_->packAmphours;
}

QDoubleSpinBox& BatteryTab::packCurrent()
{
    return *ui_->packCurrent;
}

QDoubleSpinBox& BatteryTab::packDepthOfDischarge()
{
    return *ui_->packDepthOfDischarge;
}

QDoubleSpinBox& BatteryTab::packStateOfCharge()
{
    return *ui_->packStateOfCharge;
}

QDoubleSpinBox& BatteryTab::packVoltage()
{
    return *ui_->packVoltage;
}

QSpinBox& BatteryTab::populatedCells()
{
    return *ui_->populatedCells;
}

QSpinBox& BatteryTab::requestedFanSpeed()
{
    return *ui_->requestedFanSpeed;
}
