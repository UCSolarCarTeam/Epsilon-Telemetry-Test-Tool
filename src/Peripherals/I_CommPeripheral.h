#pragma once

class QStringList;

class I_CommPeripheral
{
public:
    virtual bool attemptConnection() = 0;
    virtual void setParameters(QStringList parameters) = 0;
    virtual void sendData() {}
    virtual ~I_CommPeripheral() {}
};
