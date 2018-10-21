#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

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
    , keyMotorData0_(dataContainer0.getKeyMotorData())
    , motor0DetailsData0_(dataContainer0.getMotor0DetailsData())
    , motor1DetailsData0_(dataContainer0.getMotor1DetailsData())
    , driverControlsData0_(dataContainer0.getDriverControlsData())
    , motorFaultsData0_(dataContainer0.getMotorFaultsData())
    , batteryFaultsData0_(dataContainer0.getBatteryFaultsData())
    , batteryData0_(dataContainer0.getBatteryData())
    , mpptData0_(dataContainer0.getMpptData())
    , lightsData0_(dataContainer0.getLightsData())
    , auxBmsData0_(dataContainer0.getAuxBmsData())
    , keyMotorData1_(dataContainer1.getKeyMotorData())
    , motor0DetailsData1_(dataContainer1.getMotor0DetailsData())
    , motor1DetailsData1_(dataContainer1.getMotor1DetailsData())
    , driverControlsData1_(dataContainer1.getDriverControlsData())
    , motorFaultsData1_(dataContainer1.getMotorFaultsData())
    , batteryFaultsData1_(dataContainer1.getBatteryFaultsData())
    , batteryData1_(dataContainer1.getBatteryData())
    , mpptData1_(dataContainer1.getMpptData())
    , lightsData1_(dataContainer1.getLightsData())
    , auxBmsData1_(dataContainer1.getAuxBmsData())
    , view_(view)
    , packetNum(0)
{
    connect(&view_, SIGNAL(sendAll(int)), this, SLOT(sendAll(int)));
}

QJsonArray InternetReporting::makeKeyMotor()
{
    const KeyMotorData* keyMotorData_;
    if (packetNum == 0)
    {
        keyMotorData_ = &keyMotorData0_;
    }
    else
    {
        keyMotorData_ = &keyMotorData1_;
    }

    QJsonArray keyMotor;
    QJsonObject keyMotor0;
    keyMotor0.insert("Alive", keyMotorData_->motor0Alive());
    keyMotor0.insert("SetCurrent", keyMotorData_->motor0SetCurrent());
    keyMotor0.insert("SetVelocity", keyMotorData_->motor0SetVelocity());
    keyMotor0.insert("BusCurrent", keyMotorData_->motor0BusCurrent());
    keyMotor0.insert("BusVoltage", keyMotorData_->motor0BusVoltage());
    keyMotor0.insert("VehicleVelocity", keyMotorData_->motor0VehicleVelocity());
    keyMotor.push_back(keyMotor0);
    QJsonObject keyMotor1;
    keyMotor1.insert("Alive", keyMotorData_->motor1Alive());
    keyMotor1.insert("SetCurrent", keyMotorData_->motor1SetCurrent());
    keyMotor1.insert("SetVelocity", keyMotorData_->motor1SetVelocity());
    keyMotor1.insert("BusCurrent", keyMotorData_->motor1BusCurrent());
    keyMotor1.insert("BusVoltage", keyMotorData_->motor1BusVoltage());
    keyMotor1.insert("VehicleVelocity", keyMotorData_->motor1VehicleVelocity());
    keyMotor.push_back(keyMotor1);
    return keyMotor;
}

