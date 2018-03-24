#include "MotorDetailsData.h"

MotorDetailsData::MotorDetailsData()
{
}

MotorDetailsData::~MotorDetailsData()
{
}

float MotorDetailsData::phaseCCurrent() const
{
    return phaseCCurrent_;
}

float MotorDetailsData::phaseBCurrent() const
{
    return phaseBCurrent_;
}

float MotorDetailsData::MotorVoltageReal() const
{
    return MotorVoltageReal_;
}

float MotorDetailsData::MotorVoltageImaginary() const
{
    return MotorVoltageImaginary_;
}

float MotorDetailsData::MotorCurrentReal() const
{
    return MotorCurrentReal_;
}

float MotorDetailsData::MotorCurrentImaginary() const
{
    return MotorCurrentImaginary_;
}

float MotorDetailsData::BackEmf() const
{
    return BackEmf_;
}

float MotorDetailsData::RailSupply15V() const
{
    return RailSupply15V_;
}

float MotorDetailsData::RailSupply3V() const
{
    return RailSupply3V_;
}

float MotorDetailsData::RailSupply1V() const
{
    return RailSupply1V_;
}

float MotorDetailsData::heatSinkTemperature() const
{
    return heatSinkTemperature_;
}

float MotorDetailsData::motorTemperature() const
{
    return motorTemperature_;
}

float MotorDetailsData::dspBoardTemperature() const
{
    return dspBoardTemperature_;
}

float MotorDetailsData::dcBusAmpHours() const
{
    return dcBusAmpHours_;
}

float MotorDetailsData::odometer() const
{
    return odometer_;
}

float MotorDetailsData::slipSpeed() const
{
    return slipSpeed_;
}

void MotorDetailsData::setPhaseCCurrent(const float& phaseCCurrent)
{
    phaseCCurrent_ = phaseCCurrent;
}

void MotorDetailsData::setPhaseBCurrent(const float& phaseBCurrent)
{
    phaseBCurrent_ = phaseBCurrent;
}

void MotorDetailsData::setMotorVoltageReal(const float& MotorVoltageReal)
{
    MotorVoltageReal_ = MotorVoltageReal;
}

void MotorDetailsData::setMotorVoltageImaginary(const float& MotorVoltageImaginary)
{
    MotorVoltageImaginary_ = MotorVoltageImaginary;
}

void MotorDetailsData::setMotorCurrentReal(const float& MotorCurrentReal)
{
    MotorCurrentReal_ = MotorCurrentReal;
}

void MotorDetailsData::setMotorCurrentImaginary(const float& MotorCurrentImaginary)
{
    MotorCurrentImaginary_ = MotorCurrentImaginary;
}

void MotorDetailsData::setBackEmf(const float& BackEmf)
{
    BackEmf_ = BackEmf;
}

void MotorDetailsData::setRailSupply15V(const float& RailSupply15V)
{
    RailSupply15V_ = RailSupply15V;
}

void MotorDetailsData::setRailSupply3V(const float& RailSupply3V)
{
    RailSupply3V_ = RailSupply3V;
}

void MotorDetailsData::setRailSupply1V(const float& RailSupply1V)
{
    RailSupply1V_ = RailSupply1V;
}

void MotorDetailsData::setHeatSinkTemperature(const float& heatSinkTemperature)
{
    heatSinkTemperature_ = heatSinkTemperature;
}

void MotorDetailsData::setMotorTemperature(const float& motorTemperature)
{
    motorTemperature_ = motorTemperature;
}

void MotorDetailsData::setDspBoardTemperature(const float& dspBoardTemperature)
{
    dspBoardTemperature_ = dspBoardTemperature;
}

void MotorDetailsData::setDcBusAmpHours(const float& dcBusAmpHours)
{
    dcBusAmpHours_ = dcBusAmpHours;
}

void MotorDetailsData::setOdometer(const float& odometer)
{
    odometer_ = odometer;
}

void MotorDetailsData::setSlipSpeed(const float& slipSpeed)
{
    slipSpeed_ = slipSpeed;
}
