#pragma once

struct LightsData
{
    LightsData()
    : lowBeams_(true)
    , highBeams_(false)
    , brakes_(true)
    , leftSignal_(false)
    , rightSignal_(true)
    , bmsStrobeLight_(false)
    {}

    bool lowBeams_;
    bool highBeams_;
    bool brakes_;
    bool leftSignal_;
    bool rightSignal_;
    bool bmsStrobeLight_;
}
