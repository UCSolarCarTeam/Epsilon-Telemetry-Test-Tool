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
    void setData();

private:
    LightsData& lightsData_;
    LightsTab& lightsTab_;
};
