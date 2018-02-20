#include "PacketWindow.h"
#include "ui_PacketWindow.h"

PacketWindow::PacketWindow()
    : ui_(new Ui::PacketWindow)
{
    ui_->setupUi(this);
}

PacketWindow::~PacketWindow()
{
    delete ui_;
}

QCheckBox& PacketWindow::alwaysOnSupplyFaultCheck()
{
    return *ui_->alwaysOnSupplyFaultCheck;
}

QCheckBox& PacketWindow::canbusCommsFaultCheck()
{
    return *ui_->canbusCommsFaultCheck;
}

QCheckBox& PacketWindow::chargeLimitEnforementFaultCheck()
{
    return *ui_->chargeLimitEnforcementFaultCheck;
}

QCheckBox& PacketWindow::chargerSafetyRelayFaultCheck()
{
    return *ui_->chargerSafetyRelayFaultCheck;
}
QCheckBox& PacketWindow::currentSensorFaultCheck()
{
    return *ui_->currentSensorFaultCheck;
}

QCheckBox& PacketWindow::dischargeLimitEnforcementFaultCheck()
{
    return *ui_->dischargeLimitEnforcementFaultCheck;
}

QCheckBox& PacketWindow::fanMonitorFaultCheck()
{
    return *ui_->fanMonitorFaultCheck;
}
QCheckBox& PacketWindow::highVoltageIsolationFaultCheck()
{
    return *ui_->highVoltageIsolationFaultCheck;
}

QCheckBox& PacketWindow::internalCommFaultCheck()
{
    return *ui_->internalCommFaultCheck;
}

QCheckBox& PacketWindow::internalLogicFaultCheck()
{
    return *ui_->internalLogicFaultCheck;
}

QCheckBox& PacketWindow::internalMemoryFaultCheck()
{
    return *ui_->internalMemoryFaultCheck;
}

QCheckBox& PacketWindow::internalThermistorFaultCheck()
{
    return *ui_->internalThermistorFaultCheck;
}

QCheckBox& PacketWindow::lowCellVoltageFaultCheck()
{
    return *ui_->lowCellVoltageFaultCheck;
}

QCheckBox& PacketWindow::openWiringFaultCheck()
{
    return *ui_->openWiringFaultCheck;
}

QCheckBox& PacketWindow::packVoltageSensorCheck()
{
    return *ui_->packVoltageSensorCheck;
}

QCheckBox& PacketWindow::powerSupplyFaultCheck()
{
    return *ui_->powerSupplyFaultCheck;
}

QCheckBox& PacketWindow::thermistorFaultCheck()
{
    return *ui_->thermistorFaultCheck;
}

QCheckBox& PacketWindow::voltageRedundancyFaultCheck()
{
    return *ui_->voltageRedundancyFaultCheck;
}

QCheckBox& PacketWindow::weakCellFaultCheck()
{
    return *ui_->weakCellFaultCheck;
}

QCheckBox& PacketWindow::weakPackFaultCheck()
{
    return *ui_->weakPackFaultCheck;
}

QCheckBox& PacketWindow::cclReducedACLimit()
{
    return *ui_->cclReducedACLimit;
}

QCheckBox& PacketWindow::cclReducedChargerLatchCheck()
{
    return *ui_->cclReducedChargerLatchCheck;
}

QCheckBox& PacketWindow::cclReducedHighCellResistanceCheck()
{
    return *ui_->cclReducedHighCellResistanceCheck;
}

QCheckBox& PacketWindow::cclReducedHighCellVoltageCheck()
{
    return *ui_->cclReducedHighCellVoltageCheck;
}

QCheckBox& PacketWindow::cclReducedHighPackVoltageCheck()
{
    return *ui_->cclReducedHighPackVoltageCheck;
}

QCheckBox& PacketWindow::cclReducedHighSocCheck()
{
    return *ui_->cclReducedHighSocCheck;
}

QCheckBox& PacketWindow::cclReducedTempCheck()
{
    return *ui_->cclReducedTempCheck;
}

