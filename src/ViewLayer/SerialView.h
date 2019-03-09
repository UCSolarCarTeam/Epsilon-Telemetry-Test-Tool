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
    void setConnectionStatus(bool connectionStatus, bool attemptToConnect);
    void setPacketText(bool packet0);
    QString getCommunicationPort();

signals:
    void attemptConnectionSignal();
    void attemptDisconnectionSignal();
    void sendAll();
    void switchPacket();

private:
    QSignalMapper signalMapper;
    SerialWindow* window_;
};
