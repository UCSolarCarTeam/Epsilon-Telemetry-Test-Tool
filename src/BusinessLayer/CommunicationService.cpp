#include <QIODevice>
#include <QSerialPort>
#include <QStringList>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include "CommunicationService.h"
#include "View.h"
#include "I_CommPeripheral.h"
#include "SerialPortPeripheral.h"

/*--------------------------------------------------------
                Communication Service
    Initially sets up with a SerialPort connection unless
    specified otherwise.
--------------------------------------------------------*/

CommunicationService::CommunicationService(View& view)
    : view_(view)
{
    setPeripheralSerialPort();
    connect(&view_, SIGNAL(attemptConnectionSignal()), this, SLOT(attemptConnection()));
}

void CommunicationService::setPeripheralSerialPort()
{
    outputDevice_ = new QSerialPort();
    outputPeripheral_ = new SerialPortPeripheral(*outputDevice_);
}

void CommunicationService::sendData(const unsigned char* packet, int packetLength)
{
    outputPeripheral_->sendData(packet, packetLength);
}

void CommunicationService::sendDataInternet(const QByteArray &data)
{
    QUrl url("localhost:1234");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(syncRequestFinished(QNetworkReply*)));

    manager->post(request, data);
}

void CommunicationService::attemptConnection()
{
    QStringList paramList = (QStringList() << view_.getCommunicationPort());
    outputPeripheral_->setParameters(paramList);
    view_.setConnectionStatus(outputPeripheral_->attemptConnection());
}
