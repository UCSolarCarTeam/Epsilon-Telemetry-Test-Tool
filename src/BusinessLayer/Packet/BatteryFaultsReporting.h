#pragma once

#include <QObject>

class BatteryFaultsData;
class BatteryFaultsTab;

class BatteryFaultsReporting : public QObject
{
    Q_OBJECT

public:
    BatteryFaultsReporting(BatteryFaultsData& batteryFaultsPacket0,
                           BatteryFaultsData& batteryFaultsPacket1,
                           BatteryFaultsTab& batteryFaultsTab);
    void setData(int packetNum);

private:
    BatteryFaultsData& batteryFaultsPacket0_;
    BatteryFaultsData& batteryFaultsPacket1_;
    BatteryFaultsTab& batteryFaultsTab_;
};
