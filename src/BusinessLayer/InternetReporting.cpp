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

namespace
{
    const int FORWARD_PERIOD = 500;
}

InternetReporting::InternetReporting(I_CommunicationService& commService,
                                     DataContainer& dataContainer0,
                                     DataContainer& dataContainer1,
                                     InternetView& view)

    : communicationService_(commService)
    , view_(view)
    , packetNum_(0)
    , readTimer_(new QTimer())
    , sendContinuously_(false)
{
    dataContainerList.push_back(&dataContainer0);
    dataContainerList.push_back(&dataContainer1);
    connect(&view_, SIGNAL(toggleSendContinuously()), this, SLOT(toggleSendContinuously()));
    connect(&view_, SIGNAL(setPacketNum(int)), this, SLOT(setPacketNum(int)));
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(sendAll()));
    readTimer_->setInterval(FORWARD_PERIOD);
}

void InternetReporting::toggleSendContinuously()
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
}

void InternetReporting::setPacketNum(int packetNum)
{
    if (packetNum == 0)
    {
        packetNum_ = 0;
    }
    else
    {
        packetNum_ = 1;
    }

    if (!sendContinuously_)
    {
        sendAll();
    }
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
    obj.insert("MPPT", makeMppt());
    obj.insert("Lights", makeLights());
    obj.insert("AuxBms", makeAuxBms());
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    communicationService_.sendInternetData(data);
}

QJsonArray InternetReporting::makeKeyMotor()
{
    QJsonArray keyMotor;
    QJsonObject keyMotor0;
    keyMotor0.insert("Alive", dataContainerList[packetNum_]->getKeyMotorData().motor0Alive());
    keyMotor0.insert("SetCurrent", dataContainerList[packetNum_]->getKeyMotorData().motor0SetCurrent());
    keyMotor0.insert("SetVelocity", dataContainerList[packetNum_]->getKeyMotorData().motor0SetVelocity());
    keyMotor0.insert("BusCurrent", dataContainerList[packetNum_]->getKeyMotorData().motor0BusCurrent());
    keyMotor0.insert("BusVoltage", dataContainerList[packetNum_]->getKeyMotorData().motor0BusVoltage());
    keyMotor0.insert("VehicleVelocity", dataContainerList[packetNum_]->getKeyMotorData().motor0VehicleVelocity());
    keyMotor.push_back(keyMotor0);
    QJsonObject keyMotor1;
    keyMotor1.insert("Alive", dataContainerList[packetNum_]->getKeyMotorData().motor1Alive());
    keyMotor1.insert("SetCurrent", dataContainerList[packetNum_]->getKeyMotorData().motor1SetCurrent());
    keyMotor1.insert("SetVelocity", dataContainerList[packetNum_]->getKeyMotorData().motor1SetVelocity());
    keyMotor1.insert("BusCurrent", dataContainerList[packetNum_]->getKeyMotorData().motor1BusCurrent());
    keyMotor1.insert("BusVoltage", dataContainerList[packetNum_]->getKeyMotorData().motor1BusVoltage());
    keyMotor1.insert("VehicleVelocity", dataContainerList[packetNum_]->getKeyMotorData().motor1VehicleVelocity());
    keyMotor.push_back(keyMotor1);
    return keyMotor;
}

