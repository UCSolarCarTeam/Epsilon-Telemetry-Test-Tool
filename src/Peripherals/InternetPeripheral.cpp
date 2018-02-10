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
    try
    {
        channel_ = AmqpClient::Channel::Create(ipAddress.toStdString(), port);
    }
    catch (AmqpClient::AmqpException::exception& exception)
    {
        qDebug() << exception.what(); // TODO propagate error message up to UI
        return false;
    }
    return true;
}

bool InternetPeripheral::attemptDisconnection()
{
    if (channel_ != NULL)
    {
        channel_ = NULL;
        return true;
    }
   else
    {
        return false;
    }
}

void InternetPeripheral::sendInternetData(
    const QString exchangeName,
    const QString routingKey,
    const QByteArray& data)
{
    if (channel_ == NULL)
    {
        return; // TODO add error message
    }

    AmqpClient::BasicMessage::ptr_t msg = AmqpClient::BasicMessage::Create(data.toStdString());

    channel_->BasicPublish(
        exchangeName.toStdString(),
        routingKey.toStdString(),
        msg, false, false);
}
