#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>

namespace Ui
{
    class AuxBmsTab;
}

class AuxBmsTab : public QWidget
{
    Q_OBJECT
public:
    explicit AuxBmsTab();
    ~AuxBmsTab();

    QCheckBox& highVoltageEnableState();
    QCheckBox& allowDischarge();
    QCheckBox& orionCanReceivedRecently();
    QCheckBox& chargeContactorError();
    QCheckBox& dischargeContactorError();
    QCheckBox& commonContactorError();
    QCheckBox& dischargeShouldTrip();
    QCheckBox& chargeShouldTrip();
    QCheckBox& chargeOpenButShouldBeClosed();
    QCheckBox& dischargeOpenButShouldBeClosed();
    QCheckBox& chargeTripDueToHighCellVoltage();
    QCheckBox& chargeTripDueToHighTemperatureAndCurrent();
    QCheckBox& dischargeTripDueToHighTemperatureAndCurrent();
    QCheckBox& chargeTripDueToPackCurrent();
    QCheckBox& dischargeTripDueToLowCellVoltage();
    QCheckBox& dischargeTripDueToPackCurrent();
    QCheckBox& protectionTrip();
    QCheckBox& allowCharge();
    QCheckBox& auxBMSAlive();
    QCheckBox& strobeBmsLight();
    QComboBox& prechargeState();
    QSpinBox& auxVoltage();

private:
    Ui::AuxBmsTab* ui_;
};
