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
    , readTimer_(new QTimer())
    , forwardPeriod_(500)
    , sendContinuously_(false)
    , packetNum_(0)
{
    dataContainerList.push_back(&dataContainer0);
    dataContainerList.push_back(&dataContainer1);
    //Connect slots to SerialView Signals
    connect(&view_, SIGNAL(toggleSendContinuously()), this, SLOT(toggleSendContinuously()));
    connect(&view_, SIGNAL(sendAll()), this, SLOT(sendAll()));
    connect(&view_, SIGNAL(switchPacket()), this, SLOT(switchPacket()));
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(sendAll()));
    readTimer_->setInterval(forwardPeriod_);
}

void SerialReporting::toggleSendContinuously()
{
    sendContinuously_ = !sendContinuously_;

    if (sendContinuously_)
    {
        readTimer_->start();
    }
    else
    {
        readTimer_->stop();
    }

    view_.setSendContinuouslyText(sendContinuously_);
}

void SerialReporting::sendKeyMotor()
{
    const unsigned int unframedPacketLength = KEY_MOTOR_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];
    packetPayload[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    bool motor0AliveArray[] = {dataContainerList[packetNum_]->getKeyMotorData().motor0Alive()};
    writeBoolsIntoArray(packetPayload, 1, motor0AliveArray, 1);
    writeFloatIntoArray(packetPayload, 2, dataContainerList[packetNum_]->getKeyMotorData().motor0SetCurrent());
    writeFloatIntoArray(packetPayload, 6, dataContainerList[packetNum_]->getKeyMotorData().motor0SetVelocity());
    writeFloatIntoArray(packetPayload, 10, dataContainerList[packetNum_]->getKeyMotorData().motor0BusCurrent());
    writeFloatIntoArray(packetPayload, 14, dataContainerList[packetNum_]->getKeyMotorData().motor0BusVoltage());
    writeFloatIntoArray(packetPayload, 18, dataContainerList[packetNum_]->getKeyMotorData().motor0VehicleVelocity());
    bool motor1AliveArray[] = {dataContainerList[packetNum_]->getKeyMotorData().motor1Alive()};
    writeBoolsIntoArray(packetPayload, 22, motor1AliveArray, 1);
    writeFloatIntoArray(packetPayload, 23, dataContainerList[packetNum_]->getKeyMotorData().motor1SetCurrent());
    writeFloatIntoArray(packetPayload, 27, dataContainerList[packetNum_]->getKeyMotorData().motor1SetVelocity());
    writeFloatIntoArray(packetPayload, 31, dataContainerList[packetNum_]->getKeyMotorData().motor1BusCurrent());
    writeFloatIntoArray(packetPayload, 35, dataContainerList[packetNum_]->getKeyMotorData().motor1BusVoltage());
    writeFloatIntoArray(packetPayload, 39, dataContainerList[packetNum_]->getKeyMotorData().motor1VehicleVelocity());
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
        writeFloatIntoArray(packetPayload, 1, dataContainerList[packetNum_]->getMotor0DetailsData().phaseCCurrent());
        writeFloatIntoArray(packetPayload, 5, dataContainerList[packetNum_]->getMotor0DetailsData().phaseBCurrent());
        writeFloatIntoArray(packetPayload, 9, dataContainerList[packetNum_]->getMotor0DetailsData().MotorVoltageReal());
        writeFloatIntoArray(packetPayload, 13, dataContainerList[packetNum_]->getMotor0DetailsData().MotorVoltageImaginary());
        writeFloatIntoArray(packetPayload, 17, dataContainerList[packetNum_]->getMotor0DetailsData().MotorCurrentReal());
        writeFloatIntoArray(packetPayload, 21, dataContainerList[packetNum_]->getMotor0DetailsData().MotorCurrentImaginary());
        writeFloatIntoArray(packetPayload, 25, dataContainerList[packetNum_]->getMotor0DetailsData().BackEmf());
        writeFloatIntoArray(packetPayload, 29, dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply15V());
        writeFloatIntoArray(packetPayload, 33, dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply3V());
        writeFloatIntoArray(packetPayload, 37, dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply1V());
        writeFloatIntoArray(packetPayload, 41, dataContainerList[packetNum_]->getMotor0DetailsData().heatSinkTemperature());
        writeFloatIntoArray(packetPayload, 45, dataContainerList[packetNum_]->getMotor0DetailsData().motorTemperature());
        writeFloatIntoArray(packetPayload, 49, dataContainerList[packetNum_]->getMotor0DetailsData().dspBoardTemperature());
        writeFloatIntoArray(packetPayload, 53, dataContainerList[packetNum_]->getMotor0DetailsData().dcBusAmpHours());
        writeFloatIntoArray(packetPayload, 57, dataContainerList[packetNum_]->getMotor0DetailsData().odometer());
        writeFloatIntoArray(packetPayload, 61, dataContainerList[packetNum_]->getMotor0DetailsData().slipSpeed());
    }
    else
    {
        packetPayload[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
        writeFloatIntoArray(packetPayload, 1, dataContainerList[packetNum_]->getMotor1DetailsData().phaseCCurrent());
        writeFloatIntoArray(packetPayload, 5, dataContainerList[packetNum_]->getMotor1DetailsData().phaseBCurrent());
        writeFloatIntoArray(packetPayload, 9, dataContainerList[packetNum_]->getMotor1DetailsData().MotorVoltageReal());
        writeFloatIntoArray(packetPayload, 13, dataContainerList[packetNum_]->getMotor1DetailsData().MotorVoltageImaginary());
        writeFloatIntoArray(packetPayload, 17, dataContainerList[packetNum_]->getMotor1DetailsData().MotorCurrentReal());
        writeFloatIntoArray(packetPayload, 21, dataContainerList[packetNum_]->getMotor1DetailsData().MotorCurrentImaginary());
        writeFloatIntoArray(packetPayload, 25, dataContainerList[packetNum_]->getMotor1DetailsData().BackEmf());
        writeFloatIntoArray(packetPayload, 29, dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply15V());
        writeFloatIntoArray(packetPayload, 33, dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply3V());
        writeFloatIntoArray(packetPayload, 37, dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply1V());
        writeFloatIntoArray(packetPayload, 41, dataContainerList[packetNum_]->getMotor1DetailsData().heatSinkTemperature());
        writeFloatIntoArray(packetPayload, 45, dataContainerList[packetNum_]->getMotor1DetailsData().motorTemperature());
        writeFloatIntoArray(packetPayload, 49, dataContainerList[packetNum_]->getMotor1DetailsData().dspBoardTemperature());
        writeFloatIntoArray(packetPayload, 53, dataContainerList[packetNum_]->getMotor1DetailsData().dcBusAmpHours());
        writeFloatIntoArray(packetPayload, 57, dataContainerList[packetNum_]->getMotor1DetailsData().odometer());
        writeFloatIntoArray(packetPayload, 61, dataContainerList[packetNum_]->getMotor1DetailsData().slipSpeed());
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
    bool aliveArray[] = {dataContainerList[packetNum_]->getDriverControlsData().alive()};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool lightsArray[] = {dataContainerList[packetNum_]->getDriverControlsData().headlightsOff(),
                          dataContainerList[packetNum_]->getDriverControlsData().headlightsLow(),
                          dataContainerList[packetNum_]->getDriverControlsData().headlightsHigh(),
                          dataContainerList[packetNum_]->getDriverControlsData().signalRight(),
                          dataContainerList[packetNum_]->getDriverControlsData().signalLeft(),
                          dataContainerList[packetNum_]->getDriverControlsData().hazardLights(),
                          dataContainerList[packetNum_]->getDriverControlsData().interiorLights()
                         };
    writeBoolsIntoArray(packetPayload, 2, lightsArray, 7);
    bool musicArray[] = {dataContainerList[packetNum_]->getDriverControlsData().volumeUp(),
                         dataContainerList[packetNum_]->getDriverControlsData().volumeDown(),
                         dataContainerList[packetNum_]->getDriverControlsData().nextSong(),
                         dataContainerList[packetNum_]->getDriverControlsData().prevSong()
                        };
    writeBoolsIntoArray(packetPayload, 3, musicArray, 4);
    writeUShortIntoArray(packetPayload, 4, dataContainerList[packetNum_]->getDriverControlsData().acceleration());
    writeUShortIntoArray(packetPayload, 6, dataContainerList[packetNum_]->getDriverControlsData().regenBraking());
    bool controlsArray[] = {dataContainerList[packetNum_]->getDriverControlsData().brakes(),
                            dataContainerList[packetNum_]->getDriverControlsData().forward(),
                            dataContainerList[packetNum_]->getDriverControlsData().reverse(),
                            dataContainerList[packetNum_]->getDriverControlsData().pushToTalk(),
                            dataContainerList[packetNum_]->getDriverControlsData().horn(),
                            dataContainerList[packetNum_]->getDriverControlsData().reset(),
                            dataContainerList[packetNum_]->getDriverControlsData().aux(),
                            dataContainerList[packetNum_]->getDriverControlsData().lap()
                           };
    writeBoolsIntoArray(packetPayload, 8, controlsArray, 8);
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
    bool motor0FaultsArray[] = {dataContainerList[packetNum_]->getMotorFaultsData().motor0OverSpeed(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0SoftwareOverCurrent(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0DcBusOverVoltage(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0BadMotorPositionHallSequence(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0WatchdogCausedLastReset(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0ConfigReadError(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0Rail15VUnderVoltageLockOut(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0DesaturationFault()
                               };
    writeBoolsIntoArray(packetPayload, 1, motor0FaultsArray, 8);
    bool motor1FaultsArray[] = {dataContainerList[packetNum_]->getMotorFaultsData().motor1OverSpeed(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1SoftwareOverCurrent(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1DcBusOverVoltage(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1BadMotorPositionHallSequence(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1WatchdogCausedLastReset(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1ConfigReadError(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1Rail15VUnderVoltageLockOut(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1DesaturationFault()
                               };
    writeBoolsIntoArray(packetPayload, 2, motor1FaultsArray, 8);
    bool motor0LimitsArray[] = {dataContainerList[packetNum_]->getMotorFaultsData().motor0OutputVoltagePwmLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0MotorCurrentLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0VelocityLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0BusCurrentLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0BusVoltageUpperLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0BusVoltageLowerLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor0IpmOrMotorTemperatureLimit()
                               };
    writeBoolsIntoArray(packetPayload, 3, motor0LimitsArray, 7);
    bool motor1LimitsArray[] = {dataContainerList[packetNum_]->getMotorFaultsData().motor1OutputVoltagePwmLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1MotorCurrentLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1VelocityLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1BusCurrentLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1BusVoltageUpperLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1BusVoltageLowerLimit(),
                                dataContainerList[packetNum_]->getMotorFaultsData().motor1IpmOrMotorTemperatureLimit()
                               };
    writeBoolsIntoArray(packetPayload, 4, motor1LimitsArray, 7);
    packetPayload[5] = dataContainerList[packetNum_]->getMotorFaultsData().motor0RxErrorCount();
    packetPayload[6] = dataContainerList[packetNum_]->getMotorFaultsData().motor0TxErrorCount();
    packetPayload[7] = dataContainerList[packetNum_]->getMotorFaultsData().motor1RxErrorCount();
    packetPayload[8] = dataContainerList[packetNum_]->getMotorFaultsData().motor1TxErrorCount();
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
    bool errorFlagsArray[] = {dataContainerList[packetNum_]->getBatteryFaultsData().internalCommFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().internalConversionFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().weakCellFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().lowCellVoltageFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().openWiringFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().currentSensorFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().packVoltageSensorFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().weakPackFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().voltageRedundancyFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().fanMonitorFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().thermistorFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().canbusCommsFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().alwaysOnSupplyFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().highVoltageIsolationFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().powerSupplyFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().chargeLimitFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dischargeLimitFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().chargerSafetyRelayFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().internalMemFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().internalThermistorFault(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().internalLogicFault()
                             };
    writeBoolsIntoArray(packetPayload, 1, errorFlagsArray, 21);
    bool limitFlagsArray[] = {dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowSoc(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedHighCellResist(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedDueToTemp(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowCellVoltage(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowPackVoltage(),
                              CcsDefines::NO_DATA,
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclCclReducedVoltageFailsafe(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().dclCclReducedCommsFailsafe(),
                              CcsDefines::NO_DATA,
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighSoc(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighCellResist(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedDueToTemp(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighCellVoltage(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighPackVoltage(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedChargerLatch(),
                              dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedACLimit()
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
    bool aliveArray[] = {dataContainerList[packetNum_]->getBatteryData().alive()};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    bool bmsRelayStatusArray[] = {dataContainerList[packetNum_]->getBatteryData().dischargeRelayEnabled(),
                                  dataContainerList[packetNum_]->getBatteryData().chargeRelayEnabled(),
                                  dataContainerList[packetNum_]->getBatteryData().chargerSafetyEnabled(),
                                  dataContainerList[packetNum_]->getBatteryData().malfunctionIndicatorActive(),
                                  dataContainerList[packetNum_]->getBatteryData().multiPurposeInputSignalStatus(),
                                  dataContainerList[packetNum_]->getBatteryData().alwaysOnSignalStatus(),
                                  dataContainerList[packetNum_]->getBatteryData().isReadySignalStatus(),
                                  dataContainerList[packetNum_]->getBatteryData().isChargingSignalStatus()
                                 };
    writeBoolsIntoArray(packetPayload, 2, bmsRelayStatusArray, 8);
    packetPayload[3] = dataContainerList[packetNum_]->getBatteryData().populatedCells();
    writeFloatIntoArray(packetPayload, 4, dataContainerList[packetNum_]->getBatteryData().inputVoltage12V());
    writeFloatIntoArray(packetPayload, 8, dataContainerList[packetNum_]->getBatteryData().fanVoltage());
    writeFloatIntoArray(packetPayload, 12, dataContainerList[packetNum_]->getBatteryData().packCurrent());
    writeFloatIntoArray(packetPayload, 16, dataContainerList[packetNum_]->getBatteryData().packVoltage());
    writeFloatIntoArray(packetPayload, 20, dataContainerList[packetNum_]->getBatteryData().packStateOfCharge());
    writeFloatIntoArray(packetPayload, 24, dataContainerList[packetNum_]->getBatteryData().packAmpHours());
    writeFloatIntoArray(packetPayload, 28, dataContainerList[packetNum_]->getBatteryData().packDepthOfDischarge());
    packetPayload[32] = dataContainerList[packetNum_]->getBatteryData().highTemperature();
    packetPayload[33] = dataContainerList[packetNum_]->getBatteryData().highThermistorId();
    packetPayload[34] = dataContainerList[packetNum_]->getBatteryData().lowTemperature();
    packetPayload[35] = dataContainerList[packetNum_]->getBatteryData().lowThermistorId();
    packetPayload[36] = dataContainerList[packetNum_]->getBatteryData().averageTemperature();
    packetPayload[37] = dataContainerList[packetNum_]->getBatteryData().internalTemperature();
    packetPayload[38] = dataContainerList[packetNum_]->getBatteryData().fanSpeed();
    packetPayload[39] = dataContainerList[packetNum_]->getBatteryData().requestedFanSpeed();
    writeUShortIntoArray(packetPayload, 40, dataContainerList[packetNum_]->getBatteryData().lowCellVoltage());
    packetPayload[42] = dataContainerList[packetNum_]->getBatteryData().lowCellVoltageId();
    writeUShortIntoArray(packetPayload, 43, dataContainerList[packetNum_]->getBatteryData().highCellVoltage());
    packetPayload[45] = dataContainerList[packetNum_]->getBatteryData().highCellVoltageId();
    writeUShortIntoArray(packetPayload, 46, dataContainerList[packetNum_]->getBatteryData().averageCellVoltage());
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

        unsigned short arrayVoltage = (unsigned short)(dataContainerList[packetNum_]->getMpptData().arrayVoltage() * ONES_TO_CENTI);
        writeUShortIntoArray(packetPayload, 2, arrayVoltage);

        unsigned short arrayCurrent = (unsigned short)(dataContainerList[packetNum_]->getMpptData().arrayCurrent() * ONES_TO_MILLI);
        writeUShortIntoArray(packetPayload, 4, arrayCurrent);

        unsigned short batteryVoltage = (unsigned short)(dataContainerList[packetNum_]->getMpptData().batteryVoltage() * ONES_TO_CENTI);
        writeUShortIntoArray(packetPayload, 6, batteryVoltage);

        writeUShortIntoArray(packetPayload, 8, dataContainerList[packetNum_]->getMpptData().temperature() * ONES_TO_CENTI);
        unsigned char mpptPacketPayload[unframedPacketLength];
        std::memcpy(mpptPacketPayload, packetPayload, unframedPacketLength);
        unsigned char numberAndAlive = i & 0x03;

        if (dataContainerList[packetNum_]->getMpptData().alive())
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
    bool lightsAliveArray[] = {dataContainerList[packetNum_]->getLightsData().alive()};
    writeBoolsIntoArray(packetPayload, 1, lightsAliveArray, 1);
    bool lightsArray[] = {dataContainerList[packetNum_]->getLightsData().lowBeams(),
                          dataContainerList[packetNum_]->getLightsData().highBeams(),
                          dataContainerList[packetNum_]->getLightsData().brakes(),
                          dataContainerList[packetNum_]->getLightsData().leftSignal(),
                          dataContainerList[packetNum_]->getLightsData().rightSignal(),
                          dataContainerList[packetNum_]->getLightsData().bmsStrobeLight()
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
    packetPayload[1] = (unsigned char)dataContainerList[packetNum_]->getAuxBmsData().prechargeState();
    packetPayload[2] = dataContainerList[packetNum_]->getAuxBmsData().auxVoltage();
    bool auxBmsAliveArray[] = {dataContainerList[packetNum_]->getAuxBmsData().auxBmsAlive()};
    writeBoolsIntoArray(packetPayload, 3, auxBmsAliveArray, 1);
    bool strobeBmsLightArray[] = {dataContainerList[packetNum_]->getAuxBmsData().strobeBmsLight()};
    writeBoolsIntoArray(packetPayload, 4, strobeBmsLightArray, 1);
    bool allowChargeArray[] = {dataContainerList[packetNum_]->getAuxBmsData().allowCharge()};
    writeBoolsIntoArray(packetPayload, 5, allowChargeArray, 1);
    bool contactorErrorArray[] = {dataContainerList[packetNum_]->getAuxBmsData().contactorError()};
    writeBoolsIntoArray(packetPayload, 6, contactorErrorArray, 1);
    bool highVoltageEnableArray[] = {dataContainerList[packetNum_]->getAuxBmsData().highVoltageEnable()};
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
    if (packetNum_ == 0)
    {
        packetNum_ = 1;
        view_.setPacketText(false);
    }
    else
    {
        packetNum_ = 0;
        view_.setPacketText(true);
    }
}
