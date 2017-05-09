#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QScopedPointer>
#include "InternetWindow.h"

InternetWindow::InternetWindow()
{
    setWindowTitle("Telem Test Program");
    setupUi();
    show();
}

InternetWindow::~InternetWindow()
{
}

void InternetWindow::setupUi()
{
    QWidget* mainWidget = new QWidget(this);
    QFormLayout* layout = new QFormLayout;
    connectButton_ = new QPushButton("Connect", this);
    ipAddressLineEdit_ = new QLineEdit("localhost", this);
    portLineEdit_ = new QLineEdit("9000", this);
    connectionStatusLabel_ = new QLabel("Not connected", this);
    sendAllButton_ = new QPushButton("Send All", this);
    layout->addRow(connectButton_);
    layout->addRow(ipAddressLineEdit_);
    layout->addRow(portLineEdit_);
    layout->addRow(connectionStatusLabel_);
    layout->addRow(sendAllButton_);
    mainWidget->setLayout(layout);
}

QPushButton& InternetWindow::getConnectButton()
{
    return *connectButton_;
}

QLineEdit& InternetWindow::getPortLineEdit()
{
    return *portLineEdit_;
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
