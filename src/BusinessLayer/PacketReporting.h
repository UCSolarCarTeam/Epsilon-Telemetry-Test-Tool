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
PacketReporting(KeyMotorData& keyMotorData,
                MotorDetailsData& motor0DetailsData,
                MotorDetailsData& motor1DetailsData,
                DriverControlsData& driverControlsData,
                MotorFaultsData& motorFaultsData,
                BatteryFaultsData& batteryFaultsData,
                BatteryData& batteryData,
                MpptData& mpptData,
                LightsData& lightsData,
                PacketWindow& window);

private slots:
    void setAll();

private:
    void setKeyMotor();
    void setMotor0Details();
    void setMotor1Details();
    void setDriverControls();
    void setMotorFaults();
    void setBatteryFaults();
    void setBattery();
    void setMppt();
    void setLights();

private:
    KeyMotorData& keyMotorData_;
    MotorDetailsData& motor0DetailsData_;
    MotorDetailsData& motor1DetailsData_;
    DriverControlsData& driverControlsData_;
    MotorFaultsData& motorFaultsData_;
    BatteryFaultsData& batteryFaultsData_;
    BatteryData& batteryData_;
    MpptData& mpptData_;
    LightsData& lightsData_;
    PacketWindow& window_;
};
