#pragma once

#include <QMainWindow>
class QSerialPort;
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;
class TelemetryReporting;

class Window : public QMainWindow
{
   Q_OBJECT
public:
   Window(QSerialPort& serialPort, TelemetryReporting& telemetryReporting);
   virtual ~Window();

private slots:
   void attemptConnection();

   void differentModeSelected();
   void sendKeyDriverControl();
   void sendDriverControlDetails();
   void sendFaults();
   void sendBatteryData();
   void sendCmuData();
   void sendMpptData();
   void sendAll();
   void keyDriverControlDetails();
   void driverControlDetails();

private:
   void setupUi();

private:
   QSerialPort& serialPort_;
   TelemetryReporting& telemetryReporting_;

   QPushButton* connectButton_;
   QLineEdit* comPortLineEdit_;
   QLabel* connectionStatusLabel_;

   QString* testingMode_;
   QComboBox* modeSelectionComboBox_;

   QPushButton* sendKeyDriverControlButton_;
   QPushButton* sendDriverControlDetailsButton_;
   QPushButton* sendFaultsButton_;
   QPushButton* sendBatteryDataButton_;
   QPushButton* sendCmuDataButton_;
   QPushButton* sendMpptDataButton_;
   QPushButton* sendAllButton_;
};
