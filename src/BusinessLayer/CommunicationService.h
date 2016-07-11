#pragma once

#include <QObject>
#include <QSerialPort>
#include <SerialPortPeripheral.h>

class I_CommPeripheral;
class View;
class QIODevice;

class CommunicationService : public QObject
{
    Q_OBJECT
public:
    CommunicationService(View& view);
    I_CommPeripheral& getPeripheral();

private:
    void setPeripheralSerialPort();

public slots:
    void attemptConnection();

private:
    View& view_;
    QSerialPort* outputDevice_;
    I_CommPeripheral* outputPeripheral_;
};
