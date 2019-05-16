#pragma once

#include <QObject>

enum PrechargeState
{
    OFF = 0,
    COMMON_ENGAGED = 1,
    CHARGE_ENGAGED = 2,
    DISCHARGE_ENGAGED = 3,
    ALL_ENGAGED = 4
};

class AuxBmsData : public QObject
{
    Q_OBJECT

public:
    AuxBmsData();
    virtual ~AuxBmsData();

    PrechargeState prechargeState() const;
    QString prechargeStateJSON() const;
    unsigned char auxVoltage() const;
    bool auxBmsAlive() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool contactorError() const;
    bool highVoltageEnable() const;

    void setPrechargeState(PrechargeState prechargeState);
    void setPrechargeStateJSON(QString prechargeStateJSON);
    void setAuxVoltage(const unsigned char& auxVoltage);
    void setAuxBmsAlive(const bool& auxBmsAlive);
    void setStrobeBmsLight(const bool& strobeBmsLight);
    void setAllowCharge(const bool& allowCharge);
    void setContactorError(const bool& contactorError);
    void setHighVoltageEnable(const bool& highVoltageEnable);

private:
    PrechargeState prechargeState_;
    QString prechargeStateJSON_;
    unsigned char auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool contactorError_;
    bool highVoltageEnable_;
};
