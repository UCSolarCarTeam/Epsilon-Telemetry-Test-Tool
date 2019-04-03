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
    : signalMapper(this)
    , window_(window)
{
    //Connect slots to UI
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getDisconnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptDisconnectionSignal()));
    window_->connect(&(window_->getSendContinuouslyButton()), SIGNAL(clicked()),
                     this, SIGNAL(toggleSendContinuously()));
    connect(&(window_->getSendPacket0Button()), SIGNAL(clicked()), &signalMapper, SLOT(map()));
    connect(&(window_->getSendPacket1Button()), SIGNAL(clicked()), &signalMapper, SLOT(map()));
    signalMapper.setMapping(&(window_->getSendPacket0Button()), 0);
    signalMapper.setMapping(&(window_->getSendPacket1Button()), 1);
    connect(&signalMapper, SIGNAL(mapped(int)), this, SIGNAL(setPacketNum(int)));
}

void InternetView::setConnectionStatus(bool connectionStatus, bool attemptToConnect)
{
    if (connectionStatus)
    {
        if (attemptToConnect)
        {
            window_->getConnectionStatusLabel().setText("Connected");
            window_->getConnectButton().setEnabled(false);
            window_->getDisconnectButton().setEnabled(true);
            window_->getIpAddressLineEdit().setEnabled(false);
            window_->getPortSpinBox().setEnabled(false);
            window_->getExchangeNameLineEdit().setEnabled(false);
            window_->getRoutingKeyLineEdit().setEnabled(false);
            window_->getSendContinuouslyButton().setEnabled(true);
            window_->getSendPacket0Button().setEnabled(true);
            window_->getSendPacket1Button().setEnabled(true);
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnected");
            window_->getConnectButton().setEnabled(true);
            window_->getDisconnectButton().setEnabled(false);
            window_->getIpAddressLineEdit().setEnabled(true);
            window_->getPortSpinBox().setEnabled(true);
            window_->getExchangeNameLineEdit().setEnabled(true);
            window_->getRoutingKeyLineEdit().setEnabled(true);
            window_->getSendContinuouslyButton().setEnabled(false);
            window_->getSendPacket0Button().setEnabled(false);
            window_->getSendPacket1Button().setEnabled(false);
        }
    }
    else
    {
        if (attemptToConnect)
        {
            window_->getConnectionStatusLabel().setText("Connection Failed.");
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnection Failed.");
        }
    }
}

void InternetView::setSendContinuouslyText(bool sendContinuously)
{
    if (sendContinuously)
    {
        window_->getSendContinuouslyButton().setText("Stop");
    }
    else
    {
        window_->getSendContinuouslyButton().setText("Send Continuously");
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
