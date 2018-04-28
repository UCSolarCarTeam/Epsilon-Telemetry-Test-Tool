#include "BatteryReporting.h"
#include "BatteryData.h"
#include "../UILayer/Packet/BatteryTab.h"

BatteryReporting::BatteryReporting(BatteryData& batteryData,
                                   BatteryTab& batteryTab)
    : batteryData_(batteryData)
    , batteryTab_(batteryTab)
{
}

void BatteryReporting::setUiData()
{
    batteryData_.setAlive(batteryTab_.bmuAlive().isChecked());
    batteryData_.setDischargeRelayEnabled(batteryTab_.dischargeRelay().isChecked());
    batteryData_.setChargeRelayEnabled(batteryTab_.chargeRelay().isChecked());
    batteryData_.setChargerSafetyEnabled(batteryTab_.chargerSafety().isChecked());
    batteryData_.setMalfunctionIndicatorActive(batteryTab_.malfunctionIndicator().isChecked());
    batteryData_.setMultiPurposeInputSignalStatus(batteryTab_.multipurposeInput().isChecked());
    batteryData_.setAlwaysOnSignalStatus(batteryTab_.alwaysOn().isChecked());
    batteryData_.setIsReadySignalStatus(batteryTab_.isReady().isChecked());
    batteryData_.setIsChargingSignalStatus(batteryTab_.isCharging().isChecked());
    batteryData_.setPopulatedCells(batteryTab_.populatedCells().value());
    batteryData_.setInputVoltage12V(batteryTab_.inputVoltage12V().value());
    batteryData_.setFanVoltage(batteryTab_.fanVoltage().value());
    batteryData_.setPackCurrent(batteryTab_.packCurrent().value());
    batteryData_.setPackVoltage(batteryTab_.packVoltage().value());
    batteryData_.setPackStateOfCharge(batteryTab_.packStateOfCharge().value());
    batteryData_.setPackDepthOfDischarge(batteryTab_.packDepthOfDischarge().value());
    batteryData_.setHighTemperature(batteryTab_.highTemp().value());
    batteryData_.setHighThermistorId(batteryTab_.highThermistorId().value());
    batteryData_.setLowTemperature(batteryTab_.lowTemp().value());
    batteryData_.setLowThermistorId(batteryTab_.lowThermistorId().value());
    batteryData_.setAverageTemperature(batteryTab_.averageTemp().value());
    batteryData_.setInternalTemperature(batteryTab_.internalTemp().value());
    batteryData_.setFanSpeed(batteryTab_.fanSpeed().value());
    batteryData_.setRequestedFanSpeed(batteryTab_.requestedFanSpeed().value());
    batteryData_.setLowCellVoltage(batteryTab_.lowCellVoltage().value());
    batteryData_.setLowCellVoltageId(batteryTab_.lowCellVoltageId().value());
    batteryData_.setHighCellVoltage(batteryTab_.highCellVoltage().value());
    batteryData_.setHighCellVoltageId(batteryTab_.highCellVoltageId().value());
    batteryData_.setAverageCellVoltage(batteryTab_.averageCellVoltage().value());
    batteryData_.setAuxBmsAlive(batteryTab_.auxBMSAlive().isChecked());
    batteryData_.setStrobeBmsLight(batteryTab_.strobeBmsLight().isChecked());
    batteryData_.setAllowCharge(batteryTab_.allowCharge().isChecked());
    batteryData_.setContactorError(batteryTab_.contactorError().isChecked());
    // precharge state and precharge state JSON
}
