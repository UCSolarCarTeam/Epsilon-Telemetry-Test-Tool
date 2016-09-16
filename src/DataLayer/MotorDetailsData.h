#pragma once

struct MotorDetailsData
{
    MotorDetailsData()
    : phaseCCurrent_(11.11f)
    , phaseBCurrent_(12.21f)
    , MotorVoltageReal_(13.31f)
    , MotorVoltageImaginary_(14.41f)
    , BackEmfReal_(15.51f)
    , BackEmfImaginary_(16.61f)
    , RailSupply15V_(17.71f)
    , RailSupply3V_(18.81f)
    , RailSupply1V_(19.91f)
    , heatSinkTemperature_(20.02f)
    , motorTemperature_(21.12f)
    , dspBoardTempearture_(22.22f)
    , dcBusAmpHours_(23.32f)
    , odometer_(24.42f)
    , slipSpeed_(25.52f)
    {}

    float phaseCCurrent_;
    float phaseBCurrent_;
    float MotorVoltageReal_;
    float MotorVoltageImaginary_;
    float BackEmfReal_;
    float BackEmfImaginary_;
    float RailSupply15V_;
    float RailSupply3V_;
    float RailSupply1V_;
    float heatSinkTemperature_;
    float motorTemperature_;
    float dspBoardTempearture_;
    float dcBusAmpHours_;
    float odometer_;
    float slipSpeed_;
}
