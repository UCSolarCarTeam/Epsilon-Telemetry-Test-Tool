#pragma once

#include <QObject>

class BatteryFaultsData;
class BatteryFaultsTab;

class BatteryFaultsReporting : public QObject
{
    Q_OBJECT

public:
    BatteryFaultsReporting(BatteryFaultsTab& batteryFaultsTab);
    void setData(BatteryFaultsData& batteryFaultsData);

private:
    BatteryFaultsTab& batteryFaultsTab_;
};
