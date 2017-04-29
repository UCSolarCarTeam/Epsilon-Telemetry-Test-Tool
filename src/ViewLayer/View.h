#pragma once

#include <QObject>
#include <QSignalMapper>

class QSerialPort;
class Window;

class View : public QObject
{
    Q_OBJECT
public:
    View();
    void setConnectionStatus(bool connectionStatus);
    QString getCommunicationPort();

signals:
    void attemptConnectionSignal();
    void differentModeSelectedSignal();
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
    Window* window_;
    QSignalMapper signalMapper;
};
