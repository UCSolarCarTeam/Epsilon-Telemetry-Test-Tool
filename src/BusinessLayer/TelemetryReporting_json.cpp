#include <cstring>

#include <QIODevice>

#include <CcsDefines.h>
#include <CrcCalculator.h>
//#include <TelemetryReporting.h>
//#include <BatteryData.h>
#include <BatteryFaultsData.h>
#include <CmuData.h>
#include <DriverControlsData.h>
#include <KeyMotorData.h>
#include <LightsData.h>
#include <MotorDetailsData.h>
#include <MotorFaultsData.h>
#include <MpptData.h>
#include <CommunicationService.h>
#include <View.h>

#include <TelemetryReporting_json.h>
#include <BatteryData_json.h>

#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QJsonValue>
#include <QJsonArray>


union DataUnion
{
    float floatData;
    short shortData[2];
    unsigned short uShortData[2];
    char charData[4];
};

namespace
{
// Refer to https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0
// These lengths only include the data. Not the checksum
const int KEY_MOTOR_LENGTH = 43;
const int MOTOR_DETAILS_LENGTH = 69;
const int DRIVER_CONTROLS_LENGTH = 10;
const int MOTOR_FAULTS_LENGTH = 9;
const int BATTERY_FAULTS_LENGTH = 3;
const int BATTERY_LENGTH = 60;
const int CMU_LENGTH = 50;
const int MPPT_LENGTH = 10;
const int LIGHTS_LENGTH = 2;

const unsigned int CHECKSUM_LENGTH = 2;
const unsigned int FRAMING_LENGTH_INCREASE = 2;
const unsigned char TERMINATING_BYTE = 0x00;
}

TelemetryReporting_json::TelemetryReporting_json(CommunicationService& commService,
                                       const KeyMotorData& keyMotorData,
                                       const MotorDetailsData& motor0DetailsData,
                                       const MotorDetailsData& motor1DetailsData,
                                       const DriverControlsData& driverControlsData,
                                       const MotorFaultsData& motorFaultsData,
                                       const BatteryFaultsData& batteryFaultsData,
                                       const BatteryData_json& batteryData_json,
                                       const CmuData& cmuData,
                                       const MpptData& mpptData,
                                       const LightsData& lightsData,
                                       View& view)
    : communicationService_(commService)
    , keyMotorData_(keyMotorData)
    , motor0DetailsData_(motor0DetailsData)
    , motor1DetailsData_(motor1DetailsData)
    , driverControlsData_(driverControlsData)
    , motorFaultsData_(motorFaultsData)
    , batteryFaultsData_(batteryFaultsData)
    , batteryData_json_(batteryData_json)
    , cmuData_(cmuData)
    , mpptData_(mpptData)
    , lightsData_(lightsData)
    , view_(view)
{
    //Connect slots to View Signals
    connect(&view_, SIGNAL(sendKeyMotor()), this, SLOT(sendKeyMotor()));
    connect(&view_, SIGNAL(sendMotor0Details()), this, SLOT(sendMotor0Details()));
    connect(&view_, SIGNAL(sendMotor1Details()), this, SLOT(sendMotor1Details()));
    connect(&view_, SIGNAL(sendDriverControls()), this, SLOT(sendDriverControls()));
    connect(&view_, SIGNAL(sendMotorFaults()), this, SLOT(sendMotorFaults()));
    connect(&view_, SIGNAL(sendBatteryFaults()), this, SLOT(sendBatteryFaults()));
    connect(&view_, SIGNAL(sendBattery()), this, SLOT(sendBattery()));
    connect(&view_, SIGNAL(sendCmu()), this, SLOT(sendCmu()));
    connect(&view_, SIGNAL(sendMppt()), this, SLOT(sendMppt()));
    connect(&view_, SIGNAL(sendLights()), this, SLOT(sendLights()));
    connect(&view_, SIGNAL(sendAll()), this, SLOT(sendAll()));
}

