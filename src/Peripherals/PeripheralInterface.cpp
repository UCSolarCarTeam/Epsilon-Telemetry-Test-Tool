#include "PeripheralInterface.h"
#include <QSerialPort>
#include <QIODevice>
#include <QString>

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}

PeripheralInterface::CommunicationPeripheral()
{

}
