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
   QPushButton& getSendCmuButton();
   QPushButton& getSendMpptButton();
   QPushButton& getSendLightsButton();
   QPushButton& getSendAllButton();
   void setConnectionStatusText(QString);

private:
   void setupUi();

private:
   QScopedPointer<QPushButton> connectButton_;
   QScopedPointer<QLineEdit> comPortLineEdit_;
   QScopedPointer<QLabel> connectionStatusLabel_;
   QScopedPointer<QPushButton> sendKeyMotorButton_;
   QScopedPointer<QPushButton> sendMotor0DetailsButton_;
   QScopedPointer<QPushButton> sendMotor1DetailsButton_;
   QScopedPointer<QPushButton> sendDriverControlsButton_;
   QScopedPointer<QPushButton> sendMotorFaultsButton_;
   QScopedPointer<QPushButton> sendBatteryFaultsButton_;
   QScopedPointer<QPushButton> sendBatteryButton_;
   QScopedPointer<QPushButton> sendCmuButton_;
   QScopedPointer<QPushButton> sendMpptButton_;
   QScopedPointer<QPushButton> sendLightsButton_;
   QScopedPointer<QPushButton> sendAllButton_;
};
