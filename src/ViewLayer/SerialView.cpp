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
    window_->connect(&(window_->getDisconnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptDisconnectionSignal()));
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
            window_->getSendKeyMotorButton().setEnabled(true);
            window_->getSendMotor0DetailsButton().setEnabled(true);
            window_->getSendMotor1DetailsButton().setEnabled(true);
            window_->getSendDriverControlsButton().setEnabled(true);
            window_->getSendMotorFaultsButton().setEnabled(true);
            window_->getSendBatteryFaultsButton().setEnabled(true);
            window_->getSendBatteryButton().setEnabled(true);
            window_->getSendMpptButton().setEnabled(true);
            window_->getSendLightsButton().setEnabled(true);
            window_->getSendAllButton().setEnabled(true);
        }
        else
        {
            window_->getConnectionStatusLabel().setText("Disconnected");
            window_->getConnectButton().setEnabled(true);
            window_->getDisconnectButton().setEnabled(false);
            window_->getComPortLineEdit().setEnabled(true);
            window_->getSendKeyMotorButton().setEnabled(false);
            window_->getSendMotor0DetailsButton().setEnabled(false);
            window_->getSendMotor1DetailsButton().setEnabled(false);
            window_->getSendDriverControlsButton().setEnabled(false);
            window_->getSendMotorFaultsButton().setEnabled(false);
            window_->getSendBatteryFaultsButton().setEnabled(false);
            window_->getSendBatteryButton().setEnabled(false);
            window_->getSendMpptButton().setEnabled(false);
            window_->getSendLightsButton().setEnabled(false);
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

QString SerialView::getCommunicationPort()
{
    return window_->getComPortLineEdit().text();
}
