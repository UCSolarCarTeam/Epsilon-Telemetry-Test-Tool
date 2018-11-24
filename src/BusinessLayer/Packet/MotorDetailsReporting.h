#pragma once

#include <QObject>

class MotorDetailsData;
class MotorTab;

class MotorDetailsReporting : public QObject
{
    Q_OBJECT

public:
    MotorDetailsReporting(MotorTab& motorTab);
    void setData(MotorDetailsData& motorDetailsData);

private:
    MotorTab& motorTab_;
};
