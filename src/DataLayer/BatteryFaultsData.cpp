#include "BatteryFaultsData.h"

BatteryFaultsData::BatteryFaultsData()
    : internalCommFault_(true)
    , internalConversionFault_(false)
    , weakCellFault_(true)
    , lowCellVoltageFault_(false)
    , openWiringFault_(true)
    , currentSensorFault_(false)
    , packVoltageSensorFault_(true)
    , weakPackFault_(false)
    , voltageRedundancyFault_(true)
    , fanMonitorFault_(false)
    , thermistorFault_(true)
    , canbusCommsFault_(false)
    , alwaysOnSupplyFault_(true)
    , highVoltageIsolationFault_(false)
    , powerSupplyFault_(false)
    , chargeLimitFault_(true)
    , dischargeLimitFault_(false)
    , chargerSafetyRelayFault_(true)
    , internalMemFault_(false)
    , internalThermistorFault_(false)
    , internalLogicFault_(true)
    , dclReducedLowSoc_(true)
    , dclReducedHighCellResist_(false)
    , dclReducedDueToTemp_(false)
    , dclReducedLowCellVoltage_(true)
    , dclReducedLowPackVoltage_(false)
    , dclCclReducedVoltageFailsafe_(true)
    , dclCclReducedCommsFailsafe_(false)
    , cclReducedHighSoc_(true)
    , cclReducedHighCellResist_(false)
    , cclReducedDueToTemp_(true)
    , cclReducedHighCellVoltage_(false)
    , cclReducedHighPackVoltage_(true)
    , cclReducedChargerLatch_(false)
    , cclReducedACLimit_(true)
{
}

BatteryFaultsData::~BatteryFaultsData()
{
}

bool BatteryFaultsData::internalCommFault() const
{
    return internalCommFault_;
}

bool BatteryFaultsData::internalConversionFault() const
{
    return internalConversionFault_;
}

bool BatteryFaultsData::weakCellFault() const
{
    return weakCellFault_;
}

bool BatteryFaultsData::lowCellVoltageFault() const
{
    return lowCellVoltageFault_;
}

bool BatteryFaultsData::openWiringFault() const
{
    return openWiringFault_;
}

bool BatteryFaultsData::currentSensorFault() const
{
    return currentSensorFault_;
}

bool BatteryFaultsData::packVoltageSensorFault() const
{
    return packVoltageSensorFault_;
}

bool BatteryFaultsData::weakPackFault() const
{
    return weakPackFault_;
}

bool BatteryFaultsData::voltageRedundancyFault() const
{
    return voltageRedundancyFault_;
}

bool BatteryFaultsData::fanMonitorFault() const
{
    return fanMonitorFault_;
}

bool BatteryFaultsData::thermistorFault() const
{
    return thermistorFault_;
}

bool BatteryFaultsData::canbusCommsFault() const
{
    return canbusCommsFault_;
}

bool BatteryFaultsData::alwaysOnSupplyFault() const
{
    return alwaysOnSupplyFault_;
}

bool BatteryFaultsData::highVoltageIsolationFault() const
{
    return highVoltageIsolationFault_;
}

bool BatteryFaultsData::powerSupplyFault() const
{
    return powerSupplyFault_;
}

bool BatteryFaultsData::chargeLimitFault() const
{
    return chargeLimitFault_;
}

bool BatteryFaultsData::dischargeLimitFault() const
{
    return dischargeLimitFault_;
}

bool BatteryFaultsData::chargerSafetyRelayFault() const
{
    return chargerSafetyRelayFault_;
}

bool BatteryFaultsData::internalMemFault() const
{
    return internalMemFault_;
}

bool BatteryFaultsData::internalThermistorFault() const
{
    return internalThermistorFault_;
}

bool BatteryFaultsData::internalLogicFault() const
{
    return internalLogicFault_;
}

bool BatteryFaultsData::dclReducedLowSoc() const
{
    return dclReducedLowSoc_;
}

bool BatteryFaultsData::dclReducedHighCellResist() const
{
    return dclReducedHighCellResist_;
}

bool BatteryFaultsData::dclReducedDueToTemp() const
{
    return dclReducedDueToTemp_;
}

bool BatteryFaultsData::dclReducedLowCellVoltage() const
{
    return dclReducedLowCellVoltage_;
}

bool BatteryFaultsData::dclReducedLowPackVoltage() const
{
    return dclReducedLowPackVoltage_;
}

bool BatteryFaultsData::dclCclReducedVoltageFailsafe() const
{
    return dclCclReducedVoltageFailsafe_;
}

bool BatteryFaultsData::dclCclReducedCommsFailsafe() const
{
    return dclCclReducedCommsFailsafe_;
}

bool BatteryFaultsData::cclReducedHighSoc() const
{
    return cclReducedHighSoc_;
}

bool BatteryFaultsData::cclReducedHighCellResist() const
{
    return cclReducedHighCellResist_;
}

bool BatteryFaultsData::cclReducedDueToTemp() const
{
    return cclReducedDueToTemp_;
}

bool BatteryFaultsData::cclReducedHighCellVoltage() const
{
    return cclReducedHighCellVoltage_;
}

bool BatteryFaultsData::cclReducedHighPackVoltage() const
{
    return cclReducedHighPackVoltage_;
}

bool BatteryFaultsData::cclReducedChargerLatch() const
{
    return cclReducedChargerLatch_;
}

bool BatteryFaultsData::cclReducedACLimit() const
{
    return cclReducedACLimit_;
}

void BatteryFaultsData::setInternalCommFault(const bool& internalCommFault)
{
    internalCommFault_ = internalCommFault;
}

void BatteryFaultsData::setInternalConversionFault(const bool& internalConversionFault)
{
    internalConversionFault_ = internalConversionFault;
}

