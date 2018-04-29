#pragma once

struct AuxBmsData
{
    AuxBmsData()
        : prechargeState(PrechargeState::DISCHARGE_ENGAGED)
        , prechargeStateJSON("Enable Pack")
        , auxVoltage(13)
        , auxBmsAlive(true)
        , strobeBmsLight(true)
        , allowCharge(true)
        , contactorError(true)
    {}

    enum PrechargeState
    {
        OFF = 0,
        COMMON_ENGAGED = 1,
        CHARGE_ENGAGED = 2,
        DISCHARGE_ENGAGED = 3,
        ALL_ENGAGED = 4,
        INVALID_STATE = 5,
    };

    PrechargeState prechargeState;
    const char* prechargeStateJSON;
    unsigned char auxVoltage;
    bool auxBmsAlive;
    bool strobeBmsLight;
    bool allowCharge;
    bool contactorError;
};
