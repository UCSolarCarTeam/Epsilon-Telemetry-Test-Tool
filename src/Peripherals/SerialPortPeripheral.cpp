#include "SerialPortPeripheral.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_MPPTS = 7;
}

SerialPortPeripheral::SerialPortPeripheral()
{
    serialPort_.setBaudRate(BAUDRATE);
}

void SerialPortPeripheral::sendSerialData(const unsigned char* data, int length)
{
    for (int i = 0; i < length; ++i)
    {
        serialPort_.putChar(data[i]);
    }
}

bool SerialPortPeripheral::attemptConnection(QString portname)
{
    serialPort_.setPortName(portname);

    if (serialPort_.open(QIODevice::ReadWrite))
    {
        return true;
    }
    else
    {
        return false;
    }
}

