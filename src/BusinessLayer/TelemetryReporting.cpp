/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include <QIODevice>
#include <CcsDefines.h>
#include <CrcCalculator.h>
#include <TelemetryReporting.h>
#include <VehicleData.h>
#include <CommunicationService.h>
#include <View.h>

union FloatDataUnion
{
    float floatData;
    char charData[4];
};

namespace
{
// These lengths only include the data. Not the checksum
const KEY_MOTOR_LENGTH = 43;
const MOTOR_DETAILS_LENGTH = 69;
const DRIVER_CONTROLS_LENGTH = 10;
const MOTOR_FAULTS_LENGTH = 9;
const BATTERY_FAULTS_LENGTH = 3;
const BATTERY_LENGTH = 60;
const CMU_LENGTH = 50;
const MPPT_LENGTH = 10;
const LIGHTS_LENGTH = 2;

const unsigned int CHECKSUM_LENGTH = 2;
const unsigned int FRAMING_LENGTH_INCREASE = 5;
const unsigned char TERMINATING_BYTE = 0x00;
}

TelemetryReporting::TelemetryReporting(CommunicationService& commService,
                                       KeyMotorData& keyMotorData,
                                       MotorDetailsData& motorDetailsData,
                                       DriverControlsData& driverControlsData,
                                       MotorFaultsData& motorFaultsData,
                                       BatteryFaultsData& batteryFaultsData,
                                       BatteryData& batteryData,
                                       CmuData& cmuData,
                                       MpptData& mpptData,
                                       LightsData& lightsData,
                                       View& view)
    : communicationService_(commService)
    , keyMotorData_(keyMotorData)
    , motorDetailsData_(motorDetailsData)
    , driverControlsData_(driverControlsData)
    , motorFaultsData_(motorFaultsData)
    , batteryFaultsData_(batteryFaultsData)
    , batteryData_(batteryData)
    , cmuData_(cmuData)
    , mpptData_(mpptData)
    , lightsData_(lightsData)
    , view_(view)
{
    //Connect slots to View Signals
    connect(&view_, SIGNAL(sendKeyMotor()), this SLOT(sendKeyMotor()));
    connect(&view_, SIGNAL(sendMotorDetails()), this SLOT(sendMotorDetails()));
    connect(&view_, SIGNAL(sendDriverControls()), this SLOT(sendDriverControls()));
    connect(&view_, SIGNAL(sendMotorFaults()), this SLOT(sendMotorFaults()));
    connect(&view_, SIGNAL(sendBatteryFaults()), this SLOT(sendBatteryFaults()));
    connect(&view_, SIGNAL(sendBattery()), this SLOT(sendBattery()));
    connect(&view_, SIGNAL(sendCmu()), this SLOT(sendCmu()));
    connect(&view_, SIGNAL(sendMppt()), this SLOT(sendMppt()));
    connect(&view_, SIGNAL(sendLights()), this SLOT(sendLights()));
    connect(&view_, SIGNAL(sendAll()), this SLOT(sendAll()));
}

// void TelemetryReporting::sendKeyDriverControlTelemetry()
// {
//     const unsigned int unframedPacketLength = KEY_DRIVER_CONTROL_LENGTH + CHECKSUM_LENGTH;
//     unsigned char packetPayload[unframedPacketLength];
//     packetPayload[0] = KEY_DRIVER_CONTROL_ID;
//     const float driverSetSpeedMps = vehicleData_.driverSetSpeedRpm * CcsDefines::RPM_TO_MPS_CONVERSION;
//     writeFloatIntoArray(packetPayload, 1, driverSetSpeedMps);
//     writeFloatIntoArray(packetPayload, 5, vehicleData_.driverSetCurrent);
//     writeFloatIntoArray(packetPayload, 9, vehicleData_.busCurrent);
//     writeFloatIntoArray(packetPayload, 13, vehicleData_.busVoltage);
//     writeFloatIntoArray(packetPayload, 17, vehicleData_.vehicleVelocity);

//     addChecksum(packetPayload, KEY_DRIVER_CONTROL_LENGTH);
//     unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
//     unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
//     communicationService_.sendData(packet, packetLength);
// }

void TelemetryReporting::sendKeyMotor()
{
    
}

void TelemetryReporting::sendMotorDetails()
{
    
}

void TelemetryReporting::sendDriverControls()
{
    
}

void TelemetryReporting::sendMotorFaults()
{
    
}

void TelemetryReporting::sendBatteryFaults()
{
    
}

void TelemetryReporting::sendBattery()
{
    
}

void TelemetryReporting::sendCmu()
{
    
}

void TelemetryReporting::sendMppt()
{
    
}

void TelemetryReporting::sendLights()
{
    
}

void TelemetryReporting::sendAll()
{
    sendKeyMotor();
    sendMotorDetails();
    sendDriverControls();
    sendMotorFaults();
    sendBatteryFaults();
    sendBattery();
    sendCmu();
    sendMppt();
    sendLights();
}

unsigned int TelemetryReporting::frameData(const unsigned char* dataToEncode, unsigned long length, unsigned char* frameData)
{
    unsigned int lengthOfFramedData = stuffData(dataToEncode, length, frameData);
    frameData[lengthOfFramedData++] = TERMINATING_BYTE;
    return lengthOfFramedData;
}

#define FINISH_BLOCK(X) \
{\
   *code_ptr = (X); \
   code_ptr = encodedData++; \
   code = 0x01; \
}

unsigned int TelemetryReporting::stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData)
{
    unsigned int lengthOfEncodedData = length + 1;
    const unsigned char* end = dataToEncode + length;
    unsigned char* code_ptr = encodedData++;
    unsigned char code = 0x01;

    while (dataToEncode < end)
    {
        if (*dataToEncode == 0)
        {
            FINISH_BLOCK(code);
        }
        else
        {
            *encodedData++ = *dataToEncode;
            code++;
            if (code == 0xFF)
            {
                FINISH_BLOCK(code);
                lengthOfEncodedData++;
            }
        }
        dataToEncode++;
    }
    FINISH_BLOCK(code);
    return lengthOfEncodedData;
}
#undef FINISH_BLOCK

void TelemetryReporting::addChecksum(unsigned char* data, unsigned int length)
{
    unsigned short crc16 = CrcCalculator::calculateCrc16(data, length);
    data[length] = static_cast<unsigned char>(0xFF & crc16);
    data[length + 1] = static_cast<unsigned char>(0xFF & (crc16 >> 8));
}

void TelemetryReporting::writeFloatIntoArray(unsigned char* data, int index, const float& value)
{
    FloatDataUnion floatDataUnion;
    floatDataUnion.floatData = value;
    data[index++] = floatDataUnion.charData[0];
    data[index++] = floatDataUnion.charData[1];
    data[index++] = floatDataUnion.charData[2];
    data[index] = floatDataUnion.charData[3];
}
