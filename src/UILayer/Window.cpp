#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QScopedPointer>
#include "Window.h"

Window::Window()
{
    setWindowTitle("Telem Test Program");
    setupUi();
    show();
}

Window::~Window()
{
}

void Window::setupUi()
{
    QWidget* mainWidget = new QWidget(this);
    QFormLayout* layout = new QFormLayout;

    connectButton_.reset(new QPushButton("Connect", this));
    comPortLineEdit_.reset(new QLineEdit("/dev/ttyUSB0", this));
    connectionStatusLabel_.reset(new QLabel("Not connected", this));
    sendKeyMotorButton_.reset(new QPushButton("Send Key Motor", this));
    sendMotor0DetailsButton_.reset(new QPushButton("Send Motor 0 Details", this));
    sendMotor1DetailsButton_.reset(new QPushButton("Send Motor 1 Details", this));
    sendDriverControlsButton_.reset(new QPushButton("Send Driver Controls", this));
    sendMotorFaultsButton_.reset(new QPushButton("Send Motor Faults", this));
    sendBatteryFaultsButton_.reset(new QPushButton("Send Battery Faults", this));
    sendBatteryButton_.reset(new QPushButton("Send Battery", this));
    sendCmuButton_.reset(new QPushButton("Send CMUs", this));
    sendMpptButton_.reset(new QPushButton("Send MPPTs", this));
    sendLightsButton_.reset(new QPushButton("Send Lights", this));
    sendAllButton_.reset(new QPushButton("Send All", this));

    layout->addRow(connectButton_.data());
    layout->addRow(comPortLineEdit_.data());
    layout->addRow(connectionStatusLabel_.data());
    // layout->addRow(sendKeyDriverControlButton_.data());
    // layout->addRow(sendFaultsButton_.data());
    // layout->addRow(sendBatteryDataButton_.data());
    // layout->addRow(sendCmuDataButton_.data());
    // layout->addRow(sendMpptDataButton_.data());
    // layout->addRow(sendAllButton_.data());
    layout->addRow(sendKeyMotorButton_.data());
    layout->addRow(sendMotor0DetailsButton_.data());
    layout->addRow(sendMotor1DetailsButton_.data());
    layout->addRow(sendDriverControlsButton_.data());
    layout->addRow(sendMotorFaultsButton_.data());
    layout->addRow(sendBatteryFaultsButton_.data());
    layout->addRow(sendBatteryButton_.data());
    layout->addRow(sendCmuButton_.data());
    layout->addRow(sendMpptButton_.data());
    layout->addRow(sendLightsButton_.data());
    layout->addRow(sendAllButton_.data());
    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}

QPushButton& Window::getConnectButton()
{
    return *connectButton_;
}

QLineEdit& Window::getComPortLineEdit()
{
    return *comPortLineEdit_;
}

QLabel& Window::getConnectionStatusLabel()
{
    return *connectionStatusLabel_;
}

QPushButton& Window::getSendKeyMotorButton()
{
    return *sendKeyMotorButton_;
}

QPushButton& Window::getSendMotor0DetailsButton()
{
    return *sendMotor0DetailsButton_;
}

QPushButton& Window::getSendMotor1DetailsButton()
{
    return *sendMotor1DetailsButton_;
}

QPushButton& Window::getSendDriverControlsButton()
{
    return *sendDriverControlsButton_;
}

QPushButton& Window::getSendMotorFaultsButton()
{
    return *sendMotorFaultsButton_;
}

QPushButton& Window::getSendBatteryFaultsButton()
{
    return *sendBatteryFaultsButton_;
}

QPushButton& Window::getSendBatteryButton()
{
    return *sendBatteryButton_;
}

QPushButton& Window::getSendCmuButton()
{
    return *sendCmuButton_;
}

QPushButton& Window::getSendMpptButton()
{
    return *sendMpptButton_;
}

QPushButton& Window::getSendLightsButton()
{
    return *sendLightsButton_;
}

QPushButton& Window::getSendAllButton()
{
    return *sendAllButton_;
}
