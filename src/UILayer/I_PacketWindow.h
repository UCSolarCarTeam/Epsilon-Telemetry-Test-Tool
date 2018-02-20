#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

class I_PacketWindow : public QWidget
{
    Q_OBJECT
public:
    virtual ~I_PacketWindow() {}

    virtual QCheckBox& alwaysOnSupplyFaultCheck() = 0;
    virtual QCheckBox& canbusCommsFaultCheck() = 0;
    virtual QCheckBox& chargeLimitEnforementFaultCheck() = 0;
    virtual QCheckBox& chargerSafetyRelayFaultCheck() = 0;
    virtual QCheckBox& currentSensorFaultCheck() = 0;
    virtual QCheckBox& dischargeLimitEnforcementFaultCheck() = 0;
    virtual QCheckBox& fanMonitorFaultCheck() = 0;
    virtual QCheckBox& highVoltageIsolationFaultCheck() = 0;
    virtual QCheckBox& internalCommFaultCheck() = 0;
    virtual QCheckBox& internalLogicFaultCheck() = 0;
    virtual QCheckBox& internalMemoryFaultCheck() = 0;
    virtual QCheckBox& internalThermistorFaultCheck() = 0;
    virtual QCheckBox& lowCellVoltageFaultCheck() = 0;
    virtual QCheckBox& openWiringFaultCheck() = 0;
    virtual QCheckBox& packVoltageSensorCheck() = 0;
    virtual QCheckBox& powerSupplyFaultCheck() = 0;
    virtual QCheckBox& thermistorFaultCheck() = 0;
    virtual QCheckBox& voltageRedundancyFaultCheck() = 0;
    virtual QCheckBox& weakCellFaultCheck() = 0;
    virtual QCheckBox& weakPackFaultCheck() = 0;

    virtual QCheckBox& cclReducedACLimit() = 0;
    virtual QCheckBox& cclReducedChargerLatchCheck() = 0;
    virtual QCheckBox& cclReducedHighCellResistanceCheck() = 0;
    virtual QCheckBox& cclReducedHighCellVoltageCheck() = 0;
    virtual QCheckBox& cclReducedHighPackVoltageCheck() = 0;
    virtual QCheckBox& cclReducedHighSocCheck() = 0;
    virtual QCheckBox& cclReducedTempCheck() = 0;
    virtual QCheckBox& dclCclReducedCommsFailSafeCheck() = 0;
    virtual QCheckBox& dclCclReducedVoltageFailsafeCheck() = 0;
    virtual QCheckBox& dclReducedHighCellResistanceCheck() = 0;
    virtual QCheckBox& dclReducedLowCellVoltageCheck() = 0;
    virtual QCheckBox& dclReducedLowPackVoltageCheck() = 0;
    virtual QCheckBox& dclReducedLowSocCheck() = 0;
    virtual QCheckBox& dclReducedTempCheck() = 0;

    virtual QCheckBox& allowChargeCheck() = 0;
    virtual QCheckBox& auxBMSAliveCheck() = 0;
    virtual QCheckBox& bmuAliveCheck() = 0;
    virtual QCheckBox& strobeBmsLightCheck() = 0;
    virtual QCheckBox& contractorErrorCheck() = 0;
    virtual QCheckBox& alwaysOnCheck() = 0;
    virtual QCheckBox& chargeRelayCheck() = 0;
    virtual QCheckBox& chargerSafetyCheck() = 0;
    virtual QCheckBox& dischargeRelayCheck() = 0;
    virtual QCheckBox& isChargingCheck() = 0;
    virtual QCheckBox& isReadyCheck() = 0;
    virtual QCheckBox& malfunctionIndicatorCheck() = 0;
    virtual QCheckBox& multipurposeInputCheck() = 0;
    virtual QSpinBox& auxVoltageBox() = 0;
    virtual QSpinBox& averageCellVoltageBox() = 0;
    virtual QSpinBox& averageTempBox() = 0;
    virtual QSpinBox& fanSpeedBox() = 0;
    virtual QDoubleSpinBox& fanVoltageBox() = 0;
    virtual QSpinBox& highCellVoltageBox() = 0;
    virtual QSpinBox& highCellVoltageIdBox() = 0;
    virtual QSpinBox& highTempBox() = 0;
    virtual QSpinBox& highThermistorIdBox() = 0;
    virtual QDoubleSpinBox& inputVoltage12VBox() = 0;
    virtual QSpinBox& internalTempBox() = 0;
    virtual QSpinBox& lowCellVoltageBox() = 0;
    virtual QSpinBox& lowCellVoltageIdBox() = 0;
    virtual QSpinBox& lowTempBox() = 0;
    virtual QSpinBox& lowThermistorIdBox() = 0;
    virtual QDoubleSpinBox& packAmphoursBox() = 0;
    virtual QDoubleSpinBox& packCurrentBox() = 0;
    virtual QDoubleSpinBox& packDepthOfDischargeBox() = 0;
    virtual QDoubleSpinBox& packDepthOfChargeBox() = 0;
    virtual QDoubleSpinBox& packVoltageBox() = 0;
    virtual QSpinBox& populatedCellsBox() = 0;
    virtual QSpinBox& prechargeStateBox() = 0;
    virtual QSpinBox& requestedFanSpeedBox() = 0;

