#pragma once

#include <QObject>

class I_CommunicationService : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CommunicationService() {};

    virtual void sendData(const unsigned char* packet, int packetLength) = 0;
};


