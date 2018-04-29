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

class TestApplication : public QApplication
{
    Q_OBJECT
public:
    TestApplication(int& argc, char** argv);
    virtual ~TestApplication();

private slots:
    void setPacket(int packetNumber);
    void sendInternetAll(int packetNumber);
    void switchSerialPacket();
    void sendSerialKeyMotor();
    void sendSerialMotorDetails(int motorNumber);
    void sendSerialDriverControls();
    void sendSerialMotorFaults();
    void sendSerialBatteryFaults();
    void sendSerialBattery();
    void sendSerialMppt();
    void sendSerialLights();
    void sendSerialAuxBms();
    void sendSerialAll();

private:
    QScopedPointer<KeyMotorData> keyMotorData0_;
    QScopedPointer<MotorDetailsData> motor0DetailsData0_;
    QScopedPointer<MotorDetailsData> motor1DetailsData0_;
    QScopedPointer<DriverControlsData> driverControlsData0_;
    QScopedPointer<MotorFaultsData> motorFaultsData0_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData0_;
    QScopedPointer<BatteryData> batteryData0_;
    QScopedPointer<MpptData> mpptData0_;
    QScopedPointer<LightsData> lightsData0_;
    QScopedPointer<AuxBmsData> auxBmsData0_;
    QScopedPointer<KeyMotorData> keyMotorData1_;
    QScopedPointer<MotorDetailsData> motor0DetailsData1_;
    QScopedPointer<MotorDetailsData> motor1DetailsData1_;
    QScopedPointer<DriverControlsData> driverControlsData1_;
    QScopedPointer<MotorFaultsData> motorFaultsData1_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData1_;
    QScopedPointer<BatteryData> batteryData1_;
    QScopedPointer<MpptData> mpptData1_;
    QScopedPointer<LightsData> lightsData1_;
    QScopedPointer<AuxBmsData> auxBmsData1_;
    QScopedPointer<InternetWindow> internetWindow_;
    QScopedPointer<SerialWindow> serialWindow_;
    QScopedPointer<AuxBmsTab> auxBmsTab_;
    QScopedPointer<BatteryTab> batteryTab_;
    QScopedPointer<BatteryFaultsTab> batteryFaultsTab_;
    QScopedPointer<DriverControlsTab> driverControlsTab_;
    QScopedPointer<LightsTab> lightsTab_;
    QScopedPointer<MotorTab> motor0Tab_;
    QScopedPointer<MotorTab> motor1Tab_;
    QScopedPointer<MotorFaultsTab> motor0FaultsTab_;
    QScopedPointer<MotorFaultsTab> motor1FaultsTab_;
    QScopedPointer<MpptTab> mpptTab_;
    QScopedPointer<PacketWindow> packetWindow_;
    QScopedPointer<InternetView> internetView_;
    QScopedPointer<SerialView> serialView_;
    QScopedPointer<Window> window_;
    QScopedPointer<CommunicationService> communicationService_;
    QScopedPointer<SerialReporting> serial0Reporting_;
    QScopedPointer<InternetReporting> internet0Reporting_;
    QScopedPointer<PacketReporting> packet0Reporting_;
    QScopedPointer<SerialReporting> serial1Reporting_;
    QScopedPointer<InternetReporting> internet1Reporting_;
    QScopedPointer<PacketReporting> packet1Reporting_;
    QSignalMapper packetMapper;
    QSignalMapper internetMapper;
    QSignalMapper serialMotorMapper;
    bool packet0_;
};
