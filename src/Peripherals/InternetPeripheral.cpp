#include <QSerialPort>
#include <QStringList>
#include "InternetPeripheral.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}

InternetPeripheral::InternetPeripheral(QSerialPort& serialPort)
    : serialPort_(serialPort)
{
    serialPort_.setBaudRate(BAUDRATE);
}


InternetPeripheral::~InternetPeripheral()
{
}

void InternetPeripheral::setParameters(QStringList parameters)
{
    serialPort_.setPortName(parameters.at(0));
}


bool InternetPeripheral::attemptConnection()
{
    if (serialPort_.open(QIODevice::ReadWrite))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InternetPeripheral::sendInternetData(const QByteArray &data){
    serialPort_.write(data);
}
