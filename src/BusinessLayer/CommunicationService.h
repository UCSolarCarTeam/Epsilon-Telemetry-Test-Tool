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
    //gonna hardcode this as SerialPort type until i smooth things out
    QSerialPort* outputDevice_;
    PeripheralInterface* outputPeripheral_;
};
