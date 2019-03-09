#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "SerialView.h"
#include "SerialWindow.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_MPPTS = 4;
}

SerialView::SerialView(SerialWindow* window)
    : signalMapper(this)
    , window_(window)
{
    //Connect slots to UI
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getDisconnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptDisconnectionSignal()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAll()));
    window_->connect(&(window->getSwitchPacketButton()), SIGNAL(clicked()),
                     this, SIGNAL(switchPacket()));
}

void SerialView::setConnectionStatus(bool connectionStatus, bool attemptToConnect)
{
    if (connectionStatus)
    {
        if (attemptToConnect)
        {
            window_->getConnectionStatusLabel().setText("Connected");
            window_->getConnectButton().setEnabled(false);
            window_->getDisconnectButton().setEnabled(true);
            window_->getComPortLineEdit().setEnabled(false);
            window_->getSwitchPacketButton().setEnabled(true);
            window_->getSendAllButton().setEnabled(true);
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnected");
            window_->getConnectButton().setEnabled(true);
            window_->getDisconnectButton().setEnabled(false);
            window_->getComPortLineEdit().setEnabled(true);
            window_->getSwitchPacketButton().setEnabled(false);
            window_->getSendAllButton().setEnabled(false);
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

void SerialView::setPacketText(bool packet0)
{
    if (packet0)
    {
        window_->getSwitchPacketButton().setText("Switch to Packet 1");
    }
    else
    {
        window_->getSwitchPacketButton().setText("Switch to Packet 0");
    }
}

QString SerialView::getCommunicationPort()
{
    return window_->getComPortLineEdit().text();
}
