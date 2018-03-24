#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "DriverControlsData.h"
#include "InternetView.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "PacketReporting.h"
#include "../UILayer/PacketWindow.h"
#include "../BusinessLayer/Packet/MpptReporting.h"

PacketReporting::PacketReporting(PacketWindow& window)
    : window_(window)
{
}

void PacketReporting::setMppt(MpptData& mpptData)
{
    MpptReporting mpptReporting(mpptData, window_.mpptTab());
    mpptReporting.setMpptData();
}
