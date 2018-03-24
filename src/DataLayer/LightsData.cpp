#include "LightsData.h"

LightsData::LightsData()
{
}

LightsData::~LightsData()
{
}

bool LightsData::alive() const
{
    return alive_;
}

bool LightsData::lowBeams() const
{
    return lowBeams_;
}

bool LightsData::highBeams() const
{
    return highBeams_;
}

bool LightsData::brakes() const
{
    return brakes_;
}

bool LightsData::leftSignal() const
{
    return leftSignal_;
}

bool LightsData::rightSignal() const
{
    return rightSignal_;
}

bool LightsData::bmsStrobeLight() const
{
    return bmsStrobeLight_;
}

void LightsData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void LightsData::setLowBeams(const bool& lowBeams)
{
    lowBeams_ = lowBeams;
}

void LightsData::setHighBeams(const bool& highBeams)
{
    highBeams_ = highBeams;
}

void LightsData::setBrakes(const bool& brakes)
{
    brakes_ = brakes;
}

void LightsData::setLeftSignal(const bool& leftSignal)
{
    leftSignal_ = leftSignal;
}

void LightsData::setRightSignal(const bool& rightSignal)
{
    rightSignal_ = rightSignal;
}

void LightsData::setBmsStrobeLight(const bool& bmsStrobeLight)
{
    bmsStrobeLight_ = bmsStrobeLight;
}