QCheckBox& PacketWindow::dclCclReducedCommsFailSafeCheck()
{
    return *ui_->dclCclReducedCommsFailsafeCheck;
}

QCheckBox& PacketWindow::dclCclReducedVoltageFailsafeCheck()
{
    return *ui_->dclCclReducedVoltageFailsafeCheck;
}

QCheckBox& PacketWindow::dclReducedHighCellResistanceCheck()
{
    return *ui_->dclReducedHighCellResistanceCheck;
}

QCheckBox& PacketWindow::dclReducedLowCellVoltageCheck()
{
    return *ui_->dclReducedHighCellResistanceCheck;
}

QCheckBox& PacketWindow::dclReducedLowPackVoltageCheck()
{
    return *ui_->dclReducedLowPackVoltageCheck;
}

QCheckBox& PacketWindow::dclReducedLowSocCheck()
{
    return *ui_->dclReducedLowSocCheck;
}

QCheckBox& PacketWindow::dclReducedTempCheck()
{
    return *ui_->dclReducedTempCheck;
}

QCheckBox& PacketWindow::allowChargeCheck()
{
    return *ui_->allowChargeCheck;
}

QCheckBox& PacketWindow::auxBMSAliveCheck()
{
    return *ui_->auxBmsAliveCheck;
}

QCheckBox& PacketWindow::bmuAliveCheck()
{
    return *ui_->bmuAliveCheck;
}

QCheckBox& PacketWindow::strobeBmsLightCheck()
{
    return *ui_->strobeBmsLightCheck;
}

QCheckBox& PacketWindow::contractorErrorCheck()
{
    return *ui_->contractorErrorCheck;
}

QCheckBox& PacketWindow::alwaysOnCheck()
{
    return *ui_->alwaysOnCheck;
}

QCheckBox& PacketWindow::chargeRelayCheck()
{
    return *ui_->chargeRelayCheck;
}

QCheckBox& PacketWindow::chargerSafetyCheck()
{
    return *ui_->chargerSafetyCheck;
}

QCheckBox& PacketWindow::dischargeRelayCheck()
{
    return *ui_->dischargeRelayCheck;
}

QCheckBox& PacketWindow::isChargingCheck()
{
    return *ui_->isChargingCheck;
}

QCheckBox& PacketWindow::isReadyCheck()
{
    return *ui_->isReadyCheck;
}

QCheckBox& PacketWindow::malfunctionIndicatorCheck()
{
    return *ui_->malfunctionIndicatorCheck;
}

QCheckBox& PacketWindow::multipurposeInputCheck()
{
    return *ui_->multipurposeInputCheck;
}

QSpinBox& PacketWindow::PacketWindow::auxVoltageBox()
{
    return *ui_->auxVoltageBox;
}

QSpinBox& PacketWindow::averageCellVoltageBox()
{
    return *ui_->averageCellVoltageBox;
}

QSpinBox& PacketWindow::averageTempBox()
{
    return *ui_->averageTempBox;
}

QSpinBox& PacketWindow::fanSpeedBox()
{
    return *ui_->fanSpeedBox;
}

QDoubleSpinBox& PacketWindow::fanVoltageBox()
{
    return *ui_->fanVoltageBox;
}

QSpinBox& PacketWindow::highCellVoltageBox()
{
    return *ui_->highCellVoltageBox;
}

QSpinBox& PacketWindow::highCellVoltageIdBox()
{
    return *ui_->highCellVoltageIdBox;
}

QSpinBox& PacketWindow::highTempBox()
{
    return *ui_->highTempBox;
}

QSpinBox& PacketWindow::highThermistorIdBox()
{
    return *ui_->highThermistorIdBox;
}

QDoubleSpinBox& PacketWindow::inputVoltage12VBox()
{
    return *ui_->inputVoltage12VBox;
}

QSpinBox& PacketWindow::internalTempBox()
{
    return *ui_->internalTempBox;
}

QSpinBox& PacketWindow::lowCellVoltageBox()
{
    return *ui_->lowCellVoltageBox;
}

