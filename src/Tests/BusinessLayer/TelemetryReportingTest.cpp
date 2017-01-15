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
#include "Util.h"
#include "TestUtils.h"

#include "CcsDefines.h"
#include "CrcCalculator.h"

using ::testing::_;
using ::testing::StartsWith;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Args;
using ::testing::Eq;

using ::testing::Matcher;
using ::testing::MatcherInterface;
using ::testing::MatchResultListener;

using ::TestUtils::appendChecksum;

#include<iterator>

namespace
{
	const unsigned int CHECK_SUM_LENGTH = 2;
	const unsigned int COBS_ADDITIONAL_FRAME_DATA_SIZE = 2;

	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_KEY_MOTOR = 47;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS = 73;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_DRIVER_CONTROLS = 13;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS = 13;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS = 7;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_BATTERY = 64;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_CMU = 54;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MPPT = 14;
	const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS = 6;
}


class TelemetryReportingTest : public ::testing::Test
{

protected:

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

    inline unsigned char fitTwoSingleUChar(unsigned char bit0To3, unsigned char bit4To7) const
    {
        unsigned char ret = (bit4To7 << 4) | (bit0To3 & 0x0F);
        return ret;
    }

    void fillCmuData(unsigned char* data) const
    {
        data[0] = CcsDefines::CMU_PKG_ID;
        data[1] = cmuData_->cmuNumber;
        const int cmuCellVoltageOffset = 2;
        const int numCellVoltageFields = 8;

        for (int i = 0; i < numCellVoltageFields; ++i)
        {
            Util::writeShortIntoArray(data, cmuCellVoltageOffset + (i * 2), cmuData_->cellVoltage[i]);
        }

        Util::writeUShortIntoArray(data, 18, cmuData_->pcbTemperature);
        const int cmuCellTemperatureOffset = 20;
        const int numCellTemperatureFields = 15;

        for (int i = 0; i < numCellTemperatureFields; i++)
        {
        	Util::writeUShortIntoArray(data, cmuCellTemperatureOffset + (i * 2), cmuData_->cellTemperature[i]);
        }
    }

    void fillMpptData(unsigned char* data) const
    {
        data[0] = CcsDefines::MPPT_PKG_ID;
        unsigned char numberAndAlive = mpptData_->mpptNumber & 0x3;

        if (mpptData_->alive)
        {
            numberAndAlive |= 0x80;
        }

        data[1] = numberAndAlive;
        Util::writeUShortIntoArray(data, 2, mpptData_->arrayVoltage);
        Util::writeUShortIntoArray(data, 4, mpptData_->arrayCurrent);
        Util::writeUShortIntoArray(data, 6, mpptData_->batteryVoltage);
        Util::writeUShortIntoArray(data, 8, mpptData_->temperature);
    }

    class PackageIdMatcher : public MatcherInterface<std::tuple<const unsigned char*, int>>
    {
    public:
        explicit PackageIdMatcher(unsigned char expectedId, TelemetryReportingTest& containingTest)
            : expectedId_(expectedId), containingTest_(containingTest) {}

        virtual bool MatchAndExplain(std::tuple<const unsigned char*, int> input, /* has to contain at least 2 elements! */
                                     MatchResultListener* listener) const
        {
            if (expectedId_ < 1)
            {
                if (listener->IsInterested())
                {
                    ::std::ostream* os = listener->stream();
                    *os << "ILLEGAL MATCHER STATE: ID has to be larger than zero" << std::endl;
                }

                return false;
            }

            const int inputLength = std::get<1>(input);

            if (inputLength < 2)
            {
                if (listener->IsInterested())
                {
                    ::std::ostream* os = listener->stream();
                    *os << "Actual array is to short (length =" << inputLength << ")" << std::endl;
                }

                return false;
            }

            const unsigned char actualId = std::get<0>(input)[1];
            bool res = actualId == expectedId_;

            if (!res && listener->IsInterested())
            {
                ::std::ostream* os = listener->stream();
                *os << "Actual id is " << actualId << std::endl;
            }

            return res;
        }

