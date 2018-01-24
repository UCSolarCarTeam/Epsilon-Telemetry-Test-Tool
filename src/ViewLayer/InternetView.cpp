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
        if (window_->getConnectButton().text() == "Connect")
        {
            window_->getConnectionStatusLabel().setText("Connected");
            window_->getConnectButton().setText("Disconnect");
            window_->getIpAddressLineEdit().setEnabled(false);
            window_->getPortSpinBox().setEnabled(false);
            window_->getExchangeNameLineEdit().setEnabled(false);
            window_->getRoutingKeyLineEdit().setEnabled(false);
            window_->getSendAllButton().setEnabled(true);
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnected");
            window_->getConnectButton().setText("Connect");
            window_->getIpAddressLineEdit().setEnabled(true);
            window_->getPortSpinBox().setEnabled(true);
            window_->getExchangeNameLineEdit().setEnabled(true);
            window_->getRoutingKeyLineEdit().setEnabled(true);
            window_->getSendAllButton().setEnabled(false);

        }
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
