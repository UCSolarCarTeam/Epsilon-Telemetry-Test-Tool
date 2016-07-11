#pragma once

#include "I_CommPeripheral.h"

class QString;
class QSerialPort;

class SerialPortPeripheral : public I_CommPeripheral
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    virtual ~SerialPortPeripheral();
    bool attemptConnection();
    void setPortName(QString portName);
    void sendData(const unsigned char* data, int length);

private:
    QSerialPort& serialPort_;
};
