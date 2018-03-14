#pragma once

struct BatteryData
{
    BatteryData()
        : alive(true)
        , dischargeRelayEnabled(true)
        , chargeRelayEnabled(false)
        , chargerSafetyEnabled(true)
        , malfunctionIndicatorActive(true)
        , multiPurposeInputSignalStatus(true)
        , alwaysOnSignalStatus(false)
        , isReadySignalStatus(true)
        , isChargingSignalStatus(true)
        , populatedCells(2)
        , inputVoltage12V(12.33f)
        , fanVoltage(12.33f)
        , packCurrent(33.33f)
        , packVoltage(12.33f)
        , packStateOfCharge(88)
        , packAmpHours(32.33f)
        , packDepthOfDischarge(77)
        , highTemperature(60)
        , highThermistorId(1)
        , lowTemperature(44)
        , lowThermistorId(2)
        , averageTemperature(52)
        , internalTemperature(55)
        , fanSpeed(43)
        , requestedFanSpeed(45)
        , lowCellVoltage(10)
        , lowCellVoltageId(0)
        , highCellVoltage(14)
        , highCellVoltageId(1)
        , averageCellVoltage(12)
        , prechargeState(PrechargeState::EnablePack)
        , prechargeStateJSON("Enable Pack")
        , auxVoltage(13)
        , auxBmsAlive(true)
        , strobeBmsLight(true)
        , allowCharge(true)
        , contactorError(true)
    {}

    enum PrechargeState
    {
        Idle = 0,
        Precharge = 1,
        Measure = 2,
        EnablePack = 3,
        Run = 4,
    };

    bool alive;
    bool dischargeRelayEnabled;
    bool chargeRelayEnabled;
    bool chargerSafetyEnabled;
    bool malfunctionIndicatorActive;
    bool multiPurposeInputSignalStatus;
    bool alwaysOnSignalStatus;
    bool isReadySignalStatus;
    bool isChargingSignalStatus;
    unsigned char populatedCells;
    float inputVoltage12V;
    float fanVoltage;
    float packCurrent;
    float packVoltage;
    float packStateOfCharge;
    float packAmpHours;
    float packDepthOfDischarge;
    unsigned char highTemperature;
    unsigned char highThermistorId;
    unsigned char lowTemperature;
    unsigned char lowThermistorId;
    unsigned char averageTemperature;
    unsigned char internalTemperature;
    unsigned char fanSpeed;
    unsigned char requestedFanSpeed;
    unsigned short lowCellVoltage;
    unsigned char lowCellVoltageId;
    unsigned short highCellVoltage;
    unsigned char highCellVoltageId;
    unsigned short averageCellVoltage;
    PrechargeState prechargeState;
    const char* prechargeStateJSON;
    unsigned char auxVoltage;
    bool auxBmsAlive;
    bool strobeBmsLight;
    bool allowCharge;
    bool contactorError;
};

//#pragma once

//#include <QObject>

//class BatteryData : public QObject
//{
//    Q_OBJECT

//public:
//    BatteryData();
//      ~BatteryData();

//    bool alive() const;
//    bool dischargeRelayEnabled() const;
//    bool chargeRelayEnabled() const;
//    bool chargerSafetyEnabled() const;
//    bool malfunctionIndicatorActive() const;
//    bool multiPurposeInputSignalStatus() const;
//    bool alwaysOnSignalStatus() const;
//    bool isReadySignalStatus() const;
//    bool isChargingSignalStatus() const;
//    unsigned char populatedCells() const;
//    float inputVoltage12V() const;
//    float fanVoltage() const;
//    float packCurrent() const;
//    float packVoltage() const;
//    float packStateOfCharge() const;
//    float packAmpHours() const;
//    float packDepthOfDischarge() const;
//    unsigned char highTemperature() const;
//    unsigned char highThermistorId() const;
//    unsigned char lowTemperature() const;
//    unsigned char lowThermistorId() const;
//    unsigned char averageTemperature() const;
//    unsigned char internalTemperature() const;
//    unsigned char fanSpeed() const;
//    unsigned char requestedFanSpeed() const;
//    unsigned short lowCellVoltage() const;
//    unsigned char lowCellVoltageId() const;
//    unsigned short highCellVoltage() const;
//    unsigned char highCellVoltageId() const;
//    unsigned short averageCellVoltage() const;
//    unsigned char prechargeState() const;
//    const char* prechargeStateJSON() const;
//    unsigned char auxVoltage() const;
//    bool auxBmsAlive() const;
//    bool strobeBmsLight() const;
//    bool allowCharge() const;
//    bool contactorError() const;

