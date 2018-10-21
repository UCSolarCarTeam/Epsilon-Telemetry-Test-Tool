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
    : keyMotorData0_(dataContainer0.getKeyMotorData())
    , motor0DetailsData0_(dataContainer0.getMotor0DetailsData())
    , motor1DetailsData0_(dataContainer0.getMotor1DetailsData())
    , driverControlsData0_(dataContainer0.getDriverControlsData())
    , motorFaultsData0_(dataContainer0.getMotorFaultsData())
    , batteryFaultsData0_(dataContainer0.getBatteryFaultsData())
    , batteryData0_(dataContainer0.getBatteryData())
    , mpptData0_(dataContainer0.getMpptData())
    , lightsData0_(dataContainer0.getLightsData())
    , auxBmsData0_(dataContainer0.getAuxBmsData())
    , keyMotorData1_(dataContainer0.getKeyMotorData())
    , motor0DetailsData1_(dataContainer1.getMotor0DetailsData())
    , motor1DetailsData1_(dataContainer1.getMotor1DetailsData())
    , driverControlsData1_(dataContainer1.getDriverControlsData())
    , motorFaultsData1_(dataContainer1.getMotorFaultsData())
    , batteryFaultsData1_(dataContainer1.getBatteryFaultsData())
    , batteryData1_(dataContainer1.getBatteryData())
    , mpptData1_(dataContainer1.getMpptData())
    , lightsData1_(dataContainer1.getLightsData())
    , auxBmsData1_(dataContainer0.getAuxBmsData())
    , view_(view)
{
    auxBmsReporting_ = new AuxBmsReporting(auxBmsData0_, auxBmsData1_, view_.getAuxBmsTab());
    batteryReporting_ = new BatteryReporting(batteryData0_, batteryData1_, view_.getBatteryTab());
    batteryFaultsReporting_ = new BatteryFaultsReporting(batteryFaultsData0_, batteryFaultsData1_,
                                                         view_.getBatteryFaultsTab());
    driverControlsReporting_ = new DriverControlsReporting(driverControlsData0_, driverControlsData1_,
                                                           view_.getDriverControlsTab());
    keyMotorReporting_ = new KeyMotorReporting(keyMotorData0_, keyMotorData1_,
                                               view_.getMotor0Tab(), view_.getMotor1Tab());
    lightsReporting_ = new LightsReporting(lightsData0_, lightsData1_,
                                           view_.getLightsTab());
    motor0DetailsReporting_ = new MotorDetailsReporting(motor0DetailsData0_, motor0DetailsData1_,
                                                        view_.getMotor0Tab());
    motor1DetailsReporting_ = new MotorDetailsReporting(motor1DetailsData0_, motor0DetailsData1_,
                                                        view_.getMotor1Tab());
    motorFaultsReporting_ = new MotorFaultsReporting(motorFaultsData0_, motorFaultsData1_,
                                                     view_.getMotor0FaultsTab(), view_.getMotor1FaultsTab());
    mpptReporting_ = new MpptReporting(mpptData0_, mpptData1_,
                                       view_.getMpptTab());
    connect(&view_, SIGNAL(setAll(int)), this, SLOT(setAll(int)));
}

void PacketReporting::setAll(int packetNum)
{
    batteryReporting_->setData(packetNum);
    batteryFaultsReporting_->setData(packetNum);
    driverControlsReporting_->setData(packetNum);
    motorFaultsReporting_->setData(packetNum);
    keyMotorReporting_->setData(packetNum);
    motor0DetailsReporting_->setData(packetNum);
    motor1DetailsReporting_->setData(packetNum);
    mpptReporting_->setData(packetNum);
    auxBmsReporting_->setData(packetNum);
    lightsReporting_->setData(packetNum);
}
