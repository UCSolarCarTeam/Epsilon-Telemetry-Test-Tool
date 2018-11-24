#include "LightsReporting.h"
#include "LightsData.h"
#include "../UILayer/Packet/LightsTab.h"

LightsReporting::LightsReporting(LightsTab& lightsTab)
    : lightsTab_(lightsTab)
{
}

void LightsReporting::setData(LightsData& lightsData)
{
    LightsData* lightsData_ = &lightsData;
    lightsData_->setAlive(lightsTab_.lightsAlive().isChecked());
    lightsData_->setLowBeams(lightsTab_.lowBeams().isChecked());
    lightsData_->setHighBeams(lightsTab_.highBeams().isChecked());
    lightsData_->setBrakes(lightsTab_.brakeLights().isChecked());
    lightsData_->setLeftSignal(lightsTab_.leftSignal().isChecked());
    lightsData_->setRightSignal(lightsTab_.rightSignal().isChecked());
    lightsData_->setBmsStrobeLight(lightsTab_.bmsStrobeLight().isChecked());
}
