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

using ::testing::Matcher;
using ::testing::MatcherInterface;
using ::testing::MatchResultListener;

#include<iterator>

#define HEX( x ) std::setw(2) << "\\x" << std::hex << (int)( x )


class TelemetryReportingTest : public ::testing::Test
{

public:
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

    void assertThatCOBScorrect(unsigned char* input, unsigned char* expected, const unsigned int inputLength)
    {
        const unsigned int expectedArrayLength = inputLength + 2;
        unsigned char encodedArray[expectedArrayLength];
        telemetryReporting_->frameData(input, inputLength, encodedArray);
        std::cout << HEX(encodedArray[inputLength]) << " " << HEX(encodedArray[inputLength + 1]) << std::endl;
        ASSERT_THAT(std::vector<unsigned char>(encodedArray, encodedArray + expectedArrayLength),
                    ElementsAreArray(std::vector<unsigned char>(expected, expected + expectedArrayLength)));
    }


    void appendChecksum(unsigned char* data, unsigned int lengthPayload)
    {
        const unsigned short checksum = CrcCalculator::calculateCrc16(data, lengthPayload - CHECK_SUM_LENGTH);
        const unsigned char lowerByte = (unsigned char) checksum & 0xFF;
        const unsigned char higherByte = (unsigned char) ((checksum & 0xFF00) >> 8);
        // this is just here to ensure that every test which uses the method fails, if the length of the check sum changes.
        // In this case this method has to be adapted
        ASSERT_THAT(CHECK_SUM_LENGTH, 2);
        data[lengthPayload - CHECK_SUM_LENGTH] = lowerByte;
        data[lengthPayload - (CHECK_SUM_LENGTH - 1)] = higherByte;
    }

    inline unsigned char fitTwoSingleUChar(unsigned char bit0To3, unsigned char bit4To7)
    {
        unsigned char ret = (bit4To7 << 4) | (bit0To3 & 0x0F);
        return ret;
    }

    void fillCmuData(unsigned char* data)
    {
        data[0] = CcsDefines::CMU_PKG_ID;
        data[1] = cmuData_->cmuNumber;
        const int cmuCellVoltageOffset = 2;
        const int numCellVoltageFields = 8;

        for (int i = 0; i < numCellVoltageFields; ++i)
        {
            telemetryReporting_->writeShortIntoArray(data, cmuCellVoltageOffset + (i * 2), cmuData_->cellVoltage[i]);
        }

        telemetryReporting_->writeUShortIntoArray(data, 18, cmuData_->pcbTemperature);
        const int cmuCellTemperatureOffset = 20;
        const int numCellTemperatureFields = 15;

        for (int i = 0; i < numCellTemperatureFields; i++)
        {
            telemetryReporting_->writeUShortIntoArray(data, cmuCellTemperatureOffset + (i * 2), cmuData_->cellTemperature[i]);
        }
    }

