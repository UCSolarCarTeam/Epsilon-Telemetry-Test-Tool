#include "MotorFaultsReporting.h"
#include "MotorFaultsData.h"
#include "../UILayer/Packet/MotorTab.h"

MotorFaultsReporting::MotorFaultsReporting(MotorFaultsData& motorFaultsData,
                                           MotorTab& motor0Tab,
                                           MotorTab& motor1Tab)
    : motorFaultsData_(motorFaultsData)
    , motor0Tab_(motor0Tab)
    , motor1Tab_(motor1Tab)
{
}

void MotorFaultsReporting::setMotorFaultsData()
{
    motorFaultsData_.setMotor0OverSpeed(motor0Tab_.overSpeed().isChecked());
    motorFaultsData_.setMotor0SoftwareOverCurrent(motor0Tab_.overCurrent().isChecked());
    motorFaultsData_.setMotor0DcBusOverVoltage(motor0Tab_.dcBusOverVoltage().isChecked());
    motorFaultsData_.setMotor0BadMotorPositionHallSequence(motor0Tab_.badMotorPositionHallSequence().isChecked());
    motorFaultsData_.setMotor0WatchdogCausedLastReset(motor0Tab_.watchDogCausedLastReset().isChecked());
    motorFaultsData_.setMotor0ConfigReadError(motor0Tab_.configReadError().isChecked());
    motorFaultsData_.setMotor0Rail15VUnderVoltageLockOut(motor0Tab_.railUnderVoltageLockOut().isChecked());
    motorFaultsData_.setMotor0DesaturationFault(motor0Tab_.desaturationFault().isChecked());
    motorFaultsData_.setMotor0OutputVoltagePwmLimit(motor0Tab_.outputVoltagePwmLimit().isChecked());
    motorFaultsData_.setMotor0MotorCurrentLimit(motor0Tab_.motorCurrentLimit().isChecked());
    motorFaultsData_.setMotor0VelocityLimit(motor0Tab_.velocityLimit().isChecked());
    motorFaultsData_.setMotor0BusCurrentLimit(motor0Tab_.busCurrentLimit().isChecked());
    motorFaultsData_.setMotor0BusVoltageUpperLimit(motor0Tab_.busVoltageUpperLimit().isChecked());
    motorFaultsData_.setMotor0BusVoltageLowerLimit(motor0Tab_.busVoltageLowerLimit().isChecked());
    motorFaultsData_.setMotor0IpmOrMotorTemperatureLimit(motor0Tab_.ipmOrMotorTempLimit().isChecked());
    motorFaultsData_.setMotor0RxErrorCount(motor0Tab_.canRxErrorCount().value());
    motorFaultsData_.setMotor0TxErrorCount(motor0Tab_.canTxErrorCount().value());

    motorFaultsData_.setMotor1OverSpeed(motor1Tab_.overSpeed().isChecked());
    motorFaultsData_.setMotor1SoftwareOverCurrent(motor1Tab_.overCurrent().isChecked());
    motorFaultsData_.setMotor1DcBusOverVoltage(motor1Tab_.dcBusOverVoltage().isChecked());
    motorFaultsData_.setMotor1BadMotorPositionHallSequence(motor1Tab_.badMotorPositionHallSequence().isChecked());
    motorFaultsData_.setMotor1WatchdogCausedLastReset(motor1Tab_.watchDogCausedLastReset().isChecked());
    motorFaultsData_.setMotor1ConfigReadError(motor1Tab_.configReadError().isChecked());
    motorFaultsData_.setMotor1Rail15VUnderVoltageLockOut(motor1Tab_.railUnderVoltageLockOut().isChecked());
    motorFaultsData_.setMotor1DesaturationFault(motor1Tab_.desaturationFault().isChecked());
    motorFaultsData_.setMotor1OutputVoltagePwmLimit(motor1Tab_.outputVoltagePwmLimit().isChecked());
    motorFaultsData_.setMotor1MotorCurrentLimit(motor1Tab_.motorCurrentLimit().isChecked());
    motorFaultsData_.setMotor1VelocityLimit(motor1Tab_.velocityLimit().isChecked());
    motorFaultsData_.setMotor1BusCurrentLimit(motor1Tab_.busCurrentLimit().isChecked());
    motorFaultsData_.setMotor1BusVoltageUpperLimit(motor1Tab_.busVoltageUpperLimit().isChecked());
    motorFaultsData_.setMotor1BusVoltageLowerLimit(motor1Tab_.busVoltageLowerLimit().isChecked());
    motorFaultsData_.setMotor1IpmOrMotorTemperatureLimit(motor1Tab_.ipmOrMotorTempLimit().isChecked());
    motorFaultsData_.setMotor1RxErrorCount(motor1Tab_.canRxErrorCount().value());
    motorFaultsData_.setMotor1TxErrorCount(motor1Tab_.canTxErrorCount().value());
}
