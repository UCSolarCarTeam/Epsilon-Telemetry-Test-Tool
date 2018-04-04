#pragma once

#include <QObject>

class BatteryFaultsData;
class BatteryFaultsTab;

class BatteryFaultsReporting : public QObject
{
    Q_OBJECT

public:
    BatteryFaultsReporting(BatteryFaultsData& batteryFaultsData,
                           BatteryFaultsTab& batteryFaultsTab);
    void setData();

private:
    BatteryFaultsData& batteryFaultsData_;
    BatteryFaultsTab& batteryFaultsTab_;
};
