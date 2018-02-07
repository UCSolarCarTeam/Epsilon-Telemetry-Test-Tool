#pragma once

#include "I_CommunicationService.h"
#include "InternetPeripheral.h"
#include "SerialPortPeripheral.h"

#include <QByteArray>
#include <QSerialPort>

class SerialView;
class InternetView;
class QIODevice;

class CommunicationService : public I_CommunicationService
{

public:
    CommunicationService(SerialView& serialView, InternetView& internetView);
    void sendSerialData(const unsigned char* packet, int packetLength);
    void sendInternetData(const QByteArray& data);

public slots:
    void attemptSerialConnection();
    void attemptSerialDisconnection();
    void attemptInternetConnection();
    void attemptInternetDisconnection();

private:
    SerialView& serialView_;
    InternetView& internetView_;
    SerialPortPeripheral serialPeripheral_;
    InternetPeripheral internetPeripheral_;
};