    virtual QSpinBox& accelerationBox() = 0;
    virtual QSpinBox& regenBrakingBox() = 0;
    virtual QCheckBox& driverControlsAliveCheck() = 0;
    virtual QCheckBox& auxCheck() = 0;
    virtual QCheckBox& brakesCheck() = 0;
    virtual QCheckBox& forwardCheck() = 0;
    virtual QCheckBox& hornCheck() = 0;
    virtual QCheckBox& pushToTalkCheck() = 0;
    virtual QCheckBox& resetCheck() = 0;
    virtual QCheckBox& reverseCheck() = 0;
    virtual QCheckBox& hazardCheck() = 0;
    virtual QCheckBox& headlightsHighCheck() = 0;
    virtual QCheckBox& headlightsLowCheck() = 0;
    virtual QCheckBox& headlightsOffCheck() = 0;
    virtual QCheckBox& interiorCheck() = 0;
    virtual QCheckBox& signalLeftCheck() = 0;
    virtual QCheckBox& signalRightCheck() = 0;
    virtual QCheckBox& nextSongCheck() = 0;
    virtual QCheckBox& previousSongCheck() = 0;
    virtual QCheckBox& volumeDownCheck() = 0;
    virtual QCheckBox& volumeUpCheck() = 0;

    virtual QCheckBox& m0AliveCheck() = 0;
    virtual QDoubleSpinBox& m0BusCurrentBox() = 0;
    virtual QDoubleSpinBox& m0BusVoltageBox() = 0;
    virtual QDoubleSpinBox& m0SetCurrentBox() = 0;
    virtual QDoubleSpinBox& m0SetVelocityBox() = 0;
    virtual QDoubleSpinBox& m0VehicleVelocityBox() = 0;

    virtual QCheckBox& m1AliveCheck() = 0;
    virtual QDoubleSpinBox& m1BusCurrentBox() = 0;
    virtual QDoubleSpinBox& m1BusVoltageBox() = 0;
    virtual QDoubleSpinBox& m1SetCurrentBox() = 0;
    virtual QDoubleSpinBox& m1SetVelocityBox() = 0;
    virtual QDoubleSpinBox& m1VehicleVelocityBox() = 0;

    virtual QDoubleSpinBox& m0BackEMFBox() = 0;
    virtual QDoubleSpinBox& m0DcBusAmphoursBox() = 0;
    virtual QDoubleSpinBox& m0DspBoardTempBox() = 0;
    virtual QDoubleSpinBox& m0HeatSinkTempBox() = 0;
    virtual QDoubleSpinBox& m0MotorCurrentImaginaryBox() = 0;
    virtual QDoubleSpinBox& m0MotorCurrentRealBox() = 0;
    virtual QDoubleSpinBox& m0MotorTempBox() = 0;
    virtual QDoubleSpinBox& m0MotorVoltageImaginaryBox() = 0;
    virtual QDoubleSpinBox& m0MotorVoltageRealBox() = 0;
    virtual QDoubleSpinBox& m0OdometerBox() = 0;
    virtual QDoubleSpinBox& m0PhaseBCurrentBox() = 0;
    virtual QDoubleSpinBox& m0PhaseCCurrentBox() = 0;
    virtual QDoubleSpinBox& m0SlipSpeedBox() = 0;
    virtual QDoubleSpinBox& m0VoltageRailSupply15VBox() = 0;
    virtual QDoubleSpinBox& m0VoltageRailSupply1VBox() = 0;
    virtual QDoubleSpinBox& m0VoltageRailSupply3VBox() = 0;

