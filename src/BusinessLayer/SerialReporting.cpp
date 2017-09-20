#include <cstring>

#include "CcsDefines.h"
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "DriverControlsData.h"
#include "I_CommunicationService.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "SerialReporting.h"
#include "Util.h"
#include "SerialView.h"

namespace
{
// Refer to https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0
// These lengths only include the data. Not the checksum
    const int KEY_MOTOR_LENGTH = 47;
    const int MOTOR_DETAILS_LENGTH = 73;
    const int DRIVER_CONTROLS_LENGTH = 13;
    const int MOTOR_FAULTS_LENGTH = 13;
    const int BATTERY_FAULTS_LENGTH = 11;
    const int BATTERY_LENGTH = 55;
    const int MPPT_LENGTH = 14;
    const int LIGHTS_LENGTH = 7;
}

using namespace Util;

SerialReporting::SerialReporting(I_CommunicationService& commService,
                                 const KeyMotorData& keyMotorData,
                                 const MotorDetailsData& motor0DetailsData,
                                 const MotorDetailsData& motor1DetailsData,
                                 const DriverControlsData& driverControlsData,
                                 const MotorFaultsData& motorFaultsData,
                                 const BatteryFaultsData& batteryFaultsData,
                                 const BatteryData& batteryData,
                                 const MpptData& mpptData,
                                 const LightsData& lightsData,
                                 SerialView& view)
    : communicationService_(commService)
    , keyMotorData_(keyMotorData)
    , motor0DetailsData_(motor0DetailsData)
    , motor1DetailsData_(motor1DetailsData)
    , driverControlsData_(driverControlsData)
    , motorFaultsData_(motorFaultsData)
    , batteryFaultsData_(batteryFaultsData)
    , batteryData_(batteryData)
    , mpptData_(mpptData)
    , lightsData_(lightsData)
    , view_(view)
{
    //Connect slots to SerialView Signals
    connect(&view_, SIGNAL(sendKeyMotor()), this, SLOT(sendKeyMotor()));
    connect(&view_, SIGNAL(sendMotorDetails(int)), this, SLOT(sendMotorDetails(int)));
    connect(&view_, SIGNAL(sendDriverControls()), this, SLOT(sendDriverControls()));
    connect(&view_, SIGNAL(sendMotorFaults()), this, SLOT(sendMotorFaults()));
    connect(&view_, SIGNAL(sendBatteryFaults()), this, SLOT(sendBatteryFaults()));
    connect(&view_, SIGNAL(sendBattery()), this, SLOT(sendBattery()));
    connect(&view_, SIGNAL(sendMppt()), this, SLOT(sendMppt()));
    connect(&view_, SIGNAL(sendLights()), this, SLOT(sendLights()));
    connect(&view_, SIGNAL(sendAll()), this, SLOT(sendAll()));
}