void TelemetryReporting_json::sendKeyMotor()
{/*
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
    communicationService_.sendData(packet, packetLength);
    */

    QJsonArray KeyMotor;

    QJsonObject KeyMotor0;
    KeyMotor0.insert("Alive", keyMotorData_.motor0Alive);
    KeyMotor0.insert("SetCurrent", keyMotorData_.motor0SetCurrent);
    KeyMotor0.insert("SetVelocity", keyMotorData_.motor0SetVelocity);
    KeyMotor0.insert("BusCurrent", keyMotorData_.motor0BusVoltage);
    KeyMotor0.insert("BusVoltage", keyMotorData_.motor0BusVoltage);
    KeyMotor0.insert("VehicleVelocity", keyMotorData_.motor0VehicleVelocity);
    KeyMotor.push_back(KeyMotor0);

    QJsonObject KeyMotor1;
    KeyMotor1.insert("Alive", keyMotorData_.motor1Alive);
    KeyMotor1.insert("SetCurrent", keyMotorData_.motor1SetCurrent);
    KeyMotor1.insert("SetVelocity", keyMotorData_.motor1SetVelocity);
    KeyMotor1.insert("BusCurrent", keyMotorData_.motor1BusVoltage);
    KeyMotor1.insert("BusVoltage", keyMotorData_.motor1BusVoltage);
    KeyMotor1.insert("VehicleVelocity", keyMotorData_.motor1VehicleVelocity);
    KeyMotor.push_back(KeyMotor1);

    QJsonDocument doc(KeyMotor);

    QString filename ="KeyMotorData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }


}

void TelemetryReporting_json::sendMotorDetails(int n)
{/*
    const unsigned int unframedPacketLength = MOTOR_DETAILS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    if(n == 0) {
      packetPayload[0] = CcsDefines::MOTOR_DETAILS_0_PKG_ID;
    } else {
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
    communicationService_.sendData(packet, packetLength);
    */
    QJsonObject MotorDetails;

    MotorDetails.insert("PhaseCCurrent", motor0DetailsData_.phaseCCurrent);
    MotorDetails.insert("PhaseBCurrent", motor0DetailsData_.phaseBCurrent);
    MotorDetails.insert("MotorVoltageReal", motor0DetailsData_.MotorVoltageReal);
    MotorDetails.insert("MotorVoltageImaginary", motor0DetailsData_.MotorVoltageImaginary);
    MotorDetails.insert("MotorCurrentReal", motor0DetailsData_.MotorCurrentReal);
    MotorDetails.insert("MotorCurrentImaginary", motor0DetailsData_.MotorCurrentImaginary);
    MotorDetails.insert("BackEmfReal", motor0DetailsData_.BackEmfReal);
    MotorDetails.insert("VoltageRail15VSupply", motor0DetailsData_.RailSupply15V);
    MotorDetails.insert("VoltageRail3VSupply", motor0DetailsData_.RailSupply3V);
    MotorDetails.insert("VoltageRail1VSupply", motor0DetailsData_.RailSupply1V);
    MotorDetails.insert("HeatSinkTemp", motor0DetailsData_.heatSinkTemperature);
    MotorDetails.insert("MotorTemp", motor0DetailsData_.motorTemperature);
    MotorDetails.insert("DspBoardTemp", motor0DetailsData_.dspBoardTempearture);
    MotorDetails.insert("DcBusAmpHours", motor0DetailsData_.dcBusAmpHours);
    MotorDetails.insert("Odometer", motor0DetailsData_.odometer);
    MotorDetails.insert("Slipspeed", motor0DetailsData_.slipSpeed);

    QJsonDocument doc(MotorDetails);

    QString filename ="MotorDetailsData";
    filename.append(n);
    filename.append(".txt");

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }



}

