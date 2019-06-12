#pragma once

#include <QSpinBox>
#include <QCheckBox>

namespace Ui
{
    class DriverControlsTab;
}

class DriverControlsTab : public QWidget
{
    Q_OBJECT
public:
    explicit DriverControlsTab();
    ~DriverControlsTab();

    QSpinBox& acceleration();
    QSpinBox& regenBraking();
    QCheckBox& driverControlsAlive();
    QCheckBox& aux();
    QCheckBox& brakes();
    QCheckBox& forward();
    QCheckBox& horn();
    QCheckBox& lap();
    QCheckBox& pushToTalk();
    QCheckBox& reset();
    QCheckBox& reverse();
    QCheckBox& hazard();
    QCheckBox& headlightsHigh();
    QCheckBox& headlightsLow();
    QCheckBox& headlightsOff();
    QCheckBox& interior();
    QCheckBox& signalLeft();
    QCheckBox& signalRight();
    QCheckBox& nextSong();
    QCheckBox& previousSong();
    QCheckBox& volumeDown();
    QCheckBox& volumeUp();

private:
    Ui::DriverControlsTab* ui_;
};