    void fillMpptData(unsigned char* data)
    {
        data[0] = CcsDefines::MPPT_PKG_ID;
        unsigned char numberAndAlive = mpptData_->mpptNumber & 0x3;

        if (mpptData_->alive)
        {
            numberAndAlive |= 0x80;
        }

        data[1] = numberAndAlive;
        telemetryReporting_->writeUShortIntoArray(data, 2, mpptData_->arrayVoltage);
        telemetryReporting_->writeUShortIntoArray(data, 4, mpptData_->arrayCurrent);
        telemetryReporting_->writeUShortIntoArray(data, 6, mpptData_->batteryVoltage);
        telemetryReporting_->writeUShortIntoArray(data, 8, mpptData_->temperature);
    }
    /*
        class COBSEncodedIsMatcher : public MatcherInterface<std::vector<unsigned char> > {
         public:
          explicit COBSEncodedIsMatcher(std::vector<unsigned char> &expectedArray, TelemetryReportingTest &containingTest)
              : expectedArray_(expectedArray), containingTest_(containingTest) {}

          virtual bool MatchAndExplain(std::vector<unsigned char> input,
                                       MatchResultListener* listener) const {

        	  unsigned char encodedArray[expectedArray_.size()];
        	  containingTest_.telemetryReporting_->frameData(&input[0], input.size(), encodedArray);

        	  return ::testing::ExplainMatchResult(ElementsAreArray(expectedArray_),
        			  std::vector<unsigned char>(encodedArray, encodedArray+expectedArray_.size()), listener);
          }

          virtual void DescribeTo(::std::ostream* os) const {

        	 *os << "has " << expectedArray_.size() << " elements where" << std::endl;
        	 for(std::vector<unsigned char>::const_iterator it = expectedArray_.begin(); it != expectedArray_.end(); it++) {
        		 const unsigned int idx = it - expectedArray_.begin();
        		 *os << "element #" << it - expectedArray_.begin() << " is equal to \'" << HEX(*it) << "\' (" << ((int) *it) << ")";
        		 if(idx != expectedArray_.size()-1) {
        			 *os << "," << std::endl;;
        		 }
        	 }
          }

         private:
          const std::vector<unsigned char>& expectedArray_;
          const TelemetryReportingTest &containingTest_;
        };

        inline Matcher<std::vector<unsigned char> > COBSEncodedIs(std::vector<unsigned char> &expectedArray) {
          return MakeMatcher(new COBSEncodedIsMatcher(expectedArray, *this));
        }*/
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
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeFloatIntoArray(data, 1, motor0DetailsData_->phaseCCurrent);
    telemetryReporting_->writeFloatIntoArray(data, 5, motor0DetailsData_->phaseBCurrent);
    telemetryReporting_->writeFloatIntoArray(data, 9, motor0DetailsData_->MotorVoltageReal);
    telemetryReporting_->writeFloatIntoArray(data, 13, motor0DetailsData_->MotorVoltageImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 17, motor0DetailsData_->MotorCurrentReal);
    telemetryReporting_->writeFloatIntoArray(data, 21, motor0DetailsData_->MotorCurrentImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 25, motor0DetailsData_->BackEmfReal);
    telemetryReporting_->writeFloatIntoArray(data, 29, motor0DetailsData_->BackEmfImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 33, motor0DetailsData_->RailSupply15V);
    telemetryReporting_->writeFloatIntoArray(data, 37, motor0DetailsData_->RailSupply3V);
    telemetryReporting_->writeFloatIntoArray(data, 41, motor0DetailsData_->RailSupply1V);
    telemetryReporting_->writeFloatIntoArray(data, 45, motor0DetailsData_->heatSinkTemperature);
    telemetryReporting_->writeFloatIntoArray(data, 49, motor0DetailsData_->motorTemperature);
    telemetryReporting_->writeFloatIntoArray(data, 53, motor0DetailsData_->dspBoardTempearture);
    telemetryReporting_->writeFloatIntoArray(data, 57, motor0DetailsData_->dcBusAmpHours);
    telemetryReporting_->writeFloatIntoArray(data, 61, motor0DetailsData_->odometer);
    telemetryReporting_->writeFloatIntoArray(data, 65, motor0DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x02)); // packet id
    unsigned char expectedPacket0[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket0);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket0, expectedPackageLength))).Times(1);
    telemetryReporting_->sendMotorDetails(0);
    data[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
    telemetryReporting_->writeFloatIntoArray(data, 1, motor1DetailsData_->phaseCCurrent);
    telemetryReporting_->writeFloatIntoArray(data, 5, motor1DetailsData_->phaseBCurrent);
    telemetryReporting_->writeFloatIntoArray(data, 9, motor1DetailsData_->MotorVoltageReal);
    telemetryReporting_->writeFloatIntoArray(data, 13, motor1DetailsData_->MotorVoltageImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 17, motor1DetailsData_->MotorCurrentReal);
    telemetryReporting_->writeFloatIntoArray(data, 21, motor1DetailsData_->MotorCurrentImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 25, motor1DetailsData_->BackEmfReal);
    telemetryReporting_->writeFloatIntoArray(data, 29, motor1DetailsData_->BackEmfImaginary);
    telemetryReporting_->writeFloatIntoArray(data, 33, motor1DetailsData_->RailSupply15V);
    telemetryReporting_->writeFloatIntoArray(data, 37, motor1DetailsData_->RailSupply3V);
    telemetryReporting_->writeFloatIntoArray(data, 41, motor1DetailsData_->RailSupply1V);
    telemetryReporting_->writeFloatIntoArray(data, 45, motor1DetailsData_->heatSinkTemperature);
    telemetryReporting_->writeFloatIntoArray(data, 49, motor1DetailsData_->motorTemperature);
    telemetryReporting_->writeFloatIntoArray(data, 53, motor1DetailsData_->dspBoardTempearture);
    telemetryReporting_->writeFloatIntoArray(data, 57, motor1DetailsData_->dcBusAmpHours);
    telemetryReporting_->writeFloatIntoArray(data, 61, motor1DetailsData_->odometer);
    telemetryReporting_->writeFloatIntoArray(data, 65, motor1DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x03)); // packet id
    unsigned char expectedPacket1[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket1);
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket1, expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeBoolsIntoArray(data, 1, driverControlBoardsAlive, 1);
    bool lightsInputs[] = { driverControlsData_->headlightsOff,
                            driverControlsData_->headlightsLow,
                            driverControlsData_->headlightsHigh,
                            driverControlsData_->signalLeft,
                            driverControlsData_->signalRight,
                            driverControlsData_->hazardLights,
                            driverControlsData_->interiorLights
                          };
    telemetryReporting_->writeBoolsIntoArray(data, 2, lightsInputs, 7);
    bool musicInputs[] = { driverControlsData_->musicAux,
                           driverControlsData_->volumeUp,
                           driverControlsData_->volumeDown,
                           driverControlsData_->nextSong,
                           driverControlsData_->prevSong
                         };
    telemetryReporting_->writeBoolsIntoArray(data, 3, musicInputs, 5);
    telemetryReporting_->writeUShortIntoArray(data, 4, driverControlsData_->acceleration);
    telemetryReporting_->writeUShortIntoArray(data, 6, driverControlsData_->regenBraking);
    bool driverInputs[] = { driverControlsData_->brakes,
                            driverControlsData_->forward,
                            driverControlsData_->reverse,
                            driverControlsData_->pushToTalk,
                            driverControlsData_->horn,
                            driverControlsData_->reset
                          };
    telemetryReporting_->writeBoolsIntoArray(data, 8, driverInputs, 6);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x04)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeBoolsIntoArray(data, 1, motor0ErrorFlags, 8);
    bool motor1ErrorFlags[] = { motorFaultsData_->motor1OverSpeed,
                                motorFaultsData_->motor1SoftwareOverCurrent,
                                motorFaultsData_->motor1DcBusOverVoltage,
                                motorFaultsData_->motor1BadMootorPositionHallSequence,
                                motorFaultsData_->motor1WatchdogCausedLastReset,
                                motorFaultsData_->motor1ConfigReadError,
                                motorFaultsData_->motor1Rail15VUnderVoltageLockOut,
                                motorFaultsData_->motor1DesaturationFault
                              };
    telemetryReporting_->writeBoolsIntoArray(data, 2, motor1ErrorFlags, 8);
    bool motor0LimitFlags[] = { motorFaultsData_->motor0OutputVoltagePwmLimit,
                                motorFaultsData_->motor0MotorCurrentLimit,
                                motorFaultsData_->motor0VelocityLimit,
                                motorFaultsData_->motor0BusCurrentLimit,
                                motorFaultsData_->motor0BusVoltageUpperLimit,
                                motorFaultsData_->motor0BusVoltageLowerLimit,
                                motorFaultsData_->motor0IpmOrMotorTemperatureLimit
                              };
    telemetryReporting_->writeBoolsIntoArray(data, 3, motor0LimitFlags, 7);
    bool motor1LimitFlags[] = { motorFaultsData_->motor1OutputVoltagePwmLimit,
                                motorFaultsData_->motor1MotorCurrentLimit,
                                motorFaultsData_->motor1VelocityLimit,
                                motorFaultsData_->motor1BusCurrentLimit,
                                motorFaultsData_->motor1BusVoltageUpperLimit,
                                motorFaultsData_->motor1BusVoltageLowerLimit,
                                motorFaultsData_->motor1IpmOrMotorTemperatureLimit
                              };
    telemetryReporting_->writeBoolsIntoArray(data, 4, motor1LimitFlags, 7);
    data[5] = motorFaultsData_->motor0RxErrorCount;
    data[6] = motorFaultsData_->motor0TxErrorCount;
    data[7] = motorFaultsData_->motor1RxErrorCount;
    data[8] = motorFaultsData_->motor1TxErrorCount;
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x05)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeBoolsIntoArray(data, 1, errorFlags, 13);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x06)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeBoolsIntoArray(data, 1, bmuAlive, 1);
    telemetryReporting_->writeFloatIntoArray(data, 2, batteryData_->packSocAmpHours);
    telemetryReporting_->writeFloatIntoArray(data, 6, batteryData_->packSocPercentage);
    telemetryReporting_->writeFloatIntoArray(data, 10, batteryData_->packBalanceSoc);
    telemetryReporting_->writeFloatIntoArray(data, 14, batteryData_->packBalanceSocPercentage);
    telemetryReporting_->writeUShortIntoArray(data, 18, batteryData_->chargingCellVoltageError);
    telemetryReporting_->writeUShortIntoArray(data, 20, batteryData_->cellTemperatureMargin);
    telemetryReporting_->writeUShortIntoArray(data, 22, batteryData_->dischargingCellVoltageError);
    telemetryReporting_->writeUShortIntoArray(data, 24, batteryData_->totalPackCapacity);
    bool PrechargeContactorDriverStatus[] = { batteryData_->contactor0Errorstatus,
                                              batteryData_->contactor1ErrorStatus,
                                              batteryData_->contactor0Status,
                                              batteryData_->contactor1Status,
                                              batteryData_->contactor12VSupplyOk,
                                              batteryData_->contactor2ErrorStatus,
                                              batteryData_->contactor2Status
                                            };
    telemetryReporting_->writeBoolsIntoArray(data, 26, PrechargeContactorDriverStatus, 7);
    data[27] = (unsigned char) batteryData_->prechargeState;
    bool PrechargeTimerElapsed[] = { batteryData_->prechargeTimerElapsed,
                                     batteryData_->prechargeTimerNotElapsed
                                   };
    telemetryReporting_->writeBoolsIntoArray(data, 28, PrechargeTimerElapsed, 2);
    telemetryReporting_->writeUShortIntoArray(data, 29, batteryData_->prechargeTimerCount);
    telemetryReporting_->writeUShortIntoArray(data, 31, batteryData_->lowestCellVoltage);
    data[33] = fitTwoSingleUChar(batteryData_->lowestCellVoltageCmuNumber, batteryData_->lowestCellVoltageCellNumber);
    telemetryReporting_->writeUShortIntoArray(data, 34, batteryData_->highestCellVoltage);
    data[36] = fitTwoSingleUChar(batteryData_->highestCellVoltageCmuNumber, batteryData_->highestCellVoltageCellNumber);
    telemetryReporting_->writeUShortIntoArray(data, 37, batteryData_->lowestCellTemperature);
    data[39] = fitTwoSingleUChar(batteryData_->lowestCellTemperatureCmuNumber, batteryData_->lowestCellTemperatureCellNumber);
    telemetryReporting_->writeUShortIntoArray(data, 40, batteryData_->highestCellTemperature);
    data[42] = fitTwoSingleUChar(batteryData_->highestCellTemperatureCmuNumber, batteryData_->highestCellTemperatureCellNumber);
    telemetryReporting_->writeUIntIntoArray(data, 43, batteryData_->voltage);
    telemetryReporting_->writeUIntIntoArray(data, 47, batteryData_->current);
    telemetryReporting_->writeUShortIntoArray(data, 51, batteryData_->fan0Speed);
    telemetryReporting_->writeUShortIntoArray(data, 53, batteryData_->fan1Speed);
    telemetryReporting_->writeUShortIntoArray(data, 55, batteryData_->fanContactors12VCurrentConsumption);
    telemetryReporting_->writeUShortIntoArray(data, 57, batteryData_->cmu12VCurrentConsumption);
    bool BMSCanLockedOut[] = {batteryData_->bmsCanLockedOut};
    telemetryReporting_->writeBoolsIntoArray(data, 59, BMSCanLockedOut, 1);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x07)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    telemetryReporting_->frameData(data, payloadLength, expectedPacket);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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
        telemetryReporting_->frameData(data, payloadLength, expectedPacket[i]);
        EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket[i], expectedPackageLength))).Times(1);
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

            telemetryReporting_->frameData(data, payloadLength, expectedPacket[i]);
            EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket[i], expectedPackageLength))).Times(1);
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
    telemetryReporting_->writeBoolsIntoArray(data, 1, lightsStatus, 6);
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
    telemetryReporting_->frameData(data, payloadLength, expectedPacket);
    // check call
    EXPECT_CALL(*communicationService_, sendData(_, expectedPackageLength)).With(Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength))).Times(1);
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

