#include "MotorDetailsReporting.h"
#include "MotorDetailsData.h"
#include "../UILayer/Packet/MotorTab.h"

MotorDetailsReporting::MotorDetailsReporting(MotorDetailsData& motorDetailsPacket0,
                                             MotorDetailsData& motorDetailsPacket1,
                                             MotorTab& motorTab)
    : motorDetailsPacket0_(motorDetailsPacket0)
    , motorDetailsPacket1_(motorDetailsPacket1)
    , motorTab_(motorTab)
{
}

void MotorDetailsReporting::setData(int packetNum)
{
    MotorDetailsData* motorDetailsData_;
    if (packetNum == 0)
    {
        motorDetailsData_ = &motorDetailsPacket0_;
    }
    else
    {
        motorDetailsData_ = &motorDetailsPacket1_;
    }

    motorDetailsData_->setPhaseCCurrent(motorTab_.phaseCCurrent().value());
    motorDetailsData_->setPhaseBCurrent(motorTab_.phaseBCurrent().value());
    motorDetailsData_->setMotorVoltageReal(motorTab_.motorVoltageReal().value());
    motorDetailsData_->setMotorVoltageImaginary(motorTab_.motorVoltageImaginary().value());
    motorDetailsData_->setMotorCurrentReal(motorTab_.motorCurrentReal().value());
    motorDetailsData_->setMotorCurrentImaginary(motorTab_.motorCurrentImaginary().value());
    motorDetailsData_->setBackEmf(motorTab_.backEMF().value());
    motorDetailsData_->setRailSupply15V(motorTab_.voltageRailSupply15V().value());
    motorDetailsData_->setRailSupply3V(motorTab_.voltageRailSupply3V().value());
    motorDetailsData_->setRailSupply1V(motorTab_.voltageRailSupply1V().value());
    motorDetailsData_->setHeatSinkTemperature(motorTab_.heatSinkTemp().value());
    motorDetailsData_->setMotorTemperature(motorTab_.motorTemp().value());
    motorDetailsData_->setDspBoardTemperature(motorTab_.dspBoardTemp().value());
    motorDetailsData_->setDcBusAmpHours(motorTab_.dcBusAmphours().value());
    motorDetailsData_->setOdometer(motorTab_.odometer().value());
    motorDetailsData_->setSlipSpeed(motorTab_.slipSpeed().value());
}
