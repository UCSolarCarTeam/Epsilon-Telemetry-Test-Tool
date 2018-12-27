#include <cstring>
#include <vector>

#include "AuxBmsData.h"
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
#include "DataContainer.h"

namespace
{
// Refer to https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0
// These lengths only include the data. Not the checksum
    const int KEY_MOTOR_LENGTH = 43;
    const int MOTOR_DETAILS_LENGTH = 65;
    const int DRIVER_CONTROLS_LENGTH = 9;
    const int MOTOR_FAULTS_LENGTH = 9;
    const int BATTERY_FAULTS_LENGTH = 6;
    const int BATTERY_LENGTH = 48;
    const int MPPT_LENGTH = 10;
    const int LIGHTS_LENGTH = 3;
    const int AUX_BMS_LENGTH = 8;

    const int ONES_TO_MILLI = 1000;
    const int ONES_TO_CENTI = 100;

}

using namespace Util;

SerialReporting::SerialReporting(I_CommunicationService& commService,
                                 DataContainer& dataContainer0,
                                 DataContainer& dataContainer1,
                                 SerialView& view)
    : communicationService_(commService)
    , view_(view)
    , packetNum(0)
{
    dataContainerList.push_back(&dataContainer0);
    dataContainerList.push_back(&dataContainer1);
    //Connect slots to SerialView Signals
    connect(&view_, SIGNAL(sendKeyMotor()), this, SLOT(sendKeyMotor()));
    connect(&view_, SIGNAL(sendMotorDetails(int)), this, SLOT(sendMotorDetails(int)));
    connect(&view_, SIGNAL(sendDriverControls()), this, SLOT(sendDriverControls()));
    connect(&view_, SIGNAL(sendMotorFaults()), this, SLOT(sendMotorFaults()));
    connect(&view_, SIGNAL(sendBatteryFaults()), this, SLOT(sendBatteryFaults()));
    connect(&view_, SIGNAL(sendBattery()), this, SLOT(sendBattery()));
    connect(&view_, SIGNAL(sendMppt()), this, SLOT(sendMppt()));
    connect(&view_, SIGNAL(sendLights()), this, SLOT(sendLights()));
    connect(&view_, SIGNAL(sendAuxBms()), this, SLOT(sendAuxBms()));
    connect(&view_, SIGNAL(sendAll()), this, SLOT(sendAll()));
}

