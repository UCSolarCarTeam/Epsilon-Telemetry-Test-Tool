#pragma once

#include <QObject>
#include <QSignalMapper>

class QSerialPort;
class SerialWindow;

class SerialView : public QObject
{
    Q_OBJECT
public:
    SerialView(SerialWindow* window);
    void setConnectionStatus(bool connectionStatus, int n);
    QString getCommunicationPort();

signals:
    void attemptConnectionSignal();
    void attemptDisconnectionSignal();
    void sendKeyMotor();
    void sendMotorDetails(int n);
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendMppt();
    void sendLights();
    void sendAll();

private:
    QSignalMapper signalMapper;
    SerialWindow* window_;
};
