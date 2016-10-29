#include <cstring>

#include <QIODevice>

#include <CcsDefines.h>
#include <BatteryFaultsData.h>
#include <CmuData.h>
#include <DriverControlsData.h>
#include <KeyMotorData.h>
#include <LightsData.h>
#include <MotorDetailsData.h>
#include <MotorFaultsData.h>
#include <MpptData.h>
#include <View.h>

#include <TelemetryReporting_json.h>
#include <BatteryData_json.h>
#include <CommunicationService_json.h>

#include "qdatetime.h"
#include "qjsonarray.h"
#include "qstring.h"
#include "qjsondocument.h"
#include "qjsonobject.h"

QJsonArray KeyMotor;
QJsonObject MotorDetails0;
QJsonObject MotorDetails1;
QJsonObject DriverControls;
QJsonArray MotorFaults;
QJsonObject BatteryFaults;
QJsonObject Battery;
QJsonArray CMUArray;
QJsonArray mPPTArray;
QJsonObject lightsInfo;

TelemetryReporting_json::TelemetryReporting_json(CommunicationService_json& commService,
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
    : communicationService_json_(commService)
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

void TelemetryReporting_json::makeKeyMotor(){
    KeyMotor = QJsonArray();

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

}

void TelemetryReporting_json::makeMotorDetails(int n){
    if(n == 0) {
        MotorDetails0 = QJsonObject();
        MotorDetails0.insert("PhaseCCurrent", motor0DetailsData_.phaseCCurrent);
        MotorDetails0.insert("PhaseBCurrent", motor0DetailsData_.phaseBCurrent);
        MotorDetails0.insert("MotorVoltageReal", motor0DetailsData_.MotorVoltageReal);
        MotorDetails0.insert("MotorVoltageImaginary", motor0DetailsData_.MotorVoltageImaginary);
        MotorDetails0.insert("MotorCurrentReal", motor0DetailsData_.MotorCurrentReal);
        MotorDetails0.insert("MotorCurrentImaginary", motor0DetailsData_.MotorCurrentImaginary);
        MotorDetails0.insert("BackEmfReal", motor0DetailsData_.BackEmfReal);
        MotorDetails0.insert("VoltageRail15VSupply", motor0DetailsData_.RailSupply15V);
        MotorDetails0.insert("VoltageRail3VSupply", motor0DetailsData_.RailSupply3V);
        MotorDetails0.insert("VoltageRail1VSupply", motor0DetailsData_.RailSupply1V);
        MotorDetails0.insert("HeatSinkTemp", motor0DetailsData_.heatSinkTemperature);
        MotorDetails0.insert("MotorTemp", motor0DetailsData_.motorTemperature);
        MotorDetails0.insert("DspBoardTemp", motor0DetailsData_.dspBoardTempearture);
        MotorDetails0.insert("DcBusAmpHours", motor0DetailsData_.dcBusAmpHours);
        MotorDetails0.insert("Odometer", motor0DetailsData_.odometer);
        MotorDetails0.insert("Slipspeed", motor0DetailsData_.slipSpeed);
    }


    if( n== 1){
        MotorDetails1 = QJsonObject();
        MotorDetails1.insert("PhaseCCurrent", motor1DetailsData_.phaseCCurrent);
        MotorDetails1.insert("PhaseBCurrent", motor1DetailsData_.phaseBCurrent);
        MotorDetails1.insert("MotorVoltageReal", motor1DetailsData_.MotorVoltageReal);
        MotorDetails1.insert("MotorVoltageImaginary", motor1DetailsData_.MotorVoltageImaginary);
        MotorDetails1.insert("MotorCurrentReal", motor1DetailsData_.MotorCurrentReal);
        MotorDetails1.insert("MotorCurrentImaginary", motor1DetailsData_.MotorCurrentImaginary);
        MotorDetails1.insert("BackEmfReal", motor1DetailsData_.BackEmfReal);
        MotorDetails1.insert("VoltageRail15VSupply", motor1DetailsData_.RailSupply15V);
        MotorDetails1.insert("VoltageRail3VSupply", motor1DetailsData_.RailSupply3V);
        MotorDetails1.insert("VoltageRail1VSupply", motor1DetailsData_.RailSupply1V);
        MotorDetails1.insert("HeatSinkTemp", motor1DetailsData_.heatSinkTemperature);
        MotorDetails1.insert("MotorTemp", motor1DetailsData_.motorTemperature);
        MotorDetails1.insert("DspBoardTemp", motor1DetailsData_.dspBoardTempearture);
        MotorDetails1.insert("DcBusAmpHours", motor1DetailsData_.dcBusAmpHours);
        MotorDetails1.insert("Odometer", motor1DetailsData_.odometer);
        MotorDetails1.insert("Slipspeed", motor1DetailsData_.slipSpeed);
    }


}

void TelemetryReporting_json::makeDriverControls(){
    DriverControls = QJsonObject();

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

}

void TelemetryReporting_json::makeMotorFaults(){
    MotorFaults = QJsonArray();

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
}

void TelemetryReporting_json::makeBatteryFaults(){
    BatteryFaults = QJsonObject();

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
}

void TelemetryReporting_json::makeBattery(){

    Battery = QJsonObject();

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

}

void TelemetryReporting_json::makeCmu(){

    QJsonObject CMUinfo;

    CMUArray = QJsonArray();

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

}

void TelemetryReporting_json::makeMppt(){
    mPPTArray = QJsonArray();

    QJsonObject mPPTInfo;

    mPPTInfo.insert("Alive", mpptData_.alive);
    mPPTInfo.insert("ArrayVoltage", mpptData_.arrayVoltage);
    mPPTInfo.insert("ArrayCurrent", mpptData_.arrayCurrent);
    mPPTInfo.insert("BatteryVoltage", mpptData_.batteryVoltage);
    mPPTInfo.insert("Temperature", mpptData_.temperature);

    for(unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        mPPTArray.push_back(mPPTInfo);
    }
}

void TelemetryReporting_json::makeLights(){
    lightsInfo = QJsonObject();

    lightsInfo.insert("LowBeams", lightsData_.lowBeams);
    lightsInfo.insert("HighBeams", lightsData_.highBeams);
    lightsInfo.insert("Brakes", lightsData_.brakes);
    lightsInfo.insert("LeftSignal", lightsData_.leftSignal);
    lightsInfo.insert("RightSignal", lightsData_.rightSignal);
    lightsInfo.insert("BmsStrobeLight", lightsData_.bmsStrobeLight);
}


void TelemetryReporting_json::sendKeyMotor()
{
    makeKeyMotor();

    QJsonDocument doc(KeyMotor);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendMotorDetails(int n)
{
    makeMotorDetails(n);

    QJsonDocument doc;

    if(n == 0)
        doc = QJsonDocument(MotorDetails0);
    if(n == 1)
        doc = QJsonDocument(MotorDetails0);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendDriverControls()
{
    makeDriverControls();

    QJsonDocument doc(DriverControls);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendMotorFaults()
{
    makeMotorFaults();

    QJsonDocument doc(MotorFaults);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendBatteryFaults()
{
    makeBatteryFaults();

    QJsonDocument doc(BatteryFaults);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendBattery()
{
    makeBattery();

    QJsonDocument doc(Battery);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);
}

void TelemetryReporting_json::sendCmu()
{
    makeCmu();

    QJsonDocument doc(CMUArray);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);

}

void TelemetryReporting_json::sendMppt()
{

    makeMppt();

    QJsonDocument doc(mPPTArray);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);

}

void TelemetryReporting_json::sendLights()
{
    makeLights();

    QJsonDocument doc(lightsInfo);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);

}

void TelemetryReporting_json::sendAll()
{
    makeKeyMotor();
    makeMotorDetails(0);
    makeMotorDetails(1);
    makeDriverControls();
    makeMotorFaults();
    makeBatteryFaults();
    makeBattery();
    makeCmu();
    makeMppt();
    makeLights();

    QJsonObject obj;
    QDateTime date = date.currentDateTime();
    QString dateString = date.toString("yyyy-MM-dd hh:mm:ss.zzz");

    QJsonArray MotorDetails;
    MotorDetails.push_back(MotorDetails0);
    MotorDetails.push_back(MotorDetails1);

    obj.insert("PacketTitle", "UofC Solar Car Gen 5");
    obj.insert("TimeStamp", dateString);
    obj.insert("KeyMotor", KeyMotor);
    obj.insert("MotorDetails", MotorDetails);
    obj.insert("DriverControls", DriverControls);
    obj.insert("MotorFaults", MotorFaults);
    obj.insert("BatteryFaults", BatteryFaults);
    obj.insert("Battery", Battery);
    obj.insert("CMU", CMUArray);
    obj.insert("MPPT", mPPTArray);
    obj.insert("Lights", lightsInfo);

    QJsonDocument doc(obj);

    QByteArray data = doc.toBinaryData();
    communicationService_json_.sendData(data);

}


