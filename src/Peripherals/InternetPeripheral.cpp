#include <QStringList>
#include "InternetPeripheral.h"

/*--------------------------------------------------------
                Internet Peripheral
    Suggested function stubs for the internet peripheral
    to connect to the Internet.
    Some or all of these functions may or may not be used
    in the actual implementation.
--------------------------------------------------------*/
InternetPeripheral::InternetPeripheral()
{
    //TODO: Implement a constructor
}


InternetPeripheral::~InternetPeripheral()
{
}

void InternetPeripheral::setParameters(QStringList parameters)
{
    Q_UNUSED(parameters);
   //TODO: Implement or replace this function to set up parameters
}


bool InternetPeripheral::attemptConnection()
{
    //TODO: Implement or replace this function to attempt connection to a server
    return true;
}

void InternetPeripheral::sendInternetData(const QByteArray &data)
{
    Q_UNUSED(data);
    //TODO: Implement or replace this function to send data to the server
}
