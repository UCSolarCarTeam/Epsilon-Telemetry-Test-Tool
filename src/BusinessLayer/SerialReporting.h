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
class I_CommunicationService;
class SerialView;
class DataContainer;

class SerialReporting : public QObject
{
    Q_OBJECT
public:
    SerialReporting(I_CommunicationService& commService,
                    DataContainer& dataContainer0_,
                    DataContainer& dataContainer1_,
                    SerialView& view);

public slots:
    void sendKeyMotor();
    void sendMotorDetails(int n);
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendMppt();
    void sendLights();
    void sendAuxBms();
    void sendAll();
    void switchPacket();

private:
    I_CommunicationService& communicationService_;
    const KeyMotorData& keyMotorData0_;
    const MotorDetailsData& motor0DetailsData0_;
    const MotorDetailsData& motor1DetailsData0_;
    const DriverControlsData& driverControlsData0_;
    const MotorFaultsData& motorFaultsData0_;
    const BatteryFaultsData& batteryFaultsData0_;
    const BatteryData& batteryData0_;
    const MpptData& mpptData0_;
    const LightsData& lightsData0_;
    const AuxBmsData& auxBmsData0_;
    const KeyMotorData& keyMotorData1_;
    const MotorDetailsData& motor0DetailsData1_;
    const MotorDetailsData& motor1DetailsData1_;
    const DriverControlsData& driverControlsData1_;
    const MotorFaultsData& motorFaultsData1_;
    const BatteryFaultsData& batteryFaultsData1_;
    const BatteryData& batteryData1_;
    const MpptData& mpptData1_;
    const LightsData& lightsData1_;
    const AuxBmsData& auxBmsData1_;
    SerialView& view_;
    int packetNum;
};
