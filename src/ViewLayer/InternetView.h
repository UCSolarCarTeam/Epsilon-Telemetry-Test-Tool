#pragma once

#include <QObject>
#include <QSignalMapper>

class InternetWindow;

class InternetView : public QObject
{
    Q_OBJECT
public:
    InternetView(InternetWindow* window);
    void setConnectionStatus(bool connectionStatus, bool attemptToConnect);
    QString getIpAddress();
    unsigned short getPort();
    QString getExchangeName();
    QString getRoutingKey();

signals:
    void attemptConnectionSignal();
    void attemptDisconnectionSignal();
    void sendAll(int packetNum);

private:
    QSignalMapper signalMapper;
    InternetWindow* window_;
};
