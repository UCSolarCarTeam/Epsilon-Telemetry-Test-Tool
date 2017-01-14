#include <QIODevice>
#include <QSerialPort>
#include <QStringList>
#include "CommunicationService.h"
#include "View.h"
#include "I_CommPeripheral.h"
#include "SerialPortPeripheral.h"
#include "InternetPeripheral.h"

/*--------------------------------------------------------
                Communication Service
    Initially sets up with a SerialPort connection unless
    specified otherwise.
--------------------------------------------------------*/

CommunicationService::CommunicationService(View& view)
    : view_(view)
{
    setPeripheralSerialPort();
    connect(&view_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptSerialConnection()));
}

void CommunicationService::setPeripheralSerialPort()
{
    outputDevice_ = new QSerialPort();
    outputPeripheral_ = new SerialPortPeripheral(*outputDevice_);
}

void CommunicationService::setInternetConnection()
{
    //TODO: Implement or replace this function to set up a connection with the server
}

void CommunicationService::sendSerialData(const unsigned char* packet, int packetLength)
{
    outputPeripheral_->sendSerialData(packet, packetLength);
}

void CommunicationService::sendInternetData(const QByteArray & /*data*/)
{
    //TODO: Implement or replace this function to send incoming data
}

void CommunicationService::attemptSerialConnection()
{
    QStringList paramList = (QStringList() << view_.getCommunicationPort());
    outputPeripheral_->setParameters(paramList);
    view_.setConnectionStatus(outputPeripheral_->attemptConnection());
}

void CommunicationService::attemptInternetConnection()
{
    //TODO: Implement or replace this function to try to connect to the server
}
