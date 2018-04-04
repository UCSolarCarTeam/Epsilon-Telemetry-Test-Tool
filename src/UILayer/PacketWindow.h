#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>

class BatteryFaultsTab;
class BatteryTab;
class DriverControlsTab;
class LightsTab;
class MotorTab;
class MpptTab;

class PacketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PacketWindow(BatteryTab& batteryTab,
                          BatteryFaultsTab& batteryFaultsTab,
                          DriverControlsTab& driverControlsTab,
                          LightsTab& lightsTab,
                          MotorTab& motor0Tab,
                          MotorTab& motor1Tab,
                          MpptTab& mpptTab);
    ~PacketWindow();
    QTabWidget* tabs_;
    BatteryTab& batteryTab();
    BatteryFaultsTab& batteryFaultsTab();
    DriverControlsTab& driverControlsTab();
    LightsTab& lightsTab();
    MotorTab& motor0Tab();
    MotorTab& motor1Tab();
    MpptTab& mpptTab();
    QPushButton& setButton();

private:
    BatteryTab& batteryTab_;
    BatteryFaultsTab& batteryFaultsTab_;
    DriverControlsTab& driverControlsTab_;
    LightsTab& lightsTab_;
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
    MpptTab& mpptTab_;
    QPushButton* setButton_;
};

