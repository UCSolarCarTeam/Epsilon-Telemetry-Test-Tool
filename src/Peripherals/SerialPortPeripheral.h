#pragma once

#include <QSerialPort>

class SerialPortPeripheral
{
public:
    SerialPortPeripheral();
    virtual ~SerialPortPeripheral() {}
    bool attemptConnection(QString portname);
    bool attemptDisconnection();
    void sendSerialData(const unsigned char* data, int length);

private:
    QSerialPort serialPort_;
};
