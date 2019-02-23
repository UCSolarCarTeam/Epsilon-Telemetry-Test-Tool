#pragma once

#include "MessageStates.h"

#include <QObject>
#include <vector>

#include <QTimer>
#include <QDebug>

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

    void sendData();
    void setKeyMotor();
    void setMotorDetails(int n);
    void setDriverControls();
    void setMotorFaults();
    void setBatteryFaults();
    void setBattery();
    void setMppt();
    void setLights();
    void setAuxBms();
    void setAll();

private:

    void startSendingData();
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

    I_CommunicationService& communicationService_;
    std::vector<DataContainer*> dataContainerList;
    SerialView& view_;
    int packetNum;

    MessageStates::MESSAGE_SENDING messageState_;

    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
};
