#pragma once

#include <QObject>
#include <vector>
#include <QTimer>

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
class SerialView;
class DataContainer;

class SerialReporting : public QObject
{
    Q_OBJECT
public:
    SerialReporting(I_CommunicationService& commService,
                    DataContainer& dataContainer0_,
                    DataContainer& dataContainer1_,
                    SerialView& view);

public slots:
    void toggleSendContinuously();
    void sendKeyMotor();
    void sendMotorDetails(int n);
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendMppt();
    void sendLights();
    void sendAuxBms();
    void sendAll();
    void switchPacket();

private:
    I_CommunicationService& communicationService_;
    std::vector<DataContainer*> dataContainerList;
    SerialView& view_;
    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
    bool sendContinuously_;
    int packetNum_;
};
