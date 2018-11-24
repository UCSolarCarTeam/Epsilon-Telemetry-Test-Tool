#include "BatteryFaultsReporting.h"
#include "BatteryFaultsData.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"

BatteryFaultsReporting::BatteryFaultsReporting(BatteryFaultsTab& batteryFaultsTab)
    : batteryFaultsTab_(batteryFaultsTab)
{
}

void BatteryFaultsReporting::setData(BatteryFaultsData& batteryFaultsData)
{
    BatteryFaultsData* batteryFaultsData_ = &batteryFaultsData;
    batteryFaultsData_->setInternalCommFault(batteryFaultsTab_.internalCommFault().isChecked());
    batteryFaultsData_->setInternalConversionFault(batteryFaultsTab_.internalConversionFault().isChecked());
    batteryFaultsData_->setWeakCellFault(batteryFaultsTab_.weakCellFault().isChecked());
    batteryFaultsData_->setLowCellVoltageFault(batteryFaultsTab_.lowCellVoltageFault().isChecked());
    batteryFaultsData_->setOpenWiringFault(batteryFaultsTab_.openWiringFault().isChecked());
    batteryFaultsData_->setCurrentSensorFault(batteryFaultsTab_.currentSensorFault().isChecked());
    batteryFaultsData_->setPackVoltageSensorFault(batteryFaultsTab_.packVoltageSensor().isChecked());
    batteryFaultsData_->setWeakPackFault(batteryFaultsTab_.weakPackFault().isChecked());
    batteryFaultsData_->setVoltageRedundancyFault(batteryFaultsTab_.voltageRedundancyFault().isChecked());
    batteryFaultsData_->setFanMonitorFault(batteryFaultsTab_.fanMonitorFault().isChecked());
    batteryFaultsData_->setThermistorFault(batteryFaultsTab_.thermistorFault().isChecked());
    batteryFaultsData_->setCanbusCommsFault(batteryFaultsTab_.canbusCommsFault().isChecked());
    batteryFaultsData_->setAlwaysOnSupplyFault(batteryFaultsTab_.alwaysOnSupplyFault().isChecked());
    batteryFaultsData_->setHighVoltageIsolationFault(batteryFaultsTab_.highVoltageIsolationFault().isChecked());
    batteryFaultsData_->setPowerSupplyFault(batteryFaultsTab_.powerSupplyFault().isChecked());
    batteryFaultsData_->setChargeLimitFault(batteryFaultsTab_.chargeLimitEnforementFault().isChecked());
    batteryFaultsData_->setDischargeLimitFault(batteryFaultsTab_.dischargeLimitEnforcementFault().isChecked());
    batteryFaultsData_->setChargerSafetyRelayFault(batteryFaultsTab_.chargerSafetyRelayFault().isChecked());
    batteryFaultsData_->setInternalMemFault(batteryFaultsTab_.internalMemoryFault().isChecked());
    batteryFaultsData_->setInternalThermistorFault(batteryFaultsTab_.internalThermistorFault().isChecked());
    batteryFaultsData_->setInternalLogicFault(batteryFaultsTab_.internalLogicFault().isChecked());
    batteryFaultsData_->setDclReducedLowSoc(batteryFaultsTab_.dclReducedLowSoc().isChecked());
    batteryFaultsData_->setDclReducedHighCellResist(batteryFaultsTab_.dclReducedHighCellResistance().isChecked());
    batteryFaultsData_->setDclReducedDueToTemp(batteryFaultsTab_.dclReducedTemp().isChecked());
    batteryFaultsData_->setDclReducedLowCellVoltage(batteryFaultsTab_.dclReducedLowCellVoltage().isChecked());
    batteryFaultsData_->setDclReducedLowPackVoltage(batteryFaultsTab_.dclReducedLowPackVoltage().isChecked());
    batteryFaultsData_->setDclCclReducedVoltageFailsafe(batteryFaultsTab_.dclCclReducedVoltageFailsafe().isChecked());
    batteryFaultsData_->setDclCclReducedCommsFailsafe(batteryFaultsTab_.dclCclReducedCommsFailSafe().isChecked());
    batteryFaultsData_->setCclReducedHighSoc(batteryFaultsTab_.cclReducedHighSoc().isChecked());
    batteryFaultsData_->setCclReducedHighCellResist(batteryFaultsTab_.cclReducedHighCellResistance().isChecked());
    batteryFaultsData_->setCclReducedDueToTemp(batteryFaultsTab_.cclReducedTemp().isChecked());
    batteryFaultsData_->setCclReducedHighCellVoltage(batteryFaultsTab_.cclReducedHighCellVoltage().isChecked());
    batteryFaultsData_->setCclReducedHighPackVoltage(batteryFaultsTab_.cclReducedHighPackVoltage().isChecked());
    batteryFaultsData_->setCclReducedChargerLatch(batteryFaultsTab_.cclReducedChargerLatch().isChecked());
    batteryFaultsData_->setCclReducedACLimit(batteryFaultsTab_.cclReducedACLimit().isChecked());

}
