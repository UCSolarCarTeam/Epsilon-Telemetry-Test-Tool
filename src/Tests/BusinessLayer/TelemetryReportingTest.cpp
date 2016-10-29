#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <vector>

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
#include "MockCommunicationService.h"

using ::testing::_;
using ::testing::StartsWith;
using ::testing::ElementsAre;
//using ::testing::Eq;


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

    	communicationService_.reset(new MockCommunicationService());

        keyMotorData_.reset(new KeyMotorData());
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

    }

};

/*
 * Actual test cases are starting here
 */

/*
 * This test tests for the correct structure of the sendKeyMotor package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendKeyMotorTest)
{
	// first check if called at all
	const unsigned int expectedPackageLength = 47;
	/*unsigned char data[expectedPackageLength-4];
	data[0] = CcsDefines::KEY_MOTOR_PKG_ID;
	data[1] = keyMotorData_->motor0Alive;

	CrcCalculator::calculateCrc16(data, length);

	unsigned char expectedPacket[expectedPackageLength];*/
	// TODO create correctly encoded expected package
	EXPECT_CALL(*communicationService_, sendData(_/*ElementsAreArray(expectedPacket)TODO*/, expectedPackageLength)).Times(1);
	telemetryReporting_->sendKeyMotor();
}

/*
 * This test tests for the correct structure of the sendMotorDetails package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendMotorDetailsTest)
{
	// first check if called at all
	const unsigned int expectedPackageLength = 73;
	//const unsigned char expectedPacketMotor0[] = {1};
	// TODO create correctly encoded expected package
	EXPECT_CALL(*communicationService_, sendData(_/*ElementsAreArray(expectedPacketMotor0)TODO*/, expectedPackageLength)).Times(1);
	telemetryReporting_->sendMotorDetails(0);

	EXPECT_CALL(*communicationService_, sendData(_/*ElementsAreArray(expectedPacketMotor1)TODO*/, expectedPackageLength)).Times(1);
	telemetryReporting_->sendMotorDetails(1);
}

TEST_F(TelemetryReportingTest, StuffDataTest)
{
	// TODO test if Consistent Overhead Byte Stuffing (COBS) is working as intended
}

TEST_F(TelemetryReportingTest, writeFloatIntoArrayTest)
{
	const std::vector<float> inputs = {42.1234, 0, 3512.341, 19921.213, -10.2, -42.32, -7, 12,
			400, -66, -235.324, 8773.823, std::numeric_limits<float>::infinity(),
			std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<float>::epsilon(),
			std::numeric_limits<float>::min(), std::numeric_limits<float>::max()};
	for(std::vector<float>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const float input = *it;
		char* p = ( char*)((void*)&input);
		unsigned char actual[sizeof(float)];

		telemetryReporting_->writeFloatIntoArray(actual, 0, input);

		ASSERT_THAT(actual, ElementsAre(*p, *(p+1), *(p+2), *(p+3)));
	}
}
