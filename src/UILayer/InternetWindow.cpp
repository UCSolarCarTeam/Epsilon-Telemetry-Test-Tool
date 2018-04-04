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
    sendAllButton_ = new QPushButton("Send All", this);
    disconnectButton_->setEnabled(false);
    sendAllButton_->setEnabled(false);
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
    layout->addRow(sendAllButton_);
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

QPushButton& InternetWindow::getSendAllButton()
{
    return *sendAllButton_;
}
