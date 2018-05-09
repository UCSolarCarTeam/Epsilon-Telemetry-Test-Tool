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
    motor0Tab_.alive().setChecked(true);
    motor0Tab_.setCurrent().setValue(1.1);
    motor0Tab_.setVelocity().setValue(2.2);
    motor0Tab_.busCurrent().setValue(3.3);
    motor0Tab_.busVoltage().setValue(4.4);
    motor0Tab_.vehicleVelocity().setValue(5.5);
    motor1Tab_.setCurrent().setValue(6.6);
    motor1Tab_.setVelocity().setValue(7.7);
    motor1Tab_.busCurrent().setValue(8.8);
    motor1Tab_.busVoltage().setValue(9.9);
    motor1Tab_.vehicleVelocity().setValue(10.01);
    motor1Tab_.vehicleVelocity().setValue(5.5);
    motor0FaultsTab_.overSpeed().setChecked(true);
    motor0FaultsTab_.dcBusOverVoltage().setChecked(true);
    motor0FaultsTab_.badMotorPositionHallSequence().setChecked(true);
    motor0FaultsTab_.configReadError().setChecked(true);
    motor0FaultsTab_.desaturationFault().setChecked(true);
    motor0FaultsTab_.motorCurrentLimit().setChecked(true);
    motor0FaultsTab_.busCurrentLimit().setChecked(true);
    motor0FaultsTab_.busVoltageLowerLimit().setChecked(true);
    motor0FaultsTab_.canRxErrorCount().setValue(28);
    motor0FaultsTab_.canTxErrorCount().setValue(29);
    motor1FaultsTab_.overSpeed().setChecked(true);
    motor1FaultsTab_.dcBusOverVoltage().setChecked(true);
    motor1FaultsTab_.watchDogCausedLastReset().setChecked(true);
    motor1FaultsTab_.railUnderVoltageLockOut().setChecked(true);
    motor1FaultsTab_.outputVoltagePwmLimit().setChecked(true);
    motor1FaultsTab_.velocityLimit().setChecked(true);
    motor1FaultsTab_.busVoltageUpperLimit().setChecked(true);
    motor1FaultsTab_.ipmOrMotorTempLimit().setChecked(true);
    motor1FaultsTab_.canRxErrorCount().setValue(30);
    motor1FaultsTab_.canTxErrorCount().setValue(31);

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
