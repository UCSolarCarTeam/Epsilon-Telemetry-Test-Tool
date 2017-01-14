#include <cstring>

#include <QIODevice>
#include <QDateTime>
#include <QJsonArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#include "CcsDefines.h"
#include "InternetReporting.h"
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "CmuData.h"
#include "DriverControlsData.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "CommunicationService.h"
#include "View.h"

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
                                     const LightsData& lightsData)
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
{
}

QJsonArray InternetReporting::makeKeyMotor()
{
    QJsonArray keyMotor;

    QJsonObject keyMotor0;
    keyMotor0.insert("Alive", keyMotorData_.motor0Alive);
    keyMotor0.insert("SetCurrent", keyMotorData_.motor0SetCurrent);
    keyMotor0.insert("SetVelocity", keyMotorData_.motor0SetVelocity);
    keyMotor0.insert("BusCurrent", keyMotorData_.motor0BusVoltage);
    keyMotor0.insert("BusVoltage", keyMotorData_.motor0BusVoltage);
    keyMotor0.insert("VehicleVelocity", keyMotorData_.motor0VehicleVelocity);
    keyMotor.push_back(keyMotor0);

    QJsonObject keyMotor1;
    keyMotor1.insert("Alive", keyMotorData_.motor1Alive);
    keyMotor1.insert("SetCurrent", keyMotorData_.motor1SetCurrent);
    keyMotor1.insert("SetVelocity", keyMotorData_.motor1SetVelocity);
    keyMotor1.insert("BusCurrent", keyMotorData_.motor1BusVoltage);
    keyMotor1.insert("BusVoltage", keyMotorData_.motor1BusVoltage);
    keyMotor1.insert("VehicleVelocity", keyMotorData_.motor1VehicleVelocity);
    keyMotor.push_back(keyMotor1);

    return keyMotor;
}

QJsonObject InternetReporting::makeMotorDetails(int n)
{
    QJsonObject motorDetails;

    if(n == 0)
    {
        motorDetails.insert("PhaseCCurrent", motor0DetailsData_.phaseCCurrent);
        motorDetails.insert("PhaseBCurrent", motor0DetailsData_.phaseBCurrent);
        motorDetails.insert("MotorVoltageReal", motor0DetailsData_.MotorVoltageReal);
        motorDetails.insert("MotorVoltageImaginary", motor0DetailsData_.MotorVoltageImaginary);
        motorDetails.insert("MotorCurrentReal", motor0DetailsData_.MotorCurrentReal);
        motorDetails.insert("MotorCurrentImaginary", motor0DetailsData_.MotorCurrentImaginary);
        motorDetails.insert("BackEmfReal", motor0DetailsData_.BackEmfReal);
        motorDetails.insert("VoltageRail15VSupply", motor0DetailsData_.RailSupply15V);
        motorDetails.insert("VoltageRail3VSupply", motor0DetailsData_.RailSupply3V);
        motorDetails.insert("VoltageRail1VSupply", motor0DetailsData_.RailSupply1V);
        motorDetails.insert("HeatSinkTemp", motor0DetailsData_.heatSinkTemperature);
        motorDetails.insert("MotorTemp", motor0DetailsData_.motorTemperature);
        motorDetails.insert("DspBoardTemp", motor0DetailsData_.dspBoardTempearture);
        motorDetails.insert("DcBusAmpHours", motor0DetailsData_.dcBusAmpHours);
        motorDetails.insert("Odometer", motor0DetailsData_.odometer);
        motorDetails.insert("Slipspeed", motor0DetailsData_.slipSpeed);

        return motorDetails;
    }


    else
    {
        motorDetails.insert("PhaseCCurrent", motor1DetailsData_.phaseCCurrent);
        motorDetails.insert("PhaseBCurrent", motor1DetailsData_.phaseBCurrent);
        motorDetails.insert("MotorVoltageReal", motor1DetailsData_.MotorVoltageReal);
        motorDetails.insert("MotorVoltageImaginary", motor1DetailsData_.MotorVoltageImaginary);
        motorDetails.insert("MotorCurrentReal", motor1DetailsData_.MotorCurrentReal);
        motorDetails.insert("MotorCurrentImaginary", motor1DetailsData_.MotorCurrentImaginary);
        motorDetails.insert("BackEmfReal", motor1DetailsData_.BackEmfReal);
        motorDetails.insert("VoltageRail15VSupply", motor1DetailsData_.RailSupply15V);
        motorDetails.insert("VoltageRail3VSupply", motor1DetailsData_.RailSupply3V);
        motorDetails.insert("VoltageRail1VSupply", motor1DetailsData_.RailSupply1V);
        motorDetails.insert("HeatSinkTemp", motor1DetailsData_.heatSinkTemperature);
        motorDetails.insert("MotorTemp", motor1DetailsData_.motorTemperature);
        motorDetails.insert("DspBoardTemp", motor1DetailsData_.dspBoardTempearture);
        motorDetails.insert("DcBusAmpHours", motor1DetailsData_.dcBusAmpHours);
        motorDetails.insert("Odometer", motor1DetailsData_.odometer);
        motorDetails.insert("Slipspeed", motor1DetailsData_.slipSpeed);

        return motorDetails;
    }
}

