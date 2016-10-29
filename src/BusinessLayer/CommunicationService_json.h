#pragma once

#include <QObject>
#include <QSerialPort>
#include <SerialPortPeripheral.h>

class I_CommPeripheral;
class View;
class QIODevice;
class QByteArray;

class CommunicationService_json : public QObject
{
    Q_OBJECT
public:
    CommunicationService_json(View& view);
    void sendData(const QByteArray &data);
private:
    void setPeripheralSerialPort();

public slots:
    void attemptConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    I_CommPeripheral* outputPeripheral_;
};
