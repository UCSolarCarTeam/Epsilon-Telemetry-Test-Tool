#pragma once

#include <QObject>
#include <QSignalMapper>

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
class InternetView;
class DataContainer;

class InternetReporting : public QObject
{
    Q_OBJECT
public:
    InternetReporting(I_CommunicationService& commService,
                      DataContainer& dataContainer0,
                      DataContainer& dataContainer1,
                      InternetView& view);

public slots:
    void sendAll(int packetNum);

private:
    QJsonArray makeKeyMotor();
    QJsonObject makeMotorDetails(int n);
    QJsonObject makeDriverControls();
    QJsonArray makeMotorFaults();
    QJsonObject makeBatteryFaults();
    QJsonObject makeBattery();
    QJsonArray makeMppt();
    QJsonObject makeLights();
    QJsonObject makeAuxBms();

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
    InternetView& view_;
    int packetNum;
};
