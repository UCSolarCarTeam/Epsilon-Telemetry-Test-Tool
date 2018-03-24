#include "KeyMotorData.h"

KeyMotorData::KeyMotorData()
{
}

KeyMotorData::~KeyMotorData()
{
}

bool KeyMotorData::motor0Alive() const
{
    return motor0Alive_;
}

float KeyMotorData::motor0SetCurrent() const
{
    return motor0SetCurrent_;
}

float KeyMotorData::motor0SetVelocity() const
{
    return motor0SetVelocity_;
}

float KeyMotorData::motor0BusCurrent() const
{
    return motor0BusCurrent_;
}

float KeyMotorData::motor0BusVoltage() const
{
    return motor0BusVoltage_;
}

float KeyMotorData::motor0VehicleVelocity() const
{
    return motor0VehicleVelocity_;
}

bool KeyMotorData::motor1Alive() const
{
    return motor1Alive_;
}

float KeyMotorData::motor1SetCurrent() const
{
    return motor1SetCurrent_;
}

float KeyMotorData::motor1SetVelocity() const
{
    return motor1SetVelocity_;
}

float KeyMotorData::motor1BusCurrent() const
{
    return motor1BusCurrent_;
}

float KeyMotorData::motor1BusVoltage() const
{
    return motor1BusVoltage_;
}

float KeyMotorData::motor1VehicleVelocity() const
{
    return motor1VehicleVelocity_;
}

void KeyMotorData:: setMotor0Alive(const bool& motor0Alive)
{
    motor0Alive_ = motor0Alive;
}

void KeyMotorData:: setMotor0SetCurrent(const float& motor0SetCurrent)
{
    motor0SetCurrent_ = motor0SetCurrent;
}

void KeyMotorData:: setMotor0SetVelocity(const float& motor0SetVelocity)
{
    motor0SetVelocity_ = motor0SetVelocity;
}

void KeyMotorData:: setMotor0BusCurrent(const float& motor0BusCurrent)
{
    motor0BusCurrent_ = motor0BusCurrent;
}

void KeyMotorData:: setMotor0BusVoltage(const float& motor0BusVoltage)
{
    motor0BusVoltage_ = motor0BusVoltage;
}

void KeyMotorData:: setMotor0VehicleVelocity(const float& motor0VehicleVelocity)
{
    motor0VehicleVelocity_ = motor0VehicleVelocity;
}


void KeyMotorData:: setMotor1Alive(const bool& motor1Alive)
{
    motor1Alive_ = motor1Alive;
}

void KeyMotorData:: setMotor1SetCurrent(const float& motor1SetCurrent)
{
    motor1SetCurrent_ = motor1SetCurrent;
}

void KeyMotorData:: setMotor1SetVelocity(const float& motor1SetVelocity)
{
    motor1SetVelocity_ = motor1SetVelocity;
}

void KeyMotorData:: setMotor1BusCurrent(const float& motor1BusCurrent)
{
    motor1BusCurrent_ = motor1BusCurrent;
}

void KeyMotorData:: setMotor1BusVoltage(const float& motor1BusVoltage)
{
    motor1BusVoltage_ = motor1BusVoltage;
}

void KeyMotorData:: setMotor1VehicleVelocity(const float& motor1VehicleVelocity)
{
    motor1VehicleVelocity_ = motor1VehicleVelocity;
}
