#pragma once

#include <QObject>

class MotorDetailsData;
class MotorTab;

class MotorDetailsReporting : public QObject
{
    Q_OBJECT

public:
    MotorDetailsReporting(MotorDetailsData& motorDetailsData,
                          MotorTab& motorTab);
    void setMotorDetailsData();

private:
    MotorDetailsData& motorDetailsData_;
    MotorTab& motorTab_;
};
