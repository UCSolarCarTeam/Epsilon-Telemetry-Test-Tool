#pragma once

#include <QObject>

class DriverControlsData;
class DriverControlsTab;

class DriverControlsReporting : public QObject
{
    Q_OBJECT

public:
    DriverControlsReporting(DriverControlsData& driverControlsPacket0,
                            DriverControlsData& driverControlsPacket1,
                            DriverControlsTab& driverControlsTab);
    void setData(int packetNum);

private:
    DriverControlsData& driverControlsPacket0_;
    DriverControlsData& driverControlsPacket1_;
    DriverControlsTab& driverControlsTab_;
};
