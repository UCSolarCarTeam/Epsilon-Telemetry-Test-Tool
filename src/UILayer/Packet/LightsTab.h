#pragma once

#include <QCheckBox>
#include <QSpinBox>

namespace Ui
{
    class LightsTab;
}

class LightsTab : public QWidget
{
    Q_OBJECT
public:
    LightsTab();
    ~LightsTab();

    QCheckBox& bmsStrobeLight();
    QCheckBox& brakeLights();
    QCheckBox& highBeams();
    QCheckBox& leftSignal();
    QCheckBox& lightsAlive();
    QCheckBox& lowBeams();
    QCheckBox& rightSignal();

private:
    Ui::LightsTab* ui_;
};
