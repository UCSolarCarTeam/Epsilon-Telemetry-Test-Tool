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

public slots:
    void toggleSendContinuouslyText();

signals:
    void attemptConnectionSignal();
    void attemptDisconnectionSignal();
    void toggleSendContinuously();
    void setPacketNum(int packetNum);

private:
    QSignalMapper signalMapper;
    InternetWindow* window_;
    bool sendContinuously_;
};