        virtual void DescribeTo(::std::ostream* os) const
        {
            *os << "Expected package ID = " << expectedId_ << std::endl;
        }

    private:
        const unsigned char expectedId_;
        const TelemetryReportingTest& containingTest_;
    };

    inline Matcher<std::tuple<const unsigned char*, int>> packageIdIs(unsigned char expectedId)
    {
        return MakeMatcher(new PackageIdMatcher(expectedId, *this));
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
TEST_F(TelemetryReportingTest, sendKeyMotorTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_KEY_MOTOR;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::KEY_MOTOR_PKG_ID;
    bool motor0Alive[] = {keyMotorData_->motor0Alive};
    Util::writeBoolsIntoArray(data, 1, motor0Alive, 1);
    Util::writeFloatIntoArray(data, 2, keyMotorData_->motor0SetCurrent);
    Util::writeFloatIntoArray(data, 6, keyMotorData_->motor0SetVelocity);
    Util::writeFloatIntoArray(data, 10, keyMotorData_->motor0BusCurrent);
    Util::writeFloatIntoArray(data, 14, keyMotorData_->motor0BusVoltage);
    Util::writeFloatIntoArray(data, 18, keyMotorData_->motor0VehicleVelocity);
    bool motor1Alive[] = {keyMotorData_->motor1Alive};
    Util::writeBoolsIntoArray(data, 22, motor1Alive, 1);
    Util::writeFloatIntoArray(data, 23, keyMotorData_->motor1SetCurrent);
    Util::writeFloatIntoArray(data, 27, keyMotorData_->motor1SetVelocity);
    Util::writeFloatIntoArray(data, 31, keyMotorData_->motor1BusCurrent);
    Util::writeFloatIntoArray(data, 35, keyMotorData_->motor1BusVoltage);
    Util::writeFloatIntoArray(data, 39, keyMotorData_->motor1VehicleVelocity);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x01)); // packet id
    const unsigned char aliveBitMotor0Enconding = keyMotorData_->motor0Alive? 0x01 : 0x00;
    const unsigned char aliveBitMotor1Enconding = keyMotorData_->motor1Alive? 0x01 : 0x00;
    ASSERT_THAT(data[1], Eq(aliveBitMotor0Enconding));
    ASSERT_THAT(data[22], Eq(aliveBitMotor1Enconding));

    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendKeyMotor();
}

