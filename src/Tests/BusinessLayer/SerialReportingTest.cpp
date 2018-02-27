#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <vector>
#include <tuple>

#include "BatteryFaultsData.h"
#include "BatteryData.h"
#include "DriverControlsData.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MockCommunicationService.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "SerialReporting.h"
#include "TestUtils.h"
#include "Util.h"
#include "SerialView.h"
#include "SerialWindow.h"

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
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS = 69;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_DRIVER_CONTROLS = 13;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS = 13;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS = 10;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_BATTERY = 58;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MPPT = 14;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS = 7;
}


class SerialReportingTest : public ::testing::Test
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
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<SerialView> view;

    QScopedPointer<SerialReporting> telemetryReporting_;

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
        mpptData_.reset(new MpptData());
        lightsData_.reset(new LightsData());
        view.reset(new SerialView(new SerialWindow()));
        telemetryReporting_.reset(new SerialReporting(*communicationService_,
                                  *keyMotorData_,
                                  *motor0DetailsData_,
                                  *motor1DetailsData_,
                                  *driverControlsData_,
                                  *motorFaultsData_,
                                  *batteryFaultsData_,
                                  *batteryData_,
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
        explicit PackageIdMatcher(unsigned char expectedId, SerialReportingTest& containingTest)
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
        const SerialReportingTest& containingTest_;
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
TEST_F(SerialReportingTest, sendKeyMotorTest) // TODO create function which build the actual package to create more test cases in a easy way ...
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
    const unsigned char aliveBitMotor0Enconding = keyMotorData_->motor0Alive ? 0x01 : 0x00;
    const unsigned char aliveBitMotor1Enconding = keyMotorData_->motor1Alive ? 0x01 : 0x00;
    ASSERT_THAT(data[1], Eq(aliveBitMotor0Enconding));
    ASSERT_THAT(data[22], Eq(aliveBitMotor1Enconding));

    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendKeyMotor();
}

/*
 * This test tests for the correct structure of the sendMotorDetails package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendMotorDetailsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // create payload for motor 0 details
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
    Util::writeFloatIntoArray(data, 25, motor0DetailsData_->BackEmf);
    Util::writeFloatIntoArray(data, 29, motor0DetailsData_->RailSupply15V);
    Util::writeFloatIntoArray(data, 33, motor0DetailsData_->RailSupply3V);
    Util::writeFloatIntoArray(data, 37, motor0DetailsData_->RailSupply1V);
    Util::writeFloatIntoArray(data, 41, motor0DetailsData_->heatSinkTemperature);
    Util::writeFloatIntoArray(data, 45, motor0DetailsData_->motorTemperature);
    Util::writeFloatIntoArray(data, 49, motor0DetailsData_->dspBoardTemperature);
    Util::writeFloatIntoArray(data, 53, motor0DetailsData_->dcBusAmpHours);
    Util::writeFloatIntoArray(data, 57, motor0DetailsData_->odometer);
    Util::writeFloatIntoArray(data, 61, motor0DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x02)); // packet id
    unsigned char expectedPacket0[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket0);
    // check call
    const auto expectedPacket0AsArg = Args<0, 1>(ElementsAreArray(expectedPacket0, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacket0AsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendMotorDetails(0);

    // create payload for motor 1 details
    data[0] = CcsDefines::MOTOR_DETAILS_1_PKG_ID;
    Util::writeFloatIntoArray(data, 1, motor1DetailsData_->phaseCCurrent);
    Util::writeFloatIntoArray(data, 5, motor1DetailsData_->phaseBCurrent);
    Util::writeFloatIntoArray(data, 9, motor1DetailsData_->MotorVoltageReal);
    Util::writeFloatIntoArray(data, 13, motor1DetailsData_->MotorVoltageImaginary);
    Util::writeFloatIntoArray(data, 17, motor1DetailsData_->MotorCurrentReal);
    Util::writeFloatIntoArray(data, 21, motor1DetailsData_->MotorCurrentImaginary);
    Util::writeFloatIntoArray(data, 25, motor1DetailsData_->BackEmf);
    Util::writeFloatIntoArray(data, 29, motor1DetailsData_->RailSupply15V);
    Util::writeFloatIntoArray(data, 33, motor1DetailsData_->RailSupply3V);
    Util::writeFloatIntoArray(data, 37, motor1DetailsData_->RailSupply1V);
    Util::writeFloatIntoArray(data, 41, motor1DetailsData_->heatSinkTemperature);
    Util::writeFloatIntoArray(data, 45, motor1DetailsData_->motorTemperature);
    Util::writeFloatIntoArray(data, 49, motor1DetailsData_->dspBoardTemperature);
    Util::writeFloatIntoArray(data, 53, motor1DetailsData_->dcBusAmpHours);
    Util::writeFloatIntoArray(data, 57, motor1DetailsData_->odometer);
    Util::writeFloatIntoArray(data, 61, motor1DetailsData_->slipSpeed);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x03)); // packet id
    unsigned char expectedPacket1[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket1);
    const auto expectedPacket1AsArg = Args<0, 1>(ElementsAreArray(expectedPacket1, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacket1AsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendMotorDetails(1);
}

/*
 * This test tests for the correct structure of the sendDriverControls package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendDriverControlsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
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
                            driverControlsData_->signalRight,
                            driverControlsData_->signalLeft,
                            driverControlsData_->hazardLights,
                            driverControlsData_->interiorLights
                          };
    Util::writeBoolsIntoArray(data, 2, lightsInputs, 7);
    bool musicInputs[] = { driverControlsData_->volumeUp,
                           driverControlsData_->volumeDown,
                           driverControlsData_->nextSong,
                           driverControlsData_->prevSong
                         };
    Util::writeBoolsIntoArray(data, 3, musicInputs, 4);
    Util::writeUShortIntoArray(data, 4, driverControlsData_->acceleration);
    Util::writeUShortIntoArray(data, 6, driverControlsData_->regenBraking);
    bool driverInputs[] = { driverControlsData_->brakes,
                            driverControlsData_->forward,
                            driverControlsData_->reverse,
                            driverControlsData_->pushToTalk,
                            driverControlsData_->horn,
                            driverControlsData_->reset,
                            driverControlsData_->aux
                          };
    Util::writeBoolsIntoArray(data, 8, driverInputs, 7);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x04)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendDriverControls();
}

/*
 * This test tests for the correct structure of the sendMotorFaults package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendMotorFaultsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::MOTOR_FAULTS_PKG_ID;
    bool motor0ErrorFlags[] = { motorFaultsData_->motor0OverSpeed,
                                motorFaultsData_->motor0SoftwareOverCurrent,
                                motorFaultsData_->motor0DcBusOverVoltage,
                                motorFaultsData_->motor0BadMotorPositionHallSequence,
                                motorFaultsData_->motor0WatchdogCausedLastReset,
                                motorFaultsData_->motor0ConfigReadError,
                                motorFaultsData_->motor0Rail15VUnderVoltageLockOut,
                                motorFaultsData_->motor0DesaturationFault
                              };
    Util::writeBoolsIntoArray(data, 1, motor0ErrorFlags, 8);
    bool motor1ErrorFlags[] = { motorFaultsData_->motor1OverSpeed,
                                motorFaultsData_->motor1SoftwareOverCurrent,
                                motorFaultsData_->motor1DcBusOverVoltage,
                                motorFaultsData_->motor1BadMotorPositionHallSequence,
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
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendMotorFaults();
}

/*
 * This test tests for the correct structure of the sendBatteryFaults package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendBatteryFaultsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::BATTERY_FAULTS_PKG_ID;
    bool errorFlagsArray[] = {batteryFaultsData_ ->internalCommFault,
                              batteryFaultsData_ ->internalConversionFault,
                              batteryFaultsData_->weakCellFault,
                              batteryFaultsData_->lowCellVoltageFault,
                              batteryFaultsData_->openWiringFault,
                              batteryFaultsData_->currentSensorFault,
                              batteryFaultsData_->packVoltageSensorFault,
                              batteryFaultsData_->weakPackFault,
                              batteryFaultsData_->voltageRedundancyFault,
                              batteryFaultsData_->fanMonitorFault,
                              batteryFaultsData_->thermistorFault,
                              batteryFaultsData_->canbusCommsFault,
                              batteryFaultsData_->alwaysOnSupplyFault,
                              batteryFaultsData_->highVoltageIsolationFault,
                              batteryFaultsData_->powerSupplyFault,
                              batteryFaultsData_->chargeLimitFault,
                              batteryFaultsData_->dischargeLimitFault,
                              batteryFaultsData_->chargerSafetyRelayFault,
                              batteryFaultsData_->internalMemFault,
                              batteryFaultsData_->internalThermistorFault,
                              batteryFaultsData_->internalLogicFault
                             };
    Util::writeBoolsIntoArray(data, 1, errorFlagsArray, 21);
    bool limitFlagsArray[] = {batteryFaultsData_->dclReducedLowSoc,
                              batteryFaultsData_->dclReducedHighCellResist,
                              batteryFaultsData_->dclReducedDueToTemp,
                              batteryFaultsData_->dclReducedLowCellVoltage,
                              batteryFaultsData_->dclReducedLowPackVoltage,
                              CcsDefines::NO_DATA,
                              batteryFaultsData_->dclCclReducedVoltageFailsafe,
                              batteryFaultsData_->dclCclReducedCommsFailsafe,
                              CcsDefines::NO_DATA,
                              batteryFaultsData_->cclReducedHighSoc,
                              batteryFaultsData_->cclReducedHighCellResist,
                              batteryFaultsData_->cclReducedDueToTemp,
                              batteryFaultsData_->cclReducedHighCellVoltage,
                              batteryFaultsData_->cclReducedHighPackVoltage,
                              batteryFaultsData_->cclReducedChargerLatch,
                              batteryFaultsData_->cclReducedACLimit
                             };
    Util::writeBoolsIntoArray(data, 4, limitFlagsArray, 16);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    // checking that the data members before and after the NO_DATA is correct
    ASSERT_THAT(data[0], Eq(0x06)); // packet id
    ASSERT_THAT(((data[4] & 0x10) == 0x10), batteryFaultsData_->dclReducedLowPackVoltage);
    ASSERT_THAT(((data[4] & 0x40) == 0x40), batteryFaultsData_->dclCclReducedVoltageFailsafe);
    ASSERT_THAT(((data[4] & 0x80) == 0x80), batteryFaultsData_->dclCclReducedCommsFailsafe);
    ASSERT_THAT(((data[5] & 0x02) == 0x02), batteryFaultsData_->cclReducedHighSoc);
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendBatteryFaults();
}

/*
 * This test tests for the correct structure of the sendBattery package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendBatteryTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_BATTERY;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::BATTERY_PKG_ID;
    bool aliveArray[] = {batteryData_->alive};
    Util::writeBoolsIntoArray(data, 1, aliveArray, 1);
    bool bmsRelayStatusArray[] = {batteryData_->dischargeRelayEnabled,
                                  batteryData_->chargeRelayEnabled,
                                  batteryData_->chargerSafetyEnabled,
                                  batteryData_->malfunctionIndicatorActive,
                                  batteryData_->multiPurposeInputSignalStatus,
                                  batteryData_->alwaysOnSignalStatus,
                                  batteryData_->isReadySignalStatus,
                                  batteryData_->isChargingSignalStatus
                                 };
    Util::writeBoolsIntoArray(data, 2, bmsRelayStatusArray, 8);
    data[3] = batteryData_->populatedCells;
    Util::writeFloatIntoArray(data, 4, batteryData_->inputVoltage12V);
    Util::writeFloatIntoArray(data, 8, batteryData_->fanVoltage);
    Util::writeFloatIntoArray(data, 12, batteryData_->packCurrent);
    Util::writeFloatIntoArray(data, 16, batteryData_->packVoltage);
    Util::writeFloatIntoArray(data, 20, batteryData_->packStateOfCharge);
    Util::writeFloatIntoArray(data, 24, batteryData_->packAmpHours);
    Util::writeFloatIntoArray(data, 28, batteryData_->packDepthOfDischarge);
    data[32] = batteryData_->highTemperature;
    data[33] = batteryData_->highThermistorId;
    data[34] = batteryData_->lowTemperature;
    data[35] = batteryData_->lowThermistorId;
    data[36] = batteryData_->averageTemperature;
    data[37] = batteryData_->internalTemperature;
    data[38] = batteryData_->fanSpeed;
    data[39] = batteryData_->requestedFanSpeed;
    Util::writeUShortIntoArray(data, 40, batteryData_->lowCellVoltage);
    data[42] = batteryData_->lowCellVoltageId;
    Util::writeUShortIntoArray(data, 43, batteryData_->highCellVoltage);
    data[45] = batteryData_->highCellVoltageId;
    Util::writeUShortIntoArray(data, 46, batteryData_->averageCellVoltage);
    data[48] = batteryData_->prechargeState;
    data[49] = (unsigned char)batteryData_->auxVoltage;
    bool auxBmsAliveArray[] = {batteryData_->auxBmsAlive};
    Util::writeBoolsIntoArray(data, 50, auxBmsAliveArray, 1);
    bool strobeBmsLightArray[] = {batteryData_->strobeBmsLight};
    Util::writeBoolsIntoArray(data, 51, strobeBmsLightArray, 1);
    bool allowChargeArray[] = {batteryData_->strobeBmsLight};
    Util::writeBoolsIntoArray(data, 52, allowChargeArray, 1);
    bool contactorErrorArray[] = {batteryData_->allowCharge};
    Util::writeBoolsIntoArray(data, 53, contactorErrorArray, 1);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x07)); // packet id
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    // check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendBattery();
}

/*
 * This test tests for the correct structure of the sendMppt package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendMpptTest)
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
            EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);
        }

        // actually call the method under test through qt's signal/slot mechanism
        view->sendMppt();
    }
}

/*
 * This test tests for the correct structure of the sendLights package as defined in
 * https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=782574835
 *
 * The stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendLightsTest) // TODO create function which build the actual package to create more test cases in a easy way ...
{
    // prepare payload
    const unsigned int expectedPackageLength = EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS;
    const unsigned int payloadLength = expectedPackageLength - COBS_ADDITIONAL_FRAME_DATA_SIZE;
    unsigned char data[payloadLength];
    data[0] = CcsDefines::LIGHTS_PKG_ID;
    bool lightsAliveArray[] = {lightsData_->alive};
    Util::writeBoolsIntoArray(data, 1, lightsAliveArray, 1);
    bool lightsStatus[] = {lightsData_->lowBeams,
                           lightsData_->highBeams,
                           lightsData_->brakes,
                           lightsData_->leftSignal,
                           lightsData_->rightSignal,
                           lightsData_->bmsStrobeLight
                          };
    Util::writeBoolsIntoArray(data, 2, lightsStatus, 6);
    appendChecksum(data, payloadLength);
    // do some additional data checks
    ASSERT_THAT(data[0], Eq(0x0A)); // packet id
    ASSERT_THAT(((data[1] & 0x01) == 0x01), lightsData_->alive);
    ASSERT_THAT(((data[2] & 0x01) == 0x01), lightsData_->lowBeams);
    ASSERT_THAT(((data[2] & 0x02) == 0x02), lightsData_->highBeams);
    ASSERT_THAT(((data[2] & 0x04) == 0x04), lightsData_->brakes);
    ASSERT_THAT(((data[2] & 0x08) == 0x08), lightsData_->leftSignal);
    ASSERT_THAT(((data[2] & 0x10) == 0x10), lightsData_->rightSignal);
    ASSERT_THAT(((data[2] & 0x20) == 0x20), lightsData_->bmsStrobeLight);
    unsigned char expectedPacket[expectedPackageLength];
    Util::frameData(data, payloadLength, expectedPacket);
    //check call
    const auto expectedPacketAsArg = Args<0, 1>(ElementsAreArray(expectedPacket, expectedPackageLength));
    EXPECT_CALL(*communicationService_, sendSerialData(_, expectedPackageLength)).With(expectedPacketAsArg).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendLights();
}

/*
 * This test tests if during sendAll all methods which send a message are called.
 *
 * The actual methods, stuffing, framing and conversion is assumed to work correctly here. These methods are tested
 * separately.
 */
TEST_F(SerialReportingTest, sendAllTest)
{
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_KEY_MOTOR)).With(Args<0, 1>(packageIdIs(1))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS)).With(Args<0, 1>(packageIdIs(2))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_DETAILS)).With(Args<0, 1>(packageIdIs(3))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_DRIVER_CONTROLS)).With(Args<0, 1>(packageIdIs(4))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_MOTOR_FAULTS)).With(Args<0, 1>(packageIdIs(5))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_BATTERY_FAULTS)).With(Args<0, 1>(packageIdIs(6))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_BATTERY)).With(Args<0, 1>(packageIdIs(7))).Times(1);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_MPPT)).With(Args<0, 1>(packageIdIs(9))).Times(CcsDefines::MPPT_COUNT);
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS)).With(Args<0, 1>(packageIdIs(10))).Times(1);

    // actually call the method under test through qt's signal/slot mechanism
    view->sendAll();
}



