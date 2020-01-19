#include "MpptTab.h"
#include "ui_MpptTab.h"

MpptTab::MpptTab()
    : ui_(new Ui::MpptTab)
{
    ui_->setupUi(this);
}

MpptTab::~MpptTab()
{
    delete ui_;
}


QCheckBox& MpptTab::mpptAlive()
{
    return *ui_->mpptAlive;
}

QDoubleSpinBox& MpptTab::arrayCurrent()
{
    return *ui_->arrayCurrent;
}

QDoubleSpinBox& MpptTab::arrayVoltage()
{
    return *ui_->arrayVoltage;
}

QDoubleSpinBox& MpptTab::batteryVoltage()
{
    return *ui_->batteryVoltage;
}

QSpinBox& MpptTab::temperature()
{
    return *ui_->temperature;
}