QSpinBox& PacketWindow::lowCellVoltageIdBox()
{
    return *ui_->lowCellVoltageIdBox;
}

QSpinBox& PacketWindow::lowTempBox()
{
    return *ui_->lowTempBox;
}

QSpinBox& PacketWindow::lowThermistorIdBox()
{
    return *ui_->lowThermistorIdBox;
}

QDoubleSpinBox& PacketWindow::packAmphoursBox()
{
    return *ui_->packAmphoursBox;
}

QDoubleSpinBox& PacketWindow::packCurrentBox()
{
    return *ui_->packCurrentBox;
}

QDoubleSpinBox& PacketWindow::packDepthOfDischargeBox()
{
    return *ui_->packDepthOfDischargeBox;
}

QDoubleSpinBox& PacketWindow::packDepthOfChargeBox()
{
    return *ui_->packDepthOfDischargeBox;
}

QDoubleSpinBox& PacketWindow::packVoltageBox()
{
    return *ui_->packVoltageBox;
}

QSpinBox& PacketWindow::populatedCellsBox()
{
    return *ui_->populatedCellsBox;
}

QSpinBox& PacketWindow::prechargeStateBox()
{
    return *ui_->prechargeStateBox;
}

QSpinBox& PacketWindow::requestedFanSpeedBox()
{
    return *ui_->requestedFanSpeedBox;
}

QSpinBox& PacketWindow::accelerationBox()
{
    return *ui_->accelerationBox;
}

QSpinBox& PacketWindow::regenBrakingBox()
{
    return *ui_->regenBrakingBox;
}

QCheckBox& PacketWindow::driverControlsAliveCheck()
{
    return *ui_->driverControlsAliveCheck;
}

QCheckBox& PacketWindow::auxCheck()
{
    return *ui_->auxCheck;
}

QCheckBox& PacketWindow::brakesCheck()
{
    return *ui_->brakesCheck;
}

QCheckBox& PacketWindow::forwardCheck()
{
    return *ui_->forwardCheck;
}

QCheckBox& PacketWindow::hornCheck()
{
    return *ui_->hornCheck;
}

QCheckBox& PacketWindow::pushToTalkCheck()
{
    return *ui_->pushToTalkCheck;
}

QCheckBox& PacketWindow::resetCheck()
{
    return *ui_->resetCheck;
}

QCheckBox& PacketWindow::reverseCheck()
{
    return *ui_->reverseCheck;
}

QCheckBox& PacketWindow::hazardCheck()
{
    return *ui_->hazardCheck;
}

QCheckBox& PacketWindow::headlightsHighCheck()
{
    return *ui_->headlightsHighCheck;
}

QCheckBox& PacketWindow::headlightsLowCheck()
{
    return *ui_->headlightsLowCheck;
}

QCheckBox& PacketWindow::headlightsOffCheck()
{
    return *ui_->headlightsLowCheck;
}

QCheckBox& PacketWindow::interiorCheck()
{
    return *ui_->interiorCheck;
}

QCheckBox& PacketWindow::signalLeftCheck()
{
    return *ui_->signalLeftCheck;
}

QCheckBox& PacketWindow::signalRightCheck()
{
    return *ui_->signalRightCheck;
}

QCheckBox& PacketWindow::nextSongCheck()
{
    return *ui_->nextSongCheck;
}

QCheckBox& PacketWindow::previousSongCheck()
{
    return *ui_->previousSongCheck;
}

QCheckBox& PacketWindow::volumeDownCheck()
{
    return *ui_->volumeDownCheck;
}

QCheckBox& PacketWindow::volumeUpCheck()
{
    return *ui_->volumeUpCheck;
}

QCheckBox& PacketWindow::m0AliveCheck()
{
    return *ui_->m0AliveCheck;
}

QDoubleSpinBox& PacketWindow::m0BusCurrentBox()
{
    return *ui_->m0BusCurrentBox;
}

QDoubleSpinBox& PacketWindow::m0BusVoltageBox()
{
    return *ui_->m0BusVoltageBox;
}

QDoubleSpinBox& PacketWindow::m0SetCurrentBox()
{
    return *ui_->m0SetCurrentBox;
}

