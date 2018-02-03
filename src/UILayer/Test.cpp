#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QScopedPointer>
#include "Test.h"

Test::Test()
{
    setWindowTitle("Internet");
    setupUi();
}

Test::~Test()
{
}

void Test::setupUi()
{
    QFormLayout* layout = new QFormLayout;
    connectButton_ = new QPushButton("Connect", this);
    QLabel* ipAddressLabel = new QLabel("Ip Address", this);
    ipAddressLineEdit_ = new QLineEdit("localhost", this);
    QLabel* portSpinLabel = new QLabel("Port Spin", this);
    portSpinBox_ = new QSpinBox(this);
    portSpinBox_->setRange(0, 65535);
    portSpinBox_->setValue(5672);
    QLabel* exchangeNameLabel = new QLabel("Exchange Name", this);
    exchangeNameLineEdit_ = new QLineEdit("", this);
    QLabel* routingKeyLabel = new QLabel("Routing Key", this);
    routingKeyLineEdit_ = new QLineEdit("", this);
    connectionStatusLabel_ = new QLabel("Not connected", this);
    sendAllButton_ = new QPushButton("Send All", this);
    sendAllButton_->setEnabled(false);
    layout->addRow(connectButton_);
    layout->addRow(ipAddressLabel);
    layout->addRow(ipAddressLineEdit_);
    layout->addRow(portSpinLabel);
    layout->addRow(portSpinBox_);
    layout->addRow(exchangeNameLabel);
    layout->addRow(exchangeNameLineEdit_);
    layout->addRow(routingKeyLabel);
    layout->addRow(routingKeyLineEdit_);
    layout->addRow(connectionStatusLabel_);
    layout->addRow(sendAllButton_);
    setLayout(layout);
}

QPushButton& Test::getConnectButton()
{
    return *connectButton_;
}

QSpinBox& Test::getPortSpinBox()
{
    return *portSpinBox_;
}

QLineEdit& Test::getExchangeNameLineEdit()
{
    return *exchangeNameLineEdit_;
}

QLineEdit& Test::getRoutingKeyLineEdit()
{
    return *routingKeyLineEdit_;
}

QLineEdit& Test::getIpAddressLineEdit()
{
    return *ipAddressLineEdit_;
}

QLabel& Test::getConnectionStatusLabel()
{
    return *connectionStatusLabel_;
}

QPushButton& Test::getSendAllButton()
{
    return *sendAllButton_;
}