QJsonObject InternetReporting::makeMotorDetails(int n)
{
    QJsonObject motorDetails;

    if (n == 0)
    {
        motorDetails.insert("PhaseCCurrent", dataContainerList[packetNum_]->getMotor0DetailsData().phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", dataContainerList[packetNum_]->getMotor0DetailsData().phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", dataContainerList[packetNum_]->getMotor0DetailsData().MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", dataContainerList[packetNum_]->getMotor0DetailsData().MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", dataContainerList[packetNum_]->getMotor0DetailsData().MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", dataContainerList[packetNum_]->getMotor0DetailsData().MotorCurrentImaginary());
        motorDetails.insert("BackEmf", dataContainerList[packetNum_]->getMotor0DetailsData().BackEmf());
        motorDetails.insert("VoltageRail15VSupply", dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", dataContainerList[packetNum_]->getMotor0DetailsData().RailSupply1V());
        motorDetails.insert("HeatSinkTemp", dataContainerList[packetNum_]->getMotor0DetailsData().heatSinkTemperature());
        motorDetails.insert("MotorTemp", dataContainerList[packetNum_]->getMotor0DetailsData().motorTemperature());
        motorDetails.insert("DspBoardTemp", dataContainerList[packetNum_]->getMotor0DetailsData().dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", dataContainerList[packetNum_]->getMotor0DetailsData().dcBusAmpHours());
        motorDetails.insert("Odometer", dataContainerList[packetNum_]->getMotor0DetailsData().odometer());
        motorDetails.insert("SlipSpeed", dataContainerList[packetNum_]->getMotor0DetailsData().slipSpeed());
    }
    else
    {
        motorDetails.insert("PhaseCCurrent", dataContainerList[packetNum_]->getMotor1DetailsData().phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", dataContainerList[packetNum_]->getMotor1DetailsData().phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", dataContainerList[packetNum_]->getMotor1DetailsData().MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", dataContainerList[packetNum_]->getMotor1DetailsData().MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", dataContainerList[packetNum_]->getMotor1DetailsData().MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", dataContainerList[packetNum_]->getMotor1DetailsData().MotorCurrentImaginary());
        motorDetails.insert("BackEmf", dataContainerList[packetNum_]->getMotor1DetailsData().BackEmf());
        motorDetails.insert("VoltageRail15VSupply", dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", dataContainerList[packetNum_]->getMotor1DetailsData().RailSupply1V());
        motorDetails.insert("HeatSinkTemp", dataContainerList[packetNum_]->getMotor1DetailsData().heatSinkTemperature());
        motorDetails.insert("MotorTemp", dataContainerList[packetNum_]->getMotor1DetailsData().motorTemperature());
        motorDetails.insert("DspBoardTemp", dataContainerList[packetNum_]->getMotor1DetailsData().dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", dataContainerList[packetNum_]->getMotor1DetailsData().dcBusAmpHours());
        motorDetails.insert("Odometer", dataContainerList[packetNum_]->getMotor1DetailsData().odometer());
        motorDetails.insert("SlipSpeed", dataContainerList[packetNum_]->getMotor1DetailsData().slipSpeed());
    }

    return motorDetails;
}

QJsonObject InternetReporting::makeDriverControls()
{
    QJsonObject driverControls;
    driverControls.insert("Alive", dataContainerList[packetNum_]->getDriverControlsData().alive());
    driverControls.insert("HeadlightsOff", dataContainerList[packetNum_]->getDriverControlsData().headlightsOff());
    driverControls.insert("HeadlightsLow", dataContainerList[packetNum_]->getDriverControlsData().headlightsLow());
    driverControls.insert("HeadlightsHigh", dataContainerList[packetNum_]->getDriverControlsData().headlightsHigh());
    driverControls.insert("SignalRight", dataContainerList[packetNum_]->getDriverControlsData().signalRight());
    driverControls.insert("SignalLeft", dataContainerList[packetNum_]->getDriverControlsData().signalLeft());
    driverControls.insert("Hazard", dataContainerList[packetNum_]->getDriverControlsData().hazardLights());
    driverControls.insert("Interior", dataContainerList[packetNum_]->getDriverControlsData().interiorLights());
    driverControls.insert("VolumeUp", dataContainerList[packetNum_]->getDriverControlsData().volumeUp());
    driverControls.insert("VolumeDown", dataContainerList[packetNum_]->getDriverControlsData().volumeDown());
    driverControls.insert("NextSong", dataContainerList[packetNum_]->getDriverControlsData().nextSong());
    driverControls.insert("PrevSong", dataContainerList[packetNum_]->getDriverControlsData().prevSong());
    driverControls.insert("Acceleration", dataContainerList[packetNum_]->getDriverControlsData().acceleration());
    driverControls.insert("RegenBraking", dataContainerList[packetNum_]->getDriverControlsData().regenBraking());
    driverControls.insert("Brakes", dataContainerList[packetNum_]->getDriverControlsData().brakes());
    driverControls.insert("Forward", dataContainerList[packetNum_]->getDriverControlsData().forward());
    driverControls.insert("Reverse", dataContainerList[packetNum_]->getDriverControlsData().reverse());
    driverControls.insert("PushToTalk", dataContainerList[packetNum_]->getDriverControlsData().pushToTalk());
    driverControls.insert("Horn", dataContainerList[packetNum_]->getDriverControlsData().horn());
    driverControls.insert("Reset", dataContainerList[packetNum_]->getDriverControlsData().reset());
    driverControls.insert("Aux", dataContainerList[packetNum_]->getDriverControlsData().aux());
    return driverControls;
}

QJsonArray InternetReporting::makeMotorFaults()
{
    QJsonArray motorFaults;
    QJsonObject motorFaults0;
    QJsonObject motorFaults1;
    QJsonObject errorFlags0;
    errorFlags0.insert("MotorOverSpeed", dataContainerList[packetNum_]->getMotorFaultsData().motor0OverSpeed());
    errorFlags0.insert("SoftwareOverCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor0SoftwareOverCurrent());
    errorFlags0.insert("DcBusOverVoltage", dataContainerList[packetNum_]->getMotorFaultsData().motor0DcBusOverVoltage());
    errorFlags0.insert("BadMotorPositionHallSequence", dataContainerList[packetNum_]->getMotorFaultsData().motor0BadMotorPositionHallSequence());
    errorFlags0.insert("WatchdogCausedLastReset", dataContainerList[packetNum_]->getMotorFaultsData().motor0WatchdogCausedLastReset());
    errorFlags0.insert("ConfigReadError", dataContainerList[packetNum_]->getMotorFaultsData().motor0ConfigReadError());
    errorFlags0.insert("Rail15VUnderVoltageLockOut", dataContainerList[packetNum_]->getMotorFaultsData().motor0Rail15VUnderVoltageLockOut());
    errorFlags0.insert("DesaturationFault", dataContainerList[packetNum_]->getMotorFaultsData().motor0DesaturationFault());
    motorFaults0.insert("ErrorFlags", errorFlags0);
    QJsonObject limitFlags0;
    limitFlags0.insert("OutputVoltagePwm", dataContainerList[packetNum_]->getMotorFaultsData().motor0OutputVoltagePwmLimit());
    limitFlags0.insert("MotorCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor0MotorCurrentLimit());
    limitFlags0.insert("Velocity", dataContainerList[packetNum_]->getMotorFaultsData().motor0VelocityLimit());
    limitFlags0.insert("BusCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor0BusCurrentLimit());
    limitFlags0.insert("BusVoltageUpper", dataContainerList[packetNum_]->getMotorFaultsData().motor0BusVoltageUpperLimit());
    limitFlags0.insert("BusVoltageLower", dataContainerList[packetNum_]->getMotorFaultsData().motor0BusVoltageLowerLimit());
    limitFlags0.insert("IpmOrMotorTemperature", dataContainerList[packetNum_]->getMotorFaultsData().motor0IpmOrMotorTemperatureLimit());
    motorFaults0.insert("LimitFlags", limitFlags0);
    motorFaults0.insert("RxErrorCount", dataContainerList[packetNum_]->getMotorFaultsData().motor0RxErrorCount());
    motorFaults0.insert("TxErrorCount", dataContainerList[packetNum_]->getMotorFaultsData().motor0TxErrorCount());
    motorFaults.push_back(motorFaults0);
    QJsonObject errorFlags1;
    errorFlags1.insert("MotorOverSpeed", dataContainerList[packetNum_]->getMotorFaultsData().motor1OverSpeed());
    errorFlags1.insert("SoftwareOverCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor1SoftwareOverCurrent());
    errorFlags1.insert("DcBusOverVoltage", dataContainerList[packetNum_]->getMotorFaultsData().motor1DcBusOverVoltage());
    errorFlags1.insert("BadMotorPositionHallSequence", dataContainerList[packetNum_]->getMotorFaultsData().motor1BadMotorPositionHallSequence());
    errorFlags1.insert("WatchdogCausedLastReset", dataContainerList[packetNum_]->getMotorFaultsData().motor1WatchdogCausedLastReset());
    errorFlags1.insert("ConfigReadError", dataContainerList[packetNum_]->getMotorFaultsData().motor1ConfigReadError());
    errorFlags1.insert("Rail15VUnderVoltageLockOut", dataContainerList[packetNum_]->getMotorFaultsData().motor1Rail15VUnderVoltageLockOut());
    errorFlags1.insert("DesaturationFault", dataContainerList[packetNum_]->getMotorFaultsData().motor1DesaturationFault());
    motorFaults1.insert("ErrorFlags", errorFlags1);
    QJsonObject limitFlags1;
    limitFlags1.insert("OutputVoltagePwm", dataContainerList[packetNum_]->getMotorFaultsData().motor1OutputVoltagePwmLimit());
    limitFlags1.insert("MotorCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor1MotorCurrentLimit());
    limitFlags1.insert("Velocity", dataContainerList[packetNum_]->getMotorFaultsData().motor1VelocityLimit());
    limitFlags1.insert("BusCurrent", dataContainerList[packetNum_]->getMotorFaultsData().motor1BusCurrentLimit());
    limitFlags1.insert("BusVoltageUpper", dataContainerList[packetNum_]->getMotorFaultsData().motor1BusVoltageUpperLimit());
    limitFlags1.insert("BusVoltageLower", dataContainerList[packetNum_]->getMotorFaultsData().motor1BusVoltageLowerLimit());
    limitFlags1.insert("IpmOrMotorTemperature", dataContainerList[packetNum_]->getMotorFaultsData().motor1IpmOrMotorTemperatureLimit());
    motorFaults1.insert("LimitFlags", limitFlags1);
    motorFaults1.insert("RxErrorCount", dataContainerList[packetNum_]->getMotorFaultsData().motor1RxErrorCount());
    motorFaults1.insert("TxErrorCount", dataContainerList[packetNum_]->getMotorFaultsData().motor1TxErrorCount());
    motorFaults.push_back(motorFaults1);
    return motorFaults;
}

QJsonObject InternetReporting::makeBatteryFaults()
{
    QJsonObject batteryFaults;
    QJsonObject errorFlags;
    errorFlags.insert("InternalCommunicationFault", dataContainerList[packetNum_]->getBatteryFaultsData().internalCommFault());
    errorFlags.insert("InternalConversionFault", dataContainerList[packetNum_]->getBatteryFaultsData().internalConversionFault());
    errorFlags.insert("WeakCellFault", dataContainerList[packetNum_]->getBatteryFaultsData().weakCellFault());
    errorFlags.insert("LowCellVoltageFault", dataContainerList[packetNum_]->getBatteryFaultsData().lowCellVoltageFault());
    errorFlags.insert("OpenWiringFault", dataContainerList[packetNum_]->getBatteryFaultsData().openWiringFault());
    errorFlags.insert("CurrentSensorFault", dataContainerList[packetNum_]->getBatteryFaultsData().currentSensorFault());
    errorFlags.insert("PackVoltageSensorFault", dataContainerList[packetNum_]->getBatteryFaultsData().packVoltageSensorFault());
    errorFlags.insert("WeakPackFault", dataContainerList[packetNum_]->getBatteryFaultsData().weakPackFault());
    errorFlags.insert("VoltageRedundancyFault", dataContainerList[packetNum_]->getBatteryFaultsData().voltageRedundancyFault());
    errorFlags.insert("FanMonitorFault", dataContainerList[packetNum_]->getBatteryFaultsData().fanMonitorFault());
    errorFlags.insert("ThermistorFault", dataContainerList[packetNum_]->getBatteryFaultsData().thermistorFault());
    errorFlags.insert("CANBUSCommunicationsFault", dataContainerList[packetNum_]->getBatteryFaultsData().canbusCommsFault());
    errorFlags.insert("AlwaysOnSupplyFault", dataContainerList[packetNum_]->getBatteryFaultsData().alwaysOnSupplyFault());
    errorFlags.insert("HighVoltageIsolationFault", dataContainerList[packetNum_]->getBatteryFaultsData().highVoltageIsolationFault());
    errorFlags.insert("12vPowerSupplyFault", dataContainerList[packetNum_]->getBatteryFaultsData().powerSupplyFault());
    errorFlags.insert("ChargeLimitEnforcementFault", dataContainerList[packetNum_]->getBatteryFaultsData().chargeLimitFault());
    errorFlags.insert("DischargeLimitEnforcementFault", dataContainerList[packetNum_]->getBatteryFaultsData().dischargeLimitFault());
    errorFlags.insert("ChargerSafetyRelayFault", dataContainerList[packetNum_]->getBatteryFaultsData().chargerSafetyRelayFault());
    errorFlags.insert("InternalMemoryFault", dataContainerList[packetNum_]->getBatteryFaultsData().internalMemFault());
    errorFlags.insert("InternalThermistorFault", dataContainerList[packetNum_]->getBatteryFaultsData().internalThermistorFault());
    errorFlags.insert("InternalLogicFault", dataContainerList[packetNum_]->getBatteryFaultsData().internalLogicFault());
    batteryFaults.insert("ErrorFlags", errorFlags);
    QJsonObject limitFlags;
    limitFlags.insert("DclReducedDueToLowSoc", dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowSoc());
    limitFlags.insert("DclReducedDueToHighCellResistance", dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedHighCellResist());
    limitFlags.insert("DclReducedDueToTemperature", dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedDueToTemp());
    limitFlags.insert("DclReducedDueToLowCellVoltage", dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowCellVoltage());
    limitFlags.insert("DclReducedDueToLowPackVoltage", dataContainerList[packetNum_]->getBatteryFaultsData().dclReducedLowPackVoltage());
    limitFlags.insert("DclandCclReducedDueToVoltageFailsafe", dataContainerList[packetNum_]->getBatteryFaultsData().dclCclReducedVoltageFailsafe());
    limitFlags.insert("DclandCclReducedDueToCommunicationFailsafe", dataContainerList[packetNum_]->getBatteryFaultsData().dclCclReducedCommsFailsafe());
    limitFlags.insert("CclReducedDueToHighSoc", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighSoc());
    limitFlags.insert("CclReducedDueToHighCellResistance", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighCellResist());
    limitFlags.insert("CclReducedDueToTemperature", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedDueToTemp());
    limitFlags.insert("CclReducedDueToHighCellVoltage", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighCellVoltage());
    limitFlags.insert("CclReducedDueToHighPackVoltage", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedHighPackVoltage());
    limitFlags.insert("CclReducedDueToChargerLatch", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedChargerLatch());
    limitFlags.insert("CclReducedDueToAlternateCurrentLimit", dataContainerList[packetNum_]->getBatteryFaultsData().cclReducedACLimit());
    batteryFaults.insert("LimitFlags", limitFlags);
    return batteryFaults;
}

QJsonObject InternetReporting::makeBattery()
{
    QJsonObject battery;
    battery.insert("Alive", dataContainerList[packetNum_]->getBatteryData().alive());
    QJsonObject bmsRelayStatusFlags;
    bmsRelayStatusFlags.insert("DischargeRelayEnabled", dataContainerList[packetNum_]->getBatteryData().dischargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargeRelayEnabled", dataContainerList[packetNum_]->getBatteryData().chargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargerSafetyEnabled", dataContainerList[packetNum_]->getBatteryData().chargerSafetyEnabled());
    bmsRelayStatusFlags.insert("MalfunctionIndicatorActive", dataContainerList[packetNum_]->getBatteryData().malfunctionIndicatorActive());
    bmsRelayStatusFlags.insert("MultiPurposeInputSignalStatus", dataContainerList[packetNum_]->getBatteryData().multiPurposeInputSignalStatus());
    bmsRelayStatusFlags.insert("AlwaysOnSignalStatus", dataContainerList[packetNum_]->getBatteryData().alwaysOnSignalStatus());
    bmsRelayStatusFlags.insert("IsReadySignalStatus", dataContainerList[packetNum_]->getBatteryData().isReadySignalStatus());
    bmsRelayStatusFlags.insert("IsChargingSignalStatus", dataContainerList[packetNum_]->getBatteryData().isChargingSignalStatus());
    battery.insert("BMSRelayStatusFlags", bmsRelayStatusFlags);
    battery.insert("PopulatedCells", dataContainerList[packetNum_]->getBatteryData().populatedCells());
    battery.insert("12vInputVoltage", dataContainerList[packetNum_]->getBatteryData().inputVoltage12V());
    battery.insert("FanVoltage", dataContainerList[packetNum_]->getBatteryData().fanVoltage());
    battery.insert("PackCurrent", dataContainerList[packetNum_]->getBatteryData().packCurrent());
    battery.insert("PackVoltage", dataContainerList[packetNum_]->getBatteryData().packVoltage());
    battery.insert("PackStateOfCharge", dataContainerList[packetNum_]->getBatteryData().packStateOfCharge());
    battery.insert("PackAmphours", dataContainerList[packetNum_]->getBatteryData().packAmpHours());
    battery.insert("PackDepthOfDischarge", dataContainerList[packetNum_]->getBatteryData().packDepthOfDischarge());
    battery.insert("HighTemperature", dataContainerList[packetNum_]->getBatteryData().highTemperature());
    battery.insert("HighThermistorId", dataContainerList[packetNum_]->getBatteryData().highThermistorId());
    battery.insert("LowTemperature", dataContainerList[packetNum_]->getBatteryData().lowTemperature());
    battery.insert("LowThermistorId", dataContainerList[packetNum_]->getBatteryData().lowThermistorId());
    battery.insert("AverageTemperature", dataContainerList[packetNum_]->getBatteryData().averageTemperature());
    battery.insert("InternalTemperature", dataContainerList[packetNum_]->getBatteryData().internalTemperature());
    battery.insert("FanSpeed", dataContainerList[packetNum_]->getBatteryData().fanSpeed());
    battery.insert("RequestedFanSpeed", dataContainerList[packetNum_]->getBatteryData().requestedFanSpeed());
    battery.insert("LowCellVoltage", dataContainerList[packetNum_]->getBatteryData().lowCellVoltage());
    battery.insert("LowCellVoltageId", dataContainerList[packetNum_]->getBatteryData().lowCellVoltageId());
    battery.insert("HighCellVoltage", dataContainerList[packetNum_]->getBatteryData().highCellVoltage());
    battery.insert("HighCellVoltageId", dataContainerList[packetNum_]->getBatteryData().highCellVoltageId());
    battery.insert("AverageCellVoltage", dataContainerList[packetNum_]->getBatteryData().averageCellVoltage());
    return battery;
}

QJsonArray InternetReporting::makeMppt()
{
    QJsonArray mppt;
    QJsonObject mpptInfo;

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        mpptInfo.insert("Alive", dataContainerList[packetNum_]->getMpptData().alive());
        mpptInfo.insert("ArrayVoltage", dataContainerList[packetNum_]->getMpptData().arrayVoltage());
        mpptInfo.insert("ArrayCurrent", dataContainerList[packetNum_]->getMpptData().arrayCurrent());
        mpptInfo.insert("BatteryVoltage", dataContainerList[packetNum_]->getMpptData().batteryVoltage());
        mpptInfo.insert("Temperature", dataContainerList[packetNum_]->getMpptData().temperature());
        mppt.push_back(mpptInfo);
    }

    return mppt;
}

QJsonObject InternetReporting::makeLights()
{
    QJsonObject lightsInfo;
    lightsInfo.insert("Alive", dataContainerList[packetNum_]->getLightsData().alive());
    lightsInfo.insert("LowBeams", dataContainerList[packetNum_]->getLightsData().lowBeams());
    lightsInfo.insert("HighBeams", dataContainerList[packetNum_]->getLightsData().highBeams());
    lightsInfo.insert("Brakes", dataContainerList[packetNum_]->getLightsData().brakes());
    lightsInfo.insert("LeftSignal", dataContainerList[packetNum_]->getLightsData().leftSignal());
    lightsInfo.insert("RightSignal", dataContainerList[packetNum_]->getLightsData().rightSignal());
    lightsInfo.insert("BmsStrobeLight", dataContainerList[packetNum_]->getLightsData().bmsStrobeLight());
    return lightsInfo;
}

QJsonObject InternetReporting::makeAuxBms()
{
    QJsonObject auxBms;
    auxBms.insert("PrechargeState", dataContainerList[packetNum_]->getAuxBmsData().prechargeStateJSON());
    auxBms.insert("AuxVoltage", dataContainerList[packetNum_]->getAuxBmsData().auxVoltage());
    auxBms.insert("AuxBmsAlive", dataContainerList[packetNum_]->getAuxBmsData().auxBmsAlive());
    auxBms.insert("StrobeBmsLight", dataContainerList[packetNum_]->getAuxBmsData().strobeBmsLight());
    auxBms.insert("AllowCharge", dataContainerList[packetNum_]->getAuxBmsData().allowCharge());
    auxBms.insert("ContactorError", dataContainerList[packetNum_]->getAuxBmsData().contactorError());
    auxBms.insert("HighVoltageEnable", dataContainerList[packetNum_]->getAuxBmsData().highVoltageEnable());
    return auxBms;
}