/*
 * Tests if Consistent Overhead Byte Stuffing (COBS) is working as intended
 */
TEST_F(TelemetryReportingTest, COBSTest)
{
    unsigned char nullArrayInput[] = {0x00};
    unsigned char nullArrayExpected[] = {0x01, 0x01, 0x00};
    assertThatCOBScorrect(nullArrayInput, nullArrayExpected, 1);
    unsigned char input1[] = {0x00, 0x00};
    unsigned char expected1[] = {0x01, 0x01, 0x01, 0x00};
    assertThatCOBScorrect(input1, expected1, 2);
    unsigned char input2[] = {0x11, 0x22, 0x00, 0x33};
    unsigned char expected2[] = {0x03, 0x11, 0x22, 0x02, 0x33, 0x00};
    assertThatCOBScorrect(input2, expected2, 4);
    unsigned char input3[] = {0x11, 0x22, 0x33, 0x44};
    unsigned char expected3[] = {0x05, 0x11, 0x22, 0x33, 0x44, 0x00};
    assertThatCOBScorrect(input3, expected3, 4);
    unsigned char input4[] = {0x11, 0x00, 0x00, 0x00};
    unsigned char expected4[] = {0x02, 0x11, 0x01, 0x01, 0x01, 0x00};
    assertThatCOBScorrect(input4, expected4, 4);
    const unsigned int MAX_COBS_PACKAGE_LENGTH = 254;
    unsigned char inputAlmostMax[MAX_COBS_PACKAGE_LENGTH - 1];
    unsigned char expectedAlmostMax[MAX_COBS_PACKAGE_LENGTH + 1];

    for (unsigned char i = 0; i < MAX_COBS_PACKAGE_LENGTH - 1; ++i)
    {
        inputAlmostMax[i] = i + 1;
        expectedAlmostMax[i + 1] = i + 1;
    }

    expectedAlmostMax[0] = 0xFE;
    expectedAlmostMax[MAX_COBS_PACKAGE_LENGTH] = 0x00;
    assertThatCOBScorrect(inputAlmostMax, expectedAlmostMax, MAX_COBS_PACKAGE_LENGTH - 1);
    unsigned char inputMax[MAX_COBS_PACKAGE_LENGTH];
    unsigned char expectedMax[MAX_COBS_PACKAGE_LENGTH + 2];

    for (unsigned char i = 0; i < MAX_COBS_PACKAGE_LENGTH; ++i)
    {
        inputMax[i] = i + 1;
        expectedMax[i + 1] = i + 1;
    }

    expectedMax[0] = 0xFF;
    expectedMax[MAX_COBS_PACKAGE_LENGTH + 1] = 0x00;
    assertThatCOBScorrect(inputMax, expectedMax, MAX_COBS_PACKAGE_LENGTH); // TODO this one fails. can probably be fixed by removing line 452 from TelemetryReporting.cpp
    // TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // TODO WHAT HAPPENS IF THE Distance to the first zero is more than 254 bytes?? (our packages are smaller...)
    // TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/*
 * This test tests if the checksum is correctly appended. It does not test the checksum calculation itself.
 * (Supposed to work correctly, as copied from already tested code?!)
 */
TEST_F(TelemetryReportingTest, addChecksumTest)
{
    const unsigned char numberOfTestRuns = 42;

    for (unsigned char i = 0; i < numberOfTestRuns; i++)
    {
        const unsigned int length = i + 16;
        unsigned char dataExpected[length];
        unsigned char dataActual[length];

        for (unsigned char c = 0; c < length; c++)
        {
            dataActual[c] = c + i;
            dataExpected[c] = c + i;
        }

        appendChecksum(dataExpected, length);
        telemetryReporting_->addChecksum(dataActual, length - CHECK_SUM_LENGTH);
        ASSERT_THAT(std::vector<unsigned char>(dataActual, dataActual + length),
                    ElementsAreArray(std::vector<unsigned char>(dataExpected, dataExpected + length)));
    }
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
    const std::vector<std::tuple<bool*, int, std::vector<unsigned char>>> inputs =
    {
        std::make_tuple(inSingleTrue, sizeof(inSingleTrue) / sizeof(bool), expctSingleTrue),
        std::make_tuple(inSingleFalse, sizeof(inSingleFalse) / sizeof(bool), expctSingleFalse),
        std::make_tuple(input4, sizeof(input4) / sizeof(bool), expct4),
        std::make_tuple(input4inv, sizeof(input4inv) / sizeof(bool), expct4inv),
        std::make_tuple(input8, sizeof(input8) / sizeof(bool), expct8),
        std::make_tuple(input9, sizeof(input9) / sizeof(bool), expct9),
        std::make_tuple(inputsAllTrue, sizeof(inputsAllTrue) / sizeof(bool), expctAllTrue),
        std::make_tuple(inputsAllFalse, sizeof(inputsAllFalse) / sizeof(bool), expctAllFalse)
    };

    for (std::vector<std::tuple<bool*, int, std::vector<unsigned char>>>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        const bool* input = std::get<0>(*it);
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
                                       std::numeric_limits<float>::min(), std::numeric_limits<float>::max()
                                      };

    for (std::vector<float>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        const float input = *it;
        char* p = ( char*)((void*)&input);
        unsigned char actual[sizeof(float)];
        telemetryReporting_->writeFloatIntoArray(actual, 0, input);
        ASSERT_THAT(actual, ElementsAre(*p, *(p + 1), *(p + 2), *(p + 3)));
    }
}

// test may fail if short size is smaller than 16 bit!!
TEST_F(TelemetryReportingTest, writeShortIntoArrayTest)
{
    std::vector<short> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
                                 12416, 3264, 12825, 6, 31210 , 24,
                                 -42, -3512, -19921, -12, -400, -66, -235, -8773,
                                 -12416, -3264, -12825, -6, -31210 , -24,
                                 std::numeric_limits<short>::min() + 1, std::numeric_limits<short>::max() - 1,
                                 std::numeric_limits<short>::min(), std::numeric_limits<short>::max()
                                };
    short pot2 = 1;

    for (int i = 0; i < 16; i++)
    {
        inputs.push_back(pot2 - 1);
        inputs.push_back(pot2);
        pot2 *= 2;
    }

    for (std::vector<short>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        const short input = *it;
        char* p = ( char*)((void*)&input);
        unsigned char actual[sizeof(short)];
        telemetryReporting_->writeShortIntoArray(actual, 0, input);
        ASSERT_THAT(actual, ElementsAre(*p, *(p + 1)));
    }
}

