#pragma once

struct KeyMotorData
{
    KeyMotorData()
    : motor0Alive_(true)
    , motor0SetCurrent_(1.1f)
    , motor0SetVelocity_(2.2f)
    , motor0BusCurrent_(3.3f)
    , motor0BusVoltage_(4.4f)
    , motor0VehicleVelocity_(5.5f)
    , motor1Alive_(false)
    , motor1SetCurrent_(6.6f)
    , motor1SetVelocity_(7.7f)
    , motor1BusCurrent_(8.8f)
    , motor1BusVoltage_(9.9f)
    , motor1VehicleVelocity_(10.01f)
    {}

    bool motor0Alive_;
    float motor0SetCurrent_;
    float motor0SetVelocity_;
    float motor0BusCurrent_;
    float motor0BusVoltage_;
    float motor0VehicleVelocity_;

    bool motor1Alive_;
    float motor1SetCurrent_;
    float motor1SetVelocity_;
    float motor1BusCurrent_;
    float motor1BusVoltage_;
    float motor1VehicleVelocity_;
}
