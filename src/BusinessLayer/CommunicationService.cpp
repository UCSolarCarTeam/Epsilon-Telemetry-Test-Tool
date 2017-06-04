#include <QIODevice>
#include <QStringList>
#include "CommunicationService.h"
#include "InternetPeripheral.h"
#include "SerialPortPeripheral.h"
#include "SerialView.h"
#include "InternetView.h"

#include <QDebug>

CommunicationService::CommunicationService(SerialView& serialView, InternetView& internetView)
    : serialView_(serialView)
    , internetView_(internetView)
{
    serialPeripheral_ = new SerialPortPeripheral();
    connect(&serialView_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptSerialConnection()));
    connect(&internetView_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptInternetConnection()));
}

void CommunicationService::sendSerialData(const unsigned char* packet, int packetLength)
{
    serialPeripheral_->sendSerialData(packet, packetLength);
}

void CommunicationService::sendInternetData(const QString& data)
{
    internetPeripheral_.sendInternetData(
        internetView_.getExchangeName(),
        internetView_.getRoutingKey(),
        data);
}

void CommunicationService::attemptSerialConnection()
{
    serialView_.setConnectionStatus(serialPeripheral_->attemptConnection(serialView_.getCommunicationPort()));
}

void CommunicationService::attemptInternetConnection()
{
    internetView_.setConnectionStatus(internetPeripheral_.attemptConnection(
        internetView_.getIpAddress(), internetView_.getPort()));
    qDebug() << "CommunicationService::attemptInternetConnection";
}
