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

    QCheckBox& allowCharge();
    QCheckBox& auxBMSAlive();
    QCheckBox& strobeBmsLight();
    QCheckBox& contactorError();
    QComboBox& prechargeState();
    QSpinBox& auxVoltage();

private:
    Ui::AuxBmsTab* ui_;
};
