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
class CommunicationService;
class QIODevice;
class View;

class TelemetryReporting : public QObject
{
    Q_OBJECT
public:
    TelemetryReporting(CommunicationService& commService,
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
    unsigned int frameData(const unsigned char* dataToEncode, unsigned long length, unsigned char* frameData);
    unsigned int stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData);
    void addChecksum(unsigned char* data, unsigned int length);
    void writeFloatIntoArray(unsigned char* data, int index, const float& value);
    void writeShortIntoArray(unsigned char* data, int index, const short& value);
    void writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value);
    void writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues);

private:
    CommunicationService& communicationService_;
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
