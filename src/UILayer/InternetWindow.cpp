#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QScopedPointer>
#include "InternetWindow.h"

InternetWindow::InternetWindow()
{
    setWindowTitle("Internet");
    setupUi();
}

InternetWindow::~InternetWindow()
{
}

void InternetWindow::setupUi()
{
    QFormLayout* layout = new QFormLayout;
    connectButton_ = new QPushButton("Connect", this);
    disconnectButton_ = new QPushButton("Disconnect", this);
    QLabel* ipAddressLabel = new QLabel("Ip Address", this);
    ipAddressLineEdit_ = new QLineEdit("localhost", this);
    QLabel* portSpinLabel = new QLabel("Port Spin", this);
    portSpinBox_ = new QSpinBox(this);
    portSpinBox_->setRange(0, 65535);
    portSpinBox_->setValue(5672);
    QLabel* exchangeNameLabel = new QLabel("Exchange Name", this);
    exchangeNameLineEdit_ = new QLineEdit("hermesExchange", this);
    QLabel* routingKeyLabel = new QLabel("Routing Key", this);
    routingKeyLineEdit_ = new QLineEdit("", this);
    connectionStatusLabel_ = new QLabel("Not connected", this);
    sendContinuouslyButton_ = new QPushButton("Send Continuously", this);
    sendPacket0Button_ = new QPushButton("Send Packet 0", this);
    sendPacket1Button_ = new QPushButton("Send Packet 1", this);
    disconnectButton_->setEnabled(false);
    sendContinuouslyButton_->setEnabled(false);
    sendPacket0Button_->setEnabled(false);
    sendPacket1Button_->setEnabled(false);
    connectButton_->setToolTip("Connect to rabbitmq server with properties indicated below.");
    disconnectButton_->setToolTip("Disconnect from the rabbitmq server.");
    sendContinuouslyButton_->setToolTip("Continuously send data packet 1 through RabbitMQ.");
    sendPacket0Button_->setToolTip("Send data packet 0 through RabbitMQ.");
    sendPacket1Button_->setToolTip("Send data packet 1 through RabbitMQ.");
    layout->addRow(connectButton_);
    layout->addRow(disconnectButton_);
    layout->addRow(ipAddressLabel);
    layout->addRow(ipAddressLineEdit_);
    layout->addRow(portSpinLabel);
    layout->addRow(portSpinBox_);
    layout->addRow(exchangeNameLabel);
    layout->addRow(exchangeNameLineEdit_);
    layout->addRow(routingKeyLabel);
    layout->addRow(routingKeyLineEdit_);
    layout->addRow(connectionStatusLabel_);
    layout->addRow(sendContinuouslyButton_);
    layout->addRow(sendPacket0Button_);
    layout->addRow(sendPacket1Button_);
    setLayout(layout);
}

QPushButton& InternetWindow::getConnectButton()
{
    return *connectButton_;
}

QPushButton& InternetWindow::getDisconnectButton()
{
    return *disconnectButton_;
}

QSpinBox& InternetWindow::getPortSpinBox()
{
    return *portSpinBox_;
}

QLineEdit& InternetWindow::getExchangeNameLineEdit()
{
    return *exchangeNameLineEdit_;
}

QLineEdit& InternetWindow::getRoutingKeyLineEdit()
{
    return *routingKeyLineEdit_;
}

QLineEdit& InternetWindow::getIpAddressLineEdit()
{
    return *ipAddressLineEdit_;
}

QLabel& InternetWindow::getConnectionStatusLabel()
{
    return *connectionStatusLabel_;
}

QPushButton& InternetWindow::getSendContinuouslyButton()
{
    return *sendContinuouslyButton_;
}

QPushButton& InternetWindow::getSendPacket0Button()
{
    return *sendPacket0Button_;
}

QPushButton& InternetWindow::getSendPacket1Button()
{
    return *sendPacket1Button_;
}