QDoubleSpinBox& PacketWindow::m0SetVelocityBox()
{
    return *ui_->m0SetVelocityBox;
}

QDoubleSpinBox& PacketWindow::m0VehicleVelocityBox()
{
    return *ui_->m0VehicleVelocityBox;
}

QCheckBox& PacketWindow::m1AliveCheck()
{
    return *ui_->m1AliveCheck;
}

QDoubleSpinBox& PacketWindow::m1BusCurrentBox()
{
    return *ui_->m1BusCurrentBox;
}

QDoubleSpinBox& PacketWindow::m1BusVoltageBox()
{
    return *ui_->m1BusVoltageBox;
}

QDoubleSpinBox& PacketWindow::m1SetCurrentBox()
{
    return *ui_->m1SetCurrentBox;
}

QDoubleSpinBox& PacketWindow::m1SetVelocityBox()
{
    return *ui_->m1SetVelocityBox;
}

QDoubleSpinBox& PacketWindow::m1VehicleVelocityBox()
{
    return *ui_->m1VehicleVelocityBox;
}

QDoubleSpinBox& PacketWindow::m0BackEMFBox()
{
    return *ui_->m0BackEMFBox;
}

QDoubleSpinBox& PacketWindow::m0DcBusAmphoursBox()
{
    return *ui_->m0DcBusAmphoursBox;
}

QDoubleSpinBox& PacketWindow::m0DspBoardTempBox()
{
    return *ui_->m0DspBoardTempBox;
}

QDoubleSpinBox& PacketWindow::m0HeatSinkTempBox()
{
    return *ui_->m0HeatSinkTempBox;
}

QDoubleSpinBox& PacketWindow::m0MotorCurrentImaginaryBox()
{
    return *ui_->m0MotorCurrentImaginaryBox;
}

QDoubleSpinBox& PacketWindow::m0MotorCurrentRealBox()
{
    return *ui_->m0MotorCurrentRealBox;
}

QDoubleSpinBox& PacketWindow::m0MotorTempBox()
{
    return *ui_->m0MotorTempBox;
}

QDoubleSpinBox& PacketWindow::m0MotorVoltageImaginaryBox()
{
    return *ui_->m0MotorVoltageImaginaryBox;
}

QDoubleSpinBox& PacketWindow::m0MotorVoltageRealBox()
{
    return *ui_->m0MotorVoltageRealBox;
}

QDoubleSpinBox& PacketWindow::m0OdometerBox()
{
    return *ui_->m0OdometerBox;
}

QDoubleSpinBox& PacketWindow::m0PhaseBCurrentBox()
{
    return *ui_->m0PhaseBCurrentBox;
}

QDoubleSpinBox& PacketWindow::m0PhaseCCurrentBox()
{
    return *ui_->m0PhaseCCurrentBox;
}

QDoubleSpinBox& PacketWindow::m0SlipSpeedBox()
{
    return *ui_->m0SlipSpeedBox;
}

QDoubleSpinBox& PacketWindow::m0VoltageRailSupply15VBox()
{
    return *ui_->m0VoltageRailSupply15VBox;
}

QDoubleSpinBox& PacketWindow::m0VoltageRailSupply1VBox()
{
    return *ui_->m0VoltageRailSupply1VBox;
}

QDoubleSpinBox& PacketWindow::m0VoltageRailSupply3VBox()
{
    return *ui_->m0VoltageRailSupply3VBox;
}

QDoubleSpinBox& PacketWindow::m1BackEMFBox()
{
    return *ui_->m1BackEMFBox;
}

QDoubleSpinBox& PacketWindow::m1DcBusAmphoursBox()
{
    return *ui_->m1DcBusAmphoursBox;
}

QDoubleSpinBox& PacketWindow::m1DspBoardTempBox()
{
    return *ui_->m1DspBoardTempBox;
}

QDoubleSpinBox& PacketWindow::m1HeatSinkTempBox()
{
    return *ui_->m1HeatSinkTempBox;
}