void SerialReporting::sendKeyMotor()
{
    const unsigned int unframedPacketLength = KEY_MOTOR_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    bool motor0AliveArray[] = {dataContainerList[packetNum]->getKeyMotorData().motor0Alive()};
    writeBoolsIntoArray(packetPayload, 1, motor0AliveArray, 1);
    writeFloatIntoArray(packetPayload, 2, dataContainerList[packetNum]->getKeyMotorData().motor0SetCurrent());
    writeFloatIntoArray(packetPayload, 6, dataContainerList[packetNum]->getKeyMotorData().motor0SetVelocity());
    writeFloatIntoArray(packetPayload, 10, dataContainerList[packetNum]->getKeyMotorData().motor0BusCurrent());
    writeFloatIntoArray(packetPayload, 14, dataContainerList[packetNum]->getKeyMotorData().motor0BusVoltage());
    writeFloatIntoArray(packetPayload, 18, dataContainerList[packetNum]->getKeyMotorData().motor0VehicleVelocity());
    bool motor1AliveArray[] = {dataContainerList[packetNum]->getKeyMotorData().motor1Alive()};
    writeBoolsIntoArray(packetPayload, 22, motor1AliveArray, 1);
    writeFloatIntoArray(packetPayload, 23, dataContainerList[packetNum]->getKeyMotorData().motor1SetCurrent());
    writeFloatIntoArray(packetPayload, 27, dataContainerList[packetNum]->getKeyMotorData().motor1SetVelocity());
    writeFloatIntoArray(packetPayload, 31, dataContainerList[packetNum]->getKeyMotorData().motor1BusCurrent());
    writeFloatIntoArray(packetPayload, 35, dataContainerList[packetNum]->getKeyMotorData().motor1BusVoltage());
    writeFloatIntoArray(packetPayload, 39, dataContainerList[packetNum]->getKeyMotorData().motor1VehicleVelocity());
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
        writeFloatIntoArray(packetPayload, 1, dataContainerList[packetNum]->getMotor0DetailsData().phaseCCurrent());
        writeFloatIntoArray(packetPayload, 5, dataContainerList[packetNum]->getMotor0DetailsData().phaseBCurrent());
        writeFloatIntoArray(packetPayload, 9, dataContainerList[packetNum]->getMotor0DetailsData().MotorVoltageReal());
        writeFloatIntoArray(packetPayload, 13, dataContainerList[packetNum]->getMotor0DetailsData().MotorVoltageImaginary());
        writeFloatIntoArray(packetPayload, 17, dataContainerList[packetNum]->getMotor0DetailsData().MotorCurrentReal());
        writeFloatIntoArray(packetPayload, 21, dataContainerList[packetNum]->getMotor0DetailsData().MotorCurrentImaginary());
        writeFloatIntoArray(packetPayload, 25, dataContainerList[packetNum]->getMotor0DetailsData().BackEmf());
        writeFloatIntoArray(packetPayload, 29, dataContainerList[packetNum]->getMotor0DetailsData().RailSupply15V());
        writeFloatIntoArray(packetPayload, 33, dataContainerList[packetNum]->getMotor0DetailsData().RailSupply3V());
        writeFloatIntoArray(packetPayload, 37, dataContainerList[packetNum]->getMotor0DetailsData().RailSupply1V());
        writeFloatIntoArray(packetPayload, 41, dataContainerList[packetNum]->getMotor0DetailsData().heatSinkTemperature());
        writeFloatIntoArray(packetPayload, 45, dataContainerList[packetNum]->getMotor0DetailsData().motorTemperature());
        writeFloatIntoArray(packetPayload, 49, dataContainerList[packetNum]->getMotor0DetailsData().dspBoardTemperature());
        writeFloatIntoArray(packetPayload, 53, dataContainerList[packetNum]->getMotor0DetailsData().dcBusAmpHours());
        writeFloatIntoArray(packetPayload, 57, dataContainerList[packetNum]->getMotor0DetailsData().odometer());
        writeFloatIntoArray(packetPayload, 61, dataContainerList[packetNum]->getMotor0DetailsData().slipSpeed());
    }
    else
    {
        packetPayload[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
        writeFloatIntoArray(packetPayload, 1, dataContainerList[packetNum]->getMotor1DetailsData().phaseCCurrent());
        writeFloatIntoArray(packetPayload, 5, dataContainerList[packetNum]->getMotor1DetailsData().phaseBCurrent());
        writeFloatIntoArray(packetPayload, 9, dataContainerList[packetNum]->getMotor1DetailsData().MotorVoltageReal());
        writeFloatIntoArray(packetPayload, 13, dataContainerList[packetNum]->getMotor1DetailsData().MotorVoltageImaginary());
        writeFloatIntoArray(packetPayload, 17, dataContainerList[packetNum]->getMotor1DetailsData().MotorCurrentReal());
        writeFloatIntoArray(packetPayload, 21, dataContainerList[packetNum]->getMotor1DetailsData().MotorCurrentImaginary());
        writeFloatIntoArray(packetPayload, 25, dataContainerList[packetNum]->getMotor1DetailsData().BackEmf());
        writeFloatIntoArray(packetPayload, 29, dataContainerList[packetNum]->getMotor1DetailsData().RailSupply15V());
        writeFloatIntoArray(packetPayload, 33, dataContainerList[packetNum]->getMotor1DetailsData().RailSupply3V());
        writeFloatIntoArray(packetPayload, 37, dataContainerList[packetNum]->getMotor1DetailsData().RailSupply1V());
        writeFloatIntoArray(packetPayload, 41, dataContainerList[packetNum]->getMotor1DetailsData().heatSinkTemperature());
        writeFloatIntoArray(packetPayload, 45, dataContainerList[packetNum]->getMotor1DetailsData().motorTemperature());
        writeFloatIntoArray(packetPayload, 49, dataContainerList[packetNum]->getMotor1DetailsData().dspBoardTemperature());
        writeFloatIntoArray(packetPayload, 53, dataContainerList[packetNum]->getMotor1DetailsData().dcBusAmpHours());
        writeFloatIntoArray(packetPayload, 57, dataContainerList[packetNum]->getMotor1DetailsData().odometer());
        writeFloatIntoArray(packetPayload, 61, dataContainerList[packetNum]->getMotor1DetailsData().slipSpeed());
    }

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
    bool aliveArray[] = {dataContainerList[packetNum]->getDriverControlsData().alive()};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool lightsArray[] = {dataContainerList[packetNum]->getDriverControlsData().headlightsOff(),
                          dataContainerList[packetNum]->getDriverControlsData().headlightsLow(),
                          dataContainerList[packetNum]->getDriverControlsData().headlightsHigh(),
                          dataContainerList[packetNum]->getDriverControlsData().signalRight(),
                          dataContainerList[packetNum]->getDriverControlsData().signalLeft(),
                          dataContainerList[packetNum]->getDriverControlsData().hazardLights(),
                          dataContainerList[packetNum]->getDriverControlsData().interiorLights()
                         };
    writeBoolsIntoArray(packetPayload, 2, lightsArray, 7);
    bool musicArray[] = {dataContainerList[packetNum]->getDriverControlsData().volumeUp(),
                         dataContainerList[packetNum]->getDriverControlsData().volumeDown(),
                         dataContainerList[packetNum]->getDriverControlsData().nextSong(),
                         dataContainerList[packetNum]->getDriverControlsData().prevSong()
                        };
    writeBoolsIntoArray(packetPayload, 3, musicArray, 4);
    writeUShortIntoArray(packetPayload, 4, dataContainerList[packetNum]->getDriverControlsData().acceleration());
    writeUShortIntoArray(packetPayload, 6, dataContainerList[packetNum]->getDriverControlsData().regenBraking());
    bool controlsArray[] = {dataContainerList[packetNum]->getDriverControlsData().brakes(),
                            dataContainerList[packetNum]->getDriverControlsData().forward(),
                            dataContainerList[packetNum]->getDriverControlsData().reverse(),
                            dataContainerList[packetNum]->getDriverControlsData().pushToTalk(),
                            dataContainerList[packetNum]->getDriverControlsData().horn(),
                            dataContainerList[packetNum]->getDriverControlsData().reset(),
                            dataContainerList[packetNum]->getDriverControlsData().aux()
                           };
    writeBoolsIntoArray(packetPayload, 8, controlsArray, 7);
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
    bool motor0FaultsArray[] = {dataContainerList[packetNum]->getMotorFaultsData().motor0OverSpeed(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0SoftwareOverCurrent(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0DcBusOverVoltage(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0BadMotorPositionHallSequence(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0WatchdogCausedLastReset(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0ConfigReadError(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0Rail15VUnderVoltageLockOut(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0DesaturationFault()
                               };
    writeBoolsIntoArray(packetPayload, 1, motor0FaultsArray, 8);
    bool motor1FaultsArray[] = {dataContainerList[packetNum]->getMotorFaultsData().motor1OverSpeed(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1SoftwareOverCurrent(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1DcBusOverVoltage(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1BadMotorPositionHallSequence(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1WatchdogCausedLastReset(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1ConfigReadError(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1Rail15VUnderVoltageLockOut(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1DesaturationFault()
                               };
    writeBoolsIntoArray(packetPayload, 2, motor1FaultsArray, 8);
    bool motor0LimitsArray[] = {dataContainerList[packetNum]->getMotorFaultsData().motor0OutputVoltagePwmLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0MotorCurrentLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0VelocityLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0BusCurrentLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0BusVoltageUpperLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0BusVoltageLowerLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor0IpmOrMotorTemperatureLimit()
                               };
    writeBoolsIntoArray(packetPayload, 3, motor0LimitsArray, 7);
    bool motor1LimitsArray[] = {dataContainerList[packetNum]->getMotorFaultsData().motor1OutputVoltagePwmLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1MotorCurrentLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1VelocityLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1BusCurrentLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1BusVoltageUpperLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1BusVoltageLowerLimit(),
                                dataContainerList[packetNum]->getMotorFaultsData().motor1IpmOrMotorTemperatureLimit()
                               };
    writeBoolsIntoArray(packetPayload, 4, motor1LimitsArray, 7);
    packetPayload[5] = dataContainerList[packetNum]->getMotorFaultsData().motor0RxErrorCount();
    packetPayload[6] = dataContainerList[packetNum]->getMotorFaultsData().motor0TxErrorCount();
    packetPayload[7] = dataContainerList[packetNum]->getMotorFaultsData().motor1RxErrorCount();
    packetPayload[8] = dataContainerList[packetNum]->getMotorFaultsData().motor1TxErrorCount();
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
    bool errorFlagsArray[] = {dataContainerList[packetNum]->getBatteryFaultsData().internalCommFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().internalConversionFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().weakCellFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().lowCellVoltageFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().openWiringFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().currentSensorFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().packVoltageSensorFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().weakPackFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().voltageRedundancyFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().fanMonitorFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().thermistorFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().canbusCommsFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().alwaysOnSupplyFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().highVoltageIsolationFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().powerSupplyFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().chargeLimitFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dischargeLimitFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().chargerSafetyRelayFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().internalMemFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().internalThermistorFault(),
                              dataContainerList[packetNum]->getBatteryFaultsData().internalLogicFault()
                             };
    writeBoolsIntoArray(packetPayload, 1, errorFlagsArray, 21);
    bool limitFlagsArray[] = {dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowSoc(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dclReducedHighCellResist(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dclReducedDueToTemp(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowCellVoltage(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowPackVoltage(),
                              CcsDefines::NO_DATA,
                              dataContainerList[packetNum]->getBatteryFaultsData().dclCclReducedVoltageFailsafe(),
                              dataContainerList[packetNum]->getBatteryFaultsData().dclCclReducedCommsFailsafe(),
                              CcsDefines::NO_DATA,
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighSoc(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighCellResist(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedDueToTemp(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighCellVoltage(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighPackVoltage(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedChargerLatch(),
                              dataContainerList[packetNum]->getBatteryFaultsData().cclReducedACLimit()
                             };
    writeBoolsIntoArray(packetPayload, 4, limitFlagsArray, 16);
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
    bool aliveArray[] = {dataContainerList[packetNum]->getBatteryData().alive()};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool bmsRelayStatusArray[] = {dataContainerList[packetNum]->getBatteryData().dischargeRelayEnabled(),
                                  dataContainerList[packetNum]->getBatteryData().chargeRelayEnabled(),
                                  dataContainerList[packetNum]->getBatteryData().chargerSafetyEnabled(),
                                  dataContainerList[packetNum]->getBatteryData().malfunctionIndicatorActive(),
                                  dataContainerList[packetNum]->getBatteryData().multiPurposeInputSignalStatus(),
                                  dataContainerList[packetNum]->getBatteryData().alwaysOnSignalStatus(),
                                  dataContainerList[packetNum]->getBatteryData().isReadySignalStatus(),
                                  dataContainerList[packetNum]->getBatteryData().isChargingSignalStatus()
                                 };
    writeBoolsIntoArray(packetPayload, 2, bmsRelayStatusArray, 8);
    packetPayload[3] = dataContainerList[packetNum]->getBatteryData().populatedCells();
    writeFloatIntoArray(packetPayload, 4, dataContainerList[packetNum]->getBatteryData().inputVoltage12V());
    writeFloatIntoArray(packetPayload, 8, dataContainerList[packetNum]->getBatteryData().fanVoltage());
    writeFloatIntoArray(packetPayload, 12, dataContainerList[packetNum]->getBatteryData().packCurrent());
    writeFloatIntoArray(packetPayload, 16, dataContainerList[packetNum]->getBatteryData().packVoltage());
    writeFloatIntoArray(packetPayload, 20, dataContainerList[packetNum]->getBatteryData().packStateOfCharge());
    writeFloatIntoArray(packetPayload, 24, dataContainerList[packetNum]->getBatteryData().packAmpHours());
    writeFloatIntoArray(packetPayload, 28, dataContainerList[packetNum]->getBatteryData().packDepthOfDischarge());
    packetPayload[32] = dataContainerList[packetNum]->getBatteryData().highTemperature();
    packetPayload[33] = dataContainerList[packetNum]->getBatteryData().highThermistorId();
    packetPayload[34] = dataContainerList[packetNum]->getBatteryData().lowTemperature();
    packetPayload[35] = dataContainerList[packetNum]->getBatteryData().lowThermistorId();
    packetPayload[36] = dataContainerList[packetNum]->getBatteryData().averageTemperature();
    packetPayload[37] = dataContainerList[packetNum]->getBatteryData().internalTemperature();
    packetPayload[38] = dataContainerList[packetNum]->getBatteryData().fanSpeed();
    packetPayload[39] = dataContainerList[packetNum]->getBatteryData().requestedFanSpeed();
    writeUShortIntoArray(packetPayload, 40, dataContainerList[packetNum]->getBatteryData().lowCellVoltage());
    packetPayload[42] = dataContainerList[packetNum]->getBatteryData().lowCellVoltageId();
    writeUShortIntoArray(packetPayload, 43, dataContainerList[packetNum]->getBatteryData().highCellVoltage());
    packetPayload[45] = dataContainerList[packetNum]->getBatteryData().highCellVoltageId();
    writeUShortIntoArray(packetPayload, 46, dataContainerList[packetNum]->getBatteryData().averageCellVoltage());
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

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        writeUShortIntoArray(packetPayload, 2, dataContainerList[packetNum]->getMpptData().arrayVoltage(i) * ONES_TO_CENTI);
        writeUShortIntoArray(packetPayload, 4, dataContainerList[packetNum]->getMpptData().arrayCurrent(i) * ONES_TO_MILLI);
        writeUShortIntoArray(packetPayload, 6, dataContainerList[packetNum]->getMpptData().batteryVoltage(i) * ONES_TO_CENTI);
        writeUShortIntoArray(packetPayload, 8, dataContainerList[packetNum]->getMpptData().temperature(i) * ONES_TO_CENTI);
        unsigned char mpptPacketPayload[unframedPacketLength];
        std::memcpy(mpptPacketPayload, packetPayload, unframedPacketLength);
        unsigned char numberAndAlive = i & 0x03;

        if (dataContainerList[packetNum]->getMpptData().alive(i))
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
    bool lightsAliveArray[] = {dataContainerList[packetNum]->getLightsData().alive()};
    writeBoolsIntoArray(packetPayload, 1, lightsAliveArray, 1);
    bool lightsArray[] = {dataContainerList[packetNum]->getLightsData().lowBeams(),
                          dataContainerList[packetNum]->getLightsData().highBeams(),
                          dataContainerList[packetNum]->getLightsData().brakes(),
                          dataContainerList[packetNum]->getLightsData().leftSignal(),
                          dataContainerList[packetNum]->getLightsData().rightSignal(),
                          dataContainerList[packetNum]->getLightsData().bmsStrobeLight()
                         };
    writeBoolsIntoArray(packetPayload, 2, lightsArray, 6);
    addChecksum(packetPayload, LIGHTS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendSerialData(packet, packetLength);
}

void SerialReporting::sendAuxBms()
{
    const unsigned int unframedPacketLength = AUX_BMS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::AUX_BMS_PKG_ID;
    packetPayload[1] = (unsigned char)dataContainerList[packetNum]->getAuxBmsData().prechargeState();
    packetPayload[2] = dataContainerList[packetNum]->getAuxBmsData().auxVoltage();
    bool auxBmsAliveArray[] = {dataContainerList[packetNum]->getAuxBmsData().auxBmsAlive()};
    writeBoolsIntoArray(packetPayload, 3, auxBmsAliveArray, 1);
    bool strobeBmsLightArray[] = {dataContainerList[packetNum]->getAuxBmsData().strobeBmsLight()};
    writeBoolsIntoArray(packetPayload, 4, strobeBmsLightArray, 1);
    bool allowChargeArray[] = {dataContainerList[packetNum]->getAuxBmsData().allowCharge()};
    writeBoolsIntoArray(packetPayload, 5, allowChargeArray, 1);
    bool contactorErrorArray[] = {dataContainerList[packetNum]->getAuxBmsData().contactorError()};
    writeBoolsIntoArray(packetPayload, 6, contactorErrorArray, 1);
    bool highVoltageEnableArray[] = {dataContainerList[packetNum]->getAuxBmsData().highVoltageEnable()};
    writeBoolsIntoArray(packetPayload, 7, highVoltageEnableArray, 1);
    addChecksum(packetPayload, AUX_BMS_LENGTH);
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
    sendAuxBms();
}

void SerialReporting::switchPacket()
{
    if (packetNum == 0)
    {
        packetNum = 1;
        view_.setPacketText(false);
    }
    else
    {
        packetNum = 0;
        view_.setPacketText(true);
    }
}
