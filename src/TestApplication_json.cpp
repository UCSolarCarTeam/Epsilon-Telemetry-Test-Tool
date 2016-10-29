#include "TestApplication_json.h"

TestApplication_json::TestApplication_json(int& argc, char** argv)
    : QApplication(argc, argv)
    , keyMotorData_(new KeyMotorData())
    , motor0DetailsData_(new MotorDetailsData())
    , motor1DetailsData_(new MotorDetailsData())
    , driverControlsData_(new DriverControlsData())
    , motorFaultsData_(new MotorFaultsData())
    , batteryFaultsData_(new BatteryFaultsData())
    , batteryData_json_(new BatteryData_json())
    , cmuData_(new CmuData())
    , mpptData_(new MpptData())
    , lightsData_(new LightsData())
    , view_(new View())
    , communicationService_json_(new CommunicationService_json(*view_))
    , telemetryReporting_json_(new TelemetryReporting_json(*communicationService_json_,
                          *keyMotorData_,
                          *motor0DetailsData_,
                          *motor1DetailsData_,
                          *driverControlsData_,
                          *motorFaultsData_,
                          *batteryFaultsData_,
                          *batteryData_json_,
                          *cmuData_,
                          *mpptData_,
                          *lightsData_,
                          *view_))
{
}

TestApplication_json::~TestApplication_json()
{
}
