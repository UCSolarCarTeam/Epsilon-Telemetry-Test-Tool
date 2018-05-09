#include "MotorFaultsData.h"

MotorFaultsData::MotorFaultsData()
    : motor0OverSpeed_(true)
    , motor0SoftwareOverCurrent_(false)
    , motor0DcBusOverVoltage_(true)
    , motor0BadMotorPositionHallSequence_(true)
    , motor0WatchdogCausedLastReset_(false)
    , motor0ConfigReadError_(true)
    , motor0Rail15VUnderVoltageLockOut_(false)
    , motor0DesaturationFault_(true)
    , motor0OutputVoltagePwmLimit_(false)
    , motor0MotorCurrentLimit_(true)
    , motor0VelocityLimit_(false)
    , motor0BusCurrentLimit_(true)
    , motor0BusVoltageUpperLimit_(false)
    , motor0BusVoltageLowerLimit_(true)
    , motor0IpmOrMotorTemperatureLimit_(false)
    , motor0RxErrorCount_(28)
    , motor0TxErrorCount_(29)
    , motor1OverSpeed_(true)
    , motor1SoftwareOverCurrent_(false)
    , motor1DcBusOverVoltage_(true)
    , motor1BadMotorPositionHallSequence_(false)
    , motor1WatchdogCausedLastReset_(true)
    , motor1ConfigReadError_(false)
    , motor1Rail15VUnderVoltageLockOut_(true)
    , motor1DesaturationFault_(false)
    , motor1OutputVoltagePwmLimit_(true)
    , motor1MotorCurrentLimit_(false)
    , motor1VelocityLimit_(true)
    , motor1BusCurrentLimit_(false)
    , motor1BusVoltageUpperLimit_(true)
    , motor1BusVoltageLowerLimit_(false)
    , motor1IpmOrMotorTemperatureLimit_(true)
    , motor1RxErrorCount_(30)
    , motor1TxErrorCount_(31)
{
}

MotorFaultsData::~MotorFaultsData()
{
}

bool MotorFaultsData::motor0OverSpeed() const
{
    return motor0OverSpeed_;
}

bool MotorFaultsData::motor0SoftwareOverCurrent() const
{
    return motor0SoftwareOverCurrent_;
}

bool MotorFaultsData::motor0DcBusOverVoltage() const
{
    return motor0DcBusOverVoltage_;
}

bool MotorFaultsData::motor0BadMotorPositionHallSequence() const
{
    return motor0BadMotorPositionHallSequence_;
}

bool MotorFaultsData::motor0WatchdogCausedLastReset() const
{
    return motor0WatchdogCausedLastReset_;
}

bool MotorFaultsData::motor0ConfigReadError() const
{
    return motor0ConfigReadError_;
}

bool MotorFaultsData::motor0Rail15VUnderVoltageLockOut() const
{
    return motor0Rail15VUnderVoltageLockOut_;
}

bool MotorFaultsData::motor0DesaturationFault() const
{
    return motor0DesaturationFault_;
}

bool MotorFaultsData::motor0OutputVoltagePwmLimit() const
{
    return motor0OutputVoltagePwmLimit_;
}

bool MotorFaultsData::motor0MotorCurrentLimit() const
{
    return motor0MotorCurrentLimit_;
}

bool MotorFaultsData::motor0VelocityLimit() const
{
    return motor0VelocityLimit_;
}

bool MotorFaultsData::motor0BusCurrentLimit() const
{
    return motor0BusCurrentLimit_;
}

bool MotorFaultsData::motor0BusVoltageUpperLimit() const
{
    return motor0BusVoltageUpperLimit_;
}

bool MotorFaultsData::motor0BusVoltageLowerLimit() const
{
    return motor0BusVoltageLowerLimit_;
}

bool MotorFaultsData::motor0IpmOrMotorTemperatureLimit() const
{
    return motor0IpmOrMotorTemperatureLimit_;
}

unsigned char MotorFaultsData::motor0RxErrorCount() const
{
    return motor0RxErrorCount_;
}

unsigned char MotorFaultsData::motor0TxErrorCount() const
{
    return motor0TxErrorCount_;
}

bool MotorFaultsData::motor1OverSpeed() const
{
    return motor1OverSpeed_;
}

bool MotorFaultsData::motor1SoftwareOverCurrent() const
{
    return motor1SoftwareOverCurrent_;
}

bool MotorFaultsData::motor1DcBusOverVoltage() const
{
    return motor1DcBusOverVoltage_;
}

