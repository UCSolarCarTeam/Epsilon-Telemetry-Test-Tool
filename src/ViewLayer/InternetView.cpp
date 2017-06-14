#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include "InternetView.h"
#include "InternetWindow.h"

#include <QDebug>

namespace
{
    const int BAUDRATE = 9600;
}

InternetView::InternetView(InternetWindow* window)
    : window_(window)
{
    //Connect slots to UI
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAll()));
}

void InternetView::setConnectionStatus(bool connectionStatus)
{
    if (connectionStatus)
    {
        window_->getConnectionStatusLabel().setText("Connected");
    }
    else
    {
        window_->getConnectionStatusLabel().setText("Connection Failed.");
    }
}

QString InternetView::getIpAddress()
{
    return window_->getIpAddressLineEdit().text();
}

unsigned short InternetView::getPort()
{
    return window_->getPortSpinBox().value();
}

QString InternetView::getExchangeName()
{
    return window_->getExchangeNameLineEdit().text();
}

QString InternetView::getRoutingKey()
{
    return window_->getRoutingKeyLineEdit().text();
}
