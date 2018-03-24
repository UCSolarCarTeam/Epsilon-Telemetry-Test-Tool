#pragma once

#include <QObject>

class BatteryData;
class BatteryFaultsData;
class DriverControlsData;
class KeyMotorData;
class LightsData;
class MotorDetailsData;
class MotorFaultsData;
class MpptData;
class PacketWindow;

class PacketReporting : public QObject
{
    Q_OBJECT
public:
    PacketReporting(PacketWindow& window);
    void setKeyMotor(KeyMotorData& keyMotorData);
    void setMotor0Details(MotorDetailsData& motor0DetailsData);
    void setMotor1Details(MotorDetailsData& motor1DetailsData);
    void setDriverControls(DriverControlsData& driverControlsData);
    void setMotorFaults(MotorFaultsData& motorFaultsData);
    void setBatteryFaults(BatteryFaultsData& batteryFaultsData);
    void setBattery(BatteryData& batteryData);
    void setMppt(MpptData& mpptData);
    void setLights(LightsData& lightsData);

private:
    PacketWindow& window_;
};
