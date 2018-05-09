#include "MotorTab.h"
#include "ui_MotorTab.h"

MotorTab::MotorTab()
    : ui_(new Ui::MotorTab)
{
    ui_->setupUi(this);
}

MotorTab::~MotorTab()
{
    delete ui_;
}


QCheckBox& MotorTab::alive()
{
    return *ui_->alive;
}

QDoubleSpinBox& MotorTab::busCurrent()
{
    return *ui_->busCurrent;
}

QDoubleSpinBox& MotorTab::busVoltage()
{
    return *ui_->busVoltage;
}

QDoubleSpinBox& MotorTab::setCurrent()
{
    return *ui_->setCurrent;
}

QDoubleSpinBox& MotorTab::setVelocity()
{
    return *ui_->setVelocity;
}

QDoubleSpinBox& MotorTab::vehicleVelocity()
{
    return *ui_->vehicleVelocity;
}

QDoubleSpinBox& MotorTab::backEMF()
{
    return *ui_->backEMF;
}

QDoubleSpinBox& MotorTab::dcBusAmphours()
{
    return *ui_->dcBusAmphours;
}

QDoubleSpinBox& MotorTab::dspBoardTemp()
{
    return *ui_->dspBoardTemp;
}

QDoubleSpinBox& MotorTab::heatSinkTemp()
{
    return *ui_->heatSinkTemp;
}

QDoubleSpinBox& MotorTab::motorCurrentImaginary()
{
    return *ui_->motorCurrentImaginary;
}

QDoubleSpinBox& MotorTab::motorCurrentReal()
{
    return *ui_->motorCurrentReal;
}

QDoubleSpinBox& MotorTab::motorTemp()
{
    return *ui_->motorTemp;
}

QDoubleSpinBox& MotorTab::motorVoltageImaginary()
{
    return *ui_->motorVoltageImaginary;
}

QDoubleSpinBox& MotorTab::motorVoltageReal()
{
    return *ui_->motorVoltageReal;
}

QDoubleSpinBox& MotorTab::odometer()
{
    return *ui_->odometer;
}

QDoubleSpinBox& MotorTab::phaseBCurrent()
{
    return *ui_->phaseBCurrent;
}

QDoubleSpinBox& MotorTab::phaseCCurrent()
{
    return *ui_->phaseCCurrent;
}

QDoubleSpinBox& MotorTab::slipSpeed()
{
    return *ui_->slipSpeed;
}

QDoubleSpinBox& MotorTab::voltageRailSupply15V()
{
    return *ui_->voltageRailSupply15V;
}

QDoubleSpinBox& MotorTab::voltageRailSupply1V()
{
    return *ui_->voltageRailSupply1V;
}

QDoubleSpinBox& MotorTab::voltageRailSupply3V()
{
    return *ui_->voltageRailSupply3V;
}