void TelemetryReporting_json::sendDriverControls()
{/*
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
    communicationService_.sendData(packet, packetLength);
    */
    QJsonObject DriverControls;

    DriverControls.insert("Alive", driverControlsData_.alive);
    DriverControls.insert("HeadlightsOff", driverControlsData_.headlightsOff);
    DriverControls.insert("HeadLightsLow", driverControlsData_.headlightsLow);
    DriverControls.insert("HeadlightsHigh", driverControlsData_.headlightsHigh);
    DriverControls.insert("SignalRight", driverControlsData_.signalRight);
    DriverControls.insert("SignalLeft", driverControlsData_.signalLeft);
    DriverControls.insert("Hazard", driverControlsData_.hazardLights);
    DriverControls.insert("Interior", driverControlsData_.interiorLights);
    DriverControls.insert("Aux", driverControlsData_.musicAux);
    DriverControls.insert("VolumeUp", driverControlsData_.volumeUp);
    DriverControls.insert("VolumeDown", driverControlsData_.volumeDown);
    DriverControls.insert("NextSong", driverControlsData_.nextSong);
    DriverControls.insert("PrevSong", driverControlsData_.prevSong);
    DriverControls.insert("Acceleration", driverControlsData_.acceleration);
    DriverControls.insert("RegenBraking", driverControlsData_.regenBraking);
    DriverControls.insert("Brakes", driverControlsData_.brakes);
    DriverControls.insert("Forward", driverControlsData_.forward);
    DriverControls.insert("Reverse", driverControlsData_.reverse);
    DriverControls.insert("PushToTalk", driverControlsData_.pushToTalk);
    DriverControls.insert("Horn", driverControlsData_.horn);
    DriverControls.insert("Reset", driverControlsData_.reset);

    QJsonDocument doc(DriverControls);

    QString filename ="DriverControlData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }


}

void TelemetryReporting_json::sendMotorFaults()
{/*
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
    communicationService_.sendData(packet, packetLength);
    */
    QJsonArray MotorFaults;

    QJsonObject MotorFaults0;

    QJsonObject ErrorFlags0;

    ErrorFlags0.insert("MotorOverSpeed", motorFaultsData_.motor0OverSpeed);
    ErrorFlags0.insert("SoftwareOverCurrent", motorFaultsData_.motor0SoftwareOverCurrent);
    ErrorFlags0.insert("DcBusOverVoltage", motorFaultsData_.motor0DcBusOverVoltage);
    ErrorFlags0.insert("BadMototPositionHallSequence", motorFaultsData_.motor0BadMootorPositionHallSequence);
    ErrorFlags0.insert("WatchdogCausedLastReset", motorFaultsData_.motor0WatchdogCausedLastReset);
    ErrorFlags0.insert("ConfigReadError", motorFaultsData_.motor0ConfigReadError);
    ErrorFlags0.insert("Rail15VUnderVoltageLockOut", motorFaultsData_.motor0Rail15VUnderVoltageLockOut);
    ErrorFlags0.insert("DesaturationFault", motorFaultsData_.motor0DesaturationFault);
    MotorFaults0.insert("Error Flags", ErrorFlags0);

    QJsonObject LimitFlags0;
    LimitFlags0.insert("OutputVoltagePwm", motorFaultsData_.motor0OutputVoltagePwmLimit);
    LimitFlags0.insert("MotorCurrent", motorFaultsData_.motor0MotorCurrentLimit);
    LimitFlags0.insert("Velocity", motorFaultsData_.motor0VelocityLimit);
    LimitFlags0.insert("BusCurrent", motorFaultsData_.motor0BusCurrentLimit);
    LimitFlags0.insert("BusVoltageUpper", motorFaultsData_.motor0BusVoltageUpperLimit);
    LimitFlags0.insert("BusVoltageLower", motorFaultsData_.motor0BusVoltageLowerLimit);
    LimitFlags0.insert("IpmOrMotorTemperature", motorFaultsData_.motor0IpmOrMotorTemperatureLimit);
    MotorFaults0.insert("LimitFlags", LimitFlags0);

    MotorFaults0.insert("RxErrorCount", motorFaultsData_.motor0RxErrorCount);
    MotorFaults0.insert("TxErrorCount", motorFaultsData_.motor0TxErrorCount);

    MotorFaults.push_back(MotorFaults0);

    QJsonObject MotorFaults1;

    QJsonObject ErrorFlags1;

    ErrorFlags1.insert("MotorOverSpeed", motorFaultsData_.motor1OverSpeed);
    ErrorFlags1.insert("SoftwareOverCurrent", motorFaultsData_.motor1SoftwareOverCurrent);
    ErrorFlags1.insert("DcBusOverVoltage", motorFaultsData_.motor1DcBusOverVoltage);
    ErrorFlags1.insert("BadMototPositionHallSequence", motorFaultsData_.motor1BadMootorPositionHallSequence);
    ErrorFlags1.insert("WatchdogCausedLastReset", motorFaultsData_.motor1WatchdogCausedLastReset);
    ErrorFlags1.insert("ConfigReadError", motorFaultsData_.motor1ConfigReadError);
    ErrorFlags1.insert("Rail15VUnderVoltageLockOut", motorFaultsData_.motor1Rail15VUnderVoltageLockOut);
    ErrorFlags1.insert("DesaturationFault", motorFaultsData_.motor1DesaturationFault);
    MotorFaults1.insert("Error Flags", ErrorFlags1);

    QJsonObject LimitFlags1;
    LimitFlags1.insert("OutputVoltagePwm", motorFaultsData_.motor1OutputVoltagePwmLimit);
    LimitFlags1.insert("MotorCurrent", motorFaultsData_.motor1MotorCurrentLimit);
    LimitFlags1.insert("Velocity", motorFaultsData_.motor1VelocityLimit);
    LimitFlags1.insert("BusCurrent", motorFaultsData_.motor1BusCurrentLimit);
    LimitFlags1.insert("BusVoltageUpper", motorFaultsData_.motor1BusVoltageUpperLimit);
    LimitFlags1.insert("BusVoltageLower", motorFaultsData_.motor1BusVoltageLowerLimit);
    LimitFlags1.insert("IpmOrMotorTemperature", motorFaultsData_.motor1IpmOrMotorTemperatureLimit);
    MotorFaults1.insert("LimitFlags", LimitFlags1);

    MotorFaults1.insert("RxErrorCount", motorFaultsData_.motor1RxErrorCount);
    MotorFaults1.insert("TxErrorCount", motorFaultsData_.motor1TxErrorCount);

    MotorFaults.push_back(MotorFaults1);

    QJsonDocument doc(MotorFaults);

    QString filename ="MotorFaultsData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }


}

