#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "DriverControlsData.h"
#include "InternetView.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "PacketReporting.h"
#include "../UILayer/PacketWindow.h"
#include "../BusinessLayer/Packet/BatteryFaultsReporting.h"
#include "../BusinessLayer/Packet/BatteryReporting.h"
#include "../BusinessLayer/Packet/DriverControlsReporting.h"
#include "../BusinessLayer/Packet/KeyMotorReporting.h"
#include "../BusinessLayer/Packet/LightsReporting.h"
#include "../BusinessLayer/Packet/MotorDetailsReporting.h"
#include "../BusinessLayer/Packet/MotorFaultsReporting.h"
#include "../BusinessLayer/Packet/MpptReporting.h"
#include <QPushButton>

PacketReporting::PacketReporting(KeyMotorData& keyMotorData,
                                 MotorDetailsData& motor0DetailsData,
                                 MotorDetailsData& motor1DetailsData,
                                 DriverControlsData& driverControlsData,
                                 MotorFaultsData& motorFaultsData,
                                 BatteryFaultsData& batteryFaultsData,
                                 BatteryData& batteryData,
                                 MpptData& mpptData,
                                 LightsData& lightsData,
                                 PacketWindow& window)
    : keyMotorData_(keyMotorData)
    , motor0DetailsData_(motor0DetailsData)
    , motor1DetailsData_(motor1DetailsData)
    , driverControlsData_(driverControlsData)
    , motorFaultsData_(motorFaultsData)
    , batteryFaultsData_(batteryFaultsData)
    , batteryData_(batteryData)
    , mpptData_(mpptData)
    , lightsData_(lightsData)
    , window_(window)
{
    connect(&(window_.setButton()), SIGNAL(clicked()),
                     this, SLOT(setAll()));
}

void PacketReporting::setBattery()
{
    BatteryReporting batteryReporting(batteryData_, window_.batteryTab());
    batteryReporting.setData();
}

void PacketReporting::setBatteryFaults()
{
    BatteryFaultsReporting batteryFaultsReporting(batteryFaultsData_, window_.batteryFaultsTab());
    batteryFaultsReporting.setData();
}

void PacketReporting::setDriverControls()
{
    DriverControlsReporting driverControlsReporting(driverControlsData_, window_.driverControlsTab());
    driverControlsReporting.setData();
}

void PacketReporting::setMotorFaults()
{
    MotorFaultsReporting motorFaultsReporting(motorFaultsData_, window_.motor0Tab(), window_.motor1Tab());
    motorFaultsReporting.setData();
}

void PacketReporting::setKeyMotor()
{
    KeyMotorReporting keyMotorReporting(keyMotorData_, window_.motor0Tab(), window_.motor1Tab());
    keyMotorReporting.setData();
}

void PacketReporting::setMotor0Details()
{
    MotorDetailsReporting motor0DetailsReporting(motor0DetailsData_, window_.motor0Tab());
    motor0DetailsReporting.setData();
}

void PacketReporting::setMotor1Details()
{
    MotorDetailsReporting motor1DetailsReporting(motor1DetailsData_, window_.motor1Tab());
    motor1DetailsReporting.setData();
}

void PacketReporting::setMppt()
{
    MpptReporting mpptReporting(mpptData_, window_.mpptTab());
    mpptReporting.setData();
}

void PacketReporting::setLights()
{
    LightsReporting lightsReporting(lightsData_, window_.lightsTab());
    lightsReporting.setData();
}

void PacketReporting::setAll()
{
    setBattery();
    setBatteryFaults();
    setDriverControls();
    setMotorFaults();
    setKeyMotor();
    setMotor0Details();
    setMotor1Details();
    setMppt();
    setLights();
}
