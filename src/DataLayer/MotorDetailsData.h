#pragma once

struct MotorDetailsData
{
    MotorDetailsData()
        : phaseCCurrent(11.11f)
        , phaseBCurrent(12.21f)
        , MotorVoltageReal(13.31f)
        , MotorVoltageImaginary(14.41f)
        , MotorCurrentReal(13.13f)
        , MotorCurrentImaginary(14.14f)
        , BackEmf(15.51f)
        , BackEmfImaginary(16.61f)
        , RailSupply15V(17.71f)
        , RailSupply3V(18.81f)
        , RailSupply1V(19.91f)
        , heatSinkTemperature(20.02f)
        , motorTemperature(21.12f)
        , dspBoardTemperature(22.22f)
        , dcBusAmpHours(23.32f)
        , odometer(24.42f)
        , slipSpeed(25.52f)
    {}

    float phaseCCurrent;
    float phaseBCurrent;
    float MotorVoltageReal;
    float MotorVoltageImaginary;
    float MotorCurrentReal;
    float MotorCurrentImaginary;
    float BackEmf;
    float BackEmfImaginary;
    float RailSupply15V;
    float RailSupply3V;
    float RailSupply1V;
    float heatSinkTemperature;
    float motorTemperature;
    float dspBoardTemperature;
    float dcBusAmpHours;
    float odometer;
    float slipSpeed;
};
