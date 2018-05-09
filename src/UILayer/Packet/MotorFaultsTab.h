#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

namespace Ui
{
    class MotorFaultsTab;
}

class MotorFaultsTab : public QWidget
{
    Q_OBJECT
public:
    explicit MotorFaultsTab();
    ~MotorFaultsTab();

    QSpinBox& canRxErrorCount();
    QSpinBox& canTxErrorCount();
    QCheckBox& badMotorPositionHallSequence();
    QCheckBox& configReadError();
    QCheckBox& dcBusOverVoltage();
    QCheckBox& overCurrent();
    QCheckBox& desaturationFault();
    QCheckBox& overSpeed();
    QCheckBox& railUnderVoltageLockOut();
    QCheckBox& watchDogCausedLastReset();
    QCheckBox& busCurrentLimit();
    QCheckBox& busVoltageLowerLimit();
    QCheckBox& busVoltageUpperLimit();
    QCheckBox& ipmOrMotorTempLimit();
    QCheckBox& motorCurrentLimit();
    QCheckBox& outputVoltagePwmLimit();
    QCheckBox& velocityLimit();

private:
    Ui::MotorFaultsTab* ui_;
};

