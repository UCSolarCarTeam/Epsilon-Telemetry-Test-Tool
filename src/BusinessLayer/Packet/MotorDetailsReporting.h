#pragma once

#include <QObject>

class MotorDetailsData;
class MotorTab;

class MotorDetailsReporting : public QObject
{
    Q_OBJECT

public:
    MotorDetailsReporting(MotorDetailsData& motorDetailsPacket0,
                          MotorDetailsData& motorDetailsPacket1,
                          MotorTab& motorTab);
    void setData(int packetNum);

private:
    MotorDetailsData& motorDetailsPacket0_;
    MotorDetailsData& motorDetailsPacket1_;
    MotorTab& motorTab_;
};
