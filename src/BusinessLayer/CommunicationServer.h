#pragma once
class QString;
class QSerialPort;

/*
 *
 */
class CommunicationServer
{
public:
    CommunicationServer(QSerialPort& serialPort, QString portName);
    bool attemptConnection();
private:
    QSerialPort& serialPort_;

};
