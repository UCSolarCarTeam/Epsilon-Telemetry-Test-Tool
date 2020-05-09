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
    bool highVoltageEnableState() const;
    bool allowDischarge() const;
    bool orionCanReceivedRecently() const;
    bool chargeContactorError() const;
    bool dischargeContactorError() const;
    bool commonContactorError() const;
    bool dischargeShouldTrip() const;
    bool chargeShouldTrip() const;
    bool chargeOpenButShouldBeClosed() const;
    bool dischargeOpenButShouldBeClosed() const;
    bool chargeTripDueToHighCellVoltage() const;
    bool chargeTripDueToHighTemperatureAndCurrent() const;
    bool dischargeTripDueToHighTemperatureAndCurrent() const;
    bool chargeTripDueToPackCurrent() const;
    bool dischargeTripDueToLowCellVoltage() const;
    bool dischargeTripDueToPackCurrent() const;
    bool protectionTrip() const;

    void setPrechargeState(PrechargeState prechargeState);
    void setPrechargeStateJSON(QString prechargeStateJSON);
    void setAuxVoltage(const unsigned char& auxVoltage);
    void setAuxBmsAlive(const bool& auxBmsAlive);
    void setStrobeBmsLight(const bool& strobeBmsLight);
    void setAllowCharge(const bool& allowCharge);
    void setHighVoltageEnableState(const bool highVoltageEnableState);
    void setAllowDischarge(const bool allowDischarge);
    void setOrionCanReceivedRecently(const bool orionCanReceivedRecently) ;
    void setChargeContactorError(const bool chargeContactorError);
    void setDischargeContactorError(const bool dischargeContactorError);
    void setCommonContactorError(const bool commonContactorError);
    void setDischargeShouldTrip(const bool dischargeShouldTrip);
    void setChargeShouldTrip(const bool chargeShouldTrip);
    void setChargeOpenButShouldBeClosed(const bool chargeOpenButShouldBeClosed);
    void setDischargeOpenButShouldBeClosed(const bool dischargeOpenButShouldBeClosed);
    void setChargeTripDueToHighCellVoltage(const bool chargeTripDueToHighCellVoltage);
    void setChargeTripDueToHighTemperatureAndCurrent(const bool chargeTripDueToHighTemperatureAndCurrent);
    void setDischargeTripDueToHighTemperatureAndCurrent(const bool dischargeTripDueToHighTemperatureAndCurrent);
    void setChargeTripDueToPackCurrent(const bool chargeTripDueToPackCurrent);
    void setDischargeTripDueToLowCellVoltage(const bool dischargeTripDueToLowCellVoltage);
    void setDischargeTripDueToPackCurrent(const bool dischargeTripDueToPackCurrent);
    void setProtectionTrip(const bool protectionTrip);

private:
    PrechargeState prechargeState_;
    QString prechargeStateJSON_;
    unsigned char auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool highVoltageEnableState_;
    bool allowDischarge_;
    bool orionCanReceivedRecently_;
    bool chargeContactorError_;
    bool dischargeContactorError_;
    bool commonContactorError_;
    bool dischargeShouldTrip_;
    bool chargeShouldTrip_;
    bool chargeOpenButShouldBeClosed_;
    bool dischargeOpenButShouldBeClosed_;
    bool chargeTripDueToHighCellVoltage_;
    bool chargeTripDueToHighTemperatureAndCurrent_;
    bool dischargeTripDueToHighTemperatureAndCurrent_;
    bool chargeTripDueToPackCurrent_;
    bool dischargeTripDueToLowCellVoltage_;
    bool dischargeTripDueToPackCurrent_;
    bool protectionTrip_;
};
