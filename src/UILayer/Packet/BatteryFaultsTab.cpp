#include "BatteryFaultsTab.h"
#include "ui_BatteryFaultsTab.h"

BatteryFaultsTab::BatteryFaultsTab()
    : ui_(new Ui::BatteryFaultsTab)
{
    ui_->setupUi(this);
}

BatteryFaultsTab::~BatteryFaultsTab()
{
    delete ui_;
}

QCheckBox& BatteryFaultsTab::alwaysOnSupplyFault()
{
    return *ui_->alwaysOnSupplyFault;
}

QCheckBox& BatteryFaultsTab::canbusCommsFault()
{
    return *ui_->canbusCommsFault;
}

QCheckBox& BatteryFaultsTab::chargeLimitEnforementFault()
{
    return *ui_->chargeLimitEnforcementFault;
}

QCheckBox& BatteryFaultsTab::chargerSafetyRelayFault()
{
    return *ui_->chargerSafetyRelayFault;
}
QCheckBox& BatteryFaultsTab::currentSensorFault()
{
    return *ui_->currentSensorFault;
}

QCheckBox& BatteryFaultsTab::dischargeLimitEnforcementFault()
{
    return *ui_->dischargeLimitEnforcementFault;
}

QCheckBox& BatteryFaultsTab::fanMonitorFault()
{
    return *ui_->fanMonitorFault;
}
QCheckBox& BatteryFaultsTab::highVoltageIsolationFault()
{
    return *ui_->highVoltageIsolationFault;
}

QCheckBox& BatteryFaultsTab::internalCommFault()
{
    return *ui_->internalCommFault;
}

QCheckBox& BatteryFaultsTab::internalConversionFault()
{
    return *ui_->internalConversionFault;
}

QCheckBox& BatteryFaultsTab::internalLogicFault()
{
    return *ui_->internalLogicFault;
}

QCheckBox& BatteryFaultsTab::internalMemoryFault()
{
    return *ui_->internalMemoryFault;
}

QCheckBox& BatteryFaultsTab::internalThermistorFault()
{
    return *ui_->internalThermistorFault;
}

QCheckBox& BatteryFaultsTab::lowCellVoltageFault()
{
    return *ui_->lowCellVoltageFault;
}

QCheckBox& BatteryFaultsTab::openWiringFault()
{
    return *ui_->openWiringFault;
}

QCheckBox& BatteryFaultsTab::packVoltageSensor()
{
    return *ui_->packVoltageSensor;
}

QCheckBox& BatteryFaultsTab::powerSupplyFault()
{
    return *ui_->powerSupplyFault;
}

QCheckBox& BatteryFaultsTab::thermistorFault()
{
    return *ui_->thermistorFault;
}

QCheckBox& BatteryFaultsTab::voltageRedundancyFault()
{
    return *ui_->voltageRedundancyFault;
}

QCheckBox& BatteryFaultsTab::weakCellFault()
{
    return *ui_->weakCellFault;
}

QCheckBox& BatteryFaultsTab::weakPackFault()
{
    return *ui_->weakPackFault;
}

QCheckBox& BatteryFaultsTab::cclReducedACLimit()
{
    return *ui_->cclReducedACLimit;
}

QCheckBox& BatteryFaultsTab::cclReducedChargerLatch()
{
    return *ui_->cclReducedChargerLatch;
}

QCheckBox& BatteryFaultsTab::cclReducedHighCellResistance()
{
    return *ui_->cclReducedHighCellResistance;
}

QCheckBox& BatteryFaultsTab::cclReducedHighCellVoltage()
{
    return *ui_->cclReducedHighCellVoltage;
}

QCheckBox& BatteryFaultsTab::cclReducedHighPackVoltage()
{
    return *ui_->cclReducedHighPackVoltage;
}

QCheckBox& BatteryFaultsTab::cclReducedHighSoc()
{
    return *ui_->cclReducedHighSoc;
}

QCheckBox& BatteryFaultsTab::cclReducedTemp()
{
    return *ui_->cclReducedTemp;
}

QCheckBox& BatteryFaultsTab::dclCclReducedCommsFailSafe()
{
    return *ui_->dclCclReducedCommsFailsafe;
}

QCheckBox& BatteryFaultsTab::dclCclReducedVoltageFailsafe()
{
    return *ui_->dclCclReducedVoltageFailsafe;
}

QCheckBox& BatteryFaultsTab::dclReducedHighCellResistance()
{
    return *ui_->dclReducedHighCellResistance;
}

QCheckBox& BatteryFaultsTab::dclReducedLowCellVoltage()
{
    return *ui_->dclReducedHighCellResistance;
}

QCheckBox& BatteryFaultsTab::dclReducedLowPackVoltage()
{
    return *ui_->dclReducedLowPackVoltage;
}

QCheckBox& BatteryFaultsTab::dclReducedLowSoc()
{
    return *ui_->dclReducedLowSoc;
}

QCheckBox& BatteryFaultsTab::dclReducedTemp()
{
    return *ui_->dclReducedTemp;
}
