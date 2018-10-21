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
class DataContainer;
class PacketView;
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
    PacketReporting(DataContainer& dataContainer0,
                    DataContainer& dataContainer1,
                    PacketView& view);

public slots:
    void setAll(int packetNum);

private:
    KeyMotorData& keyMotorData0_;
    MotorDetailsData& motor0DetailsData0_;
    MotorDetailsData& motor1DetailsData0_;
    DriverControlsData& driverControlsData0_;
    MotorFaultsData& motorFaultsData0_;
    BatteryFaultsData& batteryFaultsData0_;
    BatteryData& batteryData0_;
    MpptData& mpptData0_;
    LightsData& lightsData0_;
    AuxBmsData& auxBmsData0_;
    KeyMotorData& keyMotorData1_;
    MotorDetailsData& motor0DetailsData1_;
    MotorDetailsData& motor1DetailsData1_;
    DriverControlsData& driverControlsData1_;
    MotorFaultsData& motorFaultsData1_;
    BatteryFaultsData& batteryFaultsData1_;
    BatteryData& batteryData1_;
    MpptData& mpptData1_;
    LightsData& lightsData1_;
    AuxBmsData& auxBmsData1_;
    PacketView& view_;
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
