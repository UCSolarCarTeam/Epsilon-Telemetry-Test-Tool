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
class I_CommunicationService;
class QIODevice;
class View;

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
    View& view_;
};
