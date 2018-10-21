#include "LightsReporting.h"
#include "LightsData.h"
#include "../UILayer/Packet/LightsTab.h"

LightsReporting::LightsReporting(LightsData& lightsPacket0,
                                 LightsData& lightsPacket1,
                                 LightsTab& lightsTab)
    : lightsPacket0_(lightsPacket0)
    , lightsPacket1_(lightsPacket1)
    , lightsTab_(lightsTab)
{
}

void LightsReporting::setData(int packetNum)
{
    LightsData* lightsData_;
    if (packetNum == 0)
    {
        lightsData_ = &lightsPacket0_;
    }
    else
    {
        lightsData_ = &lightsPacket1_;
    }

    lightsData_->setAlive(lightsTab_.lightsAlive().isChecked());
    lightsData_->setLowBeams(lightsTab_.lowBeams().isChecked());
    lightsData_->setHighBeams(lightsTab_.highBeams().isChecked());
    lightsData_->setBrakes(lightsTab_.brakeLights().isChecked());
    lightsData_->setLeftSignal(lightsTab_.leftSignal().isChecked());
    lightsData_->setRightSignal(lightsTab_.rightSignal().isChecked());
    lightsData_->setBmsStrobeLight(lightsTab_.bmsStrobeLight().isChecked());
}
