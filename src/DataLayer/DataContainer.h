#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QScopedPointer>

class BatteryData;
class BatteryFaultsData;
class AuxBmsData;
class DriverControlsData;
class KeyMotorData;
class LightsData;
class MotorDetailsData;
class MotorFaultsData;
class MpptData;

class DataContainer
{
public:
    DataContainer();
    KeyMotorData& getKeyMotorData();
    MotorDetailsData& getMotor0DetailsData();
    MotorDetailsData& getMotor1DetailsData();
    DriverControlsData& getDriverControlsData();
    MotorFaultsData& getMotorFaultsData();
    BatteryFaultsData& getBatteryFaultsData();
    BatteryData& getBatteryData();
    MpptData& getMpptData();
    LightsData& getLightsData();
    AuxBmsData& getAuxBmsData();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<MotorDetailsData> motor0DetailsData_;
    QScopedPointer<MotorDetailsData> motor1DetailsData_;
    QScopedPointer<DriverControlsData> driverControlsData_;
    QScopedPointer<MotorFaultsData> motorFaultsData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<BatteryData> batteryData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<AuxBmsData> auxBmsData_;
};

#endif // DATACONTAINER_H
