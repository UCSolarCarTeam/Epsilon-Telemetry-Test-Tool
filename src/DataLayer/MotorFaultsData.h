#pragma once

struct MotorFaultsData
{
    MotorFaultsData()
        : motor0OverSpeed(true)
        , motor0SoftwareOverCurrent(false)
        , motor0DcBusOverVoltage(true)
        , motor0BadMotorPositionHallSequence(true)
        , motor0WatchdogCausedLastReset(false)
        , motor0ConfigReadError(true)
        , motor0Rail15VUnderVoltageLockOut(false)
        , motor0DesaturationFault(true)
        , motor0OutputVoltagePwmLimit(false)
        , motor0MotorCurrentLimit(true)
        , motor0VelocityLimit(false)
        , motor0BusCurrentLimit(true)
        , motor0BusVoltageUpperLimit(false)
        , motor0BusVoltageLowerLimit(true)
        , motor0IpmOrMotorTemperatureLimit(false)
        , motor0RxErrorCount(28)
        , motor0TxErrorCount(29)
        , motor1OverSpeed(true)
        , motor1SoftwareOverCurrent(false)
        , motor1DcBusOverVoltage(true)
        , motor1BadMotorPositionHallSequence(false)
        , motor1WatchdogCausedLastReset(true)
        , motor1ConfigReadError(false)
        , motor1Rail15VUnderVoltageLockOut(true)
        , motor1DesaturationFault(false)
        , motor1OutputVoltagePwmLimit(true)
        , motor1MotorCurrentLimit(false)
        , motor1VelocityLimit(true)
        , motor1BusCurrentLimit(false)
        , motor1BusVoltageUpperLimit(true)
        , motor1BusVoltageLowerLimit(false)
        , motor1IpmOrMotorTemperatureLimit(true)
        , motor1RxErrorCount(30)
        , motor1TxErrorCount(31)
    {}

    bool motor0OverSpeed;
    bool motor0SoftwareOverCurrent;
    bool motor0DcBusOverVoltage;
    bool motor0BadMotorPositionHallSequence;
    bool motor0WatchdogCausedLastReset;
    bool motor0ConfigReadError;
    bool motor0Rail15VUnderVoltageLockOut;
    bool motor0DesaturationFault;
    bool motor0OutputVoltagePwmLimit;
    bool motor0MotorCurrentLimit;
    bool motor0VelocityLimit;
    bool motor0BusCurrentLimit;
    bool motor0BusVoltageUpperLimit;
    bool motor0BusVoltageLowerLimit;
    bool motor0IpmOrMotorTemperatureLimit;
    unsigned char motor0RxErrorCount;
    unsigned char motor0TxErrorCount;

    bool motor1OverSpeed;
    bool motor1SoftwareOverCurrent;
    bool motor1DcBusOverVoltage;
    bool motor1BadMotorPositionHallSequence;
    bool motor1WatchdogCausedLastReset;
    bool motor1ConfigReadError;
    bool motor1Rail15VUnderVoltageLockOut;
    bool motor1DesaturationFault;
    bool motor1OutputVoltagePwmLimit;
    bool motor1MotorCurrentLimit;
    bool motor1VelocityLimit;
    bool motor1BusCurrentLimit;
    bool motor1BusVoltageUpperLimit;
    bool motor1BusVoltageLowerLimit;
    bool motor1IpmOrMotorTemperatureLimit;
    unsigned char motor1RxErrorCount;
    unsigned char motor1TxErrorCount;
};
