#pragma once

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;

class SerialWindow : public QWidget
{
    Q_OBJECT
public:
    SerialWindow();
    virtual ~SerialWindow();

public:
    QPushButton& getConnectButton();
    QPushButton& getDisconnectButton();
    QLineEdit& getComPortLineEdit();
    QLabel& getConnectionStatusLabel();
    QPushButton& getSwitchPacketButton();
    QPushButton& getSendAllButton();
    void setConnectionStatusText(QString);

private:
    void setupUi();

private:
    QPushButton* connectButton_;
    QPushButton* disconnectButton_;
    QLineEdit* comPortLineEdit_;
    QLabel* connectionStatusLabel_;
    QPushButton* switchPacketButton_;
    QPushButton* sendAllButton_;
};