void TelemetryReporting_json::sendBatteryFaults()
{/*
    const unsigned int unframedPacketLength = BATTERY_FAULTS_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    packetPayload[0] = CcsDefines::BATTERY_FAULTS_PKG_ID;
    bool batteryFaultsArray[] = {batteryFaultsData_.cellOverVoltage,
                                 batteryFaultsData_.cellUnderVoltage,
                                 batteryFaultsData_.cellOverTemperature,
                                 batteryFaultsData_.measurementUntrusted,
                                 batteryFaultsData_.cmuCommTimeout,
                                 batteryFaultsData_.vehicleCommTimeout,
                                 batteryFaultsData_.bmuInSetupMode,
                                 batteryFaultsData_.cmuCanBusPowerStatus,
                                 batteryFaultsData_.packIsolationTestFailure,
                                 batteryFaultsData_.softwareOverCurrent,
                                 batteryFaultsData_.can12VSupplyLow,
                                 batteryFaultsData_.contactorStuck,
                                 batteryFaultsData_.cmuDetectedExtraCellPresent
                                };
    writeBoolsIntoArray(packetPayload, 1, batteryFaultsArray, 13);

    addChecksum(packetPayload, BATTERY_FAULTS_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendData(packet, packetLength);
*/
    QJsonObject BatteryFaults;

    BatteryFaults.insert("CellOverVoltage", batteryFaultsData_.cellOverVoltage);
    BatteryFaults.insert("CellUnderVoltage", batteryFaultsData_.cellOverVoltage);
    BatteryFaults.insert("CellOverTemp", batteryFaultsData_.cellOverTemperature);
    BatteryFaults.insert("MeasurementUntrusted", batteryFaultsData_.measurementUntrusted);
    BatteryFaults.insert("CMUCommTimeout", batteryFaultsData_.cmuCommTimeout);
    BatteryFaults.insert("BMUSetupMode", batteryFaultsData_.bmuInSetupMode);
    BatteryFaults.insert("CMUCANBusPowerStatus", batteryFaultsData_.cmuCanBusPowerStatus);
    BatteryFaults.insert("PackIsolationFailure", batteryFaultsData_.packIsolationTestFailure);
    BatteryFaults.insert("SoftwareOverCurrent", batteryFaultsData_.softwareOverCurrent);
    BatteryFaults.insert("CAN12VSupplyLow", batteryFaultsData_.can12VSupplyLow);
    BatteryFaults.insert("ContactorStuck", batteryFaultsData_.contactorStuck);
    BatteryFaults.insert("CMUDetectedExtraCell", batteryFaultsData_.cmuDetectedExtraCellPresent);

    QJsonDocument doc(BatteryFaults);

    QString filename ="BatteryFaultsData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }


}

