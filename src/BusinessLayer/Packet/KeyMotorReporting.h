#pragma once

#include <QObject>

class KeyMotorData;
class MotorTab;

class KeyMotorReporting : public QObject
{
    Q_OBJECT

public:
    KeyMotorReporting(KeyMotorData& keyMotorPacket0,
                      KeyMotorData& keyMotorPacket1,
                      MotorTab& motor0Tab,
                      MotorTab& motor1Tab);
    void setData(int packetNum);

private:
    KeyMotorData& keyMotorPacket0_;
    KeyMotorData& keyMotorPacket1_;
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
};
