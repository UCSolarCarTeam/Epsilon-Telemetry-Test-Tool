#include "MpptReporting.h"
#include "MpptData.h"
#include "../UILayer/Packet/MpptTab.h"

MpptReporting::MpptReporting(MpptData& mpptPacket0,
                             MpptData& mpptPacket1,
                             MpptTab& mpptTab)
    : mpptPacket0_(mpptPacket0)
    , mpptPacket1_(mpptPacket1)
    , mpptTab_(mpptTab)
{
}

void MpptReporting::setData(int packetNum)
{
    MpptData* mpptData_;
    if (packetNum == 0)
    {
        mpptData_ = &mpptPacket0_;
    }
    else
    {
      mpptData_ =&mpptPacket1_;
    }

    mpptData_->setAlive(mpptTab_.mpptAlive().isChecked());
    mpptData_->setMpptNumber(mpptTab_.mpptNumber().value());
    mpptData_->setArrayVoltage(mpptTab_.arrayVoltage().value());
    mpptData_->setArrayCurrent(mpptTab_.arrayCurrent().value());
    mpptData_->setBatteryVoltage(mpptTab_.batteryVoltage().value());
    mpptData_->setTemperature(mpptTab_.temperature().value());
}