bool MotorFaultsData::motor1BadMotorPositionHallSequence() const
{
    return motor1BadMotorPositionHallSequence_;
}

bool MotorFaultsData::motor1WatchdogCausedLastReset() const
{
    return motor1WatchdogCausedLastReset_;
}

bool MotorFaultsData::motor1ConfigReadError() const
{
    return motor1ConfigReadError_;
}

bool MotorFaultsData::motor1Rail15VUnderVoltageLockOut() const
{
    return motor1Rail15VUnderVoltageLockOut_;
}

bool MotorFaultsData::motor1DesaturationFault() const
{
    return motor1DesaturationFault_;
}

bool MotorFaultsData::motor1OutputVoltagePwmLimit() const
{
    return motor1OutputVoltagePwmLimit_;
}

bool MotorFaultsData::motor1MotorCurrentLimit() const
{
    return motor1MotorCurrentLimit_;
}

bool MotorFaultsData::motor1VelocityLimit() const
{
    return motor1VelocityLimit_;
}

bool MotorFaultsData::motor1BusCurrentLimit() const
{
    return motor1BusCurrentLimit_;
}

bool MotorFaultsData::motor1BusVoltageUpperLimit() const
{
    return motor1BusVoltageUpperLimit_;
}

bool MotorFaultsData::motor1BusVoltageLowerLimit() const
{
    return motor1BusVoltageLowerLimit_;
}

bool MotorFaultsData::motor1IpmOrMotorTemperatureLimit() const
{
    return motor1IpmOrMotorTemperatureLimit_;
}

unsigned char MotorFaultsData::motor1RxErrorCount() const
{
    return motor1RxErrorCount_;
}

unsigned char MotorFaultsData::motor1TxErrorCount() const
{
    return motor1TxErrorCount_;
}

void MotorFaultsData::setMotor0OverSpeed(const bool& motor0OverSpeed)
{
    motor0OverSpeed_ = motor0OverSpeed;
}

void MotorFaultsData::setMotor0SoftwareOverCurrent(const bool& motor0SoftwareOverCurrent)
{
    motor0SoftwareOverCurrent_ = motor0SoftwareOverCurrent;
}

void MotorFaultsData::setMotor0DcBusOverVoltage(const bool& motor0DcBusOverVoltage)
{
    motor0DcBusOverVoltage_ = motor0DcBusOverVoltage;
}

void MotorFaultsData::setMotor0BadMotorPositionHallSequence(const bool& motor0BadMotorPositionHallSequence)
{
    motor0BadMotorPositionHallSequence_ = motor0BadMotorPositionHallSequence;
}

void MotorFaultsData::setMotor0WatchdogCausedLastReset(const bool& motor0WatchdogCausedLastReset)
{
    motor0WatchdogCausedLastReset_ = motor0WatchdogCausedLastReset;
}

void MotorFaultsData::setMotor0ConfigReadError(const bool& motor0ConfigReadError)
{
    motor0ConfigReadError_ = motor0ConfigReadError;
}

void MotorFaultsData::setMotor0Rail15VUnderVoltageLockOut(const bool& motor0Rail15VUnderVoltageLockOut)
{
    motor0Rail15VUnderVoltageLockOut_ = motor0Rail15VUnderVoltageLockOut;
}

void MotorFaultsData::setMotor0DesaturationFault(const bool& motor0DesaturationFault)
{
    motor0DesaturationFault_ = motor0DesaturationFault;
}

void MotorFaultsData::setMotor0OutputVoltagePwmLimit(const bool& motor0OutputVoltagePwmLimit)
{
    motor0OutputVoltagePwmLimit_ = motor0OutputVoltagePwmLimit;
}

void MotorFaultsData::setMotor0MotorCurrentLimit(const bool& motor0MotorCurrentLimit)
{
    motor0MotorCurrentLimit_ = motor0MotorCurrentLimit;
}

void MotorFaultsData::setMotor0VelocityLimit(const bool& motor0VelocityLimit)
{
    motor0VelocityLimit_ = motor0VelocityLimit;
}

void MotorFaultsData::setMotor0BusCurrentLimit(const bool& motor0BusCurrentLimit)
{
    motor0BusCurrentLimit_ = motor0BusCurrentLimit;
}

void MotorFaultsData::setMotor0BusVoltageUpperLimit(const bool& motor0BusVoltageUpperLimit)
{
    motor0BusVoltageUpperLimit_ = motor0BusVoltageUpperLimit;
}

