#include "MotorFaultsTab.h"
#include "ui_MotorFaultsTab.h"

MotorFaultsTab::MotorFaultsTab()
    : ui_(new Ui::MotorFaultsTab)
{
    ui_->setupUi(this);
}

MotorFaultsTab::~MotorFaultsTab()
{
    delete ui_;
}

QSpinBox& MotorFaultsTab::canRxErrorCount()
{
    return *ui_->canRxErrorCount;
}

QSpinBox& MotorFaultsTab::canTxErrorCount()
{
    return *ui_->canTxErrorCount;
}

QCheckBox& MotorFaultsTab::badMotorPositionHallSequence()
{
    return *ui_->badMotorPositionHallSequence;
}

QCheckBox& MotorFaultsTab::configReadError()
{
    return *ui_->configReadError;
}

QCheckBox& MotorFaultsTab::dcBusOverVoltage()
{
    return *ui_->dcBusOverVoltage;
}

QCheckBox& MotorFaultsTab::overCurrent()
{
    return *ui_->overCurrent;
}

QCheckBox& MotorFaultsTab::desaturationFault()
{
    return *ui_->desaturationFault;
}

QCheckBox& MotorFaultsTab::overSpeed()
{
    return *ui_->overSpeed;
}

QCheckBox& MotorFaultsTab::railUnderVoltageLockOut()
{
    return *ui_->railUnderVoltageLockOut;
}

QCheckBox& MotorFaultsTab::watchDogCausedLastReset()
{
    return *ui_->watchdogCausedLastReset;
}

QCheckBox& MotorFaultsTab::busCurrentLimit()
{
    return *ui_->busCurrentLimit;
}

QCheckBox& MotorFaultsTab::busVoltageLowerLimit()
{
    return *ui_->busVoltageLowerLimit;
}

QCheckBox& MotorFaultsTab::busVoltageUpperLimit()
{
    return *ui_->busVoltageUpperLimit;
}

QCheckBox& MotorFaultsTab::ipmOrMotorTempLimit()
{
    return *ui_->ipmOrMotorTempLimit;
}

QCheckBox& MotorFaultsTab::motorCurrentLimit()
{
    return *ui_->motorCurrentLimit;
}

QCheckBox& MotorFaultsTab::outputVoltagePwmLimit()
{
    return *ui_->outputVoltagePwmLimit;
}

QCheckBox& MotorFaultsTab::velocityLimit()
{
    return *ui_->velocityLimit;
}
