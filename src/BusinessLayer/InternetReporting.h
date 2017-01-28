#pragma once

#include <QObject>
#include <initializer_list>

class BatteryData;
class BatteryFaultsData;
class CmuData;
class DriverControlsData;
class KeyMotorData;
class LightsData;
class MotorDetailsData;
class MotorFaultsData;
class MpptData;
class View;
class QIODevice;
class I_CommunicationService;

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
                      const CmuData& cmuData_,
                      const MpptData& mpptData_,
                      const LightsData& lightsData_);

private slots:
    void sendAll();

private:
    QJsonArray makeKeyMotor();
    QJsonObject makeMotorDetails(int n);
    QJsonObject makeDriverControls();
    QJsonArray makeMotorFaults();
    QJsonObject makeBatteryFaults();
    QJsonObject makeBattery();
    QJsonArray makeCmu();
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
    const CmuData& cmuData_;
    const MpptData& mpptData_;
    const LightsData& lightsData_;
};
