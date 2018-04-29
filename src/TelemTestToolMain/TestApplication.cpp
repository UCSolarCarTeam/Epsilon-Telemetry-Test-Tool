#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
    : QApplication(argc, argv)
    , keyMotorData0_(new KeyMotorData())
    , motor0DetailsData0_(new MotorDetailsData())
    , motor1DetailsData0_(new MotorDetailsData())
    , driverControlsData0_(new DriverControlsData())
    , motorFaultsData0_(new MotorFaultsData())
    , batteryFaultsData0_(new BatteryFaultsData())
    , batteryData0_(new BatteryData())
    , mpptData0_(new MpptData())
    , lightsData0_(new LightsData())
    , auxBmsData0_(new AuxBmsData())
    , keyMotorData1_(new KeyMotorData())
    , motor0DetailsData1_(new MotorDetailsData())
    , motor1DetailsData1_(new MotorDetailsData())
    , driverControlsData1_(new DriverControlsData())
    , motorFaultsData1_(new MotorFaultsData())
    , batteryFaultsData1_(new BatteryFaultsData())
    , batteryData1_(new BatteryData())
    , mpptData1_(new MpptData())
    , lightsData1_(new LightsData())
    , auxBmsData1_(new AuxBmsData())
    , internetWindow_(new InternetWindow())
    , serialWindow_(new SerialWindow())
    , auxBmsTab_(new AuxBmsTab())
    , batteryTab_(new BatteryTab())
    , batteryFaultsTab_(new BatteryFaultsTab())
    , driverControlsTab_(new DriverControlsTab())
    , lightsTab_(new LightsTab())
    , motor0Tab_(new MotorTab())
    , motor1Tab_(new MotorTab())
    , motor0FaultsTab_(new MotorFaultsTab())
    , motor1FaultsTab_(new MotorFaultsTab())
    , mpptTab_(new MpptTab())
    , packetWindow_(new PacketWindow(*auxBmsTab_,
                                     *batteryTab_,
                                     *batteryFaultsTab_,
                                     *driverControlsTab_,
                                     *lightsTab_,
                                     *motor0Tab_,
                                     *motor1Tab_,
                                     *motor0FaultsTab_,
                                     *motor1FaultsTab_,
                                     *mpptTab_))
    , internetView_(new InternetView(internetWindow_.data()))
    , serialView_(new SerialView(serialWindow_.data()))
    , window_(new Window(QList<QWidget*>{serialWindow_.data(),
                                         internetWindow_.data(),
                                         packetWindow_.data()}))
    , communicationService_(new CommunicationService(*serialView_, *internetView_))
    , serial0Reporting_(new SerialReporting(*communicationService_,
                                           *keyMotorData0_,
                                           *motor0DetailsData0_,
                                           *motor1DetailsData0_,
                                           *driverControlsData0_,
                                           *motorFaultsData0_,
                                           *batteryFaultsData0_,
                                           *batteryData0_,
                                           *mpptData0_,
                                           *lightsData0_,
                                           *auxBmsData0_,
                                           *serialView_))
    , internet0Reporting_(new InternetReporting(*communicationService_,
                                               *keyMotorData0_,
                                               *motor0DetailsData0_,
                                               *motor1DetailsData0_,
                                               *driverControlsData0_,
                                               *motorFaultsData0_,
                                               *batteryFaultsData0_,
                                               *batteryData0_,
                                               *mpptData0_,
                                               *lightsData0_,
                                               *auxBmsData0_,
                                               *internetView_))
    , packet0Reporting_(new PacketReporting(*keyMotorData0_,
                                           *motor0DetailsData0_,
                                           *motor1DetailsData0_,
                                           *driverControlsData0_,
                                           *motorFaultsData0_,
                                           *batteryFaultsData0_,
                                           *batteryData0_,
                                           *mpptData0_,
                                           *lightsData0_,
                                           *auxBmsData0_,
                                           *packetWindow_))
    , serial1Reporting_(new SerialReporting(*communicationService_,
                                           *keyMotorData1_,
                                           *motor0DetailsData1_,
                                           *motor1DetailsData1_,
                                           *driverControlsData1_,
                                           *motorFaultsData1_,
                                           *batteryFaultsData1_,
                                           *batteryData1_,
                                           *mpptData1_,
                                           *lightsData1_,
                                           *auxBmsData1_,
                                           *serialView_))
    , internet1Reporting_(new InternetReporting(*communicationService_,
                                               *keyMotorData1_,
                                               *motor0DetailsData1_,
                                               *motor1DetailsData1_,
                                               *driverControlsData1_,
                                               *motorFaultsData1_,
                                               *batteryFaultsData1_,
                                               *batteryData1_,
                                               *mpptData1_,
                                               *lightsData1_,
                                               *auxBmsData1_,
                                               *internetView_))
    , packet1Reporting_(new PacketReporting(*keyMotorData1_,
                                           *motor0DetailsData1_,
                                           *motor1DetailsData1_,
                                           *driverControlsData1_,
                                           *motorFaultsData1_,
                                           *batteryFaultsData1_,
                                           *batteryData1_,
                                           *mpptData1_,
                                           *lightsData1_,
                                           *auxBmsData1_,
                                           *packetWindow_))
{
    connect(&(packetWindow_->setPacket0()), SIGNAL(clicked()), this, SLOT(setPacket0()));
    connect(&(packetWindow_->setPacket1()), SIGNAL(clicked()), this, SLOT(setPacket1()));
    connect(&(internetWindow_->getSendPacket0Button()), SIGNAL(clicked()), this, SLOT(sendInternetPacket0()));
    connect(&(internetWindow_->getSendPacket1Button()), SIGNAL(clicked()), this, SLOT(sendInternetPacket1()));
}

TestApplication::~TestApplication()
{
}

void TestApplication::setPacket0()
{
        packet0Reporting_->setAll();
}

void TestApplication::setPacket1()
{
        packet1Reporting_->setAll();
}

void TestApplication::sendInternetPacket0()
{
        internet0Reporting_->sendAll();
}

void TestApplication::sendInternetPacket1()
{
        internet1Reporting_->sendAll();
}
