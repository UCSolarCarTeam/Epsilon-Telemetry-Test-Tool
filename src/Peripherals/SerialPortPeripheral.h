#pragma once
class QString;
class QSerialPort;

/*
 *
 */
class SerialPortPeripheral
{
public:
    SerialPortPeripheral(QSerialPort& serialPort, QString portName);
    bool attemptConnection();
private:
    QSerialPort& serialPort_;
};