void TelemetryReporting_json::sendBattery()
{
    /*const unsigned int unframedPacketLength = BATTERY_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    packetPayload[0] = CcsDefines::BATTERY_PKG_ID;
    bool aliveArray[] = {batteryData_.alive};
    writeBoolsIntoArray(packetPayload, 1, aliveArray, 1);
    writeFloatIntoArray(packetPayload, 2, batteryData_.packSocAmpHours);
    writeFloatIntoArray(packetPayload, 6, batteryData_.packSocPercentage);
    writeFloatIntoArray(packetPayload, 10, batteryData_.packBalanceSoc);
    writeFloatIntoArray(packetPayload, 14, batteryData_.packBalanceSocPercentage);
    writeUShortIntoArray(packetPayload, 18, batteryData_.chargingCellVoltageError);
    writeUShortIntoArray(packetPayload, 20, batteryData_.cellTemperatureMargin);
    writeUShortIntoArray(packetPayload, 22, batteryData_.dischargingCellVoltageError);
    writeUShortIntoArray(packetPayload, 24, batteryData_.totalPackCapacity);
    bool contactorArray[] = {batteryData_.contactor0Errorstatus,
                             batteryData_.contactor1ErrorStatus,
                             batteryData_.contactor0Status,
                             batteryData_.contactor1Status,
                             batteryData_.contactor12VSupplyOk,
                             batteryData_.contactor2ErrorStatus,
                             batteryData_.contactor2Status
                            };
    writeBoolsIntoArray(packetPayload, 26, contactorArray, 7);
    packetPayload[27] = (unsigned char)batteryData_.prechargeState;
    bool prechargeArray[] = {batteryData_.prechargeTimerElapsed,
                             batteryData_.prechargeTimerNotElapsed
                            };
    writeBoolsIntoArray(packetPayload, 28, prechargeArray, 2);
    writeUShortIntoArray(packetPayload, 29, batteryData_.prechargeTimerCount);
    writeUShortIntoArray(packetPayload, 31, batteryData_.lowestCellVoltage);
    packetPayload[33] = batteryData_.lowestCellVoltageCmuNumber;
    packetPayload[33] += batteryData_.lowestCellVoltageCellNumber << 4;
    writeUShortIntoArray(packetPayload, 34, batteryData_.highestCellVoltage);
    packetPayload[36] = batteryData_.highestCellVoltageCmuNumber;
    packetPayload[36] += batteryData_.highestCellVoltageCellNumber << 4;
    writeUShortIntoArray(packetPayload, 37, batteryData_.lowestCellTemperature);
    packetPayload[39] = batteryData_.lowestCellTemperatureCmuNumber;
    packetPayload[39] += batteryData_.lowestCellTemperatureCellNumber << 4;
    writeUShortIntoArray(packetPayload, 40, batteryData_.highestCellTemperature);
    packetPayload[42] = batteryData_.highestCellTemperatureCmuNumber;
    packetPayload[42] += batteryData_.highestCellTemperatureCellNumber << 4;
    writeUShortIntoArray(packetPayload, 51, batteryData_.fan0Speed);
    writeUShortIntoArray(packetPayload, 53, batteryData_.fan1Speed);
    writeUShortIntoArray(packetPayload, 55, batteryData_.fanContactors12VCurrentConsumption);
    writeUShortIntoArray(packetPayload, 57, batteryData_.cmu12VCurrentConsumption);
    bool lockedOutArray[] = {batteryData_.bmsCanLockedOut};
    writeBoolsIntoArray(packetPayload, 59, lockedOutArray, 1);

    addChecksum(packetPayload, BATTERY_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendData(packet, packetLength);
    */

    QJsonObject Battery;

    Battery.insert("Alive", batteryData_json_.alive);
    Battery.insert("PackSocAmpHours", batteryData_json_.packSocAmpHours);
    Battery.insert("PackSocPercentage", batteryData_json_.packSocPercentage);
    Battery.insert("PackBalanceSocAmpHours", batteryData_json_.packBalanceSoc);
    Battery.insert("PackBalanceSocPercentage", batteryData_json_.packBalanceSocPercentage);
    Battery.insert("ChargingCellVoltageError", batteryData_json_.chargingCellVoltageError);
    Battery.insert("CellTempMargin", batteryData_json_.cellTemperatureMargin);
    Battery.insert("DischargingCellVoltageError", batteryData_json_.dischargingCellVoltageError);
    Battery.insert("TotalPackCapacity", batteryData_json_.totalPackCapacity);
    Battery.insert("PrechargeContactor0DriverStatus", batteryData_json_.contactor0Status);
    Battery.insert("PrechargeContactor1DriverStatus", batteryData_json_.contactor1Status);
    Battery.insert("PrechargeContactor2DriverStatus", batteryData_json_.contactor2Status);
    Battery.insert("PrechargeContactor0DriverError", batteryData_json_.contactor0Errorstatus);
    Battery.insert("PrechargeContactor1DriverError", batteryData_json_.contactor1ErrorStatus);
    Battery.insert("PrechargeContactor2DriverError", batteryData_json_.contactor2ErrorStatus);
    Battery.insert("ContactorSupplyOK", batteryData_json_.contactor12VSupplyOk);

    Battery.insert("PrechargeState", batteryData_json_.prechargeState);
    Battery.insert("PrechargeTimerElapsed", batteryData_json_.prechargeTimerElapsed);
    Battery.insert("PrechargeTimeCount", batteryData_json_.prechargeTimerCount);

    QJsonObject LowestCellVoltage;
    LowestCellVoltage.insert("Voltage", batteryData_json_.lowestCellVoltage);
    LowestCellVoltage.insert("CmuNumber", batteryData_json_.lowestCellVoltageCmuNumber);
    LowestCellVoltage.insert("CellNumber", batteryData_json_.lowestCellVoltageCellNumber);

    Battery.insert("LowestCellVoltage", LowestCellVoltage);

    QJsonObject LowestCellTemp;
    LowestCellTemp.insert("Temp", batteryData_json_.lowestCellTemperature);
    LowestCellTemp.insert("CmuNumber", batteryData_json_.lowestCellTemperatureCmuNumber);
    LowestCellTemp.insert("CellNumber", batteryData_json_.lowestCellTemperatureCellNumber);

    Battery.insert("LowestCellTemp", LowestCellTemp);

    QJsonObject HighestCellVoltage;
    HighestCellVoltage.insert("Voltage", batteryData_json_.highestCellVoltage);
    HighestCellVoltage.insert("CmuNumber", batteryData_json_.highestCellVoltageCmuNumber);
    HighestCellVoltage.insert("CellNumber", batteryData_json_.highestCellVoltageCellNumber);

    Battery.insert("HighestCellVoltage", HighestCellVoltage);

    QJsonObject HighestCellTemp;
    HighestCellTemp.insert("Temp", batteryData_json_.highestCellTemperature);
    HighestCellTemp.insert("CmuNumber", batteryData_json_.highestCellTemperatureCmuNumber);
    HighestCellTemp.insert("CellNumber", batteryData_json_.highestCellTemperatureCellNumber);

    Battery.insert("HighestCellTemp", HighestCellTemp);

    Battery.insert("Voltage", batteryData_json_.voltage);
    Battery.insert("Current", batteryData_json_.current);
    Battery.insert("Fan0Speed", batteryData_json_.fan0Speed);
    Battery.insert("Fan1Speed", batteryData_json_.fan1Speed);
    Battery.insert("FanContactorsCurrent", batteryData_json_.fanContactors12VCurrentConsumption);
    Battery.insert("CmuCurrent", batteryData_json_.cmu12VCurrentConsumption);

    QJsonDocument doc(Battery);

    QString filename ="BatteryData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }




}

