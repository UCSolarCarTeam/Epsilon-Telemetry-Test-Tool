#pragma once

#include "PeripheralInterface.h"

class QString;
class QSerialPort;

class SerialPortPeripheral : public PeripheralInterface
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    virtual ~SerialPortPeripheral();
    bool attemptConnection();
    void setPortName(QString portName);
    void sendData(const unsigned char* data, int length);

private:
    QSerialPort& outputDevice_;
};
