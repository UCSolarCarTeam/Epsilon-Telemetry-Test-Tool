#pragma once

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class QSpinBox;

class InternetWindow : public QWidget
{
    Q_OBJECT
public:
    InternetWindow();
    virtual ~InternetWindow();

public:
    QPushButton& getConnectButton();
    QPushButton& getDisconnectButton();
    QLineEdit& getIpAddressLineEdit();
    QSpinBox& getPortSpinBox();
    QLineEdit& getExchangeNameLineEdit();
    QLineEdit& getRoutingKeyLineEdit();
    QLabel& getConnectionStatusLabel();
    QPushButton& getSendPacket0Button();
    QPushButton& getSendPacket1Button();
    void setConnectionStatusText(QString);

private:
    void setupUi();

private:
    QPushButton* connectButton_;
    QPushButton* disconnectButton_;
    QLineEdit* ipAddressLineEdit_;
    QSpinBox* portSpinBox_;
    QLineEdit* exchangeNameLineEdit_;
    QLineEdit* routingKeyLineEdit_;
    QLabel* connectionStatusLabel_;
    QPushButton* sendPacket0Button_;
    QPushButton* sendPacket1Button_;
};