QJsonObject InternetReporting::makeDriverControls()
{
    QJsonObject driverControls;

    driverControls.insert("Alive", driverControlsData_.alive);
    driverControls.insert("HeadlightsOff", driverControlsData_.headlightsOff);
    driverControls.insert("HeadLightsLow", driverControlsData_.headlightsLow);
    driverControls.insert("HeadlightsHigh", driverControlsData_.headlightsHigh);
    driverControls.insert("SignalRight", driverControlsData_.signalRight);
    driverControls.insert("SignalLeft", driverControlsData_.signalLeft);
    driverControls.insert("Hazard", driverControlsData_.hazardLights);
    driverControls.insert("Interior", driverControlsData_.interiorLights);
    driverControls.insert("Aux", driverControlsData_.musicAux);
    driverControls.insert("VolumeUp", driverControlsData_.volumeUp);
    driverControls.insert("VolumeDown", driverControlsData_.volumeDown);
    driverControls.insert("NextSong", driverControlsData_.nextSong);
    driverControls.insert("PrevSong", driverControlsData_.prevSong);
    driverControls.insert("Acceleration", driverControlsData_.acceleration);
    driverControls.insert("RegenBraking", driverControlsData_.regenBraking);
    driverControls.insert("Brakes", driverControlsData_.brakes);
    driverControls.insert("Forward", driverControlsData_.forward);
    driverControls.insert("Reverse", driverControlsData_.reverse);
    driverControls.insert("PushToTalk", driverControlsData_.pushToTalk);
    driverControls.insert("Horn", driverControlsData_.horn);
    driverControls.insert("Reset", driverControlsData_.reset);

    return driverControls;

}

