#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "InternetView.h"
#include "InternetWindow.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_MPPTS = 7;
}

InternetView::InternetView() : signalMapper(this)
{
    window_ = new InternetWindow();
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

QString InternetView::getPort()
{
    return window_->getPortLineEdit().text();
}

