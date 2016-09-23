#pragma once

#include <QObject>

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
    void sendMotor0Details();
    void sendMotor1Details();
    void sendDriverControls();
    void sendMotorFaults();
    void sendBatteryFaults();
    void sendBattery();
    void sendCmu();
    void sendMppt();
    void sendLights();
    void sendAll();

private:
    Window* window_;
};
