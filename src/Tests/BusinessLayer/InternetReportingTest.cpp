#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
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
#include "InternetReporting.h"
#include "TestUtils.h"
#include "Util.h"
#include "InternetView.h"
#include "InternetWindow.h"

class InternetReportingTest : public ::testing::Test
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
    QScopedPointer<InternetView> view;

    QScopedPointer<InternetReporting> telemetryReporting_;

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
        view.reset(new InternetView(new InternetWindow()));
        telemetryReporting_.reset(new InternetReporting(*communicationService_,
                                  *keyMotorData_,
                                  *motor0DetailsData_,
                                  *motor1DetailsData_,
                                  *driverControlsData_,
                                  *motorFaultsData_,
                                  *batteryFaultsData_,
                                  *batteryData_,
                                  *mpptData_,
                                  *lightsData_,
                                  *view));
    }
};

TEST_F(InternetReportingTest, packetTitleTest)
{

    const auto expected = "UofC Solar Car Gen 5";
    EXPECT_CALL(*communicationService_, sendInternetData(expectedPackageLength))
    .With(expectedPacketAsArg).Times(1);

    view->sendAll();
}