#include "MpptData.h"

MpptData::MpptData()
    : mpptNumber_(0)
    , alive_{true}
    , arrayVoltage_{71}
    , arrayCurrent_{72}
    , batteryVoltage_{73}
    , temperature_{74}
{
}

MpptData::~MpptData()
{
}

bool MpptData::alive() const
{
    return alive_;
}

double MpptData::arrayVoltage() const
{
    return arrayVoltage_;
}

double MpptData::arrayCurrent() const
{
    return arrayCurrent_;
}

double MpptData::batteryVoltage() const
{
    return batteryVoltage_;
}

unsigned short MpptData::temperature() const
{
    return temperature_;
}

void MpptData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void MpptData::setArrayVoltage(const double& arrayVoltage)
{
    arrayVoltage_ = arrayVoltage;
}

void MpptData::setArrayCurrent(const double& arrayCurrent)
{
    arrayCurrent_ = arrayCurrent;
}

void MpptData::setBatteryVoltage(const double& batteryVoltage)
{
    batteryVoltage_ = batteryVoltage;
}

void MpptData::setTemperature(const unsigned short& temperature)
{
    temperature_ = temperature;
}
