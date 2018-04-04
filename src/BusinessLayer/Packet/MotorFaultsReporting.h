#pragma once

#include <QObject>

class MotorFaultsData;
class MotorTab;

class MotorFaultsReporting : public QObject
{
    Q_OBJECT

public:
    MotorFaultsReporting(MotorFaultsData& motorFaultsData,
                      MotorTab& motor0Tab,
                      MotorTab& motor1Tab);
    void setData();

private:
    MotorFaultsData& motorFaultsData_;
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
};
