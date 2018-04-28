#pragma once

#include <QObject>

class LightsData;
class LightsTab;

class LightsReporting : public QObject
{
    Q_OBJECT

public:
    LightsReporting(LightsData& lightsData,
                    LightsTab& lightsTab);
    void setUiData();

private:
    LightsData& lightsData_;
    LightsTab& lightsTab_;
};
