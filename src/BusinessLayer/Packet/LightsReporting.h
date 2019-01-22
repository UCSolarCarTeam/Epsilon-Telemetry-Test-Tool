#pragma once

#include <QObject>

class LightsData;
class LightsTab;

class LightsReporting : public QObject
{
    Q_OBJECT

public:
    LightsReporting(LightsTab& lightsTab);
    void setData(LightsData& lightsData);

private:
    LightsTab& lightsTab_;
};
