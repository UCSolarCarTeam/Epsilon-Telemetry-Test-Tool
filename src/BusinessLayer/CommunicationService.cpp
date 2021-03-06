#include <QIODevice>
#include <QStringList>
#include "CommunicationService.h"
#include "InternetPeripheral.h"
#include "SerialPortPeripheral.h"
#include "SerialView.h"
#include "InternetView.h"

CommunicationService::CommunicationService(SerialView& serialView, InternetView& internetView)
    : serialView_(serialView)
    , internetView_(internetView)
{
    connect(&serialView_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptSerialConnection()));
    connect(&serialView_, SIGNAL(attemptDisconnectionSignal()), this, SLOT(attemptSerialDisconnection()));
    connect(&internetView_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptInternetConnection()));
    connect(&internetView_, SIGNAL(attemptDisconnectionSignal()), this, SLOT(attemptInternetDisconnection()));
}

void CommunicationService::sendSerialData(const unsigned char* packet, int packetLength)
{
    serialPeripheral_.sendSerialData(packet, packetLength);
}

void CommunicationService::sendInternetData(const QByteArray& data)
{
    internetPeripheral_.sendInternetData(
        internetView_.getExchangeName(),
        internetView_.getRoutingKey(),
        data);
}

void CommunicationService::attemptSerialConnection()
{
    serialView_.setConnectionStatus(serialPeripheral_.attemptConnection(serialView_.getCommunicationPort()), true);
}

void CommunicationService::attemptSerialDisconnection()
{
    serialView_.setConnectionStatus(serialPeripheral_.attemptDisconnection(), false);
}

void CommunicationService::attemptInternetConnection()
{
    internetView_.setConnectionStatus(internetPeripheral_.attemptConnection(
                                          internetView_.getIpAddress(), internetView_.getPort()), true);
}
void CommunicationService::attemptInternetDisconnection()
{
    internetView_.setConnectionStatus(internetPeripheral_.attemptDisconnection(), false);
}
