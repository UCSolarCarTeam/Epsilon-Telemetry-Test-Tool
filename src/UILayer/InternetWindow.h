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
    QLineEdit& getIpAddressLineEdit();
    QSpinBox& getPortSpinBox();
    QLineEdit& getExchangeNameLineEdit();
    QLineEdit& getRoutingKeyLineEdit();
    QLabel& getConnectionStatusLabel();
    QPushButton& getSendAllButton();
    void setConnectionStatusText(QString);

private:
    void setupUi();

private:
    QPushButton* connectButton_;
    QLineEdit* ipAddressLineEdit_;
    QSpinBox* portSpinBox_;
    QLineEdit* exchangeNameLineEdit_;
    QLineEdit* routingKeyLineEdit_;
    QLabel* connectionStatusLabel_;
    QPushButton* sendAllButton_;
};
