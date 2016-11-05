#include <cstring>

#include <QIODevice>

#include <CcsDefines.h>
#include <CommunicationService.h>
#include <BatteryFaultsData.h>
#include <BatteryData.h>
#include <CmuData.h>
#include <DriverControlsData.h>
#include <KeyMotorData.h>
#include <LightsData.h>
#include <MotorDetailsData.h>
#include <MotorFaultsData.h>
#include <MpptData.h>
#include <View.h>

#include <InternetReporting.h>

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

InternetReporting::InternetReporting(CommunicationService& commService,
                                       const KeyMotorData& keyMotorData,
                                       const MotorDetailsData& motor0DetailsData,
                                       const MotorDetailsData& motor1DetailsData,
                                       const DriverControlsData& driverControlsData,
                                       const MotorFaultsData& motorFaultsData,
                                       const BatteryFaultsData& batteryFaultsData,
                                       const BatteryData& batteryData,
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
    , batteryData_(batteryData)
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

void InternetReporting::makeKeyMotor(){
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

void InternetReporting::makeMotorDetails(int n){
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

void InternetReporting::makeDriverControls(){
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

void InternetReporting::makeMotorFaults(){
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

void InternetReporting::makeBatteryFaults(){
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

void InternetReporting::makeBattery(){

    Battery = QJsonObject();

    Battery.insert("Alive", batteryData_.alive);
    Battery.insert("PackSocAmpHours", batteryData_.packSocAmpHours);
    Battery.insert("PackSocPercentage", batteryData_.packSocPercentage);
    Battery.insert("PackBalanceSocAmpHours", batteryData_.packBalanceSoc);
    Battery.insert("PackBalanceSocPercentage", batteryData_.packBalanceSocPercentage);
    Battery.insert("ChargingCellVoltageError", batteryData_.chargingCellVoltageError);
    Battery.insert("CellTempMargin", batteryData_.cellTemperatureMargin);
    Battery.insert("DischargingCellVoltageError", batteryData_.dischargingCellVoltageError);
    Battery.insert("TotalPackCapacity", batteryData_.totalPackCapacity);
    Battery.insert("PrechargeContactor0DriverStatus", batteryData_.contactor0Status);
    Battery.insert("PrechargeContactor1DriverStatus", batteryData_.contactor1Status);
    Battery.insert("PrechargeContactor2DriverStatus", batteryData_.contactor2Status);
    Battery.insert("PrechargeContactor0DriverError", batteryData_.contactor0Errorstatus);
    Battery.insert("PrechargeContactor1DriverError", batteryData_.contactor1ErrorStatus);
    Battery.insert("PrechargeContactor2DriverError", batteryData_.contactor2ErrorStatus);
    Battery.insert("ContactorSupplyOK", batteryData_.contactor12VSupplyOk);

    Battery.insert("PrechargeState", batteryData_.prechargeStateJSON);
    Battery.insert("PrechargeTimerElapsed", batteryData_.prechargeTimerElapsed);
    Battery.insert("PrechargeTimeCount", batteryData_.prechargeTimerCount);

    QJsonObject LowestCellVoltage;
    LowestCellVoltage.insert("Voltage", batteryData_.lowestCellVoltage);
    LowestCellVoltage.insert("CmuNumber", batteryData_.lowestCellVoltageCmuNumber);
    LowestCellVoltage.insert("CellNumber", batteryData_.lowestCellVoltageCellNumber);

    Battery.insert("LowestCellVoltage", LowestCellVoltage);

    QJsonObject LowestCellTemp;
    LowestCellTemp.insert("Temp", batteryData_.lowestCellTemperature);
    LowestCellTemp.insert("CmuNumber", batteryData_.lowestCellTemperatureCmuNumber);
    LowestCellTemp.insert("CellNumber", batteryData_.lowestCellTemperatureCellNumber);

    Battery.insert("LowestCellTemp", LowestCellTemp);

    QJsonObject HighestCellVoltage;
    HighestCellVoltage.insert("Voltage", batteryData_.highestCellVoltage);
    HighestCellVoltage.insert("CmuNumber", batteryData_.highestCellVoltageCmuNumber);
    HighestCellVoltage.insert("CellNumber", batteryData_.highestCellVoltageCellNumber);

    Battery.insert("HighestCellVoltage", HighestCellVoltage);

    QJsonObject HighestCellTemp;
    HighestCellTemp.insert("Temp", batteryData_.highestCellTemperature);
    HighestCellTemp.insert("CmuNumber", batteryData_.highestCellTemperatureCmuNumber);
    HighestCellTemp.insert("CellNumber", batteryData_.highestCellTemperatureCellNumber);

    Battery.insert("HighestCellTemp", HighestCellTemp);

    Battery.insert("Voltage", batteryData_.voltage);
    Battery.insert("Current", batteryData_.current);
    Battery.insert("Fan0Speed", batteryData_.fan0Speed);
    Battery.insert("Fan1Speed", batteryData_.fan1Speed);
    Battery.insert("FanContactorsCurrent", batteryData_.fanContactors12VCurrentConsumption);
    Battery.insert("CmuCurrent", batteryData_.cmu12VCurrentConsumption);

}

void InternetReporting::makeCmu(){

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

void InternetReporting::makeMppt(){
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

void InternetReporting::makeLights(){
    lightsInfo = QJsonObject();

    lightsInfo.insert("LowBeams", lightsData_.lowBeams);
    lightsInfo.insert("HighBeams", lightsData_.highBeams);
    lightsInfo.insert("Brakes", lightsData_.brakes);
    lightsInfo.insert("LeftSignal", lightsData_.leftSignal);
    lightsInfo.insert("RightSignal", lightsData_.rightSignal);
    lightsInfo.insert("BmsStrobeLight", lightsData_.bmsStrobeLight);
}


void InternetReporting::sendKeyMotor()
{
    makeKeyMotor();

    QJsonDocument doc(KeyMotor);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);;
}

void InternetReporting::sendMotorDetails(int n)
{
    makeMotorDetails(n);

    QJsonDocument doc;

    if(n == 0)
        doc = QJsonDocument(MotorDetails0);
    if(n == 1)
        doc = QJsonDocument(MotorDetails0);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);;
}

void InternetReporting::sendDriverControls()
{
    makeDriverControls();

    QJsonDocument doc(DriverControls);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);
}

void InternetReporting::sendMotorFaults()
{
    makeMotorFaults();

    QJsonDocument doc(MotorFaults);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);
}

void InternetReporting::sendBatteryFaults()
{
    makeBatteryFaults();

    QJsonDocument doc(BatteryFaults);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);
}

void InternetReporting::sendBattery()
{
    makeBattery();

    QJsonDocument doc(Battery);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);
}

void InternetReporting::sendCmu()
{
    makeCmu();

    QJsonDocument doc(CMUArray);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);

}

void InternetReporting::sendMppt()
{

    makeMppt();

    QJsonDocument doc(mPPTArray);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);

}

void InternetReporting::sendLights()
{
    makeLights();

    QJsonDocument doc(lightsInfo);

    QByteArray data = doc.toBinaryData();
    communicationService_.sendDataInternet(data);

}

void InternetReporting::sendAll()
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
    communicationService_.sendDataInternet(data);

}


