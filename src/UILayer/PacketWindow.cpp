#include <QVBoxLayout>
#include "PacketWindow.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"
#include "../UILayer/Packet/BatteryTab.h"
#include "../UILayer/Packet/DriverControlsTab.h"
#include "../UILayer/Packet/LightsTab.h"
#include "../UILayer/Packet/MotorTab.h"
#include "../UILayer/Packet/MpptTab.h"


PacketWindow::PacketWindow(BatteryTab& batteryTab,
                           BatteryFaultsTab& batteryFaultsTab,
                           DriverControlsTab& driverControlsTab,
                           LightsTab& lightsTab,
                           MotorTab& motor0Tab,
                           MotorTab& motor1Tab,
                           MpptTab& mpptTab)
    : batteryTab_(batteryTab)
    , batteryFaultsTab_(batteryFaultsTab)
    , driverControlsTab_(driverControlsTab)
    , lightsTab_(lightsTab)
    , motor0Tab_(motor0Tab)
    , motor1Tab_(motor1Tab)
    , mpptTab_(mpptTab)
{
    tabs_ = new QTabWidget();
    tabs_->addTab(&batteryTab_, tr("Battery"));
    tabs_->addTab(&batteryFaultsTab_, tr("Battery Faults"));
    tabs_->addTab(&driverControlsTab_, tr("Driver Controls"));
    tabs_->addTab(&lightsTab_, tr("Lights"));
    tabs_->addTab(&motor0Tab_, tr("Motor 0"));
    tabs_->addTab(&motor1Tab_, tr("Motor 1"));
    tabs_->addTab(&mpptTab_, tr("MPPT"));

    QVBoxLayout* tabsLayout = new QVBoxLayout;
    tabsLayout->addWidget(tabs_);
    setMinimumSize(900, 800);
    setLayout(tabsLayout);
    setWindowTitle(tr("Data"));
}

PacketWindow::~PacketWindow()
{
}

BatteryTab& PacketWindow::batteryTab()
{
    return batteryTab_;
}

BatteryFaultsTab& PacketWindow::batteryFaultsTab()
{
    return batteryFaultsTab_;
}

DriverControlsTab& PacketWindow::driverControlsTab()
{
    return driverControlsTab_;
}

LightsTab& PacketWindow::lightsTab()
{
    return lightsTab_;
}

MotorTab& PacketWindow::motor0Tab()
{
    return motor0Tab_;
}

MotorTab& PacketWindow::motor1Tab()
{
    return motor1Tab_;
}

MpptTab& PacketWindow::mpptTab()
{
    return mpptTab_;
}