QJsonArray InternetReporting::makeMotorFaults()
{
    QJsonArray motorFaults;

    QJsonObject motorFaults0;

    QJsonObject errorFlags0;
    errorFlags0.insert("MotorOverSpeed", motorFaultsData_.motor0OverSpeed);
    errorFlags0.insert("SoftwareOverCurrent", motorFaultsData_.motor0SoftwareOverCurrent);
    errorFlags0.insert("DcBusOverVoltage", motorFaultsData_.motor0DcBusOverVoltage);
    errorFlags0.insert("BadMototPositionHallSequence", motorFaultsData_.motor0BadMootorPositionHallSequence);
    errorFlags0.insert("WatchdogCausedLastReset", motorFaultsData_.motor0WatchdogCausedLastReset);
    errorFlags0.insert("ConfigReadError", motorFaultsData_.motor0ConfigReadError);
    errorFlags0.insert("Rail15VUnderVoltageLockOut", motorFaultsData_.motor0Rail15VUnderVoltageLockOut);
    errorFlags0.insert("DesaturationFault", motorFaultsData_.motor0DesaturationFault);
    motorFaults0.insert("Error Flags", errorFlags0);

    QJsonObject limitFlags0;
    limitFlags0.insert("OutputVoltagePwm", motorFaultsData_.motor0OutputVoltagePwmLimit);
    limitFlags0.insert("MotorCurrent", motorFaultsData_.motor0MotorCurrentLimit);
    limitFlags0.insert("Velocity", motorFaultsData_.motor0VelocityLimit);
    limitFlags0.insert("BusCurrent", motorFaultsData_.motor0BusCurrentLimit);
    limitFlags0.insert("BusVoltageUpper", motorFaultsData_.motor0BusVoltageUpperLimit);
    limitFlags0.insert("BusVoltageLower", motorFaultsData_.motor0BusVoltageLowerLimit);
    limitFlags0.insert("IpmOrMotorTemperature", motorFaultsData_.motor0IpmOrMotorTemperatureLimit);
    motorFaults0.insert("LimitFlags", limitFlags0);

    motorFaults0.insert("RxErrorCount", motorFaultsData_.motor0RxErrorCount);
    motorFaults0.insert("TxErrorCount", motorFaultsData_.motor0TxErrorCount);

    motorFaults.push_back(motorFaults0);

    QJsonObject motorFaults1;

    QJsonObject errorFlags1;
    errorFlags1.insert("MotorOverSpeed", motorFaultsData_.motor1OverSpeed);
    errorFlags1.insert("SoftwareOverCurrent", motorFaultsData_.motor1SoftwareOverCurrent);
    errorFlags1.insert("DcBusOverVoltage", motorFaultsData_.motor1DcBusOverVoltage);
    errorFlags1.insert("BadMototPositionHallSequence", motorFaultsData_.motor1BadMootorPositionHallSequence);
    errorFlags1.insert("WatchdogCausedLastReset", motorFaultsData_.motor1WatchdogCausedLastReset);
    errorFlags1.insert("ConfigReadError", motorFaultsData_.motor1ConfigReadError);
    errorFlags1.insert("Rail15VUnderVoltageLockOut", motorFaultsData_.motor1Rail15VUnderVoltageLockOut);
    errorFlags1.insert("DesaturationFault", motorFaultsData_.motor1DesaturationFault);
    motorFaults1.insert("Error Flags", errorFlags1);

    QJsonObject limitFlags1;
    limitFlags1.insert("OutputVoltagePwm", motorFaultsData_.motor1OutputVoltagePwmLimit);
    limitFlags1.insert("MotorCurrent", motorFaultsData_.motor1MotorCurrentLimit);
    limitFlags1.insert("Velocity", motorFaultsData_.motor1VelocityLimit);
    limitFlags1.insert("BusCurrent", motorFaultsData_.motor1BusCurrentLimit);
    limitFlags1.insert("BusVoltageUpper", motorFaultsData_.motor1BusVoltageUpperLimit);
    limitFlags1.insert("BusVoltageLower", motorFaultsData_.motor1BusVoltageLowerLimit);
    limitFlags1.insert("IpmOrMotorTemperature", motorFaultsData_.motor1IpmOrMotorTemperatureLimit);
    motorFaults1.insert("LimitFlags", limitFlags1);

    motorFaults1.insert("RxErrorCount", motorFaultsData_.motor1RxErrorCount);
    motorFaults1.insert("TxErrorCount", motorFaultsData_.motor1TxErrorCount);

    motorFaults.push_back(motorFaults1);

    return motorFaults;
}

