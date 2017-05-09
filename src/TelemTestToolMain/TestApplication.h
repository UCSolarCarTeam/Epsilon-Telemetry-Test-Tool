#pragma once

#include <QApplication>
#include <QScopedPointer>
#include "BatteryData.h"
#include "BatteryFaultsData.h"
#include "CommunicationService.h"
#include "DriverControlsData.h"
#include "InternetReporting.h"
#include "KeyMotorData.h"
#include "LightsData.h"
#include "MotorDetailsData.h"
#include "MotorFaultsData.h"
#include "MpptData.h"
#include "SerialReporting.h"
#include "SerialView.h"

class TestApplication : public QApplication
{
    Q_OBJECT
public:
    TestApplication(int& argc, char** argv);
    virtual ~TestApplication();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<MotorDetailsData> motor0DetailsData_;
    QScopedPointer<MotorDetailsData> motor1DetailsData_;
    QScopedPointer<DriverControlsData> driverControlsData_;
    QScopedPointer<MotorFaultsData> motorFaultsData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<BatteryData> batteryData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<SerialView> serialView_;
    QScopedPointer<CommunicationService> communicationService_;
    QScopedPointer<SerialReporting> serialReporting_;
    QScopedPointer<InternetReporting> internetReporting_;
};
