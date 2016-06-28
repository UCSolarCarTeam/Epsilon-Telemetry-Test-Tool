#pragma once

class QIODevice;
class QString;

class PeripheralInterface
{
public:
    virtual bool attemptConnection()=0;
    virtual void setPortName(QString portname)=0;
    virtual void sendData(const unsigned char* data, int length)=0;
};
