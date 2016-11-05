#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <vector>
#include <tuple>

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

#include "CcsDefines.h"
#include "CrcCalculator.h"

using ::testing::_;
using ::testing::StartsWith;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Args;
using ::testing::Eq;


class TelemetryReportingTest : public ::testing::Test
{

public:
	const unsigned int CHECK_SUM_LENGTH = 2;
	const unsigned int COBS_ADDITIONAL_FRAME_DATA_SIZE = 2;

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

    void appendChecksum(unsigned char *data, unsigned int lengthPayload) {
    	const unsigned short checksum = CrcCalculator::calculateCrc16(data, lengthPayload - CHECK_SUM_LENGTH);
    	const unsigned char lowerByte = (unsigned char) checksum & 0xFF;
    	const unsigned char higherByte = (unsigned char) ((checksum & 0xFF00) >> 8);

    	// this is just here to ensure that every test which uses the method fails, if the length of the check sum changes.
    	// In this case this method has to be adapted
    	ASSERT_THAT(CHECK_SUM_LENGTH, 2);

    	data[lengthPayload-CHECK_SUM_LENGTH] = lowerByte;
    	data[lengthPayload-(CHECK_SUM_LENGTH-1)] = higherByte;
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
	const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
	unsigned char data[payloadLength];
	data[0] = CcsDefines::KEY_MOTOR_PKG_ID;
	bool motor0Alive[] = {keyMotorData_->motor0Alive};
	telemetryReporting_->writeBoolsIntoArray(data, 1, motor0Alive, 1);
	telemetryReporting_->writeFloatIntoArray(data, 2, keyMotorData_->motor0SetCurrent);
	telemetryReporting_->writeFloatIntoArray(data, 6, keyMotorData_->motor0SetVelocity);
	telemetryReporting_->writeFloatIntoArray(data, 10, keyMotorData_->motor0BusCurrent);
	telemetryReporting_->writeFloatIntoArray(data, 14, keyMotorData_->motor0BusVoltage);
	telemetryReporting_->writeFloatIntoArray(data, 18, keyMotorData_->motor0VehicleVelocity);

	bool motor1Alive[] = {keyMotorData_->motor1Alive};
	telemetryReporting_->writeBoolsIntoArray(data, 22, motor1Alive, 1);
	telemetryReporting_->writeFloatIntoArray(data, 23, keyMotorData_->motor1SetCurrent);
	telemetryReporting_->writeFloatIntoArray(data, 27, keyMotorData_->motor1SetVelocity);
	telemetryReporting_->writeFloatIntoArray(data, 31, keyMotorData_->motor1BusCurrent);
	telemetryReporting_->writeFloatIntoArray(data, 35, keyMotorData_->motor1BusVoltage);
	telemetryReporting_->writeFloatIntoArray(data, 39, keyMotorData_->motor1VehicleVelocity);

	appendChecksum(data, payloadLength);

	// do some additional data checks
	ASSERT_THAT(data[0], Eq(0x01)); // packet id
	ASSERT_THAT(data[1], Eq(0x01));
	ASSERT_THAT(data[22], Eq(0x00));

	unsigned char expectedPacket[expectedPackageLength];
	telemetryReporting_->frameData(data, payloadLength, expectedPacket);

	EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0,1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
	// TODO maybe also test frameData in here
}

TEST_F(TelemetryReportingTest, writeBoolsIntoArrayTest)
{
	bool inSingleTrue[] = {true};
	const std::vector<unsigned char> expctSingleTrue = {0x01};

	bool inSingleFalse[] = {false};
	const std::vector<unsigned char> expctSingleFalse = {0x00};

	bool input4[] = {false, true, false, true};
	const std::vector<unsigned char> expct4 = {0x0A};

	bool input4inv[] = {true, false, true, false};
	const std::vector<unsigned char> expct4inv = {0x05};

	bool input8[] = {false, true, false, true, false, true, false, true};
	const std::vector<unsigned char> expct8 = {0xAA};

	bool input9[] = {false, true, false, true, false, true, false, true, true};
	const std::vector<unsigned char> expct9 = {0xAA, 0x01};

	bool inputsAllTrue[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
	const std::vector<unsigned char> expctAllTrue = {0xFF, 0xFF};

	bool inputsAllFalse[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
	const std::vector<unsigned char> expctAllFalse = {0x00, 0x00};

	const std::vector<std::tuple<bool*, int, std::vector<unsigned char>>> inputs = {
			std::make_tuple(inSingleTrue, sizeof(inSingleTrue) / sizeof(bool), expctSingleTrue),
			std::make_tuple(inSingleFalse, sizeof(inSingleFalse) / sizeof(bool), expctSingleFalse),
			std::make_tuple(input4, sizeof(input4) / sizeof(bool), expct4),
			std::make_tuple(input4inv, sizeof(input4inv) / sizeof(bool), expct4inv),
			std::make_tuple(input8, sizeof(input8) / sizeof(bool), expct8),
			std::make_tuple(input9, sizeof(input9) / sizeof(bool), expct9),
			std::make_tuple(inputsAllTrue, sizeof(inputsAllTrue) / sizeof(bool), expctAllTrue),
			std::make_tuple(inputsAllFalse, sizeof(inputsAllFalse) / sizeof(bool), expctAllFalse)
	};

	for(std::vector<std::tuple<bool*, int, std::vector<unsigned char>>>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const bool *input = std::get<0>(*it);
		unsigned int actualLength = std::get<2>(*it).size();
		unsigned char actual[actualLength];

		telemetryReporting_->writeBoolsIntoArray(actual, 0, input, std::get<1>(*it));

		// introduce vector wrapper for actual (workaround to get the matcher handle variable-length arrays)
		std::vector<unsigned char> actual_wrapper(actual, actual + actualLength);

		ASSERT_THAT(actual_wrapper, ElementsAreArray(std::get<2>(*it)));
	}
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
