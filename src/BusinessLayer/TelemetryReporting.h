#pragma once

#include <QObject>
#include <initializer_list>

#include "gtest/gtest_prod.h"

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

class TelemetryReporting : public QObject
{
    Q_OBJECT
public:
    TelemetryReporting(I_CommunicationService& commService,
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

//friend class ::TelemetryReportingTest;

private slots:
	FRIEND_TEST(TelemetryReportingTest, sendKeyMotorTest);
    void sendKeyMotor();
    FRIEND_TEST(TelemetryReportingTest, sendMotorDetailsTest);
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
    FRIEND_TEST(TelemetryReportingTest, StuffDataTest);
    unsigned int stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData);
    void addChecksum(unsigned char* data, unsigned int length);
    FRIEND_TEST(TelemetryReportingTest, writeFloatIntoArrayTest);
    void writeFloatIntoArray(unsigned char* data, int index, const float& value);
    void writeShortIntoArray(unsigned char* data, int index, const short& value);
    void writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value);
    FRIEND_TEST(TelemetryReportingTest, writeBoolsIntoArrayTest);
    void writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues);

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
