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
    , internetWindow_(new InternetWindow())
    , serialWindow_(new SerialWindow())
    , batteryTab_(new BatteryTab())
    , batteryFaultsTab_(new BatteryFaultsTab())
    , driverControlsTab_(new DriverControlsTab())
    , lightsTab_(new LightsTab())
    , motor0Tab_(new MotorTab())
    , motor1Tab_(new MotorTab())
    , mpptTab_(new MpptTab())
    , packetWindow_(new PacketWindow(*batteryTab_,
                                     *batteryFaultsTab_,
                                     *driverControlsTab_,
                                     *lightsTab_,
                                     *motor0Tab_,
                                     *motor1Tab_,
                                     *mpptTab_))
    , internetView_(new InternetView(internetWindow_.data()))
    , serialView_(new SerialView(serialWindow_.data()))
    //, packetView_(new PacketView(packetWindow_.data()))
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
                     *internetView_))
{
}

TestApplication::~TestApplication()
{
}
