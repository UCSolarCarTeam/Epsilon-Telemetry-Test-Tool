#pragma once
#include <QObject>

class MotorFaultsData : public QObject
{
    Q_OBJECT

public:
    MotorFaultsData();
    virtual ~MotorFaultsData();

    bool motor0OverSpeed() const;
    bool motor0SoftwareOverCurrent() const;
    bool motor0DcBusOverVoltage() const;
    bool motor0BadMotorPositionHallSequence() const;
    bool motor0WatchdogCausedLastReset() const;
    bool motor0ConfigReadError() const;
    bool motor0Rail15VUnderVoltageLockOut() const;
    bool motor0DesaturationFault() const;
    bool motor0OutputVoltagePwmLimit() const;
    bool motor0MotorCurrentLimit() const;
    bool motor0VelocityLimit() const;
    bool motor0BusCurrentLimit() const;
    bool motor0BusVoltageUpperLimit() const;
    bool motor0BusVoltageLowerLimit() const;
    bool motor0IpmOrMotorTemperatureLimit() const;
    unsigned char motor0RxErrorCount() const;
    unsigned char motor0TxErrorCount() const;

    bool motor1OverSpeed() const;
    bool motor1SoftwareOverCurrent() const;
    bool motor1DcBusOverVoltage() const;
    bool motor1BadMotorPositionHallSequence() const;
    bool motor1WatchdogCausedLastReset() const;
    bool motor1ConfigReadError() const;
    bool motor1Rail15VUnderVoltageLockOut() const;
    bool motor1DesaturationFault() const;
    bool motor1OutputVoltagePwmLimit() const;
    bool motor1MotorCurrentLimit() const;
    bool motor1VelocityLimit() const;
    bool motor1BusCurrentLimit() const;
    bool motor1BusVoltageUpperLimit() const;
    bool motor1BusVoltageLowerLimit() const;
    bool motor1IpmOrMotorTemperatureLimit() const;
    unsigned char motor1RxErrorCount() const;
    unsigned char motor1TxErrorCount() const;

    void setMotor0OverSpeed(const bool& motor0OverSpeed);
    void setMotor0SoftwareOverCurrent(const bool& motor0SoftwareOverCurrent);
    void setMotor0DcBusOverVoltage(const bool& motor0DcBusOverVoltage);
    void setMotor0BadMotorPositionHallSequence(const bool& motor0BadMotorPositionHallSequence);
    void setMotor0WatchdogCausedLastReset(const bool& motor0WatchdogCausedLastReset);
    void setMotor0ConfigReadError(const bool& motor0ConfigReadError);
    void setMotor0Rail15VUnderVoltageLockOut(const bool& motor0Rail15VUnderVoltageLockOut);
    void setMotor0DesaturationFault(const bool& motor0DesaturationFault);
    void setMotor0OutputVoltagePwmLimit(const bool& motor0OutputVoltagePwmLimit);
    void setMotor0MotorCurrentLimit(const bool& motor0MotorCurrentLimit);
    void setMotor0VelocityLimit(const bool& motor0VelocityLimit);
    void setMotor0BusCurrentLimit(const bool& motor0BusCurrentLimit);
    void setMotor0BusVoltageUpperLimit(const bool& motor0BusVoltageUpperLimit);
    void setMotor0BusVoltageLowerLimit(const bool& motor0BusVoltageLowerLimit);
    void setMotor0IpmOrMotorTemperatureLimit(const bool& motor0IpmOrMotorTemperatureLimit);
    void setMotor0RxErrorCount(const unsigned char& motor0RxErrorCount);
    void setMotor0TxErrorCount(const unsigned char& motor0TxErrorCount);

    void setMotor1OverSpeed(const bool& motor1OverSpeed);
    void setMotor1SoftwareOverCurrent(const bool& motor1SoftwareOverCurrent);
    void setMotor1DcBusOverVoltage(const bool& motor1DcBusOverVoltage);
    void setMotor1BadMotorPositionHallSequence(const bool& motor1BadMotorPositionHallSequence);
    void setMotor1WatchdogCausedLastReset(const bool& motor1WatchdogCausedLastReset);
    void setMotor1ConfigReadError(const bool& motor1ConfigReadError);
    void setMotor1Rail15VUnderVoltageLockOut(const bool& motor1Rail15VUnderVoltageLockOut);
    void setMotor1DesaturationFault(const bool& motor1DesaturationFault);
    void setMotor1OutputVoltagePwmLimit(const bool& motor1OutputVoltagePwmLimit);
    void setMotor1MotorCurrentLimit(const bool& motor1MotorCurrentLimit);
    void setMotor1VelocityLimit(const bool& motor1VelocityLimit);
    void setMotor1BusCurrentLimit(const bool& motor1BusCurrentLimit);
    void setMotor1BusVoltageUpperLimit(const bool& motor1BusVoltageUpperLimit);
    void setMotor1BusVoltageLowerLimit(const bool& motor1BusVoltageLowerLimit);
    void setMotor1IpmOrMotorTemperatureLimit(const bool& motor1IpmOrMotorTemperatureLimit);
    void setMotor1RxErrorCount(const unsigned char& motor1RxErrorCount);
    void setMotor1TxErrorCount(const unsigned char& motor1TxErrorCount);

private:
    bool motor0OverSpeed_;
    bool motor0SoftwareOverCurrent_;
    bool motor0DcBusOverVoltage_;
    bool motor0BadMotorPositionHallSequence_;
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
    unsigned char motor0RxErrorCount_;
    unsigned char motor0TxErrorCount_;

    bool motor1OverSpeed_;
    bool motor1SoftwareOverCurrent_;
    bool motor1DcBusOverVoltage_;
    bool motor1BadMotorPositionHallSequence_;
    bool motor1WatchdogCausedLastReset_;
    bool motor1ConfigReadError_;
    bool motor1Rail15VUnderVoltageLockOut_;
    bool motor1DesaturationFault_;
    bool motor1OutputVoltagePwmLimit_;
    bool motor1MotorCurrentLimit_;
    bool motor1VelocityLimit_;
    bool motor1BusCurrentLimit_;
    bool motor1BusVoltageUpperLimit_;
    bool motor1BusVoltageLowerLimit_;
    bool motor1IpmOrMotorTemperatureLimit_;
    unsigned char motor1RxErrorCount_;
    unsigned char motor1TxErrorCount_;
};
