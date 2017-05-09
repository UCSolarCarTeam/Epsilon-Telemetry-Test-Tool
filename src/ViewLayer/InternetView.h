#pragma once

#include <QObject>
#include <QSignalMapper>

class QInternetPort;
class InternetWindow;

class InternetView : public QObject
{
    Q_OBJECT
public:
    InternetView();
    void setConnectionStatus(bool connectionStatus);
    QString getPort();
    QString getIpAddress();

signals:
    void attemptConnectionSignal();
    void sendAll();

private:
    InternetWindow* window_;
    QSignalMapper signalMapper;
};
