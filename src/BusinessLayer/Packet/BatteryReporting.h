#pragma once

#include <QObject>

class BatteryData;
class BatteryTab;

class BatteryReporting : public QObject
{
    Q_OBJECT

public:
    BatteryReporting(BatteryData& batteryPacket0,
                     BatteryData& batteryPacket1,
                     BatteryTab& batteryTab);
    void setData(int packetNum);

private:
    BatteryData& batteryPacket0_;
    BatteryData& batteryPacket1_;
    BatteryTab& batteryTab_;
};
