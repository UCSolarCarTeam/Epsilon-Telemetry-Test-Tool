#pragma once

struct MotorFaultsData
{
    MotorFaultsData()
    : motor0OverSpeed_(true)
    , motor0SoftwareOverCurrent_(false)
    , motor0DcBusOverVoltage_(true)
    , motor0BadMootorPositionHallSequence_(true)
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
    , motor0OverSpeed_(true)
    , motor0SoftwareOverCurrent_(false)
    , motor0DcBusOverVoltage_(true)
    , motor0BadMootorPositionHallSequence_(false)
    , motor0WatchdogCausedLastReset_(true)
    , motor0ConfigReadError_(false)
    , motor0Rail15VUnderVoltageLockOut_(true)
    , motor0DesaturationFault_(false)
    , motor0OutputVoltagePwmLimit_(true)
    , motor0MotorCurrentLimit_(false)
    , motor0VelocityLimit_(true)
    , motor0BusCurrentLimit_(false)
    , motor0BusVoltageUpperLimit_(true)
    , motor0BusVoltageLowerLimit_(false)
    , motor0IpmOrMotorTemperatureLimit_(true)
    , motor0RxErrorCount_(30)
    , motor0TxErrorCount_(31)
    {}

    bool motor0OverSpeed_;
    bool motor0SoftwareOverCurrent_;
    bool motor0DcBusOverVoltage_;
    bool motor0BadMootorPositionHallSequence_;
    bool motor0WatchdogCausedLastReset_;
    bool motor0ConfigReadError_;
    bool motor0Rail15VUnderVoltageLockOut_;
    bool motor0DesaturationFault_;
    bool motor0OutputVoltagePwmLimit_;
    bool motor0MotorCurrentLimit_;
    bool motor0VelocityLimit_;
    bool motor0BusCurrentLimit_;
    bool motor0BusVoltageUpperLimit_;
    bool motor0BusVoltageLowerLimit_;
    bool motor0IpmOrMotorTemperatureLimit_;
    char motor0RxErrorCount_;
    char motor0TxErrorCount_;

    bool motor0OverSpeed_;
    bool motor0SoftwareOverCurrent_;
    bool motor0DcBusOverVoltage_;
    bool motor0BadMootorPositionHallSequence_;
    bool motor0WatchdogCausedLastReset_;
    bool motor0ConfigReadError_;
    bool motor0Rail15VUnderVoltageLockOut_;
    bool motor0DesaturationFault_;
    bool motor0OutputVoltagePwmLimit_;
    bool motor0MotorCurrentLimit_;
    bool motor0VelocityLimit_;
    bool motor0BusCurrentLimit_;
    bool motor0BusVoltageUpperLimit_;
    bool motor0BusVoltageLowerLimit_;
    bool motor0IpmOrMotorTemperatureLimit_;
    char motor0RxErrorCount_;
    char motor0TxErrorCount_;
}
