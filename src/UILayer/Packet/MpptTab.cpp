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


QCheckBox& MpptTab::alive()
{
    return *ui_->alive;
}

QSpinBox& MpptTab::arrayCurrent()
{
    return *ui_->arrayCurrent;
}

QSpinBox& MpptTab::arrayVoltage()
{
    return *ui_->arrayVoltage;
}

QSpinBox& MpptTab::batteryVoltage()
{
    return *ui_->batteryVoltage;
}

QSpinBox& MpptTab::mpptNumber()
{
    return *ui_->mpptNumber;
}

QSpinBox& MpptTab::temperature()
{
    return *ui_->temperature;
}