QJsonObject InternetReporting::makeBatteryFaults()
{
    QJsonObject batteryFaults;

    batteryFaults.insert("CellOverVoltage", batteryFaultsData_.cellOverVoltage);
    batteryFaults.insert("CellUnderVoltage", batteryFaultsData_.cellOverVoltage);
    batteryFaults.insert("CellOverTemp", batteryFaultsData_.cellOverTemperature);
    batteryFaults.insert("MeasurementUntrusted", batteryFaultsData_.measurementUntrusted);
    batteryFaults.insert("CMUCommTimeout", batteryFaultsData_.cmuCommTimeout);
    batteryFaults.insert("BMUSetupMode", batteryFaultsData_.bmuInSetupMode);
    batteryFaults.insert("CMUCANBusPowerStatus", batteryFaultsData_.cmuCanBusPowerStatus);
    batteryFaults.insert("PackIsolationFailure", batteryFaultsData_.packIsolationTestFailure);
    batteryFaults.insert("SoftwareOverCurrent", batteryFaultsData_.softwareOverCurrent);
    batteryFaults.insert("CAN12VSupplyLow", batteryFaultsData_.can12VSupplyLow);
    batteryFaults.insert("ContactorStuck", batteryFaultsData_.contactorStuck);
    batteryFaults.insert("CMUDetectedExtraCell", batteryFaultsData_.cmuDetectedExtraCellPresent);

    return batteryFaults;
}

QJsonObject InternetReporting::makeBattery()
{

    QJsonObject battery;

    battery.insert("Alive", batteryData_.alive);
    battery.insert("PackSocAmpHours", batteryData_.packSocAmpHours);
    battery.insert("PackSocPercentage", batteryData_.packSocPercentage);
    battery.insert("PackBalanceSocAmpHours", batteryData_.packBalanceSoc);
    battery.insert("PackBalanceSocPercentage", batteryData_.packBalanceSocPercentage);
    battery.insert("ChargingCellVoltageError", batteryData_.chargingCellVoltageError);
    battery.insert("CellTempMargin", batteryData_.cellTemperatureMargin);
    battery.insert("DischargingCellVoltageError", batteryData_.dischargingCellVoltageError);
    battery.insert("TotalPackCapacity", batteryData_.totalPackCapacity);
    battery.insert("PrechargeContactor0DriverStatus", batteryData_.contactor0Status);
    battery.insert("PrechargeContactor1DriverStatus", batteryData_.contactor1Status);
    battery.insert("PrechargeContactor2DriverStatus", batteryData_.contactor2Status);
    battery.insert("PrechargeContactor0DriverError", batteryData_.contactor0Errorstatus);
    battery.insert("PrechargeContactor1DriverError", batteryData_.contactor1ErrorStatus);
    battery.insert("PrechargeContactor2DriverError", batteryData_.contactor2ErrorStatus);
    battery.insert("ContactorSupplyOK", batteryData_.contactor12VSupplyOk);
    battery.insert("PrechargeState", batteryData_.prechargeStateJSON);
    battery.insert("PrechargeTimerElapsed", batteryData_.prechargeTimerElapsed);
    battery.insert("PrechargeTimeCount", batteryData_.prechargeTimerCount);

    QJsonObject lowestCellVoltage;
    lowestCellVoltage.insert("Voltage", batteryData_.lowestCellVoltage);
    lowestCellVoltage.insert("CmuNumber", batteryData_.lowestCellVoltageCmuNumber);
    lowestCellVoltage.insert("CellNumber", batteryData_.lowestCellVoltageCellNumber);
    battery.insert("LowestCellVoltage", lowestCellVoltage);

    QJsonObject lowestCellTemp;
    lowestCellTemp.insert("Temp", batteryData_.lowestCellTemperature);
    lowestCellTemp.insert("CmuNumber", batteryData_.lowestCellTemperatureCmuNumber);
    lowestCellTemp.insert("CellNumber", batteryData_.lowestCellTemperatureCellNumber);
    battery.insert("LowestCellTemp", lowestCellTemp);

    QJsonObject highestCellVoltage;
    highestCellVoltage.insert("Voltage", batteryData_.highestCellVoltage);
    highestCellVoltage.insert("CmuNumber", batteryData_.highestCellVoltageCmuNumber);
    highestCellVoltage.insert("CellNumber", batteryData_.highestCellVoltageCellNumber);
    battery.insert("HighestCellVoltage", highestCellVoltage);

    QJsonObject highestCellTemp;
    highestCellTemp.insert("Temp", batteryData_.highestCellTemperature);
    highestCellTemp.insert("CmuNumber", batteryData_.highestCellTemperatureCmuNumber);
    highestCellTemp.insert("CellNumber", batteryData_.highestCellTemperatureCellNumber);
    battery.insert("HighestCellTemp", highestCellTemp);

    battery.insert("Voltage", batteryData_.voltage);
    battery.insert("Current", batteryData_.current);
    battery.insert("Fan0Speed", batteryData_.fan0Speed);
    battery.insert("Fan1Speed", batteryData_.fan1Speed);
    battery.insert("FanContactorsCurrent", batteryData_.fanContactors12VCurrentConsumption);
    battery.insert("CmuCurrent", batteryData_.cmu12VCurrentConsumption);

    return battery;

}

