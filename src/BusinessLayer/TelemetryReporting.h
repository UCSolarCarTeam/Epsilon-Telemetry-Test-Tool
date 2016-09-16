#pragma once

#include <QObject>

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
                       VehicleData& vehicleData,
                       View& view);

private slots:
    void sendKeyMotor();
    void sendMotorDetails();
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

private:
    CommunicationService& communicationService_;
    KeyMotorData& keyMotorData_;
    MotorDetailsData& motorDetailsData_;
    DriverControlsData& driverControlsData_;
    MotorFaultsData& motorFaultsData_;
    BatteryFaultsData& batteryFaultsData_;
    BatteryData& batteryData_;
    CmuData& cmuData_;
    MpptData& mpptData_;
    LightsData& lightsDa_;
    View& view_;
};
