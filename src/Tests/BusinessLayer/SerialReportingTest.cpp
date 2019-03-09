#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <vector>
#include <tuple>

#include "DataContainer.h"
#include "AuxBmsData.h"
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
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_BATTERY = 52;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_MPPT = 14;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_LIGHTS = 7;
    const unsigned int EXPECTED_PACKAGE_LENGTH_SEND_AUX_BMS = 12;

    const int ONES_TO_MILLI = 1000;
    const int ONES_TO_CENTI = 100;

}


class SerialReportingTest : public ::testing::Test
{

protected:

    QScopedPointer<MockCommunicationService> communicationService_;
    QScopedPointer<DataContainer> dataContainer_;
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<MotorDetailsData> motor0DetailsData_;
    QScopedPointer<MotorDetailsData> motor1DetailsData_;
    QScopedPointer<DriverControlsData> driverControlsData_;
    QScopedPointer<MotorFaultsData> motorFaultsData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<BatteryData> batteryData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<AuxBmsData> auxBmsData_;
    QScopedPointer<SerialView> view;

    QScopedPointer<SerialReporting> telemetryReporting_;

    virtual void SetUp()
    {
        communicationService_.reset(new MockCommunicationService());
        dataContainer_.reset(new DataContainer());
        keyMotorData_.reset(new KeyMotorData());
        motor0DetailsData_.reset(new MotorDetailsData());
        motor1DetailsData_.reset(new MotorDetailsData());
        driverControlsData_.reset(new DriverControlsData());
        motorFaultsData_.reset(new MotorFaultsData());
        batteryFaultsData_.reset(new BatteryFaultsData);
        batteryData_.reset(new BatteryData());
        mpptData_.reset(new MpptData());
        lightsData_.reset(new LightsData());
        auxBmsData_.reset(new AuxBmsData());
        view.reset(new SerialView(new SerialWindow()));
        telemetryReporting_.reset(new SerialReporting(*communicationService_,
                                                      *dataContainer_,
                                                      *dataContainer_,
                                                      *view));
    }

    inline unsigned char fitTwoSingleUChar(unsigned char bit0To3, unsigned char bit4To7) const
    {
        unsigned char ret = (bit4To7 << 4) | (bit0To3 & 0x0F);
        return ret;
    }

    void fillMpptData(unsigned char* data) const
       {
           data[0] = CcsDefines::MPPT_PKG_ID;
           unsigned char numberAndAlive = mpptData_->mpptNumber() & 0x3;

           if (mpptData_->alive(mpptData_->mpptNumber()))
           {
               numberAndAlive |= 0x80;
           }

           data[1] = numberAndAlive;
           Util::writeUShortIntoArray(data, 2, mpptData_->arrayVoltage(mpptData_->mpptNumber()) * ONES_TO_CENTI);
           Util::writeUShortIntoArray(data, 4, mpptData_->arrayCurrent(mpptData_->mpptNumber()) * ONES_TO_MILLI);
           Util::writeUShortIntoArray(data, 6, mpptData_->batteryVoltage(mpptData_->mpptNumber()) * ONES_TO_CENTI);
           Util::writeUShortIntoArray(data, 8, mpptData_->temperature(mpptData_->mpptNumber()) * ONES_TO_CENTI);
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
    EXPECT_CALL(*communicationService_, sendSerialData(_, EXPECTED_PACKAGE_LENGTH_SEND_AUX_BMS)).With(Args<0, 1>(packageIdIs(11))).Times(1);
    // actually call the method under test through qt's signal/slot mechanism
    view->sendAll();
}



