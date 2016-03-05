#include "CommunicationServer.h"
#include <QSerialPort>
#include <QString>

/*
 *
 */
namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}
CommunicationServer::CommunicationServer(QSerialPort& serialPort, QString portName)
: serialPort_(serialPort)
{
    serialPort_.setPortName(portName);
    serialPort_.setBaudRate(BAUDRATE);
}

bool CommunicationServer::attemptConnection()
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
