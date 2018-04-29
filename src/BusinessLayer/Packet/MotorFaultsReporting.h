#pragma once

#include <QObject>

class MotorFaultsData;
class MotorFaultsTab;

class MotorFaultsReporting : public QObject
{
    Q_OBJECT

public:
    MotorFaultsReporting(MotorFaultsData& motorFaultsData,
                      MotorFaultsTab& motor0FaultsTab,
                      MotorFaultsTab& motor1FaultsTab);
    void setData();

private:
    MotorFaultsData& motorFaultsData_;
    MotorFaultsTab& motor0FaultsTab_;
    MotorFaultsTab& motor1FaultsTab_;
};
