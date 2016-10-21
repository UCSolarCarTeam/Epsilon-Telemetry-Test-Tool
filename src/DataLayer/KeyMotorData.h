#pragma once

struct KeyMotorData
{
    KeyMotorData()
        : motor0Alive(true)
        , motor0SetCurrent(1.1f)
        , motor0SetVelocity(2.2f)
        , motor0BusCurrent(3.3f)
        , motor0BusVoltage(4.4f)
        , motor0VehicleVelocity(5.5f)
        , motor1Alive(false)
        , motor1SetCurrent(6.6f)
        , motor1SetVelocity(7.7f)
        , motor1BusCurrent(8.8f)
        , motor1BusVoltage(9.9f)
        , motor1VehicleVelocity(10.01f)
    {}

    bool motor0Alive;
    float motor0SetCurrent;
    float motor0SetVelocity;
    float motor0BusCurrent;
    float motor0BusVoltage;
    float motor0VehicleVelocity;

    bool motor1Alive;
    float motor1SetCurrent;
    float motor1SetVelocity;
    float motor1BusCurrent;
    float motor1BusVoltage;
    float motor1VehicleVelocity;
};
