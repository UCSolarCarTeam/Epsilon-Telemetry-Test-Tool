#pragma once

#include <QObject>

class DriverControlsData;
class DriverControlsTab;

class DriverControlsReporting : public QObject
{
    Q_OBJECT

public:
    DriverControlsReporting(DriverControlsTab& driverControlsTab);
    void setData(DriverControlsData& driverControlsData);

private:
    DriverControlsTab& driverControlsTab_;
};
