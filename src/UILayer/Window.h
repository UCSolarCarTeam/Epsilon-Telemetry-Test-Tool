#pragma once

#include <QMainWindow>

class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window();
    virtual ~Window();

public:
    QPushButton& getConnectButton();
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
