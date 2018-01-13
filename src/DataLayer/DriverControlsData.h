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
        , aux(true)
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
    bool aux;
    unsigned short acceleration;
    unsigned short regenBraking;
};
