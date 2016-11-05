#pragma once

#include <QApplication>
#include <QScopedPointer>
#include "TelemetryReporting.h"
#include "InternetReporting.h"
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
#include "CommunicationService.h"

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
    QScopedPointer<CmuData> cmuData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<View> view_;
    QScopedPointer<CommunicationService> communicationService_;
    QScopedPointer<TelemetryReporting> telemetryReporting_;
    QScopedPointer<InternetReporting> internetReporting_;
};
