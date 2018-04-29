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
    , packetMapper(this)
    , internetMapper(this)
    , serialMotorMapper(this)
    , packet0_(true)
{

    connect(&(packetWindow_->setPacket0()), SIGNAL(clicked()),
                     &packetMapper, SLOT(map()));
    connect(&(packetWindow_->setPacket1()), SIGNAL(clicked()),
                     &packetMapper, SLOT(map()));
    packetMapper.setMapping((&packetWindow_->setPacket0()), 0);
    packetMapper.setMapping((&packetWindow_->setPacket1()), 1);
    connect(&packetMapper, SIGNAL(mapped(int)),
                     this, SLOT(setPacket(int)));

    connect(&(internetWindow_->getSendPacket0Button()), SIGNAL(clicked()),
                     &internetMapper, SLOT(map()));
    connect(&(internetWindow_->getSendPacket1Button()), SIGNAL(clicked()),
                     &internetMapper, SLOT(map()));
    internetMapper.setMapping((&internetWindow_->getSendPacket0Button()), 0);
    internetMapper.setMapping((&internetWindow_->getSendPacket1Button()), 1);
    connect(&internetMapper, SIGNAL(mapped(int)),
                     this, SLOT(sendInternetAll(int)));


    connect(&(serialWindow_->getSwitchPacketButton()), SIGNAL(clicked()),
                     this, SLOT(switchSerialPacket()));
    connect(&(serialWindow_->getSwitchPacketButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialKeyMotor()));
    connect(&(serialWindow_->getSendMotor0DetailsButton()), SIGNAL(clicked()),
                     &serialMotorMapper, SLOT(map()));
    connect(&(serialWindow_->getSendMotor1DetailsButton()), SIGNAL(clicked()),
                     &serialMotorMapper, SLOT(map()));
    serialMotorMapper.setMapping(&(serialWindow_->getSendMotor0DetailsButton()), 0);
    serialMotorMapper.setMapping(&(serialWindow_->getSendMotor1DetailsButton()), 1);
    connect(&serialMotorMapper, SIGNAL(mapped(int)),
                     this, SLOT(sendSerialMotorDetails(int)));
    connect(&(serialWindow_->getSendDriverControlsButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialDriverControls()));
    connect(&(serialWindow_->getSendMotorFaultsButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialMotorFaults()));
    connect(&(serialWindow_->getSendBatteryFaultsButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialBatteryFaults()));
    connect(&(serialWindow_->getSendBatteryButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialBattery()));
    connect(&(serialWindow_->getSendMpptButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialMppt()));
    connect(&(serialWindow_->getSendLightsButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialLights()));
    connect(&(serialWindow_->getSendAuxBmsButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialAuxBms()));
    connect(&(serialWindow_->getSendAllButton()), SIGNAL(clicked()),
                     this, SLOT(sendSerialAll()));
}

TestApplication::~TestApplication()
{
}

void TestApplication::setPacket(int packetNumber)
{
    if (packetNumber == 0)
    {
            packet0Reporting_->setAll();
    }
    else
    {
            packet1Reporting_->setAll();
    }
}

void TestApplication::sendInternetAll(int packetNumber)
{
    if (packetNumber == 0)
    {
        internet0Reporting_->sendAll();
    }
    else
    {
        internet1Reporting_->sendAll();
    }
}

void TestApplication::switchSerialPacket()
{
    if (packet0_ == true)
    {
        serialWindow_->getSwitchPacketButton().setText("Switch to Packet 1");
        packet0_ = false;
    }
    else
    {
        serialWindow_->getSwitchPacketButton().setText("Switch to Packet 0");
        packet0_ = true;
    }
}

void TestApplication::sendSerialKeyMotor()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendKeyMotor();
    }
    else
    {
        serial1Reporting_->sendKeyMotor();
    }
}

void TestApplication::sendSerialMotorDetails(int motorNumber)
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendMotorDetails(motorNumber);
    }
    else
    {
        serial1Reporting_->sendMotorDetails(motorNumber);
    }
}

void TestApplication::sendSerialDriverControls()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendDriverControls();
    }
    else
    {
        serial1Reporting_->sendDriverControls();
    }
}

void TestApplication::sendSerialMotorFaults()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendMotorFaults();
    }
    else
    {
        serial1Reporting_->sendMotorFaults();
    }
}

void TestApplication::sendSerialBatteryFaults()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendBatteryFaults();
    }
    else
    {
        serial1Reporting_->sendBatteryFaults();
    }
}

void TestApplication::sendSerialBattery()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendBattery();
    }
    else
    {
        serial1Reporting_->sendBattery();
    }
}

void TestApplication::sendSerialMppt()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendMppt();
    }
    else
    {
        serial1Reporting_->sendMppt();
    }
}

void TestApplication::sendSerialLights()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendLights();
    }
    else
    {
        serial1Reporting_->sendLights();
    }
}

void TestApplication::sendSerialAuxBms()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendAuxBms();
    }
    else
    {
        serial1Reporting_->sendAuxBms();
    }
}

void TestApplication::sendSerialAll()
{
    if (packet0_ == true)
    {
        serial0Reporting_->sendAll();
    }
    else
    {
        serial1Reporting_->sendAll();
    }
}
