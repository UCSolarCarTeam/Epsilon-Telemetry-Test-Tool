#pragma once

#include <QObject>

class KeyMotorData;
class MotorTab;

class KeyMotorReporting : public QObject
{
    Q_OBJECT

public:
    KeyMotorReporting(KeyMotorData& keyMotorData,
                      MotorTab& motor0Tab,
                      MotorTab& motor1Tab);
    void setUiData();

private:
    KeyMotorData& keyMotorData_;
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
};