void TelemetryReporting_json::sendCmu()
{/*
    const unsigned int unframedPacketLength = CMU_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    packetPayload[0] = CcsDefines::CMU_PKG_ID;
    int cmuVoltageBaseIndex = 2;
    for (int i = 0; i < 8; i++)
    {
        writeUShortIntoArray(packetPayload, cmuVoltageBaseIndex + (i * 2), cmuData_.cellVoltage[i]);
    }
    writeUShortIntoArray(packetPayload, 18, cmuData_.pcbTemperature);
    int cmuTemperatureBaseIndex = 20;
    for (int i = 0; i < 15; i++)
    {
        writeUShortIntoArray(packetPayload, cmuTemperatureBaseIndex + (i * 2), cmuData_.cellTemperature[i]);
    }

    for (unsigned char i = 0; i < CcsDefines::CMU_COUNT; i++)
    {
        packetPayload[1] = i;

        addChecksum(packetPayload, CMU_LENGTH);
        unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
        unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
        communicationService_.sendData(packet, packetLength);
    }
    */

    QJsonObject CMUinfo;

    QJsonArray CMUArray;

    QJsonArray cellVoltageInfo;
    for (int i = 0; i < 8; i++)
    {
        cellVoltageInfo.push_back(cmuData_.cellVoltage[i]);
    }

    CMUinfo.insert("Voltages", cellVoltageInfo);

    CMUinfo.insert("PcbTemp", cmuData_.pcbTemperature);

    QJsonArray cellTemperatureInfo;
    for (int i = 0; i < 15; i++)
    {
        cellTemperatureInfo.push_back(cmuData_.cellTemperature[i]);
    }

    CMUinfo.insert("CellTemps", cellTemperatureInfo);

    for(unsigned char i = 0; i < CcsDefines::CMU_COUNT; i++)
    {
        CMUArray.push_back(CMUinfo);
    }

    QJsonDocument doc(CMUArray);

    QString filename ="CMUData.txt";

    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }

}

