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
class QIODevice;
class View;

class BatteryData_json;
class CommunicationService_json;

class TelemetryReporting_json : public QObject
{
    Q_OBJECT
public:
    TelemetryReporting_json(CommunicationService_json& commService,
                       const KeyMotorData& keyMotorData_,
                       const MotorDetailsData& motor0DetailsData_,
                       const MotorDetailsData& motor1DetailsData_,
                       const DriverControlsData& driverControlsData_,
                       const MotorFaultsData& motorFaultsData_,
                       const BatteryFaultsData& batteryFaultsData_,
                       const BatteryData_json& batteryData_json_,
                       const CmuData& cmuData_,
                       const MpptData& mpptData_,
                       const LightsData& lightsData_,
                       View& view);

private slots:
    void sendKeyMotor();
    void sendMotorDetails(int n);
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendCmu();
    void sendMppt();
    void sendLights();
    void sendAll();

private:
    void makeKeyMotor();
    void makeMotorDetails(int n);
    void makeDriverControls();
    void makeMotorFaults();
    void makeBatteryFaults();
    void makeBattery();
    void makeCmu();
    void makeMppt();
    void makeLights();

private:
    CommunicationService_json& communicationService_json_;
    const KeyMotorData& keyMotorData_;
    const MotorDetailsData& motor0DetailsData_;
    const MotorDetailsData& motor1DetailsData_;
    const DriverControlsData& driverControlsData_;
    const MotorFaultsData& motorFaultsData_;
    const BatteryFaultsData& batteryFaultsData_;
    const BatteryData_json& batteryData_json_;
    const CmuData& cmuData_;
    const MpptData& mpptData_;
    const LightsData& lightsData_;
    View& view_;
};
