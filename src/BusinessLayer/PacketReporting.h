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
    DataContainer& dataContainer0_;
    DataContainer& dataContainer1_;
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
