#pragma once

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QString>


class QByteArray;

class InternetPeripheral
{
public:
    InternetPeripheral();
    virtual ~InternetPeripheral();
    bool attemptConnection(
        QString ipAddress,
        unsigned short port);
    void sendInternetData(
        const QString exchangeName,
        const QString routingKey,
        const QByteArray& data);

private:
    AmqpClient::Channel::ptr_t channel_;
    std::string queueName_;
};
