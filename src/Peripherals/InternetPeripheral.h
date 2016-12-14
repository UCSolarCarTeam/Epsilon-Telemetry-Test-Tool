#pragma once

#include "I_CommPeripheral.h"

class QStringList;
class QSerialPort;
class QByteArray;

class InternetPeripheral : public I_CommPeripheral
{
public:
    InternetPeripheral(/* parameters here */);
    virtual ~InternetPeripheral();
    bool attemptConnection();
    //Sets the port name to parameters[0]
    void setParameters(QStringList /*parameters*/);
    void sendInternetData(const QByteArray & /*JSON data in byte array*/);

private:

};
