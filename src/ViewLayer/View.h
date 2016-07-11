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
    void sendKeyDriverControlSignal();
    void sendDriverControlDetailsSignal();
    void sendFaultsSignal();
    void sendBatteryDataSignal();
    void sendCmuDataSignal();
    void sendMpptDataSignal();
    void sendAllSignal();


private:
    Window* window_;
};
