#pragma once

#include <QObject>
#include <QSerialPort>
#include <SerialPortPeripheral.h>

class PeripheralInterface;
class View;
class QIODevice;

class CommunicationService : public QObject
{
    Q_OBJECT
public:
    CommunicationService(View& view);
    PeripheralInterface& getPeripheral();

private:
    void setPeripheralSerialPort();

public slots:
    void attemptConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    PeripheralInterface* outputPeripheral_;
};
