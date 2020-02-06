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


PacketWindow::PacketWindow()
    : auxBmsTab_(new AuxBmsTab())
    , batteryTab_(new BatteryTab())
    , batteryFaultsTab_(new BatteryFaultsTab())
    , driverControlsTab_(new DriverControlsTab())
    , lightsTab_(new LightsTab())
    , motor0Tab_(new MotorTab())
    , motor1Tab_(new MotorTab())
    , motor0FaultsTab_(new MotorFaultsTab())
    , motor1FaultsTab_(new MotorFaultsTab())
    , mpptTab_(new MpptTab())
{
    tabs_ = new QTabWidget();

    scroll_ = new QScrollArea();
    scroll_->setWidget(tabs_);
    scroll_->setWidgetResizable(true);

    tabs_->addTab(auxBmsTab_.data(), tr("Aux BMS"));
    tabs_->addTab(batteryTab_.data(), tr("Battery"));
    tabs_->addTab(batteryFaultsTab_.data(), tr("Battery Faults"));
    tabs_->addTab(driverControlsTab_.data(), tr("Driver Controls"));
    tabs_->addTab(lightsTab_.data(), tr("Lights"));
    tabs_->addTab(motor0Tab_.data(), tr("Motor 0"));
    tabs_->addTab(motor1Tab_.data(), tr("Motor 1"));
    tabs_->addTab(motor0FaultsTab_.data(), tr("Motor 0 Faults"));
    tabs_->addTab(motor1FaultsTab_.data(), tr("Motor 1 Faults"));
    tabs_->addTab(mpptTab_.data(), tr("MPPT"));
    auxBmsTab_->setToolTip("Set test data for the BMS (Battery Management System) for the auxiliary battery (low voltage).");
    batteryTab_->setToolTip("Set test data for the main battery.");
    batteryFaultsTab_->setToolTip("Set emulated battery faults.");
    driverControlsTab_->setToolTip("Set test data for driver controls");
    lightsTab_->setToolTip("Set test data for lights.");
    mpptTab_->setToolTip("Set test data for MPPT (Maximum power point tracking, Solar Cell power extraction/charging).");
    QVBoxLayout* tabsLayout = new QVBoxLayout;
    setPacket0_ = new QPushButton("Set Packet 0", this);
    setPacket1_ = new QPushButton("Set Packet 1", this);
    setPacket0_->setToolTip("Set the informations for data packet 0.");
    setPacket1_->setToolTip("Set the informations for data packet 1.");
    tabsLayout->addWidget(setPacket0_);
    tabsLayout->addWidget(setPacket1_);
    tabsLayout->addWidget(scroll_);
    setLayout(tabsLayout);
    setWindowTitle(tr("Data"));
}

PacketWindow::~PacketWindow()
{
}

BatteryTab& PacketWindow::batteryTab()
{
    return *batteryTab_.data();
}

BatteryFaultsTab& PacketWindow::batteryFaultsTab()
{
    return *batteryFaultsTab_.data();
}

DriverControlsTab& PacketWindow::driverControlsTab()
{
    return *driverControlsTab_.data();
}

LightsTab& PacketWindow::lightsTab()
{
    return *lightsTab_.data();
}

MotorTab& PacketWindow::motor0Tab()
{
    return *motor0Tab_.data();
}

MotorTab& PacketWindow::motor1Tab()
{
    return *motor1Tab_.data();
}

MotorFaultsTab& PacketWindow::motor0FaultsTab()
{
    return *motor0FaultsTab_.data();
}

MotorFaultsTab& PacketWindow::motor1FaultsTab()
{
    return *motor1FaultsTab_.data();
}

MpptTab& PacketWindow::mpptTab()
{
    return *mpptTab_.data();
}

AuxBmsTab& PacketWindow::auxBmsTab()
{
    return *auxBmsTab_.data();
}

QPushButton& PacketWindow::setPacket0()
{
    return *setPacket0_;
}

QPushButton& PacketWindow::setPacket1()
{
    return *setPacket1_;
}
