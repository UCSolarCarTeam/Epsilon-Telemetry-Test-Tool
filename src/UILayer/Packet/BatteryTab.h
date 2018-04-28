#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

namespace Ui
{
    class BatteryTab;
}

class BatteryTab : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryTab();
    ~BatteryTab();

    QCheckBox& alive();
    QCheckBox& alwaysOn();
    QCheckBox& chargeRelay();
    QCheckBox& chargerSafety();
    QCheckBox& dischargeRelay();
    QCheckBox& isCharging();
    QCheckBox& isReady();
    QCheckBox& malfunctionIndicator();
    QCheckBox& multipurposeInput();
    QSpinBox& auxVoltage();
    QSpinBox& averageCellVoltage();
    QSpinBox& averageTemp();
    QSpinBox& fanSpeed();
    QDoubleSpinBox& fanVoltage();
    QSpinBox& highCellVoltage();
    QSpinBox& highCellVoltageId();
    QSpinBox& highTemp();
    QSpinBox& highThermistorId();
    QDoubleSpinBox& inputVoltage12V();
    QSpinBox& internalTemp();
    QSpinBox& lowCellVoltage();
    QSpinBox& lowCellVoltageId();
    QSpinBox& lowTemp();
    QSpinBox& lowThermistorId();
    QDoubleSpinBox& packAmphours();
    QDoubleSpinBox& packCurrent();
    QDoubleSpinBox& packDepthOfDischarge();
    QDoubleSpinBox& packStateOfCharge();
    QDoubleSpinBox& packVoltage();
    QSpinBox& populatedCells();
    QSpinBox& requestedFanSpeed();

private:
    Ui::BatteryTab* ui_;
};