QJsonArray InternetReporting::makeCmu()
{

    QJsonObject cMUInfo;

    QJsonArray cMUArray;

    QJsonArray cellVoltageInfo;
    for (int i = 0; i < 8; i++)
    {
        cellVoltageInfo.push_back(cmuData_.cellVoltage[i]);
    }

    cMUInfo.insert("Voltages", cellVoltageInfo);

    cMUInfo.insert("PcbTemp", cmuData_.pcbTemperature);

    QJsonArray cellTemperatureInfo;
    for (int i = 0; i < 15; i++)
    {
        cellTemperatureInfo.push_back(cmuData_.cellTemperature[i]);
    }

    cMUInfo.insert("CellTemps", cellTemperatureInfo);

    for(unsigned char i = 0; i < CcsDefines::CMU_COUNT; i++)
    {
        cMUArray.push_back(cMUInfo);
    }

    return cMUArray;

}

QJsonArray InternetReporting::makeMppt()
{
    QJsonArray mPPTArray;

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

    return mPPTArray;
}

QJsonObject InternetReporting::makeLights()
{
    QJsonObject lightsInfo;
    lightsInfo.insert("LowBeams", lightsData_.lowBeams);
    lightsInfo.insert("HighBeams", lightsData_.highBeams);
    lightsInfo.insert("Brakes", lightsData_.brakes);
    lightsInfo.insert("LeftSignal", lightsData_.leftSignal);
    lightsInfo.insert("RightSignal", lightsData_.rightSignal);
    lightsInfo.insert("BmsStrobeLight", lightsData_.bmsStrobeLight);

    return lightsInfo;
}

void InternetReporting::sendAll()
{   
    QJsonObject obj;
    QDateTime date = date.currentDateTime();
    QString dateString = date.toString("yyyy-MM-dd hh:mm:ss.zzz");

    QJsonArray motorDetails;
    motorDetails.push_back(makeMotorDetails(0));
    motorDetails.push_back(makeMotorDetails(1));

    obj.insert("PacketTitle", "UofC Solar Car Gen 5");
    obj.insert("TimeStamp", dateString);
    obj.insert("KeyMotor", makeKeyMotor());
    obj.insert("MotorDetails", motorDetails);
    obj.insert("DriverControls", makeDriverControls());
    obj.insert("MotorFaults", makeMotorFaults());
    obj.insert("BatteryFaults", makeBatteryFaults());
    obj.insert("Battery", makeBattery());
    obj.insert("CMU", makeCmu());
    obj.insert("MPPT", makeMppt());
    obj.insert("Lights", makeLights());

    QJsonDocument doc(obj);
    QByteArray data = doc.toBinaryData();
    communicationService_.sendInternetData(data);
}


