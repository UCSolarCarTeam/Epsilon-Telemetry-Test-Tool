#pragma once

class QStringList;
class QSerialPort;

class SerialPortPeripheral
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    virtual ~SerialPortPeripheral();
    bool attemptConnection();
    //Sets the port name to parameters[0]
    void setParameters(QStringList parameters);
    void sendSerialData(const unsigned char* data, int length);

private:
    QSerialPort& serialPort_;
};
