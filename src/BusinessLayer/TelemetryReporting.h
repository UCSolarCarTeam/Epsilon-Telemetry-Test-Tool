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
                       KeyMotorData& keyMotorData_,
                       MotorDetailsData& motor0DetailsData_,
                       MotorDetailsData& motor1DetailsData_,
                       DriverControlsData& driverControlsData_,
                       MotorFaultsData& motorFaultsData_,
                       BatteryFaultsData& batteryFaultsData_,
                       BatteryData& batteryData_,
                       CmuData& cmuData_,
                       MpptData& mpptData_,
                       LightsData& lightsData_,
                       View& view);

private slots:
    void sendKeyMotor();
    void sendMotor0Details();
    void sendMotor1Details();
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
    KeyMotorData& keyMotorData_;
    MotorDetailsData& motor0DetailsData_;
    MotorDetailsData& motor1DetailsData_;
    DriverControlsData& driverControlsData_;
    MotorFaultsData& motorFaultsData_;
    BatteryFaultsData& batteryFaultsData_;
    BatteryData& batteryData_;
    CmuData& cmuData_;
    MpptData& mpptData_;
    LightsData& lightsData_;
    View& view_;
};