QDoubleSpinBox& PacketWindow::m1MotorCurrentImaginaryBox()
{
    return *ui_->m1MotorCurrentImaginaryBox;
}

QDoubleSpinBox& PacketWindow::m1MotorCurrentRealBox()
{
    return *ui_->m1MotorCurrentRealBox;
}

QDoubleSpinBox& PacketWindow::m1MotorTempBox()
{
    return *ui_->m1MotorTempBox;
}

QDoubleSpinBox& PacketWindow::m1MotorVoltageImaginaryBox()
{
    return *ui_->m1MotorVoltageImaginaryBox;
}

QDoubleSpinBox& PacketWindow::m1MotorVoltageRealBox()
{
    return *ui_->m1MotorVoltageRealBox;
}

QDoubleSpinBox& PacketWindow::m1OdometerBox()
{
    return *ui_->m1OdometerBox;
}

QDoubleSpinBox& PacketWindow::m1PhaseBCurrentBox()
{
    return *ui_->m1PhaseBCurrentBox;
}

QDoubleSpinBox& PacketWindow::m1PhaseCCurrentBox()
{
    return *ui_->m1PhaseCCurrentBox;
}

QDoubleSpinBox& PacketWindow::m1SlipSpeedBox()
{
    return *ui_->m1SlipSpeedBox;
}

QDoubleSpinBox& PacketWindow::m1VoltageRailSupply15VBox()
{
    return *ui_->m1VoltageRailSupply15VBox;
}

QDoubleSpinBox& PacketWindow::m1VoltageRailSupply1VBox()
{
    return *ui_->m1VoltageRailSupply1VBox;
}

QDoubleSpinBox& PacketWindow::m1VoltageRailSupply3VBox()
{
    return *ui_->m1VoltageRailSupply3VBox;
}

QSpinBox& PacketWindow::m0CanRxErrorCountBox()
{
    return *ui_->m0CanRxErrorCountBox;
}

QSpinBox& PacketWindow::m0CanTxErrorCountBox()
{
    return *ui_->m0CanTxErrorCountBox;
}

QCheckBox& PacketWindow::m0BadMotorPositionHallSequenceCheck()
{
    return *ui_->m0BadMotorPositionHallSequenceCheck;
}

QCheckBox& PacketWindow::m0ConfigReadErrorBox()
{
    return *ui_->m0ConfigReadErrorBox;
}

QCheckBox& PacketWindow::m0DcBusOverVoltageCheck()
{
    return *ui_->m0DcBusOverVoltageCheck;
}

QCheckBox& PacketWindow::m0OverCurrentCheck()
{
    return *ui_->m0OverCurrentCheck;
}

QCheckBox& PacketWindow::m0DesaturationFaultCheck()
{
    return *ui_->m0DesaturationFaultCheck;
}

QCheckBox& PacketWindow::m0OverSpeedCheck()
{
    return *ui_->m0OverSpeedCheck;
}

QCheckBox& PacketWindow::m0RailUnderVoltageLockOutCheck()
{
    return *ui_->m0RailUnderVoltageLockOutCheck;
}

QCheckBox& PacketWindow::m0WatchDogCausedLastResetCheck()
{
    return *ui_->m0WatchdogCausedLastResetCheck;
}

QCheckBox& PacketWindow::m0BusCurrentCheck()
{
    return *ui_->m0BusCurrentCheck;
}

QCheckBox& PacketWindow::m0BusVoltageLowerCheck()
{
    return *ui_->m0BusVoltageLowerCheck;
}

QCheckBox& PacketWindow::m0BusVoltageUpperCheck()
{
    return *ui_->m0BusVoltageUpperCheck;
}

QCheckBox& PacketWindow::m0IpmOrMotorTempCheck()
{
    return *ui_->m0IpmOrMotorTempCheck;
}

QCheckBox& PacketWindow::m0MotorCurrentCheck()
{
    return *ui_->m0MotorCurrentCheck;
}

QCheckBox& PacketWindow::m0OutputVoltagePwmCheck()
{
    return *ui_->m0OutputVoltagePwmCheck;
}

