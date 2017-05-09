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
    , internetView_(new InternetView(internetWindow_.data()))
    , serialView_(new SerialView(serialWindow_.data()))
    , window_(new Window(QList<QWidget*> {serialWindow_.data(), internetWindow_.data()}))
    , communicationService_(new CommunicationService(*serialView_))
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
                         *lightsData_))
{
}

TestApplication::~TestApplication()
{
}
