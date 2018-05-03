#include <QVBoxLayout>
#include <QPushButton>
#include "PacketWindow.h"
#include "../UILayer/Packet/AuxBmsTab.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"
#include "../UILayer/Packet/BatteryTab.h"
#include "../UILayer/Packet/DriverControlsTab.h"
#include "../UILayer/Packet/LightsTab.h"
#include "../UILayer/Packet/MotorTab.h"
#include "../UILayer/Packet/MotorFaultsTab.h"
#include "../UILayer/Packet/MpptTab.h"


PacketWindow::PacketWindow(AuxBmsTab& auxBmsTab,
                           BatteryTab& batteryTab,
                           BatteryFaultsTab& batteryFaultsTab,
                           DriverControlsTab& driverControlsTab,
                           LightsTab& lightsTab,
                           MotorTab& motor0Tab,
                           MotorTab& motor1Tab,
                           MotorFaultsTab& motor0FaultsTab,
                           MotorFaultsTab& motor1FaultsTab,
                           MpptTab& mpptTab)
    : auxBmsTab_(auxBmsTab)
    , batteryTab_(batteryTab)
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
    tabs_->addTab(&auxBmsTab_, tr("Aux BMS"));
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
    setPacket0_ = new QPushButton("Set Packet 0", this);
    setPacket1_ = new QPushButton("Set Packet 1", this);
    tabsLayout->addWidget(setPacket0_);
    tabsLayout->addWidget(setPacket1_);
    tabsLayout->addWidget(tabs_);
    setMinimumSize(900, 800);
    setMaximumSize(1920, 1080);
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

AuxBmsTab& PacketWindow::auxBmsTab()
{
    return auxBmsTab_;
}

QPushButton& PacketWindow::setPacket0()
{
    return *setPacket0_;
}

QPushButton& PacketWindow::setPacket1()
{
    return *setPacket1_;
}
