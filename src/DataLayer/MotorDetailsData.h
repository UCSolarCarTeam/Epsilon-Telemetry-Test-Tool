//#pragma once

//struct MotorDetailsData
//{
//    MotorDetailsData()
//        : phaseCCurrent(11.11f)
//        , phaseBCurrent(12.21f)
//        , MotorVoltageReal(13.31f)
//        , MotorVoltageImaginary(14.41f)
//        , MotorCurrentReal(13.13f)
//        , MotorCurrentImaginary(14.14f)
//        , BackEmf(15.51f)
//        , RailSupply15V(17.71f)
//        , RailSupply3V(18.81f)
//        , RailSupply1V(19.91f)
//        , heatSinkTemperature(20.02f)
//        , motorTemperature(21.12f)
//        , dspBoardTemperature(22.22f)
//        , dcBusAmpHours(23.32f)
//        , odometer(24.42f)
//        , slipSpeed(25.52f)
//    {}

//    float phaseCCurrent;
//    float phaseBCurrent;
//    float MotorVoltageReal;
//    float MotorVoltageImaginary;
//    float MotorCurrentReal;
//    float MotorCurrentImaginary;
//    float BackEmf;
//    float RailSupply15V;
//    float RailSupply3V;
//    float RailSupply1V;
//    float heatSinkTemperature;
//    float motorTemperature;
//    float dspBoardTemperature;
//    float dcBusAmpHours;
//    float odometer;
//    float slipSpeed;
//};

#pragma once
#include <QObject>

class MotorDetailsData : public QObject
{
    Q_OBJECT

public:
    MotorDetailsData();
    virtual ~MotorDetailsData();

    float phaseCCurrent() const;
    float phaseBCurrent() const;
    float MotorVoltageReal() const;
    float MotorVoltageImaginary() const;
    float MotorCurrentReal() const;
    float MotorCurrentImaginary() const;
    float BackEmf() const;
    float RailSupply15V() const;
    float RailSupply3V() const;
    float RailSupply1V() const;
    float heatSinkTemperature() const;
    float motorTemperature() const;
    float dspBoardTemperature() const;
    float dcBusAmpHours() const;
    float odometer() const;
    float slipSpeed() const;

    void setPhaseCCurrent(const float& phaseCCurrent);
    void setPhaseBCurrent(const float& phaseBCurrent);
    void setMotorVoltageReal(const float& MotorVoltageReal);
    void setMotorVoltageImaginary(const float& MotorVoltageImaginary);
    void setMotorCurrentReal(const float& MotorCurrentReal);
    void setMotorCurrentImaginary(const float& MotorCurrentImaginary);
    void setBackEmf(const float& BackEmf);
    void setRailSupply15V(const float& RailSupply15V);
    void setRailSupply3V(const float& RailSupply3V);
    void setRailSupply1V(const float& RailSupply1V);
    void setHeatSinkTemperature(const float& heatSinkTemperature);
    void setMotorTemperature(const float& motorTemperature);
    void setDspBoardTemperature(const float& dspBoardTemperature);
    void setDcBusAmpHours(const float& dcBusAmpHours);
    void setOdometer(const float& odometer);
    void setSlipSpeed(const float& slipSpeed);

private:
    float phaseCCurrent_;
    float phaseBCurrent_;
    float MotorVoltageReal_;
    float MotorVoltageImaginary_;
    float MotorCurrentReal_;
    float MotorCurrentImaginary_;
    float BackEmf_;
    float RailSupply15V_;
    float RailSupply3V_;
    float RailSupply1V_;
    float heatSinkTemperature_;
    float motorTemperature_;
    float dspBoardTemperature_;
    float dcBusAmpHours_;
    float odometer_;
    float slipSpeed_;
};
