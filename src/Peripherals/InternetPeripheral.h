#pragma once

#include "I_CommPeripheral.h"

class QStringList;
class QSerialPort;
class QByteArray;

class InternetPeripheral : public I_CommPeripheral
{
public:
    InternetPeripheral();
    virtual ~InternetPeripheral();
    bool attemptConnection();
    void setParameters(QStringList /*params*/);
    void sendInternetData(const QByteArray & /*data*/);

private:

};
