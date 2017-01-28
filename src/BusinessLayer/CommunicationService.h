#pragma once

#include "I_CommunicationService.h"

#include <QSerialPort>
#include <QByteArray>
#include <SerialPortPeripheral.h>
#include <InternetPeripheral.h>

class View;
class QIODevice;

class CommunicationService : public I_CommunicationService
{

public:
    CommunicationService(View& view);
    void sendSerialData(const unsigned char* packet, int packetLength);
    void sendInternetData(const QByteArray& data);

private:
    void setPeripheralSerialPort();
    void setInternetConnection();

public slots:
    void attemptSerialConnection();
    void attemptInternetConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    SerialPortPeripheral* serialPeripheral_;
    InternetPeripheral* internetPeripheral_;
};