//    void setAlive(const bool& alive);
//    void setDischargeRelayEnabled(const bool& dischargeRelayEnabled);
//    void setChargeRelayEnabled(const bool& chargeRelayEnabled);
//    void setChargerSafetyEnabled(const bool& chargerSafetyEnabled);
//    void setMalfunctionIndicatorActive(const bool& malfunctionIndicatorActive);
//    void setMultiPurposeInputSignalStatus(const bool& multiPurposeInputSignalStatus);
//    void setAlwaysOnSignalStatus(const bool& alwaysOnSignalStatus);
//    void setIsReadySignalStatus(const bool& isReadySignalStatus);
//    void setIsChargingSignalStatus(const bool& isChargingSignalStatus);
//    void setPopulatedCells(const unsigned char& populatedCells);
//    void setInputVoltage12V(const float& inputVoltage12V);
//    void setFanVoltage(const float& fanVoltage);
//    void setPackCurrent(const float& packCurrent);
//    void setPackVoltage(const float& packVoltage);
//    void setPackStateOfCharge(const float& packStateOfCharge);
//    void setPackAmpHours(const float& packAmpHours);
//    void setPackDepthOfDischarge(const float& packDepthOfDischarge);
//    void setHighTemperature(const unsigned char& highTemperature);
//    void setHighThermistorId(const unsigned char& highThermistorId);
//    void setLowTemperature(const unsigned char& lowTemperature);
//    void setLowThermistorId(const unsigned char& lowThermistorId);
//    void setAverageTemperature(const unsigned char& averageTemperature);
//    void setInternalTemperature(const unsigned char& internalTemperature);
//    void setFanSpeed(const unsigned char& fanSpeed);
//    void setRequestedFanSpeed(const unsigned char& requestedFanSpeed);
//    void setLowCellVoltage(const unsigned short& lowCellVoltage);
//    void setLowCellVoltageId(const unsigned char& lowCellVoltageId);
//    void setHighCellVoltage(const unsigned short& highCellVoltage);
//    void setHighCellVoltageId(const unsigned char& highCellVoltageId);
//    void setAverageCellVoltage(const unsigned short& averageCellVoltage);
//    void setPrechargeState(const QString& prechargeState);
//    void setAuxVoltage(const unsigned char& auxVoltage);
//    void setAuxBmsAlive(const bool& auxBmsAlive);
//    void setStrobeBmsLight(const bool& strobeBmsLight);
//    void setAllowCharge(const bool& allowCharge);
//    void setContactorError(const bool& contactorError);

//private:
//      bool alive_;
//      bool dischargeRelayEnabled_;
//      bool chargeRelayEnabled_;
//      bool chargerSafetyEnabled_;
//      bool malfunctionIndicatorActive_;
//      bool multiPurposeInputSignalStatus_;
//      bool alwaysOnSignalStatus_;
//      bool isReadySignalStatus_;
//      bool isChargingSignalStatus_;
//      unsigned char populatedCells_;
//      float inputVoltage12V_;
//      float fanVoltage_;
//      float packCurrent_;
//      float packVoltage_;
//      float packStateOfCharge_;
//      float packAmpHours_;
//      float packDepthOfDischarge_;
//      unsigned char highTemperature_;
//      unsigned char highThermistorId_;
//      unsigned char lowTemperature_;
//      unsigned char lowThermistorId_;
//      unsigned char averageTemperature_;
//      unsigned char internalTemperature_;
//      unsigned char fanSpeed_;
//      unsigned char requestedFanSpeed_;
//      unsigned short lowCellVoltage_;
//      unsigned char lowCellVoltageId_;
//      unsigned short highCellVoltage_;
//      unsigned char highCellVoltageId_;
//      unsigned short averageCellVoltage_;
//      unsigned char prechargeState_;
//      const char* prechargeStateJSON_;
//      unsigned char auxVoltage_;
//      bool auxBmsAlive_;
//      bool strobeBmsLight_;
//      bool allowCharge_;
//      bool contactorError_;
//};
