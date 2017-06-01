#include "InternetPeripheral.h"
#include <QDebug>
/*--------------------------------------------------------
                Internet Peripheral
    Suggested function stubs for the internet peripheral
    to connect to the Internet.
    Some or all of these functions may or may not be used
    in the actual implementation.
--------------------------------------------------------*/
InternetPeripheral::InternetPeripheral()
    : channel_()
{
}


InternetPeripheral::~InternetPeripheral()
{
}


bool InternetPeripheral::attemptConnection(QString ipAddress, unsigned short port)
{
    qDebug() << "InternetPeripheral::attemptConnection 0";

    try
    {
        qDebug() << ipAddress;
        qDebug() << port;
        channel_ = AmqpClient::Channel::Create(ipAddress.toStdString(), port);
    }
    catch (AmqpClient::AmqpException::exception&)
    {
        qDebug() << "catch";
        return false;
    }
    qDebug() << "end";
    return true;
}

void InternetPeripheral::sendInternetData(
    const QString exchangeName,
    const QString routingKey,
    const QString& data)
{
    AmqpClient::BasicMessage::ptr_t msg = AmqpClient::BasicMessage::Create(data.toStdString());

    channel_->BasicPublish(
        exchangeName.toStdString(),
        routingKey.toStdString(),
        msg, true, true); 
}
