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
    QPushButton& getSendKeyMotorButton();
    QPushButton& getSendMotor0DetailsButton();
    QPushButton& getSendMotor1DetailsButton();
    QPushButton& getSendDriverControlsButton();
    QPushButton& getSendMotorFaultsButton();
    QPushButton& getSendBatteryFaultsButton();
    QPushButton& getSendBatteryButton();
    QPushButton& getSendMpptButton();
    QPushButton& getSendLightsButton();
    QPushButton& getSendAllButton();
    void setConnectionStatusText(QString);

private:
    void setupUi();

private:
    QPushButton* connectButton_;
    QPushButton* disconnectButton_;
    QLineEdit* comPortLineEdit_;
    QLabel* connectionStatusLabel_;
    QPushButton* sendKeyMotorButton_;
    QPushButton* sendMotor0DetailsButton_;
    QPushButton* sendMotor1DetailsButton_;
    QPushButton* sendDriverControlsButton_;
    QPushButton* sendMotorFaultsButton_;
    QPushButton* sendBatteryFaultsButton_;
    QPushButton* sendBatteryButton_;
    QPushButton* sendMpptButton_;
    QPushButton* sendLightsButton_;
    QPushButton* sendAllButton_;
};
