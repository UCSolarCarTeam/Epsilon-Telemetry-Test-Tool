#pragma once

#include <QObject>

class AuxBmsData;
class BatteryData;
class BatteryFaultsData;
class DriverControlsData;
class KeyMotorData;
class LightsData;
class MotorDetailsData;
class MotorFaultsData;
class MpptData;
class PacketWindow;
class AuxBmsReporting;
class BatteryFaultsReporting;
class BatteryReporting;
class DriverControlsReporting;
class KeyMotorReporting;
class LightsReporting;
class MotorDetailsReporting;
class MotorFaultsReporting;
class MpptReporting;

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
                    AuxBmsData& auxBmsData,
                    PacketWindow& window);

    //change to private slot later
    void setPacket(BatteryFaultsData& packetBatteryFaults);

private slots:
    void setAll();

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
    AuxBmsData& auxBmsData_;
    PacketWindow& window_;
    BatteryReporting* batteryReporting_;
    BatteryFaultsReporting* batteryFaultsReporting_;
    DriverControlsReporting* driverControlsReporting_;
    KeyMotorReporting* keyMotorReporting_;
    LightsReporting* lightsReporting_;
    MotorDetailsReporting* motor0DetailsReporting_;
    MotorDetailsReporting* motor1DetailsReporting_;
    MotorFaultsReporting* motorFaultsReporting_;
    AuxBmsReporting* auxBmsReporting_;
    MpptReporting* mpptReporting_;
};