// test may fail if short size is smaller than 16 bit!!
TEST_F(TelemetryReportingTest, writeUShortIntoArrayTest)
{
    std::vector<unsigned short> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
                                          12416, 3264, 12825, 6, 51210 , 24,
                                          std::numeric_limits<unsigned short>::min() + 1, std::numeric_limits<unsigned short>::max() - 1,
                                          std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max()
                                         };
    unsigned short pot2 = 1;

    for (int i = 0; i < 16; i++)
    {
        inputs.push_back(pot2 - 1);
        inputs.push_back(pot2);
        pot2 *= 2;
    }

    for (std::vector<unsigned short>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        const unsigned short input = *it;
        char* p = ( char*)((void*)&input);
        unsigned char actual[sizeof(unsigned short)];
        telemetryReporting_->writeUShortIntoArray(actual, 0, input);
        ASSERT_THAT(actual, ElementsAre(*p, *(p + 1)));
    }
}

// test may fail if uint size smaller than 32 bit!!
TEST_F(TelemetryReportingTest, writeUIntIntoArrayTest)
{
    std::vector<unsigned int> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
                                        1241632, 64128256, 5121024,
                                        std::numeric_limits<unsigned int>::min() + 1, std::numeric_limits<unsigned int>::max() - 1,
                                        std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max()
                                       };
    unsigned int pot2 = 1;

    for (int i = 0; i < 32; i++)
    {
        inputs.push_back(pot2 - 1);
        inputs.push_back(pot2);
        pot2 *= 2;
    }

    for (std::vector<unsigned int>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        const unsigned int input = *it;
        char* p = ( char*)((void*)&input);
        unsigned char actual[sizeof(unsigned int)];
        telemetryReporting_->writeUIntIntoArray(actual, 0, input);
        ASSERT_THAT(actual, ElementsAre(*p, *(p + 1), *(p + 2), *(p + 3)));
    }
}




