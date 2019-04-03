#pragma once

#include <QObject>
#include <QSignalMapper>
#include <QTimer>
#include <vector>

class AuxBmsData;
class BatteryData;
class BatteryFaultsData;
class DriverControlsData;
class KeyMotorData;
class LightsData;
class MotorDetailsData;
class MotorFaultsData;
class MpptData;
class I_CommunicationService;
class InternetView;
class DataContainer;

class InternetReporting : public QObject
{
    Q_OBJECT
public:
    InternetReporting(I_CommunicationService& commService,
                      DataContainer& dataContainer0,
                      DataContainer& dataContainer1,
                      InternetView& view);

public slots:
    void toggleSendContinuously();
    void setPacketNum(int packetNum);
    void sendAll();

private:
    QJsonArray makeKeyMotor();
    QJsonObject makeMotorDetails(int n);
    QJsonObject makeDriverControls();
    QJsonArray makeMotorFaults();
    QJsonObject makeBatteryFaults();
    QJsonObject makeBattery();
    QJsonArray makeMppt();
    QJsonObject makeLights();
    QJsonObject makeAuxBms();

private:

    I_CommunicationService& communicationService_;
    std::vector<DataContainer*> dataContainerList;
    InternetView& view_;
    QSignalMapper signalMapper_;
    int packetNum_;
    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
    bool sendContinuously_;
};
