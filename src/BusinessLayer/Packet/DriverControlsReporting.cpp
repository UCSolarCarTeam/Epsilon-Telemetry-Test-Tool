#include "DriverControlsReporting.h"
#include "DriverControlsData.h"
#include "../UILayer/Packet/DriverControlsTab.h"

DriverControlsReporting::DriverControlsReporting(DriverControlsTab& driverControlsTab)
    : driverControlsTab_(driverControlsTab)
{
}

void DriverControlsReporting::setData(DriverControlsData& driverControlsData)
{
    DriverControlsData* driverControlsData_ = &driverControlsData;
    driverControlsData_->setAlive(driverControlsTab_.driverControlsAlive().isChecked());
    driverControlsData_->setHeadlightsOff(driverControlsTab_.headlightsOff().isChecked());
    driverControlsData_->setHeadlightsLow(driverControlsTab_.headlightsLow().isChecked());
    driverControlsData_->setHeadlightsHigh(driverControlsTab_.headlightsHigh().isChecked());
    driverControlsData_->setSignalLeft(driverControlsTab_.signalLeft().isChecked());
    driverControlsData_->setSignalRight(driverControlsTab_.signalRight().isChecked());
    driverControlsData_->setHazardLights(driverControlsTab_.hazard().isChecked());
    driverControlsData_->setInteriorLights(driverControlsTab_.interior().isChecked());
    driverControlsData_->setVolumeUp(driverControlsTab_.volumeUp().isChecked());
    driverControlsData_->setVolumeDown(driverControlsTab_.volumeDown().isChecked());
    driverControlsData_->setNextSong(driverControlsTab_.nextSong().isChecked());
    driverControlsData_->setPrevSong(driverControlsTab_.previousSong().isChecked());
    driverControlsData_->setBrakes(driverControlsTab_.brakes().isChecked());
    driverControlsData_->setForward(driverControlsTab_.forward().isChecked());
    driverControlsData_->setReverse(driverControlsTab_.reverse().isChecked());
    driverControlsData_->setPushToTalk(driverControlsTab_.pushToTalk().isChecked());
    driverControlsData_->setHorn(driverControlsTab_.horn().isChecked());
    driverControlsData_->setReset(driverControlsTab_.reset().isChecked());
    driverControlsData_->setAux(driverControlsTab_.aux().isChecked());
    driverControlsData_->setLap(driverControlsTab_.lap().isChecked());
    driverControlsData_->setAcceleration(driverControlsTab_.acceleration().value());
    driverControlsData_->setRegenBraking(driverControlsTab_.regenBraking().value());
}
