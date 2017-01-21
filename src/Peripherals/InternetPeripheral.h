#pragma once

class QStringList;
class QByteArray;

class InternetPeripheral
{
public:
    InternetPeripheral();
    virtual ~InternetPeripheral();
    bool attemptConnection();
    void setParameters(QStringList parameters);
    void sendInternetData(const QByteArray &data);
};