void SerialReporting::sendKeyMotor()
{
    const unsigned int unframedPacketLength = KEY_MOTOR_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    bool motor0AliveArray[] = {keyMotorData_.motor0Alive};
    writeBoolsIntoArray(packetPayload, 1, motor0AliveArray, 1);
    writeFloatIntoArray(packetPayload, 2, keyMotorData_.motor0SetCurrent);
    writeFloatIntoArray(packetPayload, 6, keyMotorData_.motor0SetVelocity);
    writeFloatIntoArray(packetPayload, 10, keyMotorData_.motor0BusCurrent);
    writeFloatIntoArray(packetPayload, 14, keyMotorData_.motor0BusVoltage);
    writeFloatIntoArray(packetPayload, 18, keyMotorData_.motor0VehicleVelocity);
    bool motor1AliveArray[] = {keyMotorData_.motor1Alive};
    writeBoolsIntoArray(packetPayload, 22, motor1AliveArray, 1);
    writeFloatIntoArray(packetPayload, 23, keyMotorData_.motor1SetCurrent);
    writeFloatIntoArray(packetPayload, 27, keyMotorData_.motor1SetVelocity);
    writeFloatIntoArray(packetPayload, 31, keyMotorData_.motor1BusCurrent);
    writeFloatIntoArray(packetPayload, 35, keyMotorData_.motor1BusVoltage);
    writeFloatIntoArray(packetPayload, 39, keyMotorData_.motor1VehicleVelocity);
    addChecksum(packetPayload, KEY_MOTOR_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendMotorDetails(int n)
{
    const unsigned int unframedPacketLength = MOTOR_DETAILS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    if (n == 0)
    {
        packetPayload[0] = CcsDefines::MOTOR_DETAILS_0_PKG_ID;
    }
    else
    {
        packetPayload[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
    }

    writeFloatIntoArray(packetPayload, 1, motor0DetailsData_.phaseCCurrent);
    writeFloatIntoArray(packetPayload, 5, motor0DetailsData_.phaseBCurrent);
    writeFloatIntoArray(packetPayload, 9, motor0DetailsData_.MotorVoltageReal);
    writeFloatIntoArray(packetPayload, 13, motor0DetailsData_.MotorVoltageImaginary);
    writeFloatIntoArray(packetPayload, 17, motor0DetailsData_.MotorCurrentReal);
    writeFloatIntoArray(packetPayload, 21, motor0DetailsData_.MotorCurrentImaginary);
    writeFloatIntoArray(packetPayload, 25, motor0DetailsData_.BackEmfReal);
    writeFloatIntoArray(packetPayload, 29, motor0DetailsData_.BackEmfImaginary);
    writeFloatIntoArray(packetPayload, 33, motor0DetailsData_.RailSupply15V);
    writeFloatIntoArray(packetPayload, 37, motor0DetailsData_.RailSupply3V);
    writeFloatIntoArray(packetPayload, 41, motor0DetailsData_.RailSupply1V);
    writeFloatIntoArray(packetPayload, 45, motor0DetailsData_.heatSinkTemperature);
    writeFloatIntoArray(packetPayload, 49, motor0DetailsData_.motorTemperature);
    writeFloatIntoArray(packetPayload, 53, motor0DetailsData_.dspBoardTempearture);
    writeFloatIntoArray(packetPayload, 57, motor0DetailsData_.dcBusAmpHours);
    writeFloatIntoArray(packetPayload, 61, motor0DetailsData_.odometer);
    writeFloatIntoArray(packetPayload, 65, motor0DetailsData_.slipSpeed);
    addChecksum(packetPayload, MOTOR_DETAILS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendDriverControls()
{
    const unsigned int unframedPacketLength = DRIVER_CONTROLS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::DRIVER_CONTROLS_PKG_ID;
    bool aliveArray[] = {driverControlsData_.alive};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool lightsArray[] = {driverControlsData_.headlightsOff,
                          driverControlsData_.headlightsLow,
                          driverControlsData_.headlightsHigh,
                          driverControlsData_.signalLeft,
                          driverControlsData_.signalRight,
                          driverControlsData_.hazardLights,
                          driverControlsData_.interiorLights
                         };
    writeBoolsIntoArray(packetPayload, 2, lightsArray, 7);
    bool musicArray[] = {driverControlsData_.musicAux,
                         driverControlsData_.volumeUp,
                         driverControlsData_.volumeDown,
                         driverControlsData_.nextSong,
                         driverControlsData_.prevSong
                        };
    writeBoolsIntoArray(packetPayload, 3, musicArray, 5);
    writeUShortIntoArray(packetPayload, 4, driverControlsData_.acceleration);
    writeUShortIntoArray(packetPayload, 6, driverControlsData_.regenBraking);
    bool controlsArray[] = {driverControlsData_.brakes,
                            driverControlsData_.forward,
                            driverControlsData_.reverse,
                            driverControlsData_.pushToTalk,
                            driverControlsData_.horn,
                            driverControlsData_.reset
                           };
    writeBoolsIntoArray(packetPayload, 8, controlsArray, 6);
    addChecksum(packetPayload, DRIVER_CONTROLS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendMotorFaults()
{
    const unsigned int unframedPacketLength = MOTOR_FAULTS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::MOTOR_FAULTS_PKG_ID;
    bool motor0FaultsArray[] = {motorFaultsData_.motor0OverSpeed,
                                motorFaultsData_.motor0SoftwareOverCurrent,
                                motorFaultsData_.motor0DcBusOverVoltage,
                                motorFaultsData_.motor0BadMootorPositionHallSequence,
                                motorFaultsData_.motor0WatchdogCausedLastReset,
                                motorFaultsData_.motor0ConfigReadError,
                                motorFaultsData_.motor0Rail15VUnderVoltageLockOut,
                                motorFaultsData_.motor0DesaturationFault
                               };
    writeBoolsIntoArray(packetPayload, 1, motor0FaultsArray, 8);
    bool motor1FaultsArray[] = {motorFaultsData_.motor1OverSpeed,
                                motorFaultsData_.motor1SoftwareOverCurrent,
                                motorFaultsData_.motor1DcBusOverVoltage,
                                motorFaultsData_.motor1BadMootorPositionHallSequence,
                                motorFaultsData_.motor1WatchdogCausedLastReset,
                                motorFaultsData_.motor1ConfigReadError,
                                motorFaultsData_.motor1Rail15VUnderVoltageLockOut,
                                motorFaultsData_.motor1DesaturationFault
                               };
    writeBoolsIntoArray(packetPayload, 2, motor1FaultsArray, 8);
    bool motor0LimitsArray[] = {motorFaultsData_.motor0OutputVoltagePwmLimit,
                                motorFaultsData_.motor0MotorCurrentLimit,
                                motorFaultsData_.motor0VelocityLimit,
                                motorFaultsData_.motor0BusCurrentLimit,
                                motorFaultsData_.motor0BusVoltageUpperLimit,
                                motorFaultsData_.motor0BusVoltageLowerLimit,
                                motorFaultsData_.motor0IpmOrMotorTemperatureLimit
                               };
    writeBoolsIntoArray(packetPayload, 3, motor0LimitsArray, 7);
    bool motor1LimitsArray[] = {motorFaultsData_.motor1OutputVoltagePwmLimit,
                                motorFaultsData_.motor1MotorCurrentLimit,
                                motorFaultsData_.motor1VelocityLimit,
                                motorFaultsData_.motor1BusCurrentLimit,
                                motorFaultsData_.motor1BusVoltageUpperLimit,
                                motorFaultsData_.motor1BusVoltageLowerLimit,
                                motorFaultsData_.motor1IpmOrMotorTemperatureLimit
                               };
    writeBoolsIntoArray(packetPayload, 4, motor1LimitsArray, 7);
    packetPayload[5] = motorFaultsData_.motor0RxErrorCount;
    packetPayload[6] = motorFaultsData_.motor0TxErrorCount;
    packetPayload[7] = motorFaultsData_.motor1RxErrorCount;
    packetPayload[8] = motorFaultsData_.motor1TxErrorCount;
    addChecksum(packetPayload, MOTOR_FAULTS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendBatteryFaults()
{
    const unsigned int unframedPacketLength = BATTERY_FAULTS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::BATTERY_FAULTS_PKG_ID;
    bool errorFlagsArray[] = {batteryFaultsData_.internalCommFault,
                              batteryFaultsData_.internalConversionFault,
                              batteryFaultsData_.weakCellFault,
                              batteryFaultsData_.lowCellVoltageFault,
                              batteryFaultsData_.openWiringFault,
                              batteryFaultsData_.currentSensorFault,
                              batteryFaultsData_.packVoltageSensorFault,
                              batteryFaultsData_.weakPackFault,
                              batteryFaultsData_.voltageRedundancyFault,
                              batteryFaultsData_.fanMonitorFault,
                              batteryFaultsData_.thermistorFault,
                              batteryFaultsData_.canbusCommsFault,
                              batteryFaultsData_.alwaysOnSupplyFault,
                              batteryFaultsData_.highVoltageIsolationFault,
                              batteryFaultsData_.powerSupplyFault,
                              batteryFaultsData_.chargeLimitFault,
                              batteryFaultsData_.dischargeLimitFault,
                              batteryFaultsData_.chargerSafetyRelayFault,
                              batteryFaultsData_.internalMemFault,
                              batteryFaultsData_.internalThermistorFault,
                              batteryFaultsData_.internalLogicFault
                             };
    writeBoolsIntoArray(packetPayload, 1, errorFlagsArray, 21);
    bool limitFlagsArray[] = {batteryFaultsData_.dclReducedLowSoc,
                              batteryFaultsData_.dclReducedHighCellResist,
                              batteryFaultsData_.dclReducedDueToTemp,
                              batteryFaultsData_.dclReducedLowCellVoltage,
                              batteryFaultsData_.dclReducedLowPackVoltage,
                              CcsDefines::NO_DATA,
                              batteryFaultsData_.dclCclReducedVoltageFailsafe,
                              batteryFaultsData_.dclCclReducedCommsFailsafe,
                              CcsDefines::NO_DATA,
                              batteryFaultsData_.cclReducedHighSoc,
                              batteryFaultsData_.cclReducedHighCellResist,
                              batteryFaultsData_.cclReducedDueToTemp,
                              batteryFaultsData_.cclReducedHighCellVoltage,
                              batteryFaultsData_.cclReducedHighPackVoltage,
                              batteryFaultsData_.cclReducedChargerLatch,
                              batteryFaultsData_.cclReducedACLimit
                             };
    writeBoolsIntoArray(packetPayload, 5, limitFlagsArray, 16);
    addChecksum(packetPayload, BATTERY_FAULTS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendBattery()
{
    const unsigned int unframedPacketLength = BATTERY_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::BATTERY_PKG_ID;
    bool aliveArray[] = {batteryData_.alive};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool bmsRelayStatusArray[] = {batteryData_.dischargeRelayEnabled,
                                  batteryData_.chargeRelayEnabled,
                                  batteryData_.chargerSafetyEnabled,
                                  batteryData_.malfunctionIndicatorActive,
                                  batteryData_.multiPurposeInputSignalStatus,
                                  batteryData_.alwaysOnSignalStatus,
                                  batteryData_.isReadySignalStatus,
                                  batteryData_.isChargingSignalStatus
                                 };
    writeBoolsIntoArray(packetPayload, 2, bmsRelayStatusArray, 8);
    packetPayload[3] = batteryData_.populatedCells;
    writeFloatIntoArray(packetPayload, 4, batteryData_.inputVoltage12V);
    writeFloatIntoArray(packetPayload, 8, batteryData_.fanVoltage);
    writeFloatIntoArray(packetPayload, 12, batteryData_.packCurrent);
    writeFloatIntoArray(packetPayload, 16, batteryData_.packVoltage);
    writeFloatIntoArray(packetPayload, 20, batteryData_.packStateOfCharge);
    writeFloatIntoArray(packetPayload, 24, batteryData_.packAmpHours);
    writeFloatIntoArray(packetPayload, 28, batteryData_.packDepthOfDischarge);
    packetPayload[32] = batteryData_.highTemperature;
    packetPayload[33] = batteryData_.highThermistorId;
    packetPayload[34] = batteryData_.lowTemperature;
    packetPayload[35] = batteryData_.lowThermistorId;
    packetPayload[36] = batteryData_.averageTemperature;
    packetPayload[37] = batteryData_.internalTemperature;
    packetPayload[38] = batteryData_.fanSpeed;
    packetPayload[39] = batteryData_.requestedFanSpeed;
    writeUShortIntoArray(packetPayload, 40, batteryData_.lowCellVoltage);
    packetPayload[42] = batteryData_.lowCellVoltageId;
    writeUShortIntoArray(packetPayload, 43, batteryData_.highCellVoltage);
    packetPayload[46] = batteryData_.highCellVoltageId;
    writeUShortIntoArray(packetPayload, 47, batteryData_.averageCellVoltage);
    packetPayload[49] = (unsigned char)batteryData_.prechargeState;
    packetPayload[50] = batteryData_.auxVoltage;
    bool auxBmsaliveArray[] = {batteryData_.auxBmsAlive};
    writeBoolsIntoArray(packetPayload, 51, auxBmsaliveArray, 1);
    addChecksum(packetPayload, BATTERY_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendMppt()
{
    const unsigned int unframedPacketLength = MPPT_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::MPPT_PKG_ID;
    writeUShortIntoArray(packetPayload, 2, mpptData_.arrayVoltage);
    writeUShortIntoArray(packetPayload, 4, mpptData_.arrayCurrent);
    writeUShortIntoArray(packetPayload, 6, mpptData_.batteryVoltage);
    writeUShortIntoArray(packetPayload, 8, mpptData_.temperature);

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        unsigned char mpptPacketPayload[unframedPacketLength];
        std::memcpy(mpptPacketPayload, packetPayload, unframedPacketLength);
        unsigned char numberAndAlive = i & 0x03;

        if (mpptData_.alive)
        {
            numberAndAlive |= 0x80;
        }

        mpptPacketPayload[1] = numberAndAlive;
        addChecksum(mpptPacketPayload, MPPT_LENGTH);
        unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
        unsigned int packetLength = frameData(mpptPacketPayload, unframedPacketLength, packet);
        communicationService_.sendSerialData(packet, packetLength);
    }
}

void SerialReporting::sendLights()
{
    const unsigned int unframedPacketLength = LIGHTS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::LIGHTS_PKG_ID;
    bool lightsArray[] = {lightsData_.lowBeams,
                          lightsData_.highBeams,
                          lightsData_.brakes,
                          lightsData_.leftSignal,
                          lightsData_.rightSignal,
                          lightsData_.bmsStrobeLight
                         };
    writeBoolsIntoArray(packetPayload, 1, lightsArray, 6);
    addChecksum(packetPayload, LIGHTS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendAll()
{
    sendKeyMotor();
    sendMotorDetails(0);
    sendMotorDetails(1);
    sendDriverControls();
    sendMotorFaults();
    sendBatteryFaults();
    sendBattery();
    sendMppt();
    sendLights();
}
