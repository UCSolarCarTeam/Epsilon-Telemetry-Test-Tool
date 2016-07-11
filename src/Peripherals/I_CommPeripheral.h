#pragma once

class QString;

class I_CommPeripheral
{
public:
    virtual bool attemptConnection() = 0;
    virtual void setPortName(QString portname) = 0;
    virtual void sendData(const unsigned char* data, int length) = 0;
    virtual ~I_CommPeripheral(){}
};
