#include "MpptData.h"

MpptData::MpptData()
{
}

MpptData::~MpptData()
{
}

unsigned char MpptData::mpptNumber() const
{
    return mpptNumber_;
}

bool MpptData::alive() const
{
    return alive_;
}

unsigned short MpptData::arrayVoltage() const
{
    return arrayVoltage_;
}

unsigned short MpptData::arrayCurrent() const
{
    return arrayCurrent_;
}

unsigned short MpptData::batteryVoltage() const
{
    return batteryVoltage_;
}

unsigned short MpptData::temperature() const
{
    return temperature_;
}

void MpptData::setMpptNumber(const unsigned char& mpptNumber)
{
    mpptNumber_ = mpptNumber;
}

void MpptData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void MpptData::setArrayVoltage(const unsigned short& arrayVoltage)
{
    arrayVoltage_ = arrayVoltage;
}

void MpptData::setArrayCurrent(const unsigned short& arrayCurrent)
{
    arrayCurrent_ = arrayCurrent;
}

void MpptData::setBatteryVoltage(const unsigned short& batteryVoltage)
{
    batteryVoltage_ = batteryVoltage;
}

void MpptData::setTemperature(const unsigned short& temperature)
{
    temperature_ = temperature;
}
