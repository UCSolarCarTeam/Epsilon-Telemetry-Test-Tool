#include "MpptData.h"

MpptData::MpptData()
    : mpptNumber_(0)
    , alive_{true, true, true}
    , arrayVoltage_{71, 71, 71}
    , arrayCurrent_{72, 72, 72}
    , batteryVoltage_{73, 73, 73}
    , temperature_{74, 74, 74}
{
}

MpptData::~MpptData()
{
}

unsigned char MpptData::mpptNumber() const
{
    return mpptNumber_;
}

bool MpptData::alive(int mpptNumber) const
{
    return alive_[mpptNumber];
}

unsigned short MpptData::arrayVoltage(int mpptNumber) const
{
    return arrayVoltage_[mpptNumber];
}

unsigned short MpptData::arrayCurrent(int mpptNumber) const
{
    return arrayCurrent_[mpptNumber];
}

unsigned short MpptData::batteryVoltage(int mpptNumber) const
{
    return batteryVoltage_[mpptNumber];
}

unsigned short MpptData::temperature(int mpptNumber) const
{
    return temperature_[mpptNumber];
}

void MpptData::setMpptNumber(const unsigned char& mpptNumber)
{
    mpptNumber_ = mpptNumber;
}

void MpptData::setAlive(const bool& alive)
{
    alive_[mpptNumber_] = alive;
}

void MpptData::setArrayVoltage(const unsigned short& arrayVoltage)
{
    arrayVoltage_[mpptNumber_] = arrayVoltage;
}

void MpptData::setArrayCurrent(const unsigned short& arrayCurrent)
{
    arrayCurrent_[mpptNumber_] = arrayCurrent;
}

void MpptData::setBatteryVoltage(const unsigned short& batteryVoltage)
{
    batteryVoltage_[mpptNumber_] = batteryVoltage;
}

void MpptData::setTemperature(const unsigned short& temperature)
{
    temperature_[mpptNumber_] = temperature;
}
