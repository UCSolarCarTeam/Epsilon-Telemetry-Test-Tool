#pragma once

#include "I_PacketWindow.h"

namespace Ui
{
    class PacketWindow;
}

class PacketWindow : public I_PacketWindow
{
    Q_OBJECT

public:
    explicit PacketWindow();
    ~PacketWindow();

    QCheckBox& alwaysOnSupplyFaultCheck();
    QCheckBox& canbusCommsFaultCheck();
    QCheckBox& chargeLimitEnforementFaultCheck();
    QCheckBox& chargerSafetyRelayFaultCheck();
    QCheckBox& currentSensorFaultCheck();
    QCheckBox& dischargeLimitEnforcementFaultCheck();
    QCheckBox& fanMonitorFaultCheck();
    QCheckBox& highVoltageIsolationFaultCheck();
    QCheckBox& internalCommFaultCheck();
    QCheckBox& internalLogicFaultCheck();
    QCheckBox& internalMemoryFaultCheck();
    QCheckBox& internalThermistorFaultCheck();
    QCheckBox& lowCellVoltageFaultCheck();
    QCheckBox& openWiringFaultCheck();
    QCheckBox& packVoltageSensorCheck();
    QCheckBox& powerSupplyFaultCheck();
    QCheckBox& thermistorFaultCheck();
    QCheckBox& voltageRedundancyFaultCheck();
    QCheckBox& weakCellFaultCheck();
    QCheckBox& weakPackFaultCheck();

    QCheckBox& cclReducedACLimit();
    QCheckBox& cclReducedChargerLatchCheck();
    QCheckBox& cclReducedHighCellResistanceCheck();
    QCheckBox& cclReducedHighCellVoltageCheck();
    QCheckBox& cclReducedHighPackVoltageCheck();
    QCheckBox& cclReducedHighSocCheck();
    QCheckBox& cclReducedTempCheck();
    QCheckBox& dclCclReducedCommsFailSafeCheck();
    QCheckBox& dclCclReducedVoltageFailsafeCheck();
    QCheckBox& dclReducedHighCellResistanceCheck();
    QCheckBox& dclReducedLowCellVoltageCheck();
    QCheckBox& dclReducedLowPackVoltageCheck();
    QCheckBox& dclReducedLowSocCheck();
    QCheckBox& dclReducedTempCheck();

    QCheckBox& allowChargeCheck();
    QCheckBox& auxBMSAliveCheck();
    QCheckBox& bmuAliveCheck();
    QCheckBox& strobeBmsLightCheck();
    QCheckBox& contractorErrorCheck();
    QCheckBox& alwaysOnCheck();
    QCheckBox& chargeRelayCheck();
    QCheckBox& chargerSafetyCheck();
    QCheckBox& dischargeRelayCheck();
    QCheckBox& isChargingCheck();
    QCheckBox& isReadyCheck();
    QCheckBox& malfunctionIndicatorCheck();
    QCheckBox& multipurposeInputCheck();
    QSpinBox& auxVoltageBox();
    QSpinBox& averageCellVoltageBox();
    QSpinBox& averageTempBox();
    QSpinBox& fanSpeedBox();
    QDoubleSpinBox& fanVoltageBox();
    QSpinBox& highCellVoltageBox();
    QSpinBox& highCellVoltageIdBox();
    QSpinBox& highTempBox();
    QSpinBox& highThermistorIdBox();
    QDoubleSpinBox& inputVoltage12VBox();
    QSpinBox& internalTempBox();
    QSpinBox& lowCellVoltageBox();
    QSpinBox& lowCellVoltageIdBox();
    QSpinBox& lowTempBox();
    QSpinBox& lowThermistorIdBox();
    QDoubleSpinBox& packAmphoursBox();
    QDoubleSpinBox& packCurrentBox();
    QDoubleSpinBox& packDepthOfDischargeBox();
    QDoubleSpinBox& packDepthOfChargeBox();
    QDoubleSpinBox& packVoltageBox();
    QSpinBox& populatedCellsBox();
    QSpinBox& prechargeStateBox();
    QSpinBox& requestedFanSpeedBox();

    QSpinBox& accelerationBox();
    QSpinBox& regenBrakingBox();
    QCheckBox& driverControlsAliveCheck();
    QCheckBox& auxCheck();
    QCheckBox& brakesCheck();
    QCheckBox& forwardCheck();
    QCheckBox& hornCheck();
    QCheckBox& pushToTalkCheck();
    QCheckBox& resetCheck();
    QCheckBox& reverseCheck();
    QCheckBox& hazardCheck();
    QCheckBox& headlightsHighCheck();
    QCheckBox& headlightsLowCheck();
    QCheckBox& headlightsOffCheck();
    QCheckBox& interiorCheck();
    QCheckBox& signalLeftCheck();
    QCheckBox& signalRightCheck();
    QCheckBox& nextSongCheck();
    QCheckBox& previousSongCheck();
    QCheckBox& volumeDownCheck();
    QCheckBox& volumeUpCheck();

    QCheckBox& m0AliveCheck();
    QDoubleSpinBox& m0BusCurrentBox();
    QDoubleSpinBox& m0BusVoltageBox();
    QDoubleSpinBox& m0SetCurrentBox();
    QDoubleSpinBox& m0SetVelocityBox();
    QDoubleSpinBox& m0VehicleVelocityBox();