QCheckBox& PacketWindow::m0VelocityCheck()
{
    return *ui_->m0VelocityCheck;
}

QSpinBox& PacketWindow::m1CanRxErrorCountBox()
{
    return *ui_->m1CanRxErrorCountBox;
}

QSpinBox& PacketWindow::m1CanTxErrorCountBox()
{
    return *ui_->m1CanTxErrorCountBox;
}

QCheckBox& PacketWindow::m1BadMotorPositionHallSequenceCheck()
{
    return *ui_->m1BadMotorPositionHallSequenceCheck;
}

QCheckBox& PacketWindow::m1ConfigReadErrorBox()
{
    return *ui_->m1ConfigReadErrorCheck;
}

QCheckBox& PacketWindow::m1DcBusOverVoltageCheck()
{
    return *ui_->m1DcBusOverVoltageCheck;
}

QCheckBox& PacketWindow::m1OverCurrentCheck()
{
    return *ui_->m1OverCurrentCheck;
}

QCheckBox& PacketWindow::m1DesaturationFaultCheck()
{
    return *ui_->m1DesaturationFaultCheck;
}

QCheckBox& PacketWindow::m1OverSpeedCheck()
{
    return *ui_->m1OverSpeedCheck;
}

QCheckBox& PacketWindow::m1RailUnderVoltageLockOutCheck()
{
    return *ui_->m1RailOverVoltageLockOutCheck;
}

QCheckBox& PacketWindow::m1WatchDogCausedLastResetCheck()
{
    return *ui_->m1WatchdogCausedLastResetCheck;
}

QCheckBox& PacketWindow::m1BusCurrentCheck()
{
    return *ui_->m1BusCurrentCheck;
}

QCheckBox& PacketWindow::m1BusVoltageLowerCheck()
{
    return *ui_->m1BusVoltageLowerCheck;
}

QCheckBox& PacketWindow::m1BusVoltageUpperCheck()
{
    return *ui_->m1BusVoltageUpperCheck;
}

QCheckBox& PacketWindow::m1IpmOrMotorTempCheck()
{
    return *ui_->m1IpmOrMotorTempCheck;
}

QCheckBox& PacketWindow::m1MotorCurrentCheck()
{
    return *ui_->m1MotorCurrentCheck;
}

QCheckBox& PacketWindow::m1OutputVoltagePwmCheck()
{
    return *ui_->m1OutputVoltagePwmCheck;
}

QCheckBox& PacketWindow::m1VelocityCheck()
{
    return *ui_->m1VelocityCheck;
}

QCheckBox& PacketWindow::bmsStrobeLightCheck()
{
    return *ui_->bmsStrobeLightCheck;
}

QCheckBox& PacketWindow::brakeLightsCheck()
{
    return *ui_->brakeLightsCheck;
}

QCheckBox& PacketWindow::highBeamsCheck()
{
    return *ui_->highBeamsCheck;
}

QCheckBox& PacketWindow::leftSignalCheck()
{
    return *ui_->leftSignalCheck;
}

QCheckBox& PacketWindow::lightsAliveCheck()
{
    return *ui_->lightsAliveCheck;
}

QCheckBox& PacketWindow::lowBeamsCheck()
{
    return *ui_->lowBeamsCheck;
}

QCheckBox& PacketWindow::rightSignalCheck()
{
    return *ui_->rightSignalCheck;
}

QCheckBox& PacketWindow::mpptAliveCheck()
{
    return *ui_->mpptAliveCheck;
}

QSpinBox& PacketWindow::arrayCurrentBox()
{
    return *ui_->arrayCurrentBox;
}

QSpinBox& PacketWindow::arrayVoltageBox()
{
    return *ui_->arrayVoltageBox;
}

QSpinBox& PacketWindow::batteryVoltageBox()
{
    return *ui_->batteryVoltageBox;
}

QSpinBox& PacketWindow::mpptNumberBox()
{
    return *ui_->mpptNumberBox;
}

QSpinBox& PacketWindow::temperatureBox()
{
    return *ui_->temperatureBox;
}
