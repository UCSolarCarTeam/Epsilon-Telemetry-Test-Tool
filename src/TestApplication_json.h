#pragma once

#include <QApplication>
#include <QScopedPointer>
#include "TelemetryReporting_json.h"
#include "KeyMotorData.h"
#include "MotorDetailsData.h"
#include "DriverControlsData.h"
#include "MotorFaultsData.h"
#include "BatteryFaultsData.h"
#include "BatteryData_json.h"
#include "CmuData.h"
#include "MpptData.h"
#include "LightsData.h"
#include "View.h"
#include "CommunicationService_json.h"

class TestApplication_json : public QApplication
{
    Q_OBJECT
public:
    TestApplication_json(int& argc, char** argv);
    virtual ~TestApplication_json();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<MotorDetailsData> motor0DetailsData_;
    QScopedPointer<MotorDetailsData> motor1DetailsData_;
    QScopedPointer<DriverControlsData> driverControlsData_;
    QScopedPointer<MotorFaultsData> motorFaultsData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<BatteryData_json> batteryData_json_;
    QScopedPointer<CmuData> cmuData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<LightsData> lightsData_;
    QScopedPointer<View> view_;
    QScopedPointer<CommunicationService_json> communicationService_json_;
    QScopedPointer<TelemetryReporting_json> telemetryReporting_json_;


};




