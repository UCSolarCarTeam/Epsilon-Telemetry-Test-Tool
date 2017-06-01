#pragma once

#include <QObject>
#include <QSignalMapper>

class InternetWindow;

class InternetView : public QObject
{
    Q_OBJECT
public:
    InternetView(InternetWindow* window);
    void setConnectionStatus(bool connectionStatus);
    QString getIpAddress();
    unsigned short getPort();
    QString getExchangeName();
    QString getRoutingKey();

signals:
    void attemptConnectionSignal();
    void sendAll();

private:
    InternetWindow* window_;
};