/*
 * This test tests for the correct structure of the sendMotorDetails package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendMotorDetailsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // create payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::MOTOR_DETAILS_0_PKG_ID;
    Util::writeFloatIntoArray(data, 1, motor0DetailsData_->phaseCCurrent);
    Util::writeFloatIntoArray(data, 5, motor0DetailsData_->phaseBCurrent);
    Util::writeFloatIntoArray(data, 9, motor0DetailsData_->MotorVoltageReal);
    Util::writeFloatIntoArray(data, 13, motor0DetailsData_->MotorVoltageImaginary);
    Util::writeFloatIntoArray(data, 17, motor0DetailsData_->MotorCurrentReal);
    Util::writeFloatIntoArray(data, 21, motor0DetailsData_->MotorCurrentImaginary);
    Util::writeFloatIntoArray(data, 25, motor0DetailsData_->BackEmfReal);
    Util::writeFloatIntoArray(data, 29, motor0DetailsData_->BackEmfImaginary);
    Util::writeFloatIntoArray(data, 33, motor0DetailsData_->RailSupply15V);
    Util::writeFloatIntoArray(data, 37, motor0DetailsData_->RailSupply3V);
    Util::writeFloatIntoArray(data, 41, motor0DetailsData_->RailSupply1V);
    Util::writeFloatIntoArray(data, 45, motor0DetailsData_->heatSinkTemperature);
    Util::writeFloatIntoArray(data, 49, motor0DetailsData_->motorTemperature);
    Util::writeFloatIntoArray(data, 53, motor0DetailsData_->dspBoardTempearture);
    Util::writeFloatIntoArray(data, 57, motor0DetailsData_->dcBusAmpHours);
    Util::writeFloatIntoArray(data, 61, motor0DetailsData_->odometer);
    Util::writeFloatIntoArray(data, 65, motor0DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x02)); // packet id
    unsigned char expectedPacket0[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket0);
    // check call
    const auto expectedPacket0AsArg = Args<0, 1>(ElementsAreArray(expectedPacket0, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacket0AsArg).Times(1);
    telemetryReporting_->sendMotorDetails(0);
    data[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
    Util::writeFloatIntoArray(data, 1, motor1DetailsData_->phaseCCurrent);
    Util::writeFloatIntoArray(data, 5, motor1DetailsData_->phaseBCurrent);
    Util::writeFloatIntoArray(data, 9, motor1DetailsData_->MotorVoltageReal);
    Util::writeFloatIntoArray(data, 13, motor1DetailsData_->MotorVoltageImaginary);
    Util::writeFloatIntoArray(data, 17, motor1DetailsData_->MotorCurrentReal);
    Util::writeFloatIntoArray(data, 21, motor1DetailsData_->MotorCurrentImaginary);
    Util::writeFloatIntoArray(data, 25, motor1DetailsData_->BackEmfReal);
    Util::writeFloatIntoArray(data, 29, motor1DetailsData_->BackEmfImaginary);
    Util::writeFloatIntoArray(data, 33, motor1DetailsData_->RailSupply15V);
    Util::writeFloatIntoArray(data, 37, motor1DetailsData_->RailSupply3V);
    Util::writeFloatIntoArray(data, 41, motor1DetailsData_->RailSupply1V);
    Util::writeFloatIntoArray(data, 45, motor1DetailsData_->heatSinkTemperature);
    Util::writeFloatIntoArray(data, 49, motor1DetailsData_->motorTemperature);
    Util::writeFloatIntoArray(data, 53, motor1DetailsData_->dspBoardTempearture);
    Util::writeFloatIntoArray(data, 57, motor1DetailsData_->dcBusAmpHours);
    Util::writeFloatIntoArray(data, 61, motor1DetailsData_->odometer);
    Util::writeFloatIntoArray(data, 65, motor1DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x03)); // packet id
    unsigned char expectedPacket1[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket1);
    const auto expectedPacket1AsArg = Args<0, 1>(ElementsAreArray(expectedPacket1, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacket1AsArg).Times(1);
    telemetryReporting_->sendMotorDetails(1);
}

/*
 * This test tests for the correct structure of the sendDriverControls package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendDriverControlsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_DRIVER_CONTROLS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::DRIVER_CONTROLS_PKG_ID;
    bool driverControlBoardsAlive[] = {driverControlsData_->alive};
    Util::writeBoolsIntoArray(data, 1, driverControlBoardsAlive, 1);
    bool lightsInputs[] = { driverControlsData_->headlightsOff,
                            driverControlsData_->headlightsLow,
                            driverControlsData_->headlightsHigh,
                            driverControlsData_->signalLeft,
                            driverControlsData_->signalRight,
                            driverControlsData_->hazardLights,
                            driverControlsData_->interiorLights
                          };
    Util::writeBoolsIntoArray(data, 2, lightsInputs, 7);
    bool musicInputs[] = { driverControlsData_->musicAux,
                           driverControlsData_->volumeUp,
                           driverControlsData_->volumeDown,
                           driverControlsData_->nextSong,
                           driverControlsData_->prevSong
                         };
    Util::writeBoolsIntoArray(data, 3, musicInputs, 5);
    Util::writeUShortIntoArray(data, 4, driverControlsData_->acceleration);
    Util::writeUShortIntoArray(data, 6, driverControlsData_->regenBraking);
    bool driverInputs[] = { driverControlsData_->brakes,
                            driverControlsData_->forward,
                            driverControlsData_->reverse,
                            driverControlsData_->pushToTalk,
                            driverControlsData_->horn,
                            driverControlsData_->reset
                          };
    Util::writeBoolsIntoArray(data, 8, driverInputs, 6);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x04)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendDriverControls();
}

/*
 * This test tests for the correct structure of the sendMotorFaults package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendMotorFaultsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::MOTOR_FAULTS_PKG_ID;
    bool motor0ErrorFlags[] = { motorFaultsData_->motor0OverSpeed,
                                motorFaultsData_->motor0SoftwareOverCurrent,
                                motorFaultsData_->motor0DcBusOverVoltage,
                                motorFaultsData_->motor0BadMootorPositionHallSequence,
                                motorFaultsData_->motor0WatchdogCausedLastReset,
                                motorFaultsData_->motor0ConfigReadError,
                                motorFaultsData_->motor0Rail15VUnderVoltageLockOut,
                                motorFaultsData_->motor0DesaturationFault
                              };
    Util::writeBoolsIntoArray(data, 1, motor0ErrorFlags, 8);
    bool motor1ErrorFlags[] = { motorFaultsData_->motor1OverSpeed,
                                motorFaultsData_->motor1SoftwareOverCurrent,
                                motorFaultsData_->motor1DcBusOverVoltage,
                                motorFaultsData_->motor1BadMootorPositionHallSequence,
                                motorFaultsData_->motor1WatchdogCausedLastReset,
                                motorFaultsData_->motor1ConfigReadError,
                                motorFaultsData_->motor1Rail15VUnderVoltageLockOut,
                                motorFaultsData_->motor1DesaturationFault
                              };
    Util::writeBoolsIntoArray(data, 2, motor1ErrorFlags, 8);
    bool motor0LimitFlags[] = { motorFaultsData_->motor0OutputVoltagePwmLimit,
                                motorFaultsData_->motor0MotorCurrentLimit,
                                motorFaultsData_->motor0VelocityLimit,
                                motorFaultsData_->motor0BusCurrentLimit,
                                motorFaultsData_->motor0BusVoltageUpperLimit,
                                motorFaultsData_->motor0BusVoltageLowerLimit,
                                motorFaultsData_->motor0IpmOrMotorTemperatureLimit
                              };
    Util::writeBoolsIntoArray(data, 3, motor0LimitFlags, 7);
    bool motor1LimitFlags[] = { motorFaultsData_->motor1OutputVoltagePwmLimit,
                                motorFaultsData_->motor1MotorCurrentLimit,
                                motorFaultsData_->motor1VelocityLimit,
                                motorFaultsData_->motor1BusCurrentLimit,
                                motorFaultsData_->motor1BusVoltageUpperLimit,
                                motorFaultsData_->motor1BusVoltageLowerLimit,
                                motorFaultsData_->motor1IpmOrMotorTemperatureLimit
                              };
    Util::writeBoolsIntoArray(data, 4, motor1LimitFlags, 7);
    data[5] = motorFaultsData_->motor0RxErrorCount;
    data[6] = motorFaultsData_->motor0TxErrorCount;
    data[7] = motorFaultsData_->motor1RxErrorCount;
    data[8] = motorFaultsData_->motor1TxErrorCount;
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x05)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendMotorFaults();
}

/*
 * This test tests for the correct structure of the sendBatteryFaults package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendBatteryFaultsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::BATTERY_FAULTS_PKG_ID;
    bool errorFlags[] = { batteryFaultsData_->cellOverVoltage,
                          batteryFaultsData_->cellUnderVoltage,
                          batteryFaultsData_->cellOverTemperature,
                          batteryFaultsData_->measurementUntrusted,
                          batteryFaultsData_->cmuCommTimeout,
                          batteryFaultsData_->vehicleCommTimeout,
                          batteryFaultsData_->bmuInSetupMode,
                          batteryFaultsData_->cmuCanBusPowerStatus,
                          batteryFaultsData_->packIsolationTestFailure,
                          batteryFaultsData_->softwareOverCurrent,
                          batteryFaultsData_->can12VSupplyLow,
                          batteryFaultsData_->contactorStuck,
                          batteryFaultsData_->cmuDetectedExtraCellPresent
                        };
    Util::writeBoolsIntoArray(data, 1, errorFlags, 13);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x06)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendBatteryFaults();
}

/*
 * This test tests for the correct structure of the sendBattery package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendBatteryTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_BATTERY;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::BATTERY_PKG_ID;
    bool bmuAlive[] = { batteryData_->alive};
    Util::writeBoolsIntoArray(data, 1, bmuAlive, 1);
    Util::writeFloatIntoArray(data, 2, batteryData_->packSocAmpHours);
    Util::writeFloatIntoArray(data, 6, batteryData_->packSocPercentage);
    Util::writeFloatIntoArray(data, 10, batteryData_->packBalanceSoc);
    Util::writeFloatIntoArray(data, 14, batteryData_->packBalanceSocPercentage);
    Util::writeUShortIntoArray(data, 18, batteryData_->chargingCellVoltageError);
    Util::writeUShortIntoArray(data, 20, batteryData_->cellTemperatureMargin);
    Util::writeUShortIntoArray(data, 22, batteryData_->dischargingCellVoltageError);
    Util::writeUShortIntoArray(data, 24, batteryData_->totalPackCapacity);
    bool PrechargeContactorDriverStatus[] = { batteryData_->contactor0Errorstatus,
                                              batteryData_->contactor1ErrorStatus,
                                              batteryData_->contactor0Status,
                                              batteryData_->contactor1Status,
                                              batteryData_->contactor12VSupplyOk,
                                              batteryData_->contactor2ErrorStatus,
                                              batteryData_->contactor2Status
                                            };
    Util::writeBoolsIntoArray(data, 26, PrechargeContactorDriverStatus, 7);
    data[27] = (unsigned char) batteryData_->prechargeState;
    bool PrechargeTimerElapsed[] = { batteryData_->prechargeTimerElapsed,
                                     batteryData_->prechargeTimerNotElapsed
                                   };
    Util::writeBoolsIntoArray(data, 28, PrechargeTimerElapsed, 2);
    Util::writeUShortIntoArray(data, 29, batteryData_->prechargeTimerCount);
    Util::writeUShortIntoArray(data, 31, batteryData_->lowestCellVoltage);
    data[33] = fitTwoSingleUChar(batteryData_->lowestCellVoltageCmuNumber, batteryData_->lowestCellVoltageCellNumber);
    Util::writeUShortIntoArray(data, 34, batteryData_->highestCellVoltage);
    data[36] = fitTwoSingleUChar(batteryData_->highestCellVoltageCmuNumber, batteryData_->highestCellVoltageCellNumber);
    Util::writeUShortIntoArray(data, 37, batteryData_->lowestCellTemperature);
    data[39] = fitTwoSingleUChar(batteryData_->lowestCellTemperatureCmuNumber, batteryData_->lowestCellTemperatureCellNumber);
    Util::writeUShortIntoArray(data, 40, batteryData_->highestCellTemperature);
    data[42] = fitTwoSingleUChar(batteryData_->highestCellTemperatureCmuNumber, batteryData_->highestCellTemperatureCellNumber);
    Util::writeUIntIntoArray(data, 43, batteryData_->voltage);
    Util::writeUIntIntoArray(data, 47, batteryData_->current);
    Util::writeUShortIntoArray(data, 51, batteryData_->fan0Speed);
    Util::writeUShortIntoArray(data, 53, batteryData_->fan1Speed);
    Util::writeUShortIntoArray(data, 55, batteryData_->fanContactors12VCurrentConsumption);
    Util::writeUShortIntoArray(data, 57, batteryData_->cmu12VCurrentConsumption);
    bool BMSCanLockedOut[] = {batteryData_->bmsCanLockedOut};
    Util::writeBoolsIntoArray(data, 59, BMSCanLockedOut, 1);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x07)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendBattery();
}

/*
 * This test tests for the correct structure of the sendCmu package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendCmuTest)
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_CMU;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char expectedPacket[CcsDefines::CMU_COUNT][expectedPackageLength];

    for (unsigned char i = 0; i < CcsDefines::CMU_COUNT; i++)
    {
        unsigned char data[payloadLength];
        cmuData_->cmuNumber = i;
        // build actual package
        fillCmuData(data);
        appendChecksum(data, payloadLength);
        // do some additional data checks
        ASSERT_THAT(data[0], Eq(0x08)); // packet id
        ASSERT_THAT(data[1], Eq(i)); // cmu number
        Util::frameData(data, payloadLength, expectedPacket[i]);
        const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket[i], expectedPackageLength));
        EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    }

    // check call
    telemetryReporting_->sendCmu();
}

/*
 * This test tests for the correct structure of the sendMppt package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendMpptTest)
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_MPPT;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;

    for (unsigned char testCount = 0; testCount < 2; testCount++)
    {
        unsigned char expectedPacket[CcsDefines::MPPT_COUNT][expectedPackageLength];
        mpptData_->alive = testCount % 2 == 0; // set all mppts to non alive in all odd test runs

        for (unsigned char i = 0; i < CcsDefines::MPPT_COUNT; i++)
        {
            unsigned char data[payloadLength];
            mpptData_->mpptNumber = i;
            // build actual package
            fillMpptData(data);
            appendChecksum(data, payloadLength);
            // do some additional data checks
            ASSERT_THAT(data[0], Eq(0x09)); // packet id

            if (mpptData_->alive)
            {
                ASSERT_THAT(data[1], Eq((i | 0x80))); // mppt number including alive bit
            }
            else
            {
                ASSERT_THAT(data[1], Eq(i)); // mppt number including alive bit
            }

            Util::frameData(data, payloadLength, expectedPacket[i]);
            const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket[i], expectedPackageLength));
            EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
        }

        // check call
        telemetryReporting_->sendMppt();
    }
}

/*
 * This test tests for the correct structure of the sendLights package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendLightsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::LIGHTS_PKG_ID;
    bool lightsStatus[] = {lightsData_->lowBeams,
                           lightsData_->highBeams,
                           lightsData_->brakes,
                           lightsData_->leftSignal,
                           lightsData_->rightSignal,
                           lightsData_->bmsStrobeLight
                          };
    Util::writeBoolsIntoArray(data, 1, lightsStatus, 6);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x0A)); // packet id
    ASSERT_THAT(((data[1] & 0x01) == 0x01), lightsData_->lowBeams);
    ASSERT_THAT(((data[1] & 0x02) == 0x02), lightsData_->highBeams);
    ASSERT_THAT(((data[1] & 0x04) == 0x04), lightsData_->brakes);
    ASSERT_THAT(((data[1] & 0x08) == 0x08), lightsData_->leftSignal);
    ASSERT_THAT(((data[1] & 0x10) == 0x10), lightsData_->rightSignal);
    ASSERT_THAT(((data[1] & 0x20) == 0x20), lightsData_->bmsStrobeLight);
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
    telemetryReporting_->sendLights();
}

/*
 * This test tests if during sendAll all methods which send a message are called.
 *
 * The actual methods, stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(TelemetryReportingTest, sendAllTest)
{
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_KEY_MOTOR)).With(Args<0, 1>(packageIdIs(1))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS)).With(Args<0, 1>(packageIdIs(2))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS)).With(Args<0, 1>(packageIdIs(3))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_DRIVER_CONTROLS)).With(Args<0, 1>(packageIdIs(4))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS)).With(Args<0, 1>(packageIdIs(5))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS)).With(Args<0, 1>(packageIdIs(6))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_BATTERY)).With(Args<0, 1>(packageIdIs(7))).Times(1);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_CMU)).With(Args<0, 1>(packageIdIs(8))).Times(CcsDefines::CMU_COUNT);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_MPPT)).With(Args<0, 1>(packageIdIs(9))).Times(CcsDefines::MPPT_COUNT);
    EXPECT_CALL(*communicationService_, sendData(_, EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS)).With(Args<0, 1>(packageIdIs(10))).Times(1);
    telemetryReporting_->sendAll();
}



