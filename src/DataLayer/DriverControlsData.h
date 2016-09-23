#pragma once

struct DriverControlsData
{
    DriverControlsData()
    : alive(true)
    , headlightsOff(false)
    , headlightsLow(true)
    , headlightsHigh(false)
    , signalLeft(true)
    , signalRight(false)
    , hazardLights(true)
    , interiorLights(false)
    , musicAux(true)
    , volumeUp(false)
    , volumeDown(true)
    , nextSong(false)
    , prevSong(true)
    , brakes(false)
    , forward(true)
    , reverse(false)
    , pushToTalk(true)
    , horn(false)
    , reset(true)
    , acceleration(26)
    , regenBraking(27)
    {}

    bool alive;
    bool headlightsOff;
    bool headlightsLow;
    bool headlightsHigh;
    bool signalLeft;
    bool signalRight;
    bool hazardLights;
    bool interiorLights;
    bool musicAux;
    bool volumeUp;
    bool volumeDown;
    bool nextSong;
    bool prevSong;
    bool brakes;
    bool forward;
    bool reverse;
    bool pushToTalk;
    bool horn;
    bool reset;
    unsigned short acceleration;
    unsigned short regenBraking;
};
