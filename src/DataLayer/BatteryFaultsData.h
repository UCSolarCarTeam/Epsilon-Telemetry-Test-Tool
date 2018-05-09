#pragma once

#include <QObject>

class BatteryFaultsData : public QObject
{
    Q_OBJECT

public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    bool internalCommFault() const;
    bool internalConversionFault() const;
    bool weakCellFault() const;
    bool lowCellVoltageFault() const;
    bool openWiringFault() const;
    bool currentSensorFault() const;
    bool packVoltageSensorFault() const;
    bool weakPackFault() const;
    bool voltageRedundancyFault() const;
    bool fanMonitorFault() const;
    bool thermistorFault() const;
    bool canbusCommsFault() const;
    bool alwaysOnSupplyFault() const;
    bool highVoltageIsolationFault() const;
    bool powerSupplyFault() const;
    bool chargeLimitFault() const;
    bool dischargeLimitFault() const;
    bool chargerSafetyRelayFault() const;
    bool internalMemFault() const;
    bool internalThermistorFault() const;
    bool internalLogicFault() const;
    bool dclReducedLowSoc() const;
    bool dclReducedHighCellResist() const;
    bool dclReducedDueToTemp() const;
    bool dclReducedLowCellVoltage() const;
    bool dclReducedLowPackVoltage() const;
    bool dclCclReducedVoltageFailsafe() const;
    bool dclCclReducedCommsFailsafe() const;
    bool cclReducedHighSoc() const;
    bool cclReducedHighCellResist() const;
    bool cclReducedDueToTemp() const;
    bool cclReducedHighCellVoltage() const;
    bool cclReducedHighPackVoltage() const;
    bool cclReducedChargerLatch() const;
    bool cclReducedACLimit() const;

    void setInternalCommFault(const bool& internalCommFault);
    void setInternalConversionFault(const bool& internalConversionFault);
    void setWeakCellFault(const bool& weakCellFault);
    void setLowCellVoltageFault(const bool& lowCellVoltageFault);
    void setOpenWiringFault(const bool& openWiringFault);
    void setCurrentSensorFault(const bool& currentSensorFault);
    void setPackVoltageSensorFault(const bool& packVoltageSensorFault);
    void setWeakPackFault(const bool& weakPackFault);
    void setVoltageRedundancyFault(const bool& voltageRedundancyFault);
    void setFanMonitorFault(const bool& fanMonitorFault);
    void setThermistorFault(const bool& thermistorFault);
    void setCanbusCommsFault(const bool& canbusCommsFault);
    void setAlwaysOnSupplyFault(const bool& alwaysOnSupplyFault);
    void setHighVoltageIsolationFault(const bool& highVoltageIsolationFault);
    void setPowerSupplyFault(const bool& powerSupplyFault);
    void setChargeLimitFault(const bool& chargeLimitFault);
    void setDischargeLimitFault(const bool& dischargeLimitFault);
    void setChargerSafetyRelayFault(const bool& chargerSafetyRelayFault);
    void setInternalMemFault(const bool& internalMemFault);
    void setInternalThermistorFault(const bool& internalThermistorFault);
    void setInternalLogicFault(const bool& internalLogicFault);
    void setDclReducedLowSoc(const bool& dclReducedLowSoc);
    void setDclReducedHighCellResist(const bool& dclReducedHighCellResist);
    void setDclReducedDueToTemp(const bool& dclReducedDueToTemp);
    void setDclReducedLowCellVoltage(const bool& dclReducedLowCellVoltage);
    void setDclReducedLowPackVoltage(const bool& dclReducedLowPackVoltage);
    void setDclCclReducedVoltageFailsafe(const bool& dclCclReducedVoltageFailsafe);
    void setDclCclReducedCommsFailsafe(const bool& dclCclReducedCommsFailsafe);
    void setCclReducedHighSoc(const bool& cclReducedHighSoc);
    void setCclReducedHighCellResist(const bool& cclReducedHighCellResist);
    void setCclReducedDueToTemp(const bool& cclReducedDuetoTemp);
    void setCclReducedHighCellVoltage(const bool& cclReducedHighCellVoltage);
    void setCclReducedHighPackVoltage(const bool& cclReducedHighPackVoltage);
    void setCclReducedChargerLatch(const bool& cclReducedChargerLatch);
    void setCclReducedACLimit(const bool& cclReducedACLimit);

private:
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
};
