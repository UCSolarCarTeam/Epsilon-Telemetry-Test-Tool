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
    , cmuData_(new CmuData())
    , mpptData_(new MpptData())
    , lightsData_(new LightsData())
    , view_(new View())
    , communicationService_(new CommunicationService(*view_))
    , telemetryReporting_(new TelemetryReporting(*communicationService_,
                          *keyMotorData_,
                          *motor0DetailsData_,
                          *motor1DetailsData_,
                          *driverControlsData_,
                          *motorFaultsData_,
                          *batteryFaultsData_,
                          *batteryData_,
                          *cmuData_,
                          *mpptData_,
                          *lightsData_,
                          *view_))
    ,telemetryReporting_json_(new TelemetryReporting_json(*communicationService_,
                                                *keyMotorData_,
                                                *motor0DetailsData_,
                                                *motor1DetailsData_,
                                                *driverControlsData_,
                                                *motorFaultsData_,
                                                *batteryFaultsData_,
                                                *batteryData_,
                                                *cmuData_,
                                                *mpptData_,
                                                *lightsData_,
                                                *view_))
{
}

TestApplication::~TestApplication()
{
}
