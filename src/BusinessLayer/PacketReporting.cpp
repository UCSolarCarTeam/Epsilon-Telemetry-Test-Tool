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
#include "DataContainer.h"
#include "PacketReporting.h"
#include "PacketView.h"
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

PacketReporting::PacketReporting(DataContainer& dataContainer0,
                                 DataContainer& dataContainer1,
                                 PacketView& view)
    : dataContainer0_(dataContainer0)
    , dataContainer1_(dataContainer1)
    , view_(view)
{
    auxBmsReporting_ = new AuxBmsReporting(view_.getAuxBmsTab());
    batteryReporting_ = new BatteryReporting(view_.getBatteryTab());
    batteryFaultsReporting_ = new BatteryFaultsReporting(view_.getBatteryFaultsTab());
    driverControlsReporting_ = new DriverControlsReporting(view_.getDriverControlsTab());
    keyMotorReporting_ = new KeyMotorReporting(view_.getMotor0Tab(), view_.getMotor1Tab());
    lightsReporting_ = new LightsReporting(view_.getLightsTab());
    motor0DetailsReporting_ = new MotorDetailsReporting(view_.getMotor0Tab());
    motor1DetailsReporting_ = new MotorDetailsReporting(view_.getMotor1Tab());
    motorFaultsReporting_ = new MotorFaultsReporting(view_.getMotor0FaultsTab(), view_.getMotor1FaultsTab());
    mpptReporting_ = new MpptReporting(view_.getMpptTab());
    connect(&view_, SIGNAL(setAll(int)), this, SLOT(setAll(int)));
}

void PacketReporting::setAll(int packetNum)
{
    DataContainer* dataContainer;

    if (packetNum == 0)
    {
        dataContainer = &dataContainer0_;
    }
    else
    {
        dataContainer = &dataContainer1_;
    }

    batteryReporting_->setData(dataContainer->getBatteryData());
    batteryFaultsReporting_->setData(dataContainer->getBatteryFaultsData());
    driverControlsReporting_->setData(dataContainer->getDriverControlsData());
    motorFaultsReporting_->setData(dataContainer->getMotorFaultsData());
    keyMotorReporting_->setData(dataContainer->getKeyMotorData());
    motor0DetailsReporting_->setData(dataContainer->getMotor0DetailsData());
    motor1DetailsReporting_->setData(dataContainer->getMotor1DetailsData());
    mpptReporting_->setData(dataContainer->getMpptData());
    auxBmsReporting_->setData(dataContainer->getAuxBmsData());
    lightsReporting_->setData(dataContainer->getLightsData());
}