QJsonObject InternetReporting::makeMotorDetails(int n)
{
    const MotorDetailsData* motor0DetailsData_;
    const MotorDetailsData* motor1DetailsData_;
    if (packetNum == 0)
    {
        motor0DetailsData_ = &motor0DetailsData0_;
        motor1DetailsData_ = &motor1DetailsData0_;
    }
    else
    {
        motor0DetailsData_ = &motor0DetailsData1_;
        motor1DetailsData_ = &motor1DetailsData1_;
    }

    QJsonObject motorDetails;

    if (n == 0)
    {
        motorDetails.insert("PhaseCCurrent", motor0DetailsData_->phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", motor0DetailsData_->phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", motor0DetailsData_->MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", motor0DetailsData_->MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", motor0DetailsData_->MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", motor0DetailsData_->MotorCurrentImaginary());
        motorDetails.insert("BackEmf", motor0DetailsData_->BackEmf());
        motorDetails.insert("VoltageRail15VSupply", motor0DetailsData_->RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", motor0DetailsData_->RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", motor0DetailsData_->RailSupply1V());
        motorDetails.insert("HeatSinkTemp", motor0DetailsData_->heatSinkTemperature());
        motorDetails.insert("MotorTemp", motor0DetailsData_->motorTemperature());
        motorDetails.insert("DspBoardTemp", motor0DetailsData_->dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", motor0DetailsData_->dcBusAmpHours());
        motorDetails.insert("Odometer", motor0DetailsData_->odometer());
        motorDetails.insert("SlipSpeed", motor0DetailsData_->slipSpeed());
    }
    else
    {
        motorDetails.insert("PhaseCCurrent", motor1DetailsData_->phaseCCurrent());
        motorDetails.insert("PhaseBCurrent", motor1DetailsData_->phaseBCurrent());
        motorDetails.insert("MotorVoltageReal", motor1DetailsData_->MotorVoltageReal());
        motorDetails.insert("MotorVoltageImaginary", motor1DetailsData_->MotorVoltageImaginary());
        motorDetails.insert("MotorCurrentReal", motor1DetailsData_->MotorCurrentReal());
        motorDetails.insert("MotorCurrentImaginary", motor1DetailsData_->MotorCurrentImaginary());
        motorDetails.insert("BackEmf", motor1DetailsData_->BackEmf());
        motorDetails.insert("VoltageRail15VSupply", motor1DetailsData_->RailSupply15V());
        motorDetails.insert("VoltageRail3VSupply", motor1DetailsData_->RailSupply3V());
        motorDetails.insert("VoltageRail1VSupply", motor1DetailsData_->RailSupply1V());
        motorDetails.insert("HeatSinkTemp", motor1DetailsData_->heatSinkTemperature());
        motorDetails.insert("MotorTemp", motor1DetailsData_->motorTemperature());
        motorDetails.insert("DspBoardTemp", motor1DetailsData_->dspBoardTemperature());
        motorDetails.insert("DcBusAmpHours", motor1DetailsData_->dcBusAmpHours());
        motorDetails.insert("Odometer", motor1DetailsData_->odometer());
        motorDetails.insert("SlipSpeed", motor1DetailsData_->slipSpeed());
    }

    return motorDetails;
}

QJsonObject InternetReporting::makeDriverControls()
{
    const DriverControlsData* driverControlsData_;
    if (packetNum == 0)
    {
        driverControlsData_ = &driverControlsData0_;
    }
    else
    {
        driverControlsData_ = &driverControlsData1_;
    }

    QJsonObject driverControls;
    driverControls.insert("Alive", driverControlsData_->alive());
    driverControls.insert("HeadlightsOff", driverControlsData_->headlightsOff());
    driverControls.insert("HeadlightsLow", driverControlsData_->headlightsLow());
    driverControls.insert("HeadlightsHigh", driverControlsData_->headlightsHigh());
    driverControls.insert("SignalRight", driverControlsData_->signalRight());
    driverControls.insert("SignalLeft", driverControlsData_->signalLeft());
    driverControls.insert("Hazard", driverControlsData_->hazardLights());
    driverControls.insert("Interior", driverControlsData_->interiorLights());
    driverControls.insert("VolumeUp", driverControlsData_->volumeUp());
    driverControls.insert("VolumeDown", driverControlsData_->volumeDown());
    driverControls.insert("NextSong", driverControlsData_->nextSong());
    driverControls.insert("PrevSong", driverControlsData_->prevSong());
    driverControls.insert("Acceleration", driverControlsData_->acceleration());
    driverControls.insert("RegenBraking", driverControlsData_->regenBraking());
    driverControls.insert("Brakes", driverControlsData_->brakes());
    driverControls.insert("Forward", driverControlsData_->forward());
    driverControls.insert("Reverse", driverControlsData_->reverse());
    driverControls.insert("PushToTalk", driverControlsData_->pushToTalk());
    driverControls.insert("Horn", driverControlsData_->horn());
    driverControls.insert("Reset", driverControlsData_->reset());
    driverControls.insert("Aux", driverControlsData_->aux());
    return driverControls;
}

QJsonArray InternetReporting::makeMotorFaults()
{
    const MotorFaultsData* motorFaultsData_;
    if (packetNum == 0)
    {
        motorFaultsData_ = &motorFaultsData0_;
    }
    else
    {
        motorFaultsData_ = &motorFaultsData1_;
    }

    QJsonArray motorFaults;
    QJsonObject motorFaults0;
    QJsonObject motorFaults1;
    QJsonObject errorFlags0;
    errorFlags0.insert("MotorOverSpeed", motorFaultsData_->motor0OverSpeed());
    errorFlags0.insert("SoftwareOverCurrent", motorFaultsData_->motor0SoftwareOverCurrent());
    errorFlags0.insert("DcBusOverVoltage", motorFaultsData_->motor0DcBusOverVoltage());
    errorFlags0.insert("BadMotorPositionHallSequence", motorFaultsData_->motor0BadMotorPositionHallSequence());
    errorFlags0.insert("WatchdogCausedLastReset", motorFaultsData_->motor0WatchdogCausedLastReset());
    errorFlags0.insert("ConfigReadError", motorFaultsData_->motor0ConfigReadError());
    errorFlags0.insert("Rail15VUnderVoltageLockOut", motorFaultsData_->motor0Rail15VUnderVoltageLockOut());
    errorFlags0.insert("DesaturationFault", motorFaultsData_->motor0DesaturationFault());
    motorFaults0.insert("ErrorFlags", errorFlags0);
    QJsonObject limitFlags0;
    limitFlags0.insert("OutputVoltagePwm", motorFaultsData_->motor0OutputVoltagePwmLimit());
    limitFlags0.insert("MotorCurrent", motorFaultsData_->motor0MotorCurrentLimit());
    limitFlags0.insert("Velocity", motorFaultsData_->motor0VelocityLimit());
    limitFlags0.insert("BusCurrent", motorFaultsData_->motor0BusCurrentLimit());
    limitFlags0.insert("BusVoltageUpper", motorFaultsData_->motor0BusVoltageUpperLimit());
    limitFlags0.insert("BusVoltageLower", motorFaultsData_->motor0BusVoltageLowerLimit());
    limitFlags0.insert("IpmOrMotorTemperature", motorFaultsData_->motor0IpmOrMotorTemperatureLimit());
    motorFaults0.insert("LimitFlags", limitFlags0);
    motorFaults0.insert("RxErrorCount", motorFaultsData_->motor0RxErrorCount());
    motorFaults0.insert("TxErrorCount", motorFaultsData_->motor0TxErrorCount());
    motorFaults.push_back(motorFaults0);
    QJsonObject errorFlags1;
    errorFlags1.insert("MotorOverSpeed", motorFaultsData_->motor1OverSpeed());
    errorFlags1.insert("SoftwareOverCurrent", motorFaultsData_->motor1SoftwareOverCurrent());
    errorFlags1.insert("DcBusOverVoltage", motorFaultsData_->motor1DcBusOverVoltage());
    errorFlags1.insert("BadMotorPositionHallSequence", motorFaultsData_->motor1BadMotorPositionHallSequence());
    errorFlags1.insert("WatchdogCausedLastReset", motorFaultsData_->motor1WatchdogCausedLastReset());
    errorFlags1.insert("ConfigReadError", motorFaultsData_->motor1ConfigReadError());
    errorFlags1.insert("Rail15VUnderVoltageLockOut", motorFaultsData_->motor1Rail15VUnderVoltageLockOut());
    errorFlags1.insert("DesaturationFault", motorFaultsData_->motor1DesaturationFault());
    motorFaults1.insert("ErrorFlags", errorFlags1);
    QJsonObject limitFlags1;
    limitFlags1.insert("OutputVoltagePwm", motorFaultsData_->motor1OutputVoltagePwmLimit());
    limitFlags1.insert("MotorCurrent", motorFaultsData_->motor1MotorCurrentLimit());
    limitFlags1.insert("Velocity", motorFaultsData_->motor1VelocityLimit());
    limitFlags1.insert("BusCurrent", motorFaultsData_->motor1BusCurrentLimit());
    limitFlags1.insert("BusVoltageUpper", motorFaultsData_->motor1BusVoltageUpperLimit());
    limitFlags1.insert("BusVoltageLower", motorFaultsData_->motor1BusVoltageLowerLimit());
    limitFlags1.insert("IpmOrMotorTemperature", motorFaultsData_->motor1IpmOrMotorTemperatureLimit());
    motorFaults1.insert("LimitFlags", limitFlags1);
    motorFaults1.insert("RxErrorCount", motorFaultsData_->motor1RxErrorCount());
    motorFaults1.insert("TxErrorCount", motorFaultsData_->motor1TxErrorCount());
    motorFaults.push_back(motorFaults1);
    return motorFaults;
}

QJsonObject InternetReporting::makeBatteryFaults()
{
    const BatteryFaultsData* batteryFaultsData_;
    if (packetNum == 0)
    {
        batteryFaultsData_ = &batteryFaultsData0_;
    }
    else
    {
        batteryFaultsData_ = &batteryFaultsData1_;
    }

    QJsonObject batteryFaults;
    QJsonObject errorFlags;
    errorFlags.insert("InternalCommunicationFault", batteryFaultsData_->internalCommFault());
    errorFlags.insert("InternalConversionFault", batteryFaultsData_->internalConversionFault());
    errorFlags.insert("WeakCellFault", batteryFaultsData_->weakCellFault());
    errorFlags.insert("LowCellVoltageFault", batteryFaultsData_->lowCellVoltageFault());
    errorFlags.insert("OpenWiringFault", batteryFaultsData_->openWiringFault());
    errorFlags.insert("CurrentSensorFault", batteryFaultsData_->currentSensorFault());
    errorFlags.insert("PackVoltageSensorFault", batteryFaultsData_->packVoltageSensorFault());
    errorFlags.insert("WeakPackFault", batteryFaultsData_->weakPackFault());
    errorFlags.insert("VoltageRedundancyFault", batteryFaultsData_->voltageRedundancyFault());
    errorFlags.insert("FanMonitorFault", batteryFaultsData_->fanMonitorFault());
    errorFlags.insert("ThermistorFault", batteryFaultsData_->thermistorFault());
    errorFlags.insert("CANBUSCommunicationsFault", batteryFaultsData_->canbusCommsFault());
    errorFlags.insert("AlwaysOnSupplyFault", batteryFaultsData_->alwaysOnSupplyFault());
    errorFlags.insert("HighVoltageIsolationFault", batteryFaultsData_->highVoltageIsolationFault());
    errorFlags.insert("12vPowerSupplyFault", batteryFaultsData_->powerSupplyFault());
    errorFlags.insert("ChargeLimitEnforcementFault", batteryFaultsData_->chargeLimitFault());
    errorFlags.insert("DischargeLimitEnforcementFault", batteryFaultsData_->dischargeLimitFault());
    errorFlags.insert("ChargerSafetyRelayFault", batteryFaultsData_->chargerSafetyRelayFault());
    errorFlags.insert("InternalMemoryFault", batteryFaultsData_->internalMemFault());
    errorFlags.insert("InternalThermistorFault", batteryFaultsData_->internalThermistorFault());
    errorFlags.insert("InternalLogicFault", batteryFaultsData_->internalLogicFault());
    batteryFaults.insert("ErrorFlags", errorFlags);
    QJsonObject limitFlags;
    limitFlags.insert("DclReducedDueToLowSoc", batteryFaultsData_->dclReducedLowSoc());
    limitFlags.insert("DclReducedDueToHighCellResistance", batteryFaultsData_->dclReducedHighCellResist());
    limitFlags.insert("DclReducedDueToTemperature", batteryFaultsData_->dclReducedDueToTemp());
    limitFlags.insert("DclReducedDueToLowCellVoltage", batteryFaultsData_->dclReducedLowCellVoltage());
    limitFlags.insert("DclReducedDueToLowPackVoltage", batteryFaultsData_->dclReducedLowPackVoltage());
    limitFlags.insert("DclandCclReducedDueToVoltageFailsafe", batteryFaultsData_->dclCclReducedVoltageFailsafe());
    limitFlags.insert("DclandCclReducedDueToCommunicationFailsafe", batteryFaultsData_->dclCclReducedCommsFailsafe());
    limitFlags.insert("CclReducedDueToHighSoc", batteryFaultsData_->cclReducedHighSoc());
    limitFlags.insert("CclReducedDueToHighCellResistance", batteryFaultsData_->cclReducedHighCellResist());
    limitFlags.insert("CclReducedDueToTemperature", batteryFaultsData_->cclReducedDueToTemp());
    limitFlags.insert("CclReducedDueToHighCellVoltage", batteryFaultsData_->cclReducedHighCellVoltage());
    limitFlags.insert("CclReducedDueToHighPackVoltage", batteryFaultsData_->cclReducedHighPackVoltage());
    limitFlags.insert("CclReducedDueToChargerLatch", batteryFaultsData_->cclReducedChargerLatch());
    limitFlags.insert("CclReducedDueToAlternateCurrentLimit", batteryFaultsData_->cclReducedACLimit());
    batteryFaults.insert("LimitFlags", limitFlags);
    return batteryFaults;
}

QJsonObject InternetReporting::makeBattery()
{
    const BatteryData* batteryData_;
    if (packetNum == 0)
    {
        batteryData_ = &batteryData0_;
    }
    else
    {
        batteryData_ = &batteryData1_;
    }

    QJsonObject battery;
    battery.insert("Alive", batteryData_->alive());
    QJsonObject bmsRelayStatusFlags;
    bmsRelayStatusFlags.insert("DischargeRelayEnabled", batteryData_->dischargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargeRelayEnabled", batteryData_->chargeRelayEnabled());
    bmsRelayStatusFlags.insert("ChargerSafetyEnabled", batteryData_->chargerSafetyEnabled());
    bmsRelayStatusFlags.insert("MalfunctionIndicatorActive", batteryData_->malfunctionIndicatorActive());
    bmsRelayStatusFlags.insert("MultiPurposeInputSignalStatus", batteryData_->multiPurposeInputSignalStatus());
    bmsRelayStatusFlags.insert("AlwaysOnSignalStatus", batteryData_->alwaysOnSignalStatus());
    bmsRelayStatusFlags.insert("IsReadySignalStatus", batteryData_->isReadySignalStatus());
    bmsRelayStatusFlags.insert("IsChargingSignalStatus", batteryData_->isChargingSignalStatus());
    battery.insert("BMSRelayStatusFlags", bmsRelayStatusFlags);
    battery.insert("PopulatedCells", batteryData_->populatedCells());
    battery.insert("12vInputVoltage", batteryData_->inputVoltage12V());
    battery.insert("FanVoltage", batteryData_->fanVoltage());
    battery.insert("PackCurrent", batteryData_->packCurrent());
    battery.insert("PackVoltage", batteryData_->packVoltage());
    battery.insert("PackStateOfCharge", batteryData_->packStateOfCharge());
    battery.insert("PackAmphours", batteryData_->packAmpHours());
    battery.insert("PackDepthOfDischarge", batteryData_->packDepthOfDischarge());
    battery.insert("HighTemperature", batteryData_->highTemperature());
    battery.insert("HighThermistorId", batteryData_->highThermistorId());
    battery.insert("LowTemperature", batteryData_->lowTemperature());
    battery.insert("LowThermistorId", batteryData_->lowThermistorId());
    battery.insert("AverageTemperature", batteryData_->averageTemperature());
    battery.insert("InternalTemperature", batteryData_->internalTemperature());
    battery.insert("FanSpeed", batteryData_->fanSpeed());
    battery.insert("RequestedFanSpeed", batteryData_->requestedFanSpeed());
    battery.insert("LowCellVoltage", batteryData_->lowCellVoltage());
    battery.insert("LowCellVoltageId", batteryData_->lowCellVoltageId());
    battery.insert("HighCellVoltage", batteryData_->highCellVoltage());
    battery.insert("HighCellVoltageId", batteryData_->highCellVoltageId());
    battery.insert("AverageCellVoltage", batteryData_->averageCellVoltage());
    return battery;
}

QJsonArray InternetReporting::makeMppt()
{
    const MpptData* mpptData_;
    if (packetNum == 0)
    {
        mpptData_ = &mpptData0_;
    }
    else
    {
        mpptData_ = &mpptData1_;
    }

    QJsonArray mppt;
    QJsonObject mpptInfo;

    for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
    {
        mpptInfo.insert("Alive", mpptData_->alive(i));
        mpptInfo.insert("ArrayVoltage", mpptData_->arrayVoltage(i));
        mpptInfo.insert("ArrayCurrent", mpptData_->arrayCurrent(i));
        mpptInfo.insert("BatteryVoltage", mpptData_->batteryVoltage(i));
        mpptInfo.insert("Temperature", mpptData_->temperature(i));
        mppt.push_back(mpptInfo);
    }

    return mppt;
}

QJsonObject InternetReporting::makeLights()
{
    const LightsData* lightsData_;
    if (packetNum == 0)
    {
        lightsData_ = &lightsData0_;
    }
    else
    {
        lightsData_ = &lightsData1_;
    }

    QJsonObject lightsInfo;
    lightsInfo.insert("Alive", lightsData_->alive());
    lightsInfo.insert("LowBeams", lightsData_->lowBeams());
    lightsInfo.insert("HighBeams", lightsData_->highBeams());
    lightsInfo.insert("Brakes", lightsData_->brakes());
    lightsInfo.insert("LeftSignal", lightsData_->leftSignal());
    lightsInfo.insert("RightSignal", lightsData_->rightSignal());
    lightsInfo.insert("BmsStrobeLight", lightsData_->bmsStrobeLight());
    return lightsInfo;
}

QJsonObject InternetReporting::makeAuxBms()
{
    const AuxBmsData* auxBmsData_;
    if (packetNum == 0)
    {
        auxBmsData_ = &auxBmsData0_;
    }
    else
    {
        auxBmsData_ = &auxBmsData1_;
    }

    QJsonObject auxBms;
    auxBms.insert("PrechargeState", auxBmsData_->prechargeStateJSON());
    auxBms.insert("AuxVoltage", auxBmsData_->auxVoltage());
    auxBms.insert("AuxBmsAlive", auxBmsData_->auxBmsAlive());
    auxBms.insert("StrobeBmsLight", auxBmsData_->strobeBmsLight());
    auxBms.insert("AllowCharge", auxBmsData_->allowCharge());
    auxBms.insert("ContactorError", auxBmsData_->contactorError());
    auxBms.insert("HighVoltageEnable", auxBmsData_->highVoltageEnable());
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
