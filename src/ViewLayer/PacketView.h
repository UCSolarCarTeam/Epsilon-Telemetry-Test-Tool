#pragma once

#include <QObject>
#include <QSignalMapper>

class PacketWindow;

class PacketView : public QObject
{
    Q_OBJECT
public:
    PacketView(PacketWindow* window);

signals:

private:
    PacketWindow* window_;
};
