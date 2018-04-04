#pragma once
#include <QObject>

class KeyMotorData : public QObject
{
    Q_OBJECT

public:
    KeyMotorData();
    virtual ~KeyMotorData();

    bool motor0Alive() const;
    float motor0SetCurrent() const;
    float motor0SetVelocity() const;
    float motor0BusCurrent() const;
    float motor0BusVoltage() const;
    float motor0VehicleVelocity() const;

    bool motor1Alive() const;
    float motor1SetCurrent() const;
    float motor1SetVelocity() const;
    float motor1BusCurrent() const;
    float motor1BusVoltage() const;
    float motor1VehicleVelocity() const;

    void setMotor0Alive(const bool& motor0Alive);
    void setMotor0SetCurrent(const float& motor0SetCurrent);
    void setMotor0SetVelocity(const float& motor0SetVelocity);
    void setMotor0BusCurrent(const float& motor0BusCurrent);
    void setMotor0BusVoltage(const float& motor0BusVoltage);
    void setMotor0VehicleVelocity(const float& motor0VehicleVelocity);

    void setMotor1Alive(const bool& motor1Alive);
    void setMotor1SetCurrent(const float& motor1SetCurrent);
    void setMotor1SetVelocity(const float& motor1SetVelocity);
    void setMotor1BusCurrent(const float& motor1BusCurrent);
    void setMotor1BusVoltage(const float& motor1BusVoltage);
    void setMotor1VehicleVelocity(const float& motor1VehicleVelocity);

private:
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
};