void BatteryFaultsData::setWeakCellFault(const bool& weakCellFault)
{
    weakCellFault_ = weakCellFault;
}

void BatteryFaultsData::setLowCellVoltageFault(const bool& lowCellVoltageFault)
{
    lowCellVoltageFault_ = lowCellVoltageFault;
}

void BatteryFaultsData::setOpenWiringFault(const bool& openWiringFault)
{
    openWiringFault_ = openWiringFault;
}

void BatteryFaultsData::setCurrentSensorFault(const bool& currentSensorFault)
{
    currentSensorFault_ = currentSensorFault;
}

void BatteryFaultsData::setPackVoltageSensorFault(const bool& packVoltageSensorFault)
{
    packVoltageSensorFault_ = packVoltageSensorFault;
}

void BatteryFaultsData::setWeakPackFault(const bool& weakPackFault)
{
    weakPackFault_ = weakPackFault;
}

void BatteryFaultsData::setVoltageRedundancyFault(const bool& voltageRedundancyFault)
{
    voltageRedundancyFault_ = voltageRedundancyFault;
}

void BatteryFaultsData::setFanMonitorFault(const bool& fanMonitorFault)
{
    fanMonitorFault_ = fanMonitorFault;
}

void BatteryFaultsData::setThermistorFault(const bool& thermistorFault)
{
    thermistorFault_ = thermistorFault;
}

void BatteryFaultsData::setCanbusCommsFault(const bool& canbusCommsFault)
{
    canbusCommsFault_ = canbusCommsFault;
}

void BatteryFaultsData::setAlwaysOnSupplyFault(const bool& alwaysOnSupplyFault)
{
    alwaysOnSupplyFault_ = alwaysOnSupplyFault;
}

void BatteryFaultsData::setHighVoltageIsolationFault(const bool& highVoltageIsolationFault)
{
    highVoltageIsolationFault_ = highVoltageIsolationFault;
}

void BatteryFaultsData::setPowerSupplyFault(const bool& powerSupplyFault)
{
    powerSupplyFault_ = powerSupplyFault;
}

void BatteryFaultsData::setChargeLimitFault(const bool& chargeLimitFault)
{
    chargeLimitFault_ = chargeLimitFault;
}

void BatteryFaultsData::setDischargeLimitFault(const bool& dischargeLimitFault)
{
    dischargeLimitFault_ = dischargeLimitFault;
}

void BatteryFaultsData::setChargerSafetyRelayFault(const bool& chargerSafetyRelayFault)
{
    chargerSafetyRelayFault_ = chargerSafetyRelayFault;
}

void BatteryFaultsData::setInternalMemFault(const bool& internalMemFault)
{
    internalMemFault_ = internalMemFault;
}

void BatteryFaultsData::setInternalThermistorFault(const bool& internalThermistorFault)
{
    internalThermistorFault_ = internalThermistorFault;
}

void BatteryFaultsData::setInternalLogicFault(const bool& internalLogicFault)
{
    internalLogicFault_ = internalLogicFault;
}

void BatteryFaultsData::setDclReducedLowSoc(const bool& dclReducedLowSoc)
{
    dclReducedLowSoc_ = dclReducedLowSoc;
}

void BatteryFaultsData::setDclReducedHighCellResist(const bool& dclReducedHighCellResist)
{
    dclReducedHighCellResist_ = dclReducedHighCellResist;
}

void BatteryFaultsData::setDclReducedDueToTemp(const bool& dclReducedDueToTemp)
{
    dclReducedDueToTemp_ = dclReducedDueToTemp;
}

void BatteryFaultsData::setDclReducedLowCellVoltage(const bool& dclReducedLowCellVoltage)
{
    dclReducedLowCellVoltage_ = dclReducedLowCellVoltage;
}

void BatteryFaultsData::setDclReducedLowPackVoltage(const bool& dclReducedLowPackVoltage)
{
    dclReducedLowPackVoltage_ = dclReducedLowPackVoltage;
}

void BatteryFaultsData::setDclCclReducedVoltageFailsafe(const bool& dclCclReducedVoltageFailsafe)
{
    dclCclReducedVoltageFailsafe_ = dclCclReducedVoltageFailsafe;
}

void BatteryFaultsData::setDclCclReducedCommsFailsafe(const bool& dclCclReducedCommsFailsafe)
{
    dclCclReducedCommsFailsafe_ = dclCclReducedCommsFailsafe;
}

void BatteryFaultsData::setCclReducedHighSoc(const bool& cclReducedHighSoc)
{
    cclReducedHighSoc_ = cclReducedHighSoc;
}

void BatteryFaultsData::setCclReducedHighCellResist(const bool& cclReducedHighCellResist)
{
    cclReducedHighCellResist_ = cclReducedHighCellResist;
}

void BatteryFaultsData::setCclReducedDueToTemp(const bool& cclReducedDuetoTemp)
{
    cclReducedDueToTemp_ = cclReducedDuetoTemp;
}

void BatteryFaultsData::setCclReducedHighCellVoltage(const bool& cclReducedHighCellVoltage)
{
    cclReducedHighCellVoltage_ = cclReducedHighCellVoltage;
}

void BatteryFaultsData::setCclReducedHighPackVoltage(const bool& cclReducedHighPackVoltage)
{
    cclReducedHighPackVoltage_ = cclReducedHighPackVoltage;
}

void BatteryFaultsData::setCclReducedChargerLatch(const bool& cclReducedChargerLatch)
{
    cclReducedChargerLatch_ = cclReducedChargerLatch;
}

void BatteryFaultsData::setCclReducedACLimit(const bool& cclReducedACLimit)
{
    cclReducedACLimit_ = cclReducedACLimit;
}
