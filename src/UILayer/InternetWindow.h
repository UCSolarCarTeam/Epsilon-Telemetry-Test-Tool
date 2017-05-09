#pragma once

#include <QMainWindow>

class QPushButton;
class QLineEdit;
class QLabel;

class InternetWindow : public QWidget
{
    Q_OBJECT
public:
    InternetWindow();
    virtual ~InternetWindow();

public:
    QPushButton& getConnectButton();
    QLineEdit& getIpAddressLineEdit();
    QLineEdit& getPortLineEdit();
    QLabel& getConnectionStatusLabel();
    QPushButton& getSendAllButton();
    void setConnectionStatusText(QString);

private:
    void setupUi();

private:
    QPushButton* connectButton_;
    QLineEdit* ipAddressLineEdit_;
    QLineEdit* portLineEdit_;
    QLabel* connectionStatusLabel_;
    QPushButton* sendAllButton_;
};
