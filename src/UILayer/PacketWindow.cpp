#include <QVBoxLayout>
#include <QPushButton>
#include "PacketWindow.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"
#include "../UILayer/Packet/BatteryTab.h"
#include "../UILayer/Packet/DriverControlsTab.h"
#include "../UILayer/Packet/LightsTab.h"
#include "../UILayer/Packet/MotorTab.h"
#include "../UILayer/Packet/MotorFaultsTab.h"
#include "../UILayer/Packet/MpptTab.h"


PacketWindow::PacketWindow(BatteryTab& batteryTab,
                           BatteryFaultsTab& batteryFaultsTab,
                           DriverControlsTab& driverControlsTab,
                           LightsTab& lightsTab,
                           MotorTab& motor0Tab,
                           MotorTab& motor1Tab,
                           MotorFaultsTab& motor0FaultsTab,
                           MotorFaultsTab& motor1FaultsTab,
                           MpptTab& mpptTab)
    : batteryTab_(batteryTab)
    , batteryFaultsTab_(batteryFaultsTab)
    , driverControlsTab_(driverControlsTab)
    , lightsTab_(lightsTab)
    , motor0Tab_(motor0Tab)
    , motor1Tab_(motor1Tab)
    , motor0FaultsTab_(motor0FaultsTab)
    , motor1FaultsTab_(motor1FaultsTab)
    , mpptTab_(mpptTab)
{
    tabs_ = new QTabWidget();
    tabs_->addTab(&batteryTab_, tr("Battery"));
    tabs_->addTab(&batteryFaultsTab_, tr("Battery Faults"));
    tabs_->addTab(&driverControlsTab_, tr("Driver Controls"));
    tabs_->addTab(&lightsTab_, tr("Lights"));
    tabs_->addTab(&motor0Tab_, tr("Motor 0"));
    tabs_->addTab(&motor1Tab_, tr("Motor 1"));
    tabs_->addTab(&motor0FaultsTab_, tr("Motor 0 Faults"));
    tabs_->addTab(&motor1FaultsTab_, tr("Motor 1 Faults"));
    tabs_->addTab(&mpptTab_, tr("MPPT"));

    QVBoxLayout* tabsLayout = new QVBoxLayout;
    setButton_ = new QPushButton("Set Data", this);
    tabsLayout->addWidget(setButton_);
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

MotorFaultsTab& PacketWindow::motor0FaultsTab()
{
    return motor0FaultsTab_;
}

MotorFaultsTab& PacketWindow::motor1FaultsTab()
{
    return motor1FaultsTab_;
}

MpptTab& PacketWindow::mpptTab()
{
    return mpptTab_;
}

QPushButton& PacketWindow::setButton()
{
    return *setButton_;
}
