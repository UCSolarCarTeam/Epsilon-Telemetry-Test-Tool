#include "MotorFaultsReporting.h"
#include "MotorFaultsData.h"
#include "../UILayer/Packet/MotorFaultsTab.h"

MotorFaultsReporting::MotorFaultsReporting(MotorFaultsData& motorFaultsData,
                                           MotorFaultsTab& motor0FaultsTab,
                                           MotorFaultsTab& motor1FaultsTab)
    : motorFaultsData_(motorFaultsData)
    , motor0FaultsTab_(motor0FaultsTab)
    , motor1FaultsTab_(motor1FaultsTab)
{
}

void MotorFaultsReporting::setData()
{
    motorFaultsData_.setMotor0OverSpeed(motor0FaultsTab_.overSpeed().isChecked());
    motorFaultsData_.setMotor0SoftwareOverCurrent(motor0FaultsTab_.overCurrent().isChecked());
    motorFaultsData_.setMotor0DcBusOverVoltage(motor0FaultsTab_.dcBusOverVoltage().isChecked());
    motorFaultsData_.setMotor0BadMotorPositionHallSequence(motor0FaultsTab_.badMotorPositionHallSequence().isChecked());
    motorFaultsData_.setMotor0WatchdogCausedLastReset(motor0FaultsTab_.watchDogCausedLastReset().isChecked());
    motorFaultsData_.setMotor0ConfigReadError(motor0FaultsTab_.configReadError().isChecked());
    motorFaultsData_.setMotor0Rail15VUnderVoltageLockOut(motor0FaultsTab_.railUnderVoltageLockOut().isChecked());
    motorFaultsData_.setMotor0DesaturationFault(motor0FaultsTab_.desaturationFault().isChecked());
    motorFaultsData_.setMotor0OutputVoltagePwmLimit(motor0FaultsTab_.outputVoltagePwmLimit().isChecked());
    motorFaultsData_.setMotor0MotorCurrentLimit(motor0FaultsTab_.motorCurrentLimit().isChecked());
    motorFaultsData_.setMotor0VelocityLimit(motor0FaultsTab_.velocityLimit().isChecked());
    motorFaultsData_.setMotor0BusCurrentLimit(motor0FaultsTab_.busCurrentLimit().isChecked());
    motorFaultsData_.setMotor0BusVoltageUpperLimit(motor0FaultsTab_.busVoltageUpperLimit().isChecked());
    motorFaultsData_.setMotor0BusVoltageLowerLimit(motor0FaultsTab_.busVoltageLowerLimit().isChecked());
    motorFaultsData_.setMotor0IpmOrMotorTemperatureLimit(motor0FaultsTab_.ipmOrMotorTempLimit().isChecked());
    motorFaultsData_.setMotor0RxErrorCount(motor0FaultsTab_.canRxErrorCount().value());
    motorFaultsData_.setMotor0TxErrorCount(motor0FaultsTab_.canTxErrorCount().value());

    motorFaultsData_.setMotor1OverSpeed(motor1FaultsTab_.overSpeed().isChecked());
    motorFaultsData_.setMotor1SoftwareOverCurrent(motor1FaultsTab_.overCurrent().isChecked());
    motorFaultsData_.setMotor1DcBusOverVoltage(motor1FaultsTab_.dcBusOverVoltage().isChecked());
    motorFaultsData_.setMotor1BadMotorPositionHallSequence(motor1FaultsTab_.badMotorPositionHallSequence().isChecked());
    motorFaultsData_.setMotor1WatchdogCausedLastReset(motor1FaultsTab_.watchDogCausedLastReset().isChecked());
    motorFaultsData_.setMotor1ConfigReadError(motor1FaultsTab_.configReadError().isChecked());
    motorFaultsData_.setMotor1Rail15VUnderVoltageLockOut(motor1FaultsTab_.railUnderVoltageLockOut().isChecked());
    motorFaultsData_.setMotor1DesaturationFault(motor1FaultsTab_.desaturationFault().isChecked());
    motorFaultsData_.setMotor1OutputVoltagePwmLimit(motor1FaultsTab_.outputVoltagePwmLimit().isChecked());
    motorFaultsData_.setMotor1MotorCurrentLimit(motor1FaultsTab_.motorCurrentLimit().isChecked());
    motorFaultsData_.setMotor1VelocityLimit(motor1FaultsTab_.velocityLimit().isChecked());
    motorFaultsData_.setMotor1BusCurrentLimit(motor1FaultsTab_.busCurrentLimit().isChecked());
    motorFaultsData_.setMotor1BusVoltageUpperLimit(motor1FaultsTab_.busVoltageUpperLimit().isChecked());
    motorFaultsData_.setMotor1BusVoltageLowerLimit(motor1FaultsTab_.busVoltageLowerLimit().isChecked());
    motorFaultsData_.setMotor1IpmOrMotorTemperatureLimit(motor1FaultsTab_.ipmOrMotorTempLimit().isChecked());
    motorFaultsData_.setMotor1RxErrorCount(motor1FaultsTab_.canRxErrorCount().value());
    motorFaultsData_.setMotor1TxErrorCount(motor1FaultsTab_.canTxErrorCount().value());
}
