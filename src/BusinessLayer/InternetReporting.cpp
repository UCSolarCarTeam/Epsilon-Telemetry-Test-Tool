#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <vector>

#include "AuxBmsData.h"
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "CcsDefines.h"
#include "DriverControlsData.h"
#include "I_CommunicationService.h"
#include "InternetReporting.h"
#include "InternetView.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "DataContainer.h"

InternetReporting::InternetReporting(I_CommunicationService& commService,
                                     DataContainer& dataContainer0,
                                     DataContainer& dataContainer1,
                                     InternetView& view)

    : communicationService_(commService)
    , view_(view)
    , packetNum(0)
{
    dataContainerList.push_back(&dataContainer0);
    dataContainerList.push_back(&dataContainer1);
    connect(&view_, SIGNAL(sendAll(int)), this, SLOT(sendAll(int)));
}

QJsonArray InternetReporting::makeKeyMotor()
{
    QJsonArray keyMotor;
    QJsonObject keyMotor0;
    keyMotor0.insert("Alive", dataContainerList[packetNum]->getKeyMotorData().motor0Alive());
    keyMotor0.insert("SetCurrent", dataContainerList[packetNum]->getKeyMotorData().motor0SetCurrent());
    keyMotor0.insert("SetVelocity", dataContainerList[packetNum]->getKeyMotorData().motor0SetVelocity());
    keyMotor0.insert("BusCurrent", dataContainerList[packetNum]->getKeyMotorData().motor0BusCurrent());
    keyMotor0.insert("BusVoltage", dataContainerList[packetNum]->getKeyMotorData().motor0BusVoltage());
    keyMotor0.insert("VehicleVelocity", dataContainerList[packetNum]->getKeyMotorData().motor0VehicleVelocity());
    keyMotor.push_back(keyMotor0);
    QJsonObject keyMotor1;
    keyMotor1.insert("Alive", dataContainerList[packetNum]->getKeyMotorData().motor1Alive());
    keyMotor1.insert("SetCurrent", dataContainerList[packetNum]->getKeyMotorData().motor1SetCurrent());
    keyMotor1.insert("SetVelocity", dataContainerList[packetNum]->getKeyMotorData().motor1SetVelocity());
    keyMotor1.insert("BusCurrent", dataContainerList[packetNum]->getKeyMotorData().motor1BusCurrent());
    keyMotor1.insert("BusVoltage", dataContainerList[packetNum]->getKeyMotorData().motor1BusVoltage());
    keyMotor1.insert("VehicleVelocity", dataContainerList[packetNum]->getKeyMotorData().motor1VehicleVelocity());
    keyMotor.push_back(keyMotor1);
    return keyMotor;
}

