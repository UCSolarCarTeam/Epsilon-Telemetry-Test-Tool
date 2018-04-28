#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>

class AuxBmsTab;
class BatteryFaultsTab;
class BatteryTab;
class DriverControlsTab;
class LightsTab;
class MotorTab;
class MotorFaultsTab;
class MpptTab;

class PacketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PacketWindow(AuxBmsTab& auxBmsTab,
                          BatteryTab& batteryTab,
                          BatteryFaultsTab& batteryFaultsTab,
                          DriverControlsTab& driverControlsTab,
                          LightsTab& lightsTab,
                          MotorTab& motor0Tab,
                          MotorTab& motor1Tab,
                          MotorFaultsTab& motor0FaultsTab,
                          MotorFaultsTab& motor1FaultsTab,
                          MpptTab& mpptTab);
    ~PacketWindow();
    QTabWidget* tabs_;
    AuxBmsTab& auxBmsTab();
    BatteryTab& batteryTab();
    BatteryFaultsTab& batteryFaultsTab();
    DriverControlsTab& driverControlsTab();
    LightsTab& lightsTab();
    MotorTab& motor0Tab();
    MotorTab& motor1Tab();
    MotorFaultsTab& motor0FaultsTab();
    MotorFaultsTab& motor1FaultsTab();
    MpptTab& mpptTab();
    QPushButton& setButton();

private:
    AuxBmsTab& auxBmsTab_;
    BatteryTab& batteryTab_;
    BatteryFaultsTab& batteryFaultsTab_;
    DriverControlsTab& driverControlsTab_;
    LightsTab& lightsTab_;
    MotorTab& motor0Tab_;
    MotorTab& motor1Tab_;
    MotorFaultsTab& motor0FaultsTab_;
    MotorFaultsTab& motor1FaultsTab_;
    MpptTab& mpptTab_;
    QPushButton* setButton_;
};

