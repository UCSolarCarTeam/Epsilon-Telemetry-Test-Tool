#pragma once

struct LightsData
{
    LightsData()
        : alive(true)
        , lowBeams(true)
        , highBeams(false)
        , brakes(true)
        , leftSignal(false)
        , rightSignal(true)
        , bmsStrobeLight(false)
    {}

    bool alive;
    bool lowBeams;
    bool highBeams;
    bool brakes;
    bool leftSignal;
    bool rightSignal;
    bool bmsStrobeLight;
};
