#pragma once

#include <QObject>

class KeyMotorData;
class MotorTab;

class KeyMotorReporting : public QObject
{
    Q_OBJECT

public:
    KeyMotorReporting(MotorTab& motor0Tab,
                      MotorTab& motor1Tab);
    void setData(KeyMotorData& keyMotorData);

private:
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
};
