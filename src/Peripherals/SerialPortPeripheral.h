#pragma once

class QString;
class QSerialPort;
class PeripheralInterface;

class SerialPortPeripheral : PeripheralInterface
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    bool attemptConnection();
    void setPortName(QString portName);
    void sendData(const unsigned char* data, int length);
};
