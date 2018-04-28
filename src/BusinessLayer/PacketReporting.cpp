#include "AuxBmsData.h"
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
#include "../BusinessLayer/Packet/AuxBmsReporting.h"
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
                                 AuxBmsData& auxBmsData,
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
    , auxBmsData_(auxBmsData)
    , window_(window)
{
    auxBmsReporting_ = new AuxBmsReporting(auxBmsData_, window_.auxBmsTab());
    batteryReporting_ = new BatteryReporting(batteryData_, window_.batteryTab());
    batteryFaultsReporting_ = new BatteryFaultsReporting(batteryFaultsData_, window_.batteryFaultsTab());
    driverControlsReporting_ = new DriverControlsReporting(driverControlsData_, window_.driverControlsTab());
    keyMotorReporting_ = new KeyMotorReporting(keyMotorData_, window_.motor0Tab(), window_.motor1Tab());
    lightsReporting_ = new LightsReporting(lightsData_, window_.lightsTab());
    motor0DetailsReporting_ = new MotorDetailsReporting(motor0DetailsData_, window_.motor0Tab());
    motor1DetailsReporting_ = new MotorDetailsReporting(motor1DetailsData_, window_.motor1Tab());
    motorFaultsReporting_ = new MotorFaultsReporting(motorFaultsData_, window_.motor0FaultsTab(), window_.motor1FaultsTab());
    mpptReporting_ = new MpptReporting(mpptData_, window_.mpptTab());

    connect(&(window_.setButton()), SIGNAL(clicked()),
                     this, SLOT(setAll()));
}

void PacketReporting::setAll()
{
    batteryReporting_->setUiData();
    batteryFaultsReporting_->setUiData();
    driverControlsReporting_->setUiData();
    motorFaultsReporting_->setUiData();
    keyMotorReporting_->setUiData();
    motor0DetailsReporting_->setUiData();
    motor1DetailsReporting_->setUiData();
    mpptReporting_->setUiData();
    auxBmsReporting_->setUiData();
    lightsReporting_->setUiData();
}
