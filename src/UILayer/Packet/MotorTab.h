#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

namespace Ui
{
    class MotorTab;
}

class MotorTab : public QWidget
{
    Q_OBJECT
public:
    explicit MotorTab();
    ~MotorTab();

    QCheckBox& alive();
    QDoubleSpinBox& busCurrent();
    QDoubleSpinBox& busVoltage();
    QDoubleSpinBox& setCurrent();
    QDoubleSpinBox& setVelocity();
    QDoubleSpinBox& vehicleVelocity();

    QDoubleSpinBox& backEMF();
    QDoubleSpinBox& dcBusAmphours();
    QDoubleSpinBox& dspBoardTemp();
    QDoubleSpinBox& heatSinkTemp();
    QDoubleSpinBox& motorCurrentImaginary();
    QDoubleSpinBox& motorCurrentReal();
    QDoubleSpinBox& motorTemp();
    QDoubleSpinBox& motorVoltageImaginary();
    QDoubleSpinBox& motorVoltageReal();
    QDoubleSpinBox& odometer();
    QDoubleSpinBox& phaseBCurrent();
    QDoubleSpinBox& phaseCCurrent();
    QDoubleSpinBox& slipSpeed();
    QDoubleSpinBox& voltageRailSupply15V();
    QDoubleSpinBox& voltageRailSupply1V();
    QDoubleSpinBox& voltageRailSupply3V();

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
    Ui::MotorTab* ui_;
};
