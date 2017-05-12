#pragma once

#include "I_CommunicationService.h"
#include "InternetPeripheral.h"
#include "SerialPortPeripheral.h"

#include <QByteArray>
#include <QSerialPort>

class SerialView;
class QIODevice;

class CommunicationService : public I_CommunicationService
{

public:
    CommunicationService(SerialView& view);
    void sendSerialData(const unsigned char* packet, int packetLength);
    void sendInternetData(const QByteArray& data);

private:
    void setPeripheralSerialPort();
    void setInternetConnection();

public slots:
    void attemptSerialConnection();
    void attemptInternetConnection();

private:
    SerialView& view_;
    QSerialPort* outputDevice_;
    SerialPortPeripheral* serialPeripheral_;
    InternetPeripheral* internetPeripheral_;
};
