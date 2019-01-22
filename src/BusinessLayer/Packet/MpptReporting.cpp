#include "MpptReporting.h"
#include "MpptData.h"
#include "../UILayer/Packet/MpptTab.h"

MpptReporting::MpptReporting(MpptTab& mpptTab)
    : mpptTab_(mpptTab)
{
}

void MpptReporting::setData(MpptData& mpptData)
{
    MpptData* mpptData_ = &mpptData;
    mpptData_->setAlive(mpptTab_.mpptAlive().isChecked());
    mpptData_->setMpptNumber(mpptTab_.mpptNumber().value());
    mpptData_->setArrayVoltage(mpptTab_.arrayVoltage().value());
    mpptData_->setArrayCurrent(mpptTab_.arrayCurrent().value());
    mpptData_->setBatteryVoltage(mpptTab_.batteryVoltage().value());
    mpptData_->setTemperature(mpptTab_.temperature().value());
}
