#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

namespace Ui
{
    class MpptTab;
}

class MpptTab : public QWidget
{
    Q_OBJECT
public:
    explicit MpptTab();
    ~MpptTab();

    QCheckBox& mpptAlive();
    QDoubleSpinBox& arrayCurrent();
    QDoubleSpinBox& arrayVoltage();
    QDoubleSpinBox& batteryVoltage();
    QSpinBox& mpptNumber();
    QSpinBox& temperature();

private:
    Ui::MpptTab* ui_;
};
