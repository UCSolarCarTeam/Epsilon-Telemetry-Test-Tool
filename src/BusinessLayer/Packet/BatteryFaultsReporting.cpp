#include "BatteryFaultsReporting.h"
#include "BatteryFaultsData.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"

BatteryFaultsReporting::BatteryFaultsReporting(BatteryFaultsData& batteryFaultsData,
                                               BatteryFaultsTab& batteryFaultsTab)
    : batteryFaultsData_(batteryFaultsData)
    , batteryFaultsTab_(batteryFaultsTab)
{
}

void BatteryFaultsReporting::setBatteryFaultsData()
{
    batteryFaultsData_.setInternalCommFault(batteryFaultsTab_.internalCommFault().isChecked());
    batteryFaultsData_.setInternalConversionFault(batteryFaultsTab_.internalConversionFault().isChecked());
    batteryFaultsTab_.inter
}

bool internalCommFault_;
bool internalConversionFault_;
bool weakCellFault_;
bool lowCellVoltageFault_;
bool openWiringFault_;
bool currentSensorFault_;
bool packVoltageSensorFault_;
bool weakPackFault_;
bool voltageRedundancyFault_;
bool fanMonitorFault_;
bool thermistorFault_;
bool canbusCommsFault_;
bool alwaysOnSupplyFault_;
bool highVoltageIsolationFault_;
bool powerSupplyFault_;
bool chargeLimitFault_;
bool dischargeLimitFault_;
bool chargerSafetyRelayFault_;
bool internalMemFault_;
bool internalThermistorFault_;
bool internalLogicFault_;
bool dclReducedLowSoc_;
bool dclReducedHighCellResist_;
bool dclReducedDueToTemp_;
bool dclReducedLowCellVoltage_;
bool dclReducedLowPackVoltage_;
bool dclCclReducedVoltageFailsafe_;
bool dclCclReducedCommsFailsafe_;
bool cclReducedHighSoc_;
bool cclReducedHighCellResist_;
bool cclReducedDueToTemp_;
bool cclReducedHighCellVoltage_;
bool cclReducedHighPackVoltage_;
bool cclReducedChargerLatch_;
bool cclReducedACLimit_;
