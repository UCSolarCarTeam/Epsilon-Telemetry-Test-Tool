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
class SerialView;

class SerialReporting : public QObject
{
    Q_OBJECT
public:
    SerialReporting(I_CommunicationService& commService,
                    const KeyMotorData& keyMotorData_,
                    const MotorDetailsData& motor0DetailsData_,
                    const MotorDetailsData& motor1DetailsData_,
                    const DriverControlsData& driverControlsData_,
                    const MotorFaultsData& motorFaultsData_,
                    const BatteryFaultsData& batteryFaultsData_,
                    const BatteryData& batteryData_,
                    const MpptData& mpptData_,
                    const LightsData& lightsData_,
                    SerialView& view);

private slots:
    void sendKeyMotor();
    void sendMotorDetails(int n);
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendMppt();
    void sendLights();
    void sendAll();

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
    SerialView& view_;
};
