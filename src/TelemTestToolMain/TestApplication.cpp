#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
    : QApplication(argc, argv)
    , keyMotorData_(new KeyMotorData())
    , motor0DetailsData_(new MotorDetailsData())
    , motor1DetailsData_(new MotorDetailsData())
    , driverControlsData_(new DriverControlsData())
    , motorFaultsData_(new MotorFaultsData())
    , batteryFaultsData_(new BatteryFaultsData())
    , batteryData_(new BatteryData())
    , mpptData_(new MpptData())
    , lightsData_(new LightsData())
    , auxBmsData_(new AuxBmsData())
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
    , serialReporting_(new SerialReporting(*communicationService_,
                                           *keyMotorData_,
                                           *motor0DetailsData_,
                                           *motor1DetailsData_,
                                           *driverControlsData_,
                                           *motorFaultsData_,
                                           *batteryFaultsData_,
                                           *batteryData_,
                                           *mpptData_,
                                           *lightsData_,
                                           *auxBmsData_,
                                           *serialView_))
    , internetReporting_(new InternetReporting(*communicationService_,
                                               *keyMotorData_,
                                               *motor0DetailsData_,
                                               *motor1DetailsData_,
                                               *driverControlsData_,
                                               *motorFaultsData_,
                                               *batteryFaultsData_,
                                               *batteryData_,
                                               *mpptData_,
                                               *lightsData_,
                                               *auxBmsData_,
                                               *internetView_))
    , packetReporting_(new PacketReporting(*keyMotorData_,
                                           *motor0DetailsData_,
                                           *motor1DetailsData_,
                                           *driverControlsData_,
                                           *motorFaultsData_,
                                           *batteryFaultsData_,
                                           *batteryData_,
                                           *mpptData_,
                                           *lightsData_,
                                           *auxBmsData_,
                                           *packetWindow_))
{
}

TestApplication::~TestApplication()
{
}
