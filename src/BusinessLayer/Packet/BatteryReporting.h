#pragma once

#include <QObject>
//test
class BatteryData;
class BatteryTab;

class BatteryReporting : public QObject
{
    Q_OBJECT

public:
    BatteryReporting(BatteryData& batteryData,
                     BatteryTab& batteryTab);
    void setData();

private:
    BatteryData& batteryData_;
    BatteryTab& batteryTab_;
};
