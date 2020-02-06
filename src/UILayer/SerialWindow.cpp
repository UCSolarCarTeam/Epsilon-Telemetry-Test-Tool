#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QScopedPointer>
#include "SerialWindow.h"

SerialWindow::SerialWindow()
{
    setWindowTitle("Serial");
    setupUi();
}

SerialWindow::~SerialWindow()
{
}

void SerialWindow::setupUi()
{
    QFormLayout* layout = new QFormLayout;
    connectButton_ = new QPushButton("Connect", this);
    disconnectButton_ = new QPushButton("Disconnect", this);
    comPortLineEdit_ = new QLineEdit("/dev/ttyUSB0", this);
    connectionStatusLabel_ = new QLabel("Not connected", this);
    switchPacketButton_ = new QPushButton("Switch to Packet 1", this);
    sendContinuouslyButton_ = new QPushButton("Send Continuously", this);
    sendAllButton_ = new QPushButton("Send All", this);
    disconnectButton_->setEnabled(false);
    switchPacketButton_->setEnabled(false);
    sendContinuouslyButton_->setEnabled(false);
    sendAllButton_->setEnabled(false);
    layout->addRow(connectButton_);
    layout->addRow(disconnectButton_);
    layout->addRow(comPortLineEdit_);
    layout->addRow(connectionStatusLabel_);
    layout->addRow(switchPacketButton_);
    layout->addRow(sendContinuouslyButton_);
    layout->addRow(sendAllButton_);
    setLayout(layout);
}

QPushButton& SerialWindow::getConnectButton()
{
    return *connectButton_;
}

QPushButton& SerialWindow::getDisconnectButton()
{
    return *disconnectButton_;
}

QLineEdit& SerialWindow::getComPortLineEdit()
{
    return *comPortLineEdit_;
}

QLabel& SerialWindow::getConnectionStatusLabel()
{
    return *connectionStatusLabel_;
}

QPushButton& SerialWindow::getSwitchPacketButton()
{
    return *switchPacketButton_;
}

QPushButton& SerialWindow::getSendContinuouslyButton()
{
    return *sendContinuouslyButton_;
}

QPushButton& SerialWindow::getSendAllButton()
{
    return *sendAllButton_;
}