    virtual QDoubleSpinBox& m1BackEMFBox() = 0;
    virtual QDoubleSpinBox& m1DcBusAmphoursBox() = 0;
    virtual QDoubleSpinBox& m1DspBoardTempBox() = 0;
    virtual QDoubleSpinBox& m1HeatSinkTempBox() = 0;
    virtual QDoubleSpinBox& m1MotorCurrentImaginaryBox() = 0;
    virtual QDoubleSpinBox& m1MotorCurrentRealBox() = 0;
    virtual QDoubleSpinBox& m1MotorTempBox() = 0;
    virtual QDoubleSpinBox& m1MotorVoltageImaginaryBox() = 0;
    virtual QDoubleSpinBox& m1MotorVoltageRealBox() = 0;
    virtual QDoubleSpinBox& m1OdometerBox() = 0;
    virtual QDoubleSpinBox& m1PhaseBCurrentBox() = 0;
    virtual QDoubleSpinBox& m1PhaseCCurrentBox() = 0;
    virtual QDoubleSpinBox& m1SlipSpeedBox() = 0;
    virtual QDoubleSpinBox& m1VoltageRailSupply15VBox() = 0;
    virtual QDoubleSpinBox& m1VoltageRailSupply1VBox() = 0;
    virtual QDoubleSpinBox& m1VoltageRailSupply3VBox() = 0;

    virtual QSpinBox& m0CanRxErrorCountBox() = 0;
    virtual QSpinBox& m0CanTxErrorCountBox() = 0;
    virtual QCheckBox& m0BadMotorPositionHallSequenceCheck() = 0;
    virtual QCheckBox& m0ConfigReadErrorBox() = 0;
    virtual QCheckBox& m0DcBusOverVoltageCheck() = 0;
    virtual QCheckBox& m0OverCurrentCheck() = 0;
    virtual QCheckBox& m0DesaturationFaultCheck() = 0;
    virtual QCheckBox& m0OverSpeedCheck() = 0;
    virtual QCheckBox& m0RailUnderVoltageLockOutCheck() = 0;
    virtual QCheckBox& m0WatchDogCausedLastResetCheck() = 0;
    virtual QCheckBox& m0BusCurrentCheck() = 0;
    virtual QCheckBox& m0BusVoltageLowerCheck() = 0;
    virtual QCheckBox& m0BusVoltageUpperCheck() = 0;
    virtual QCheckBox& m0IpmOrMotorTempCheck() = 0;
    virtual QCheckBox& m0MotorCurrentCheck() = 0;
    virtual QCheckBox& m0OutputVoltagePwmCheck() = 0;
    virtual QCheckBox& m0VelocityCheck() = 0;

    virtual QSpinBox& m1CanRxErrorCountBox() = 0;
    virtual QSpinBox& m1CanTxErrorCountBox() = 0;
    virtual QCheckBox& m1BadMotorPositionHallSequenceCheck() = 0;
    virtual QCheckBox& m1ConfigReadErrorBox() = 0;
    virtual QCheckBox& m1DcBusOverVoltageCheck() = 0;
    virtual QCheckBox& m1OverCurrentCheck() = 0;
    virtual QCheckBox& m1DesaturationFaultCheck() = 0;
    virtual QCheckBox& m1OverSpeedCheck() = 0;
    virtual QCheckBox& m1RailUnderVoltageLockOutCheck() = 0;
    virtual QCheckBox& m1WatchDogCausedLastResetCheck() = 0;
    virtual QCheckBox& m1BusCurrentCheck() = 0;
    virtual QCheckBox& m1BusVoltageLowerCheck() = 0;
    virtual QCheckBox& m1BusVoltageUpperCheck() = 0;
    virtual QCheckBox& m1IpmOrMotorTempCheck() = 0;
    virtual QCheckBox& m1MotorCurrentCheck() = 0;
    virtual QCheckBox& m1OutputVoltagePwmCheck() = 0;
    virtual QCheckBox& m1VelocityCheck() = 0;

    virtual QCheckBox& bmsStrobeLightCheck() = 0;
    virtual QCheckBox& brakeLightsCheck() = 0;
    virtual QCheckBox& highBeamsCheck() = 0;
    virtual QCheckBox& leftSignalCheck() = 0;
    virtual QCheckBox& lightsAliveCheck() = 0;
    virtual QCheckBox& lowBeamsCheck() = 0;
    virtual QCheckBox& rightSignalCheck() = 0;

    virtual QCheckBox& mpptAliveCheck() = 0;
    virtual QSpinBox& arrayCurrentBox() = 0;
    virtual QSpinBox& arrayVoltageBox() = 0;
    virtual QSpinBox& batteryVoltageBox() = 0;
    virtual QSpinBox& mpptNumberBox() = 0;
    virtual QSpinBox& temperatureBox() = 0;
};

