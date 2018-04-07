#pragma once

struct AuxBmsData
{
    AuxBmsData()
        : prechargeState(PrechargeState::EnablePack)
        , prechargeStateJSON("Enable Pack")
        , auxVoltage(13)
        , auxBmsAlive(true)
        , strobeBmsLight(true)
        , allowCharge(true)
        , contactorError(true)
    {}

    enum PrechargeState
    {
        Idle = 0,
        Precharge = 1,
        Measure = 2,
        EnablePack = 3,
        Run = 4,
    };

    PrechargeState prechargeState;
    const char* prechargeStateJSON;
    unsigned char auxVoltage;
    bool auxBmsAlive;
    bool strobeBmsLight;
    bool allowCharge;
    bool contactorError;
};