    QCheckBox& m1AliveCheck();
    QDoubleSpinBox& m1BusCurrentBox();
    QDoubleSpinBox& m1BusVoltageBox();
    QDoubleSpinBox& m1SetCurrentBox();
    QDoubleSpinBox& m1SetVelocityBox();
    QDoubleSpinBox& m1VehicleVelocityBox();

    QDoubleSpinBox& m0BackEMFBox();
    QDoubleSpinBox& m0DcBusAmphoursBox();
    QDoubleSpinBox& m0DspBoardTempBox();
    QDoubleSpinBox& m0HeatSinkTempBox();
    QDoubleSpinBox& m0MotorCurrentImaginaryBox();
    QDoubleSpinBox& m0MotorCurrentRealBox();
    QDoubleSpinBox& m0MotorTempBox();
    QDoubleSpinBox& m0MotorVoltageImaginaryBox();
    QDoubleSpinBox& m0MotorVoltageRealBox();
    QDoubleSpinBox& m0OdometerBox();
    QDoubleSpinBox& m0PhaseBCurrentBox();
    QDoubleSpinBox& m0PhaseCCurrentBox();
    QDoubleSpinBox& m0SlipSpeedBox();
    QDoubleSpinBox& m0VoltageRailSupply15VBox();
    QDoubleSpinBox& m0VoltageRailSupply1VBox();
    QDoubleSpinBox& m0VoltageRailSupply3VBox();

    QDoubleSpinBox& m1BackEMFBox();
    QDoubleSpinBox& m1DcBusAmphoursBox();
    QDoubleSpinBox& m1DspBoardTempBox();
    QDoubleSpinBox& m1HeatSinkTempBox();
    QDoubleSpinBox& m1MotorCurrentImaginaryBox();
    QDoubleSpinBox& m1MotorCurrentRealBox();
    QDoubleSpinBox& m1MotorTempBox();
    QDoubleSpinBox& m1MotorVoltageImaginaryBox();
    QDoubleSpinBox& m1MotorVoltageRealBox();
    QDoubleSpinBox& m1OdometerBox();
    QDoubleSpinBox& m1PhaseBCurrentBox();
    QDoubleSpinBox& m1PhaseCCurrentBox();
    QDoubleSpinBox& m1SlipSpeedBox();
    QDoubleSpinBox& m1VoltageRailSupply15VBox();
    QDoubleSpinBox& m1VoltageRailSupply1VBox();
    QDoubleSpinBox& m1VoltageRailSupply3VBox();

    QSpinBox& m0CanRxErrorCountBox();
    QSpinBox& m0CanTxErrorCountBox();
    QCheckBox& m0BadMotorPositionHallSequenceCheck();
    QCheckBox& m0ConfigReadErrorBox();
    QCheckBox& m0DcBusOverVoltageCheck();
    QCheckBox& m0OverCurrentCheck();
    QCheckBox& m0DesaturationFaultCheck();
    QCheckBox& m0OverSpeedCheck();
    QCheckBox& m0RailUnderVoltageLockOutCheck();
    QCheckBox& m0WatchDogCausedLastResetCheck();
    QCheckBox& m0BusCurrentCheck();
    QCheckBox& m0BusVoltageLowerCheck();
    QCheckBox& m0BusVoltageUpperCheck();
    QCheckBox& m0IpmOrMotorTempCheck();
    QCheckBox& m0MotorCurrentCheck();
    QCheckBox& m0OutputVoltagePwmCheck();
    QCheckBox& m0VelocityCheck();

    QSpinBox& m1CanRxErrorCountBox();
    QSpinBox& m1CanTxErrorCountBox();
    QCheckBox& m1BadMotorPositionHallSequenceCheck();
    QCheckBox& m1ConfigReadErrorBox();
    QCheckBox& m1DcBusOverVoltageCheck();
    QCheckBox& m1OverCurrentCheck();
    QCheckBox& m1DesaturationFaultCheck();
    QCheckBox& m1OverSpeedCheck();
    QCheckBox& m1RailUnderVoltageLockOutCheck();
    QCheckBox& m1WatchDogCausedLastResetCheck();
    QCheckBox& m1BusCurrentCheck();
    QCheckBox& m1BusVoltageLowerCheck();
    QCheckBox& m1BusVoltageUpperCheck();
    QCheckBox& m1IpmOrMotorTempCheck();
    QCheckBox& m1MotorCurrentCheck();
    QCheckBox& m1OutputVoltagePwmCheck();
    QCheckBox& m1VelocityCheck();

    QCheckBox& bmsStrobeLightCheck();
    QCheckBox& brakeLightsCheck();
    QCheckBox& highBeamsCheck();
    QCheckBox& leftSignalCheck();
    QCheckBox& lightsAliveCheck();
    QCheckBox& lowBeamsCheck();
    QCheckBox& rightSignalCheck();

    QCheckBox& mpptAliveCheck();
    QSpinBox& arrayCurrentBox();
    QSpinBox& arrayVoltageBox();
    QSpinBox& batteryVoltageBox();
    QSpinBox& mpptNumberBox();
    QSpinBox& temperatureBox();

private:
    Ui::PacketWindow* ui_;
};

