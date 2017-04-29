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
    connectButton_ = new QPushButton("Connect", this);
    comPortLineEdit_ = new QLineEdit("/dev/ttyUSB0", this);
    connectionStatusLabel_ = new QLabel("Not connected", this);
    sendKeyMotorButton_ = new QPushButton("Send Key Motor", this);
    sendMotor0DetailsButton_ = new QPushButton("Send Motor 0 Details", this);
    sendMotor1DetailsButton_ = new QPushButton("Send Motor 1 Details", this);
    sendDriverControlsButton_ = new QPushButton("Send Driver Controls", this);
    sendMotorFaultsButton_ = new QPushButton("Send Motor Faults", this);
    sendBatteryFaultsButton_ = new QPushButton("Send Battery Faults", this);
    sendBatteryButton_ = new QPushButton("Send Battery", this);
    sendMpptButton_ = new QPushButton("Send MPPTs", this);
    sendLightsButton_ = new QPushButton("Send Lights", this);
    sendAllButton_ = new QPushButton("Send All", this);
    layout->addRow(connectButton_);
    layout->addRow(comPortLineEdit_);
    layout->addRow(connectionStatusLabel_);
    layout->addRow(sendKeyMotorButton_);
    layout->addRow(sendMotor0DetailsButton_);
    layout->addRow(sendMotor1DetailsButton_);
    layout->addRow(sendDriverControlsButton_);
    layout->addRow(sendMotorFaultsButton_);
    layout->addRow(sendBatteryFaultsButton_);
    layout->addRow(sendBatteryButton_);
    layout->addRow(sendMpptButton_);
    layout->addRow(sendLightsButton_);
    layout->addRow(sendAllButton_);
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
