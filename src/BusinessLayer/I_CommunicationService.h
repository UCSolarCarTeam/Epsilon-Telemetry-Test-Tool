#pragma once

#include <QObject>
//#include <QSerialPort>
//#include <SerialPortPeripheral.h>

class I_CommunicationService : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CommunicationService() {};

    virtual void sendData(const unsigned char* packet, int packetLength) = 0; // TODO this method should / could be const?

//public slots:
//    virtual void attemptConnection();

};


