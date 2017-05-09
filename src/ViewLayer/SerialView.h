#pragma once

#include <QObject>
#include <QSignalMapper>

class QSerialPort;
class SerialWindow;

class SerialView : public QObject
{
    Q_OBJECT
public:
    SerialView();
    void setConnectionStatus(bool connectionStatus);
    QString getCommunicationPort();

signals:
    void attemptConnectionSignal();
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
    SerialWindow* window_;
    QSignalMapper signalMapper;
};
