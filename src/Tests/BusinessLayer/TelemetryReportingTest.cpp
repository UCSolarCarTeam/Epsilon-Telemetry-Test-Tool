#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>

#include "KeyMotorData.h"
#include "MotorDetailsData.h"
#include "DriverControlsData.h"
#include "MotorFaultsData.h"
#include "BatteryFaultsData.h"
#include "BatteryData.h"
#include "CmuData.h"
#include "MpptData.h"
#include "LightsData.h"
#include "View.h"
#include "TelemetryReporting.h"

//#include "CommunicationServiceTestWrapper.h"
#include "MockCommunicationService.h"

using ::testing::_;

// TODO make this class a friend class to allow the testing of private functions 
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md#testing-private-code

class TelemetryReportingTest : public ::testing::Test
{

protected:

	//QScopedPointer<CommunicationServiceTestWrapper> communicationService_;
	QScopedPointer<MockCommunicationService> communicationService_;
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<MotorDetailsData> motor0DetailsData_;
    QScopedPointer<MotorDetailsData> motor1DetailsData_;
    QScopedPointer<DriverControlsData> driverControlsData_;
    QScopedPointer<MotorFaultsData> motorFaultsData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<BatteryData> batteryData_;
    QScopedPointer<CmuData> cmuData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<View> view;

    QScopedPointer<TelemetryReporting> telemetryReporting_;

    virtual void SetUp()
    {

    	std::cout << "CALLED SetUp" << std::endl;

    	communicationService_.reset(new MockCommunicationService());

        keyMotorData_.reset(new KeyMotorData());
        std::cout << "1 SetUp" << std::endl;
        motor0DetailsData_.reset(new MotorDetailsData());
        motor1DetailsData_.reset(new MotorDetailsData());

        driverControlsData_.reset(new DriverControlsData());
        motorFaultsData_.reset(new MotorFaultsData());
        batteryFaultsData_.reset(new BatteryFaultsData());
        batteryData_.reset(new BatteryData());
        cmuData_.reset(new CmuData());
        mpptData_.reset(new MpptData());
        lightsData_.reset(new LightsData());
        view.reset(new View());

        std::cout << "10 SetUp" << std::endl;

        telemetryReporting_.reset(new TelemetryReporting(*communicationService_,
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
				*view
				));

        std::cout << "END OF CALL TO SetUp" << std::endl;

    }

};

/*
 * Actual test cases starts here
 */

TEST_F(TelemetryReportingTest, dataForwarded)
{
	std::cout << "CALLED TEST 1" << std::endl;
    // TODO
	// first check if called at all
	EXPECT_CALL(*communicationService_, sendData(_,_)).Times(1);
	telemetryReporting_->sendKeyMotor();
    
// TODO check result which has been sent
}
