#pragma once

#include <QObject>

class BatteryData;
class BatteryTab;

class BatteryReporting : public QObject
{
    Q_OBJECT

public:
    BatteryReporting(BatteryTab& batteryTab);
    void setData(BatteryData& batteryData);

private:
    BatteryTab& batteryTab_;
};
