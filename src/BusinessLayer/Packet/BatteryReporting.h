#pragma once

#include <QObject>

class BatteryData;
class BatteryTab;

class BatteryReporting : public QObject
{
    Q_OBJECT

public:
    BatteryReporting(BatteryData& batteryData,
                     BatteryTab& batteryTab);
    void setBatteryData();

private:
    BatteryData& batteryData_;
    BatteryTab& batteryTab_;
};
