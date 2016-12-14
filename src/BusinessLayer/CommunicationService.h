#pragma once

#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <SerialPortPeripheral.h>
#include <InternetPeripheral.h>

class I_CommPeripheral;
class View;
class QIODevice;

class CommunicationService : public QObject
{
    Q_OBJECT
public:
    CommunicationService(View& view);
    void sendSerialData(const unsigned char* packet, int packetLength);
    void sendInternetData(const QByteArray &data);
private:
    void setPeripheralSerialPort();

public slots:
    void attemptConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    SerialPortPeripheral* outputPeripheral_;
};
