#pragma once

#include <QObject>

class MotorFaultsData;
class MotorFaultsTab;

class MotorFaultsReporting : public QObject
{
    Q_OBJECT

public:
    MotorFaultsReporting(MotorFaultsData& motorFaultsPacket0,
                         MotorFaultsData& motorFaultsPacket1,
                         MotorFaultsTab& motor0FaultsTab,
                         MotorFaultsTab& motor1FaultsTab);
    void setData(int packetNum);

private:
    MotorFaultsData& motorFaultsPacket0_;
    MotorFaultsData& motorFaultsPacket1_;
    MotorFaultsTab& motor0FaultsTab_;
    MotorFaultsTab& motor1FaultsTab_;
};
