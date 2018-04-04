#pragma once

#include <QObject>

enum PrechargeState
{
    Idle = 0,
    Precharge = 1,
    Measure = 2,
    EnablePack = 3,
    Run = 4
};

class BatteryData : public QObject
{
    Q_OBJECT

public:
     BatteryData();
     virtual ~BatteryData();

    bool alive() const;
    bool dischargeRelayEnabled() const;
    bool chargeRelayEnabled() const;
    bool chargerSafetyEnabled() const;
    bool malfunctionIndicatorActive() const;
    bool multiPurposeInputSignalStatus() const;
    bool alwaysOnSignalStatus() const;
    bool isReadySignalStatus() const;
    bool isChargingSignalStatus() const;
    unsigned char populatedCells() const;
    float inputVoltage12V() const;
    float fanVoltage() const;
    float packCurrent() const;
    float packVoltage() const;
    float packStateOfCharge() const;
    float packAmpHours() const;
    float packDepthOfDischarge() const;
    unsigned char highTemperature() const;
    unsigned char highThermistorId() const;
    unsigned char lowTemperature() const;
    unsigned char lowThermistorId() const;
    unsigned char averageTemperature() const;
    unsigned char internalTemperature() const;
    unsigned char fanSpeed() const;
    unsigned char requestedFanSpeed() const;
    unsigned short lowCellVoltage() const;
    unsigned char lowCellVoltageId() const;
    unsigned short highCellVoltage() const;
    unsigned char highCellVoltageId() const;
    unsigned short averageCellVoltage() const;
    PrechargeState prechargeState() const;
    const char* prechargeStateJSON() const;
    unsigned char auxVoltage() const;
    bool auxBmsAlive() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool contactorError() const;

    void setAlive(const bool& alive);
    void setDischargeRelayEnabled(const bool& dischargeRelayEnabled);
    void setChargeRelayEnabled(const bool& chargeRelayEnabled);
    void setChargerSafetyEnabled(const bool& chargerSafetyEnabled);
    void setMalfunctionIndicatorActive(const bool& malfunctionIndicatorActive);
    void setMultiPurposeInputSignalStatus(const bool& multiPurposeInputSignalStatus);
    void setAlwaysOnSignalStatus(const bool& alwaysOnSignalStatus);
    void setIsReadySignalStatus(const bool& isReadySignalStatus);
    void setIsChargingSignalStatus(const bool& isChargingSignalStatus);
    void setPopulatedCells(const unsigned char& populatedCells);
    void setInputVoltage12V(const float& inputVoltage12V);
    void setFanVoltage(const float& fanVoltage);
    void setPackCurrent(const float& packCurrent);
    void setPackVoltage(const float& packVoltage);
    void setPackStateOfCharge(const float& packStateOfCharge);
    void setPackAmpHours(const float& packAmpHours);
    void setPackDepthOfDischarge(const float& packDepthOfDischarge);
    void setHighTemperature(const unsigned char& highTemperature);
    void setHighThermistorId(const unsigned char& highThermistorId);
    void setLowTemperature(const unsigned char& lowTemperature);
    void setLowThermistorId(const unsigned char& lowThermistorId);
    void setAverageTemperature(const unsigned char& averageTemperature);
    void setInternalTemperature(const unsigned char& internalTemperature);
    void setFanSpeed(const unsigned char& fanSpeed);
    void setRequestedFanSpeed(const unsigned char& requestedFanSpeed);
    void setLowCellVoltage(const unsigned short& lowCellVoltage);
    void setLowCellVoltageId(const unsigned char& lowCellVoltageId);
    void setHighCellVoltage(const unsigned short& highCellVoltage);
    void setHighCellVoltageId(const unsigned char& highCellVoltageId);
    void setAverageCellVoltage(const unsigned short& averageCellVoltage);
    void setPrechargeState(PrechargeState prechargeState);
    void setPrechargeStateJSON(const char* prechargeStateJSON);
    void setAuxVoltage(const unsigned char& auxVoltage);
    void setAuxBmsAlive(const bool& auxBmsAlive);
    void setStrobeBmsLight(const bool& strobeBmsLight);
    void setAllowCharge(const bool& allowCharge);
    void setContactorError(const bool& contactorError);

private:
      bool alive_;
      bool dischargeRelayEnabled_;
      bool chargeRelayEnabled_;
      bool chargerSafetyEnabled_;
      bool malfunctionIndicatorActive_;
      bool multiPurposeInputSignalStatus_;
      bool alwaysOnSignalStatus_;
      bool isReadySignalStatus_;
      bool isChargingSignalStatus_;
      unsigned char populatedCells_;
      float inputVoltage12V_;
      float fanVoltage_;
      float packCurrent_;
      float packVoltage_;
      float packStateOfCharge_;
      float packAmpHours_;
      float packDepthOfDischarge_;
      unsigned char highTemperature_;
      unsigned char highThermistorId_;
      unsigned char lowTemperature_;
      unsigned char lowThermistorId_;
      unsigned char averageTemperature_;
      unsigned char internalTemperature_;
      unsigned char fanSpeed_;
      unsigned char requestedFanSpeed_;
      unsigned short lowCellVoltage_;
      unsigned char lowCellVoltageId_;
      unsigned short highCellVoltage_;
      unsigned char highCellVoltageId_;
      unsigned short averageCellVoltage_;
      PrechargeState prechargeState_;
      const char* prechargeStateJSON_;
      unsigned char auxVoltage_;
      bool auxBmsAlive_;
      bool strobeBmsLight_;
      bool allowCharge_;
      bool contactorError_;
};
