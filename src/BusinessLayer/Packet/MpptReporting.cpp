#include "MpptReporting.h"
#include "MpptData.h"
#include "../UILayer/Packet/MpptTab.h"

MpptReporting::MpptReporting(MpptData& mpptData,
                             MpptTab& mpptTab)
    : mpptData_(mpptData)
    , mpptTab_(mpptTab)
{
}

void MpptReporting::setUiData()
{
    mpptData_.setAlive(mpptTab_.mpptAlive().isChecked());
    mpptData_.setMpptNumber(mpptTab_.mpptNumber().value());
    mpptData_.setArrayVoltage(mpptTab_.arrayVoltage().value());
    mpptData_.setArrayCurrent(mpptTab_.arrayCurrent().value());
    mpptData_.setBatteryVoltage(mpptTab_.batteryVoltage().value());
    mpptData_.setTemperature(mpptTab_.temperature().value());
}
