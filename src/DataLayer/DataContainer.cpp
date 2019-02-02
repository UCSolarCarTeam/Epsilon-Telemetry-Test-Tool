#include "DataContainer.h"
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "AuxBmsData.h"
#include "DriverControlsData.h"
#include "KeyMotorData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "LightsData.h"

DataContainer::DataContainer()
    : keyMotorData_(new KeyMotorData)
    , motor0DetailsData_(new MotorDetailsData)
    , motor1DetailsData_(new MotorDetailsData)
    , driverControlsData_(new DriverControlsData)
    , motorFaultsData_(new MotorFaultsData)
    , batteryFaultsData_(new BatteryFaultsData)
    , batteryData_(new BatteryData)
    , mpptData_(new MpptData)
    , lightsData_(new LightsData)
    , auxBmsData_(new AuxBmsData)
{
}

AuxBmsData& DataContainer::getAuxBmsData()
{
    return *auxBmsData_.data();
}

BatteryData& DataContainer::getBatteryData()
{
    return *batteryData_.data();
}

BatteryFaultsData& DataContainer::getBatteryFaultsData()
{
    return *batteryFaultsData_.data();
}

DriverControlsData& DataContainer::getDriverControlsData()
{
    return *driverControlsData_.data();
}

KeyMotorData& DataContainer::getKeyMotorData()
{
    return *keyMotorData_.data();
}

LightsData& DataContainer::getLightsData()
{
    return *lightsData_.data();
}

MotorDetailsData& DataContainer::getMotor0DetailsData()
{
    return *motor0DetailsData_.data();
}

MotorDetailsData& DataContainer::getMotor1DetailsData()
{
    return *motor1DetailsData_.data();
}

MotorFaultsData& DataContainer::getMotorFaultsData()
{
    return *motorFaultsData_.data();
}

MpptData& DataContainer::getMpptData()
{
    return *mpptData_.data();
}