void TelemetryReporting_json::sendMppt()
{
/*
    const unsigned int unframedPacketLength = KEY_MOTOR_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    packetPayload[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    writeUShortIntoArray(packetPayload, 2, mpptData_.arrayVoltage);
    writeUShortIntoArray(packetPayload, 4, mpptData_.arrayCurrent);
    writeUShortIntoArray(packetPayload, 6, mpptData_.batteryVoltage);
    writeUShortIntoArray(packetPayload, 8, mpptData_.temperature);

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        unsigned char mpptPacketPayload[unframedPacketLength];
        std::memcpy(mpptPacketPayload, packetPayload, unframedPacketLength);
        mpptPacketPayload[1] = i;

        addChecksum(mpptPacketPayload, KEY_MOTOR_LENGTH);
        unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
        unsigned int packetLength = frameData(mpptPacketPayload, unframedPacketLength, packet);
        communicationService_.sendData(packet, packetLength);
    }
    */


    QJsonObject mPPTInfo;

    QJsonArray mPPTArray;

    mPPTInfo.insert("Alive", mpptData_.alive);
    mPPTInfo.insert("ArrayVoltage", mpptData_.arrayVoltage);
    mPPTInfo.insert("ArrayCurrent", mpptData_.arrayCurrent);
    mPPTInfo.insert("BatteryVoltage", mpptData_.batteryVoltage);
    mPPTInfo.insert("Temperature", mpptData_.temperature);

    for(unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        mPPTArray.push_back(mPPTInfo);
    }

    QJsonDocument doc(mPPTArray);

    QString filename = "mPPTData.txt";
    QFile file( filename );

    if ( file.open(QIODevice::ReadWrite) )
    {
        //Simulate sending document
        QTextStream stream( &file );
        stream << doc.toJson();
    }


}

