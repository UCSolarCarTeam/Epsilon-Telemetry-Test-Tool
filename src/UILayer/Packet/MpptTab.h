#pragma once

#include <QCheckBox>
#include <QSpinBox>

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

    QCheckBox& alive();
    QSpinBox& arrayCurrent();
    QSpinBox& arrayVoltage();
    QSpinBox& batteryVoltage();
    QSpinBox& mpptNumber();
    QSpinBox& temperature();

private:
    Ui::MpptTab* ui_;
};
