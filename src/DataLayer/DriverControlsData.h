#pragma once

struct DriverControlsData
{
    DriverControlsData()
    : alive_(true)
    , headlightsOff_(false)
    , headlightsLow_(true)
    , headlightsHigh_(false)
    , signalLeft_(true)
    , signalRight_(false)
    , hazardLights_(true)
    , interiorLights_(false)
    , musicAux_(true)
    , volumeUp_(false)
    , volumeDown_(true)
    , nextSong_(false)
    , prevSong_(true)
    , brakes_(false)
    , forward_(true)
    , reverse_(false)
    , pushToTalk_(true)
    , Horn_(false)
    , Reset_(true)
    , acceleration_(26)
    , regenBraking_(27)
    {}

    bool alive_;
    bool headlightsOff_;
    bool headlightsLow_;
    bool headlightsHigh_;
    bool signalLeft_;
    bool signalRight_;
    bool hazardLights_;
    bool interiorLights_;
    bool musicAux_;
    bool volumeUp_;
    bool volumeDown_;
    bool nextSong_;
    bool prevSong_;
    bool brakes_;
    bool forward_;
    bool reverse_;
    bool pushToTalk_;
    bool horn_;
    bool reset_;
    unsigned short acceleration_;
    unsigned short regenBraking_;
}
