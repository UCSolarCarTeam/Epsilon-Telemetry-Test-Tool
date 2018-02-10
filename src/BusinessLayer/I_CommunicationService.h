#pragma once

#include <QByteArray>
#include <QObject>

class I_CommunicationService : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CommunicationService() {}

    virtual void sendSerialData(const unsigned char* packet, int packetLength) = 0;
    virtual void sendInternetData(const QByteArray& data) = 0;

public slots:
    virtual void attemptSerialConnection() = 0;
    virtual void attemptSerialDisconnection() = 0;
    virtual void attemptInternetConnection() = 0;
    virtual void attemptInternetDisconnection() = 0;
};


