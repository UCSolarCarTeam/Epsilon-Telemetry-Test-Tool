#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "View.h"
#include "Window.h"

namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}

View::View()
{
    window_ = new Window();
    //Connect slots to UI
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getSendKeyMotorButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendKeyMotor()));
    window_->connect(&(window_->getSendMotor0DetailsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMotor0Details()));
    window_->connect(&(window_->getSendMotor1DetailsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMotor1Details()));
    window_->connect(&(window_->getSendDriverControlsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendDriverControls()));
    window_->connect(&(window_->getSendMotorFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMotorFaults()));
    window_->connect(&(window_->getSendBatteryFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBatteryFaults()));
    window_->connect(&(window_->getSendBatteryButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBattery()));
    window_->connect(&(window_->getSendCmuButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendCmu()));
    window_->connect(&(window_->getSendMpptButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMppt()));
    window_->connect(&(window_->getSendLightsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendLights()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAll()));
}

void View::setConnectionStatus(bool connectionStatus)
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

QString View::getCommunicationPort()
{
    return window_->getComPortLineEdit().text();
}
