#pragma once

#include <QObject>

class MotorFaultsData;
class MotorFaultsTab;

class MotorFaultsReporting : public QObject
{
    Q_OBJECT

public:
    MotorFaultsReporting(MotorFaultsTab& motor0FaultsTab,
                         MotorFaultsTab& motor1FaultsTab);
    void setData(MotorFaultsData& motorFaultsData);

private:
    MotorFaultsTab& motor0FaultsTab_;
    MotorFaultsTab& motor1FaultsTab_;
};
