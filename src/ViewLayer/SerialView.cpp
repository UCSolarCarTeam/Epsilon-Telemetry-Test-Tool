#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "SerialView.h"
#include "SerialWindow.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_MPPTS = 7;
}

SerialView::SerialView(SerialWindow* window)
    : signalMapper(this)
    , window_(window)
{
    //Connect slots to UI
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getSendKeyMotorButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendKeyMotor()));

    connect(&(window_->getSendMotor0DetailsButton()), SIGNAL(clicked()), &signalMapper, SLOT(map()));
    connect(&(window_->getSendMotor1DetailsButton()), SIGNAL(clicked()), &signalMapper, SLOT(map()));
    signalMapper.setMapping(&(window_->getSendMotor0DetailsButton()), 0);
    signalMapper.setMapping(&(window_->getSendMotor1DetailsButton()), 1);
    connect(&signalMapper, SIGNAL(mapped(int)), this, SIGNAL(sendMotorDetails(int)));

    window_->connect(&(window_->getSendDriverControlsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendDriverControls()));
    window_->connect(&(window_->getSendMotorFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMotorFaults()));
    window_->connect(&(window_->getSendBatteryFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBatteryFaults()));
    window_->connect(&(window_->getSendBatteryButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBattery()));
    window_->connect(&(window_->getSendMpptButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMppt()));
    window_->connect(&(window_->getSendLightsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendLights()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAll()));
}

void SerialView::setConnectionStatus(bool connectionStatus)
{
    if (connectionStatus)
    {
        if (window_->getConnectButton().text() == "Connect")
        {
            window_->getConnectionStatusLabel().setText("Connected");
            window_->getConnectButton().setText("Disconnect");
            window_->getConnectionStatusLabel().setEnabled(false);
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnected");
            window_->getConnectButton().setText("Connect");
            window_->getConnectionStatusLabel().setEnabled(true);
        }
    }
    else
    {
        window_->getConnectionStatusLabel().setText("Connection Failed.");
    }
}

QString SerialView::getCommunicationPort()
{
    return window_->getComPortLineEdit().text();
}
