#pragma once

#include <QObject>

class DriverControlsData;
class DriverControlsTab;

class DriverControlsReporting : public QObject
{
    Q_OBJECT

public:
    DriverControlsReporting(DriverControlsData& driverControlsData,
                            DriverControlsTab& driverControlsTab);
    void setData();

private:
    DriverControlsData& driverControlsData_;
    DriverControlsTab& driverControlsTab_;
};
