#pragma once

#include <QApplication>
#include <QScopedPointer>
#include <QSignalMapper>
#include "AuxBmsData.h"
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "CommunicationService.h"
#include "DriverControlsData.h"
#include "InternetReporting.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "SerialReporting.h"
#include "InternetView.h"
#include "SerialView.h"
#include "PacketView.h"
#include "InternetWindow.h"
#include "SerialWindow.h"
#include "../UILayer/Packet/AuxBmsTab.h"
#include "../UILayer/Packet/BatteryTab.h"
#include "../UILayer/Packet/BatteryFaultsTab.h"
#include "../UILayer/Packet/DriverControlsTab.h"
#include "../UILayer/Packet/LightsTab.h"
#include "../UILayer/Packet/MotorTab.h"
#include "../UILayer/Packet/MotorFaultsTab.h"
#include "../UILayer/Packet/MpptTab.h"
#include "PacketWindow.h"
#include "Window.h"
#include "PacketReporting.h"
#include "DataContainer.h"

class TestApplication : public QApplication
{
    Q_OBJECT
public:
    TestApplication(int& argc, char** argv);
    virtual ~TestApplication();

private:
    QScopedPointer<DataContainer> data0Container_;
    QScopedPointer<DataContainer> data1Container_;
    QScopedPointer<InternetWindow> internetWindow_;
    QScopedPointer<SerialWindow> serialWindow_;
    QScopedPointer<PacketWindow> packetWindow_;
    QScopedPointer<InternetView> internetView_;
    QScopedPointer<SerialView> serialView_;
    QScopedPointer<PacketView> packetView_;
    QScopedPointer<Window> window_;
    QScopedPointer<CommunicationService> communicationService_;
    QScopedPointer<SerialReporting> serialReporting_;
    QScopedPointer<InternetReporting> internetReporting_;
    QScopedPointer<PacketReporting> packetReporting_;
};