void MotorFaultsData::setMotor0BusVoltageLowerLimit(const bool& motor0BusVoltageLowerLimit)
{
    motor0BusVoltageLowerLimit_ = motor0BusVoltageLowerLimit;
}

void MotorFaultsData::setMotor0IpmOrMotorTemperatureLimit(const bool& motor0IpmOrMotorTemperatureLimit)
{
    motor0IpmOrMotorTemperatureLimit_ = motor0IpmOrMotorTemperatureLimit;
}

void MotorFaultsData::setMotor0RxErrorCount(const unsigned char& motor0RxErrorCount)
{
    motor0RxErrorCount_ = motor0RxErrorCount;
}

void MotorFaultsData::setMotor0TxErrorCount(const unsigned char& motor0TxErrorCount)
{
    motor0TxErrorCount_ = motor0TxErrorCount;
}

void MotorFaultsData::setMotor1OverSpeed(const bool& motor1OverSpeed)
{
    motor1OverSpeed_ = motor1OverSpeed;
}

void MotorFaultsData::setMotor1SoftwareOverCurrent(const bool& motor1SoftwareOverCurrent)
{
    motor1SoftwareOverCurrent_ = motor1SoftwareOverCurrent;
}

void MotorFaultsData::setMotor1DcBusOverVoltage(const bool& motor1DcBusOverVoltage)
{
    motor1DcBusOverVoltage_ = motor1DcBusOverVoltage;
}

void MotorFaultsData::setMotor1BadMotorPositionHallSequence(const bool& motor1BadMotorPositionHallSequence)
{
    motor1BadMotorPositionHallSequence_ = motor1BadMotorPositionHallSequence;
}

void MotorFaultsData::setMotor1WatchdogCausedLastReset(const bool& motor1WatchdogCausedLastReset)
{
    motor1WatchdogCausedLastReset_ = motor1WatchdogCausedLastReset;
}

void MotorFaultsData::setMotor1ConfigReadError(const bool& motor1ConfigReadError)
{
    motor1ConfigReadError_ = motor1ConfigReadError;
}

void MotorFaultsData::setMotor1Rail15VUnderVoltageLockOut(const bool& motor1Rail15VUnderVoltageLockOut)
{
    motor1Rail15VUnderVoltageLockOut_ = motor1Rail15VUnderVoltageLockOut;
}

void MotorFaultsData::setMotor1DesaturationFault(const bool& motor1DesaturationFault)
{
    motor1DesaturationFault_ = motor1DesaturationFault;
}

void MotorFaultsData::setMotor1OutputVoltagePwmLimit(const bool& motor1OutputVoltagePwmLimit)
{
    motor1OutputVoltagePwmLimit_ = motor1OutputVoltagePwmLimit;
}

void MotorFaultsData::setMotor1MotorCurrentLimit(const bool& motor1MotorCurrentLimit)
{
    motor1MotorCurrentLimit_ = motor1MotorCurrentLimit;
}

void MotorFaultsData::setMotor1VelocityLimit(const bool& motor1VelocityLimit)
{
    motor1VelocityLimit_ = motor1VelocityLimit;
}

void MotorFaultsData::setMotor1BusCurrentLimit(const bool& motor1BusCurrentLimit)
{
    motor1BusCurrentLimit_ = motor1BusCurrentLimit;
}

void MotorFaultsData::setMotor1BusVoltageUpperLimit(const bool& motor1BusVoltageUpperLimit)
{
    motor1BusVoltageUpperLimit_ = motor1BusVoltageUpperLimit;
}

void MotorFaultsData::setMotor1BusVoltageLowerLimit(const bool& motor1BusVoltageLowerLimit)
{
    motor1BusVoltageLowerLimit_ = motor1BusVoltageLowerLimit;
}

void MotorFaultsData::setMotor1IpmOrMotorTemperatureLimit(const bool& motor1IpmOrMotorTemperatureLimit)
{
    motor1IpmOrMotorTemperatureLimit_ = motor1IpmOrMotorTemperatureLimit;
}

void MotorFaultsData::setMotor1RxErrorCount(const unsigned char& motor1RxErrorCount)
{
    motor1RxErrorCount_ = motor1RxErrorCount;
}

void MotorFaultsData::setMotor1TxErrorCount(const unsigned char& motor1TxErrorCount)
{
    motor1TxErrorCount_ = motor1TxErrorCount;
}
