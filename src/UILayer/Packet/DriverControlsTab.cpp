#include "DriverControlsTab.h"
#include "ui_DriverControlsTab.h"

DriverControlsTab::DriverControlsTab()
    : ui_(new Ui::DriverControlsTab)
{
    ui_->setupUi(this);
}

DriverControlsTab::~DriverControlsTab()
{
    delete ui_;
}

QSpinBox& DriverControlsTab::acceleration()
{
    return *ui_->acceleration;
}

QSpinBox& DriverControlsTab::regenBraking()
{
    return *ui_->regenBraking;
}

QCheckBox& DriverControlsTab::driverControlsAlive()
{
    return *ui_->driverControlsAlive;
}

QCheckBox& DriverControlsTab::aux()
{
    return *ui_->aux;
}

QCheckBox& DriverControlsTab::brakes()
{
    return *ui_->brakes;
}

QCheckBox& DriverControlsTab::forward()
{
    return *ui_->forward;
}

QCheckBox& DriverControlsTab::horn()
{
    return *ui_->horn;
}

QCheckBox& DriverControlsTab::lapButton()
{
    return *ui_->lapButton;
}

QCheckBox& DriverControlsTab::pushToTalk()
{
    return *ui_->pushToTalk;
}

QCheckBox& DriverControlsTab::reset()
{
    return *ui_->reset;
}

QCheckBox& DriverControlsTab::reverse()
{
    return *ui_->reverse;
}

QCheckBox& DriverControlsTab::hazard()
{
    return *ui_->hazard;
}

QCheckBox& DriverControlsTab::headlightsHigh()
{
    return *ui_->headlightsHigh;
}

QCheckBox& DriverControlsTab::headlightsLow()
{
    return *ui_->headlightsLow;
}

QCheckBox& DriverControlsTab::headlightsOff()
{
    return *ui_->headlightsOff;
}

QCheckBox& DriverControlsTab::interior()
{
    return *ui_->interior;
}

QCheckBox& DriverControlsTab::signalLeft()
{
    return *ui_->signalLeft;
}

QCheckBox& DriverControlsTab::signalRight()
{
    return *ui_->signalRight;
}

QCheckBox& DriverControlsTab::nextSong()
{
    return *ui_->nextSong;
}

QCheckBox& DriverControlsTab::previousSong()
{
    return *ui_->previousSong;
}

QCheckBox& DriverControlsTab::volumeDown()
{
    return *ui_->volumeDown;
}

QCheckBox& DriverControlsTab::volumeUp()
{
    return *ui_->volumeUp;
}