void TelemetryReporting_json::sendLights()
{
    /*
    const unsigned int unframedPacketLength = KEY_MOTOR_LENGTH + CHECKSUM_LENGTH;
    unsigned char packetPayload[unframedPacketLength];

    packetPayload[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    bool lightsArray[] = {lightsData_.lowBeams,
                          lightsData_.highBeams,
                          lightsData_.brakes,
                          lightsData_.leftSignal,
                          lightsData_.rightSignal,
                          lightsData_.bmsStrobeLight
                         };
    writeBoolsIntoArray(packetPayload, 1, lightsArray, 6);

    addChecksum(packetPayload, KEY_MOTOR_LENGTH);
    unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
    unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
    communicationService_.sendData(packet, packetLength);
    */

    QJsonObject lightsInfo;

    lightsInfo.insert("LowBeams", lightsData_.lowBeams);
    lightsInfo.insert("HighBeams", lightsData_.highBeams);
    lightsInfo.insert("Brakes", lightsData_.brakes);
    lightsInfo.insert("LeftSignal", lightsData_.leftSignal);
    lightsInfo.insert("RightSignal", lightsData_.rightSignal);
    lightsInfo.insert("BmsStrobeLight", lightsData_.bmsStrobeLight);

    QJsonDocument doc(lightsInfo);

   // qDebug() << doc.toJson();

    QString filename="lightsData.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << doc.toJson();

        //Simulate sending the a JSON document
    }

}

void TelemetryReporting_json::sendAll()
{
    sendKeyMotor();
    sendMotorDetails(0);
    sendMotorDetails(1);
    sendDriverControls();
    sendMotorFaults();
    sendBatteryFaults();
    sendBattery();
    sendCmu();
    sendMppt();
    sendLights();
}

unsigned int TelemetryReporting_json::frameData(const unsigned char* dataToEncode, unsigned long length, unsigned char* frameData)
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

unsigned int TelemetryReporting_json::stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData)
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

void TelemetryReporting_json::addChecksum(unsigned char* data, unsigned int length)
{
    unsigned short crc16 = CrcCalculator::calculateCrc16(data, length);
    data[length] = static_cast<unsigned char>(0xFF & crc16);
    data[length + 1] = static_cast<unsigned char>(0xFF & (crc16 >> 8));
}

void TelemetryReporting_json::writeFloatIntoArray(unsigned char* data, int index, const float& value)
{
    DataUnion dataUnion;
    dataUnion.floatData = value;
    data[index++] = dataUnion.charData[0];
    data[index++] = dataUnion.charData[1];
    data[index++] = dataUnion.charData[2];
    data[index] = dataUnion.charData[3];
}

void TelemetryReporting_json::writeShortIntoArray(unsigned char* data, int index, const short& value)
{
    DataUnion dataUnion;
    dataUnion.shortData[0] = value;
    data[index++] = dataUnion.charData[0];
    data[index] = dataUnion.charData[1];
}

void TelemetryReporting_json::writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value)
{
    DataUnion dataUnion;
    dataUnion.uShortData[0] = value;
    data[index++] = dataUnion.charData[0];
    data[index] = dataUnion.charData[1];
}

void TelemetryReporting_json::writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues)
{
    index -= 1;

    for (int i = 0; i < numValues; i++)
    {
        if ((i % 8) == 0)
        {
            index++;
            data[index] = 0;
        }
        if (values[i])
        {
            data[index] += 1 << (i % 8);
        }
    }
}
