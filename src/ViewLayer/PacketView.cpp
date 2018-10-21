#include "PacketView.h"
#include "PacketWindow.h"
#include "Packet/AuxBmsTab.h"
#include "Packet/BatteryFaultsTab.h"
#include "Packet/BatteryTab.h"
#include "Packet/DriverControlsTab.h"
#include "Packet/MotorTab.h"
#include "Packet/LightsTab.h"
#include "Packet/MpptTab.h"

PacketView::PacketView(PacketWindow* window)
    : window_(window)
    , signalMapper(this)
{
    connect(&(window_->setPacket0()), SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(&(window_->setPacket1()), SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    signalMapper.setMapping((&window_->setPacket0()), 0);
    signalMapper.setMapping((&window_->setPacket1()), 1);
    connect(&signalMapper, SIGNAL(mapped(int)),
            this, SIGNAL(setAll(int)));
}

AuxBmsTab& PacketView::getAuxBmsTab()
{
    return window_->auxBmsTab();
}

BatteryFaultsTab& PacketView::getBatteryFaultsTab()
{
    return window_->batteryFaultsTab();
}

BatteryTab& PacketView::getBatteryTab()
{
    return window_->batteryTab();
}

DriverControlsTab& PacketView::getDriverControlsTab()
{
    return window_->driverControlsTab();
}

LightsTab& PacketView::getLightsTab()
{
    return window_->lightsTab();
}

MotorTab& PacketView::getMotor0Tab()
{
    return window_->motor0Tab();
}

MotorTab& PacketView::getMotor1Tab()
{
    return window_->motor1Tab();
}

MotorFaultsTab& PacketView::getMotor0FaultsTab()
{
    return window_->motor0FaultsTab();
}

MotorFaultsTab& PacketView::getMotor1FaultsTab()
{
    return window_->motor1FaultsTab();
}

MpptTab& PacketView::getMpptTab()
{
    return window_->mpptTab();
}
