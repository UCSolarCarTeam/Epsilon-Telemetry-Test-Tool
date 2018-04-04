#pragma once

#include <QCheckBox>


namespace Ui
{
    class BatteryFaultsTab;
}

class BatteryFaultsTab : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryFaultsTab();
    ~BatteryFaultsTab();

    QCheckBox& alwaysOnSupplyFault();
    QCheckBox& canbusCommsFault();
    QCheckBox& chargeLimitEnforementFault();
    QCheckBox& chargerSafetyRelayFault();
    QCheckBox& currentSensorFault();
    QCheckBox& dischargeLimitEnforcementFault();
    QCheckBox& fanMonitorFault();
    QCheckBox& highVoltageIsolationFault();
    QCheckBox& internalCommFault();
    QCheckBox& internalConversionFault();
    QCheckBox& internalLogicFault();
    QCheckBox& internalMemoryFault();
    QCheckBox& internalThermistorFault();
    QCheckBox& lowCellVoltageFault();
    QCheckBox& openWiringFault();
    QCheckBox& packVoltageSensor();
    QCheckBox& powerSupplyFault();
    QCheckBox& thermistorFault();
    QCheckBox& voltageRedundancyFault();
    QCheckBox& weakCellFault();
    QCheckBox& weakPackFault();

    QCheckBox& cclReducedACLimit();
    QCheckBox& cclReducedChargerLatch();
    QCheckBox& cclReducedHighCellResistance();
    QCheckBox& cclReducedHighCellVoltage();
    QCheckBox& cclReducedHighPackVoltage();
    QCheckBox& cclReducedHighSoc();
    QCheckBox& cclReducedTemp();
    QCheckBox& dclCclReducedCommsFailSafe();
    QCheckBox& dclCclReducedVoltageFailsafe();
    QCheckBox& dclReducedHighCellResistance();
    QCheckBox& dclReducedLowCellVoltage();
    QCheckBox& dclReducedLowPackVoltage();
    QCheckBox& dclReducedLowSoc();
    QCheckBox& dclReducedTemp();

private:
    Ui::BatteryFaultsTab* ui_;
};
