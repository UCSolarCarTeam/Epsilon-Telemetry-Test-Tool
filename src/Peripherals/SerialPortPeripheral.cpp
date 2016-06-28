#include "SerialPortPeripheral.h"
#include <QSerialPort>
#include <QString>

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}

SerialPortPeripheral::SerialPortPeripheral(QSerialPort& serialPort)
: outputDevice_(serialPort)
{
    outputDevice_.setBaudRate(BAUDRATE);
}


SerialPortPeripheral::~SerialPortPeripheral()
{
}

void SerialPortPeripheral::setPortName(QString portName)
{
    outputDevice_.setPortName(portName);
}

void SerialPortPeripheral::sendData(const unsigned char* data, int length)
{
    for (int i = 0; i < length; ++i)
    {
       outputDevice_.putChar(data[i]);
    }
}

bool SerialPortPeripheral::attemptConnection()
{
   if (outputDevice_.open(QIODevice::ReadWrite))
   {
      return true;
   }
   else
   {
      return false;
   }
}
