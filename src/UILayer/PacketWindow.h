#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScopedPointer>

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
    explicit PacketWindow();
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
    QPushButton& setPacket0();
    QPushButton& setPacket1();

private:
    QScopedPointer<AuxBmsTab> auxBmsTab_;
    QScopedPointer<BatteryTab> batteryTab_;
    QScopedPointer<BatteryFaultsTab> batteryFaultsTab_;
    QScopedPointer<DriverControlsTab> driverControlsTab_;
    QScopedPointer<LightsTab> lightsTab_;
    QScopedPointer<MotorTab> motor0Tab_;
    QScopedPointer<MotorTab> motor1Tab_;
    QScopedPointer<MotorFaultsTab> motor0FaultsTab_;
    QScopedPointer<MotorFaultsTab> motor1FaultsTab_;
    QScopedPointer<MpptTab> mpptTab_;
    QPushButton* setPacket0_;
    QPushButton* setPacket1_;
    QScrollArea* scroll_;
};

