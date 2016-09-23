#pragma once

struct LightsData
{
    LightsData()
    : lowBeams(true)
    , highBeams(false)
    , brakes(true)
    , leftSignal(false)
    , rightSignal(true)
    , bmsStrobeLight(false)
    {}

    bool lowBeams;
    bool highBeams;
    bool brakes;
    bool leftSignal;
    bool rightSignal;
    bool bmsStrobeLight;
};
