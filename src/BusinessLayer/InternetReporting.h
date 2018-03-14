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
class I_CommunicationService;
class InternetView;

class InternetReporting : public QObject
{
    Q_OBJECT
public:
    InternetReporting(I_CommunicationService& commService,
                      const KeyMotorData& keyMotorData_,
                      const MotorDetailsData& motor0DetailsData_,
                      const MotorDetailsData& motor1DetailsData_,
                      const DriverControlsData& driverControlsData_,
                      const MotorFaultsData& motorFaultsData_,
                      const BatteryFaultsData& batteryFaultsData_,
                      const BatteryData& batteryData_,
                      const MpptData& mpptData_,
                      const LightsData& lightsData_,
                      InternetView& view);

private slots:
    void sendAll();

private:
    QJsonArray makeKeyMotor();
    QJsonObject makeMotorDetails(int n);
    QJsonObject makeDriverControls();
    QJsonArray makeMotorFaults();
    QJsonObject makeBatteryFaults();
    QJsonObject makeBattery();
    QJsonArray makeMppt();
    QJsonObject makeLights();

private:
    I_CommunicationService& communicationService_;
    const KeyMotorData& keyMotorData_;
    const MotorDetailsData& motor0DetailsData_;
    const MotorDetailsData& motor1DetailsData_;
    const DriverControlsData& driverControlsData_;
    const MotorFaultsData& motorFaultsData_;
    const BatteryFaultsData& batteryFaultsData_;
    const BatteryData& batteryData_;
    const MpptData& mpptData_;
    const LightsData& lightsData_;
    InternetView& view_;
};
