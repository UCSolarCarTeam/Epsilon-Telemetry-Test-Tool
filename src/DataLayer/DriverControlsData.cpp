#include "DriverControlsData.h"

DriverControlsData::DriverControlsData()
{
}

DriverControlsData::~DriverControlsData()
{
}

bool DriverControlsData::alive() const
{
    return alive_;
}

bool DriverControlsData::headlightsOff() const
{
    return headlightsOff_;
}

bool DriverControlsData::headlightsLow() const
{
    return headlightsLow_;
}

bool DriverControlsData::headlightsHigh() const
{
    return headlightsHigh_;
}

bool DriverControlsData::signalLeft() const
{
    return signalLeft_;
}

bool DriverControlsData::signalRight() const
{
    return signalRight_;
}

bool DriverControlsData::hazardLights() const
{
    return hazardLights_;
}

bool DriverControlsData::interiorLights() const
{
    return interiorLights_;
}

bool DriverControlsData::volumeUp() const
{
    return volumeUp_;
}

bool DriverControlsData::volumeDown() const
{
    return volumeDown_;
}

bool DriverControlsData::nextSong() const
{
    return nextSong_;
}

bool DriverControlsData::prevSong() const
{
    return prevSong_;
}

bool DriverControlsData::brakes() const
{
    return brakes_;
}

bool DriverControlsData::forward() const
{
    return forward_;
}

bool DriverControlsData::reverse() const
{
    return reverse_;
}

bool DriverControlsData::pushToTalk() const
{
    return pushToTalk_;
}

bool DriverControlsData::horn() const
{
    return horn_;
}

bool DriverControlsData::reset() const
{
    return reset_;
}

bool DriverControlsData::aux() const
{
    return aux_;
}

unsigned short DriverControlsData::acceleration() const
{
    return acceleration_;
}

unsigned short DriverControlsData::regenBraking() const
{
    return regenBraking_;
}

void DriverControlsData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void DriverControlsData::setHeadlightsOff(const bool& headlightsOff)
{
    headlightsOff_ = headlightsOff;
}

void DriverControlsData::setHeadlightsLow(const bool& headlightsLow)
{
    headlightsLow_ = headlightsLow;
}

void DriverControlsData::setHeadlightsHigh(const bool& headlightsHigh)
{
    headlightsHigh_ = headlightsHigh;
}

void DriverControlsData::setSignalLeft(const bool& signalLeft)
{
    signalLeft_ = signalLeft;
}

void DriverControlsData::setSignalRight(const bool& signalRight)
{
    signalRight_ = signalRight;
}

void DriverControlsData::setHazardLights(const bool& hazardLights)
{
    hazardLights_ = hazardLights;
}

void DriverControlsData::setInteriorLights(const bool& interiorLights)
{
    interiorLights_ = interiorLights;
}

void DriverControlsData::setVolumeUp(const bool& volumeUp)
{
    volumeUp_ = volumeUp;
}

void DriverControlsData::setVolumeDown(const bool& volumeDown)
{
    volumeDown_ = volumeDown;
}

void DriverControlsData::setNextSong(const bool& nextSong)
{
    nextSong_ = nextSong;
}

void DriverControlsData::setPrevSong(const bool& prevSong)
{
    prevSong_ = prevSong;
}

void DriverControlsData::setBrakes(const bool& brakes)
{
    brakes_ = brakes;
}

void DriverControlsData::setForward(const bool& forward)
{
    forward_ = forward;
}

void DriverControlsData::setReverse(const bool& reverse)
{
    reverse_ = reverse;
}

void DriverControlsData::setPushToTalk(const bool& pushToTalk)
{
    pushToTalk_ = pushToTalk;
}

void DriverControlsData::setHorn(const bool& horn)
{
    horn_ = horn;
}

void DriverControlsData::setReset(const bool& reset)
{
    reset_ = reset;
}

void DriverControlsData::setAux(const bool& aux)
{
    aux_ = aux;
}

void DriverControlsData::setAcceleration(const unsigned short& acceleration)
{
    acceleration_ = acceleration;
}

void DriverControlsData::setRegenBraking(const unsigned short& regenBraking)
{
    regenBraking_ = regenBraking;
}
