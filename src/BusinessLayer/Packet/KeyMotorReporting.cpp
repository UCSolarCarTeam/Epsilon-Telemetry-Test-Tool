#include "KeyMotorReporting.h"
#include "KeyMotorData.h"
#include "../UILayer/Packet/MotorTab.h"

KeyMotorReporting::KeyMotorReporting(MotorTab& motor0Tab,
                                     MotorTab& motor1Tab)
    : motor0Tab_(motor0Tab)
    , motor1Tab_(motor1Tab)
{
}

void KeyMotorReporting::setData(KeyMotorData& keyMotorData)
{
    KeyMotorData* keyMotorData_ = &keyMotorData;
    keyMotorData_->setMotor0Alive(motor0Tab_.alive().isChecked());
    keyMotorData_->setMotor0SetCurrent(motor0Tab_.setCurrent().value());
    keyMotorData_->setMotor0SetVelocity(motor0Tab_.setVelocity().value());
    keyMotorData_->setMotor0BusCurrent(motor0Tab_.busCurrent().value());
    keyMotorData_->setMotor0BusVoltage(motor0Tab_.busVoltage().value());
    keyMotorData_->setMotor0VehicleVelocity(motor0Tab_.vehicleVelocity().value());

    keyMotorData_->setMotor1Alive(motor1Tab_.alive().isChecked());
    keyMotorData_->setMotor1SetCurrent(motor1Tab_.setCurrent().value());
    keyMotorData_->setMotor1SetVelocity(motor1Tab_.setVelocity().value());
    keyMotorData_->setMotor1BusCurrent(motor1Tab_.busCurrent().value());
    keyMotorData_->setMotor1BusVoltage(motor1Tab_.busVoltage().value());
    keyMotorData_->setMotor1VehicleVelocity(motor1Tab_.vehicleVelocity().value());
}
