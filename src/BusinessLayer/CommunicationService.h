#pragma once

#include "I_CommunicationService.h"

#include <QSerialPort>
#include <SerialPortPeripheral.h>

class I_CommPeripheral;
class View;
class QIODevice;

class CommunicationService : public I_CommunicationService
{

public:
    CommunicationService(View& view);
    void sendData(const unsigned char* packet, int packetLength);

private:
    void setPeripheralSerialPort();

public slots:
    void attemptConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    I_CommPeripheral* outputPeripheral_;
};