QJsonObject InternetReporting::makeMotorDetails(int n)
{
    QJsonObject motorDetails;

    if (n == 0)
    {
        motorDetails.insert("PhaseCCurrent", dataContainerList[packetNum]->getMotor0DetailsData().phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", dataContainerList[packetNum]->getMotor0DetailsData().phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", dataContainerList[packetNum]->getMotor0DetailsData().MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", dataContainerList[packetNum]->getMotor0DetailsData().MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", dataContainerList[packetNum]->getMotor0DetailsData().MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", dataContainerList[packetNum]->getMotor0DetailsData().MotorCurrentImaginary());
        motorDetails.insert("BackEmf", dataContainerList[packetNum]->getMotor0DetailsData().BackEmf());
        motorDetails.insert("VoltageRail15VSupply", dataContainerList[packetNum]->getMotor0DetailsData().RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", dataContainerList[packetNum]->getMotor0DetailsData().RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", dataContainerList[packetNum]->getMotor0DetailsData().RailSupply1V());
        motorDetails.insert("HeatSinkTemp", dataContainerList[packetNum]->getMotor0DetailsData().heatSinkTemperature());
        motorDetails.insert("MotorTemp", dataContainerList[packetNum]->getMotor0DetailsData().motorTemperature());
        motorDetails.insert("DspBoardTemp", dataContainerList[packetNum]->getMotor0DetailsData().dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", dataContainerList[packetNum]->getMotor0DetailsData().dcBusAmpHours());
        motorDetails.insert("Odometer", dataContainerList[packetNum]->getMotor0DetailsData().odometer());
        motorDetails.insert("SlipSpeed", dataContainerList[packetNum]->getMotor0DetailsData().slipSpeed());
    }
    else
    {
        motorDetails.insert("PhaseCCurrent", dataContainerList[packetNum]->getMotor1DetailsData().phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", dataContainerList[packetNum]->getMotor1DetailsData().phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", dataContainerList[packetNum]->getMotor1DetailsData().MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", dataContainerList[packetNum]->getMotor1DetailsData().MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", dataContainerList[packetNum]->getMotor1DetailsData().MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", dataContainerList[packetNum]->getMotor1DetailsData().MotorCurrentImaginary());
        motorDetails.insert("BackEmf", dataContainerList[packetNum]->getMotor1DetailsData().BackEmf());
        motorDetails.insert("VoltageRail15VSupply", dataContainerList[packetNum]->getMotor1DetailsData().RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", dataContainerList[packetNum]->getMotor1DetailsData().RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", dataContainerList[packetNum]->getMotor1DetailsData().RailSupply1V());
        motorDetails.insert("HeatSinkTemp", dataContainerList[packetNum]->getMotor1DetailsData().heatSinkTemperature());
        motorDetails.insert("MotorTemp", dataContainerList[packetNum]->getMotor1DetailsData().motorTemperature());
        motorDetails.insert("DspBoardTemp", dataContainerList[packetNum]->getMotor1DetailsData().dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", dataContainerList[packetNum]->getMotor1DetailsData().dcBusAmpHours());
        motorDetails.insert("Odometer", dataContainerList[packetNum]->getMotor1DetailsData().odometer());
        motorDetails.insert("SlipSpeed", dataContainerList[packetNum]->getMotor1DetailsData().slipSpeed());
    }

    return motorDetails;
}

QJsonObject InternetReporting::makeDriverControls()
{
    QJsonObject driverControls;
    driverControls.insert("Alive", dataContainerList[packetNum]->getDriverControlsData().alive());
    driverControls.insert("HeadlightsOff", dataContainerList[packetNum]->getDriverControlsData().headlightsOff());
    driverControls.insert("HeadlightsLow", dataContainerList[packetNum]->getDriverControlsData().headlightsLow());
    driverControls.insert("HeadlightsHigh", dataContainerList[packetNum]->getDriverControlsData().headlightsHigh());
    driverControls.insert("SignalRight", dataContainerList[packetNum]->getDriverControlsData().signalRight());
    driverControls.insert("SignalLeft", dataContainerList[packetNum]->getDriverControlsData().signalLeft());
    driverControls.insert("Hazard", dataContainerList[packetNum]->getDriverControlsData().hazardLights());
    driverControls.insert("Interior", dataContainerList[packetNum]->getDriverControlsData().interiorLights());
    driverControls.insert("VolumeUp", dataContainerList[packetNum]->getDriverControlsData().volumeUp());
    driverControls.insert("VolumeDown", dataContainerList[packetNum]->getDriverControlsData().volumeDown());
    driverControls.insert("NextSong", dataContainerList[packetNum]->getDriverControlsData().nextSong());
    driverControls.insert("PrevSong", dataContainerList[packetNum]->getDriverControlsData().prevSong());
    driverControls.insert("Acceleration", dataContainerList[packetNum]->getDriverControlsData().acceleration());
    driverControls.insert("RegenBraking", dataContainerList[packetNum]->getDriverControlsData().regenBraking());
    driverControls.insert("Brakes", dataContainerList[packetNum]->getDriverControlsData().brakes());
    driverControls.insert("Forward", dataContainerList[packetNum]->getDriverControlsData().forward());
    driverControls.insert("Reverse", dataContainerList[packetNum]->getDriverControlsData().reverse());
    driverControls.insert("PushToTalk", dataContainerList[packetNum]->getDriverControlsData().pushToTalk());
    driverControls.insert("Horn", dataContainerList[packetNum]->getDriverControlsData().horn());
    driverControls.insert("Reset", dataContainerList[packetNum]->getDriverControlsData().reset());
    driverControls.insert("Aux", dataContainerList[packetNum]->getDriverControlsData().aux());
    return driverControls;
}

QJsonArray InternetReporting::makeMotorFaults()
{
    QJsonArray motorFaults;
    QJsonObject motorFaults0;
    QJsonObject motorFaults1;
    QJsonObject errorFlags0;
    errorFlags0.insert("MotorOverSpeed", dataContainerList[packetNum]->getMotorFaultsData().motor0OverSpeed());
    errorFlags0.insert("SoftwareOverCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor0SoftwareOverCurrent());
    errorFlags0.insert("DcBusOverVoltage", dataContainerList[packetNum]->getMotorFaultsData().motor0DcBusOverVoltage());
    errorFlags0.insert("BadMotorPositionHallSequence", dataContainerList[packetNum]->getMotorFaultsData().motor0BadMotorPositionHallSequence());
    errorFlags0.insert("WatchdogCausedLastReset", dataContainerList[packetNum]->getMotorFaultsData().motor0WatchdogCausedLastReset());
    errorFlags0.insert("ConfigReadError", dataContainerList[packetNum]->getMotorFaultsData().motor0ConfigReadError());
    errorFlags0.insert("Rail15VUnderVoltageLockOut", dataContainerList[packetNum]->getMotorFaultsData().motor0Rail15VUnderVoltageLockOut());
    errorFlags0.insert("DesaturationFault", dataContainerList[packetNum]->getMotorFaultsData().motor0DesaturationFault());
    motorFaults0.insert("ErrorFlags", errorFlags0);
    QJsonObject limitFlags0;
    limitFlags0.insert("OutputVoltagePwm", dataContainerList[packetNum]->getMotorFaultsData().motor0OutputVoltagePwmLimit());
    limitFlags0.insert("MotorCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor0MotorCurrentLimit());
    limitFlags0.insert("Velocity", dataContainerList[packetNum]->getMotorFaultsData().motor0VelocityLimit());
    limitFlags0.insert("BusCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor0BusCurrentLimit());
    limitFlags0.insert("BusVoltageUpper", dataContainerList[packetNum]->getMotorFaultsData().motor0BusVoltageUpperLimit());
    limitFlags0.insert("BusVoltageLower", dataContainerList[packetNum]->getMotorFaultsData().motor0BusVoltageLowerLimit());
    limitFlags0.insert("IpmOrMotorTemperature", dataContainerList[packetNum]->getMotorFaultsData().motor0IpmOrMotorTemperatureLimit());
    motorFaults0.insert("LimitFlags", limitFlags0);
    motorFaults0.insert("RxErrorCount", dataContainerList[packetNum]->getMotorFaultsData().motor0RxErrorCount());
    motorFaults0.insert("TxErrorCount", dataContainerList[packetNum]->getMotorFaultsData().motor0TxErrorCount());
    motorFaults.push_back(motorFaults0);
    QJsonObject errorFlags1;
    errorFlags1.insert("MotorOverSpeed", dataContainerList[packetNum]->getMotorFaultsData().motor1OverSpeed());
    errorFlags1.insert("SoftwareOverCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor1SoftwareOverCurrent());
    errorFlags1.insert("DcBusOverVoltage", dataContainerList[packetNum]->getMotorFaultsData().motor1DcBusOverVoltage());
    errorFlags1.insert("BadMotorPositionHallSequence", dataContainerList[packetNum]->getMotorFaultsData().motor1BadMotorPositionHallSequence());
    errorFlags1.insert("WatchdogCausedLastReset", dataContainerList[packetNum]->getMotorFaultsData().motor1WatchdogCausedLastReset());
    errorFlags1.insert("ConfigReadError", dataContainerList[packetNum]->getMotorFaultsData().motor1ConfigReadError());
    errorFlags1.insert("Rail15VUnderVoltageLockOut", dataContainerList[packetNum]->getMotorFaultsData().motor1Rail15VUnderVoltageLockOut());
    errorFlags1.insert("DesaturationFault", dataContainerList[packetNum]->getMotorFaultsData().motor1DesaturationFault());
    motorFaults1.insert("ErrorFlags", errorFlags1);
    QJsonObject limitFlags1;
    limitFlags1.insert("OutputVoltagePwm", dataContainerList[packetNum]->getMotorFaultsData().motor1OutputVoltagePwmLimit());
    limitFlags1.insert("MotorCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor1MotorCurrentLimit());
    limitFlags1.insert("Velocity", dataContainerList[packetNum]->getMotorFaultsData().motor1VelocityLimit());
    limitFlags1.insert("BusCurrent", dataContainerList[packetNum]->getMotorFaultsData().motor1BusCurrentLimit());
    limitFlags1.insert("BusVoltageUpper", dataContainerList[packetNum]->getMotorFaultsData().motor1BusVoltageUpperLimit());
    limitFlags1.insert("BusVoltageLower", dataContainerList[packetNum]->getMotorFaultsData().motor1BusVoltageLowerLimit());
    limitFlags1.insert("IpmOrMotorTemperature", dataContainerList[packetNum]->getMotorFaultsData().motor1IpmOrMotorTemperatureLimit());
    motorFaults1.insert("LimitFlags", limitFlags1);
    motorFaults1.insert("RxErrorCount", dataContainerList[packetNum]->getMotorFaultsData().motor1RxErrorCount());
    motorFaults1.insert("TxErrorCount", dataContainerList[packetNum]->getMotorFaultsData().motor1TxErrorCount());
    motorFaults.push_back(motorFaults1);
    return motorFaults;
}

QJsonObject InternetReporting::makeBatteryFaults()
{
    QJsonObject batteryFaults;
    QJsonObject errorFlags;
    errorFlags.insert("InternalCommunicationFault", dataContainerList[packetNum]->getBatteryFaultsData().internalCommFault());
    errorFlags.insert("InternalConversionFault", dataContainerList[packetNum]->getBatteryFaultsData().internalConversionFault());
    errorFlags.insert("WeakCellFault", dataContainerList[packetNum]->getBatteryFaultsData().weakCellFault());
    errorFlags.insert("LowCellVoltageFault", dataContainerList[packetNum]->getBatteryFaultsData().lowCellVoltageFault());
    errorFlags.insert("OpenWiringFault", dataContainerList[packetNum]->getBatteryFaultsData().openWiringFault());
    errorFlags.insert("CurrentSensorFault", dataContainerList[packetNum]->getBatteryFaultsData().currentSensorFault());
    errorFlags.insert("PackVoltageSensorFault", dataContainerList[packetNum]->getBatteryFaultsData().packVoltageSensorFault());
    errorFlags.insert("WeakPackFault", dataContainerList[packetNum]->getBatteryFaultsData().weakPackFault());
    errorFlags.insert("VoltageRedundancyFault", dataContainerList[packetNum]->getBatteryFaultsData().voltageRedundancyFault());
    errorFlags.insert("FanMonitorFault", dataContainerList[packetNum]->getBatteryFaultsData().fanMonitorFault());
    errorFlags.insert("ThermistorFault", dataContainerList[packetNum]->getBatteryFaultsData().thermistorFault());
    errorFlags.insert("CANBUSCommunicationsFault", dataContainerList[packetNum]->getBatteryFaultsData().canbusCommsFault());
    errorFlags.insert("AlwaysOnSupplyFault", dataContainerList[packetNum]->getBatteryFaultsData().alwaysOnSupplyFault());
    errorFlags.insert("HighVoltageIsolationFault", dataContainerList[packetNum]->getBatteryFaultsData().highVoltageIsolationFault());
    errorFlags.insert("12vPowerSupplyFault", dataContainerList[packetNum]->getBatteryFaultsData().powerSupplyFault());
    errorFlags.insert("ChargeLimitEnforcementFault", dataContainerList[packetNum]->getBatteryFaultsData().chargeLimitFault());
    errorFlags.insert("DischargeLimitEnforcementFault", dataContainerList[packetNum]->getBatteryFaultsData().dischargeLimitFault());
    errorFlags.insert("ChargerSafetyRelayFault", dataContainerList[packetNum]->getBatteryFaultsData().chargerSafetyRelayFault());
    errorFlags.insert("InternalMemoryFault", dataContainerList[packetNum]->getBatteryFaultsData().internalMemFault());
    errorFlags.insert("InternalThermistorFault", dataContainerList[packetNum]->getBatteryFaultsData().internalThermistorFault());
    errorFlags.insert("InternalLogicFault", dataContainerList[packetNum]->getBatteryFaultsData().internalLogicFault());
    batteryFaults.insert("ErrorFlags", errorFlags);
    QJsonObject limitFlags;
    limitFlags.insert("DclReducedDueToLowSoc", dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowSoc());
    limitFlags.insert("DclReducedDueToHighCellResistance", dataContainerList[packetNum]->getBatteryFaultsData().dclReducedHighCellResist());
    limitFlags.insert("DclReducedDueToTemperature", dataContainerList[packetNum]->getBatteryFaultsData().dclReducedDueToTemp());
    limitFlags.insert("DclReducedDueToLowCellVoltage", dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowCellVoltage());
    limitFlags.insert("DclReducedDueToLowPackVoltage", dataContainerList[packetNum]->getBatteryFaultsData().dclReducedLowPackVoltage());
    limitFlags.insert("DclandCclReducedDueToVoltageFailsafe", dataContainerList[packetNum]->getBatteryFaultsData().dclCclReducedVoltageFailsafe());
    limitFlags.insert("DclandCclReducedDueToCommunicationFailsafe", dataContainerList[packetNum]->getBatteryFaultsData().dclCclReducedCommsFailsafe());
    limitFlags.insert("CclReducedDueToHighSoc", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighSoc());
    limitFlags.insert("CclReducedDueToHighCellResistance", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighCellResist());
    limitFlags.insert("CclReducedDueToTemperature", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedDueToTemp());
    limitFlags.insert("CclReducedDueToHighCellVoltage", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighCellVoltage());
    limitFlags.insert("CclReducedDueToHighPackVoltage", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedHighPackVoltage());
    limitFlags.insert("CclReducedDueToChargerLatch", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedChargerLatch());
    limitFlags.insert("CclReducedDueToAlternateCurrentLimit", dataContainerList[packetNum]->getBatteryFaultsData().cclReducedACLimit());
    batteryFaults.insert("LimitFlags", limitFlags);
    return batteryFaults;
}

QJsonObject InternetReporting::makeBattery()
{
    QJsonObject battery;
    battery.insert("Alive", dataContainerList[packetNum]->getBatteryData().alive());
    QJsonObject bmsRelayStatusFlags;
    bmsRelayStatusFlags.insert("DischargeRelayEnabled", dataContainerList[packetNum]->getBatteryData().dischargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargeRelayEnabled", dataContainerList[packetNum]->getBatteryData().chargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargerSafetyEnabled", dataContainerList[packetNum]->getBatteryData().chargerSafetyEnabled());
    bmsRelayStatusFlags.insert("MalfunctionIndicatorActive", dataContainerList[packetNum]->getBatteryData().malfunctionIndicatorActive());
    bmsRelayStatusFlags.insert("MultiPurposeInputSignalStatus", dataContainerList[packetNum]->getBatteryData().multiPurposeInputSignalStatus());
    bmsRelayStatusFlags.insert("AlwaysOnSignalStatus", dataContainerList[packetNum]->getBatteryData().alwaysOnSignalStatus());
    bmsRelayStatusFlags.insert("IsReadySignalStatus", dataContainerList[packetNum]->getBatteryData().isReadySignalStatus());
    bmsRelayStatusFlags.insert("IsChargingSignalStatus", dataContainerList[packetNum]->getBatteryData().isChargingSignalStatus());
    battery.insert("BMSRelayStatusFlags", bmsRelayStatusFlags);
    battery.insert("PopulatedCells", dataContainerList[packetNum]->getBatteryData().populatedCells());
    battery.insert("12vInputVoltage", dataContainerList[packetNum]->getBatteryData().inputVoltage12V());
    battery.insert("FanVoltage", dataContainerList[packetNum]->getBatteryData().fanVoltage());
    battery.insert("PackCurrent", dataContainerList[packetNum]->getBatteryData().packCurrent());
    battery.insert("PackVoltage", dataContainerList[packetNum]->getBatteryData().packVoltage());
    battery.insert("PackStateOfCharge", dataContainerList[packetNum]->getBatteryData().packStateOfCharge());
    battery.insert("PackAmphours", dataContainerList[packetNum]->getBatteryData().packAmpHours());
    battery.insert("PackDepthOfDischarge", dataContainerList[packetNum]->getBatteryData().packDepthOfDischarge());
    battery.insert("HighTemperature", dataContainerList[packetNum]->getBatteryData().highTemperature());
    battery.insert("HighThermistorId", dataContainerList[packetNum]->getBatteryData().highThermistorId());
    battery.insert("LowTemperature", dataContainerList[packetNum]->getBatteryData().lowTemperature());
    battery.insert("LowThermistorId", dataContainerList[packetNum]->getBatteryData().lowThermistorId());
    battery.insert("AverageTemperature", dataContainerList[packetNum]->getBatteryData().averageTemperature());
    battery.insert("InternalTemperature", dataContainerList[packetNum]->getBatteryData().internalTemperature());
    battery.insert("FanSpeed", dataContainerList[packetNum]->getBatteryData().fanSpeed());
    battery.insert("RequestedFanSpeed", dataContainerList[packetNum]->getBatteryData().requestedFanSpeed());
    battery.insert("LowCellVoltage", dataContainerList[packetNum]->getBatteryData().lowCellVoltage());
    battery.insert("LowCellVoltageId", dataContainerList[packetNum]->getBatteryData().lowCellVoltageId());
    battery.insert("HighCellVoltage", dataContainerList[packetNum]->getBatteryData().highCellVoltage());
    battery.insert("HighCellVoltageId", dataContainerList[packetNum]->getBatteryData().highCellVoltageId());
    battery.insert("AverageCellVoltage", dataContainerList[packetNum]->getBatteryData().averageCellVoltage());
    return battery;
}

QJsonArray InternetReporting::makeMppt()
{
    QJsonArray mppt;
    QJsonObject mpptInfo;

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        mpptInfo.insert("Alive", dataContainerList[packetNum]->getMpptData().alive());
        mpptInfo.insert("ArrayVoltage", dataContainerList[packetNum]->getMpptData().arrayVoltage());
        mpptInfo.insert("ArrayCurrent", dataContainerList[packetNum]->getMpptData().arrayCurrent());
        mpptInfo.insert("BatteryVoltage", dataContainerList[packetNum]->getMpptData().batteryVoltage());
        mpptInfo.insert("Temperature", dataContainerList[packetNum]->getMpptData().temperature());
        mppt.push_back(mpptInfo);
    }

    return mppt;
}

QJsonObject InternetReporting::makeLights()
{
    QJsonObject lightsInfo;
    lightsInfo.insert("Alive", dataContainerList[packetNum]->getLightsData().alive());
    lightsInfo.insert("LowBeams", dataContainerList[packetNum]->getLightsData().lowBeams());
    lightsInfo.insert("HighBeams", dataContainerList[packetNum]->getLightsData().highBeams());
    lightsInfo.insert("Brakes", dataContainerList[packetNum]->getLightsData().brakes());
    lightsInfo.insert("LeftSignal", dataContainerList[packetNum]->getLightsData().leftSignal());
    lightsInfo.insert("RightSignal", dataContainerList[packetNum]->getLightsData().rightSignal());
    lightsInfo.insert("BmsStrobeLight", dataContainerList[packetNum]->getLightsData().bmsStrobeLight());
    return lightsInfo;
}

QJsonObject InternetReporting::makeAuxBms()
{
    QJsonObject auxBms;
    auxBms.insert("PrechargeState", dataContainerList[packetNum]->getAuxBmsData().prechargeStateJSON());
    auxBms.insert("AuxVoltage", dataContainerList[packetNum]->getAuxBmsData().auxVoltage());
    auxBms.insert("AuxBmsAlive", dataContainerList[packetNum]->getAuxBmsData().auxBmsAlive());
    auxBms.insert("StrobeBmsLight", dataContainerList[packetNum]->getAuxBmsData().strobeBmsLight());
    auxBms.insert("AllowCharge", dataContainerList[packetNum]->getAuxBmsData().allowCharge());
    auxBms.insert("ContactorError", dataContainerList[packetNum]->getAuxBmsData().contactorError());
    auxBms.insert("HighVoltageEnable", dataContainerList[packetNum]->getAuxBmsData().highVoltageEnable());
    return auxBms;
}

void InternetReporting::sendAll(int packetNum)
{
    if (packetNum == 0)
    {
        this->packetNum = 0;
    }
    else
    {
        this->packetNum = 1;
    }

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
    obj.insert("MPPT", makeMppt());
    obj.insert("Lights", makeLights());
    obj.insert("AuxBms", makeAuxBms());
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    communicationService_.sendInternetData(data);
}
