#pragma once

#include <QMainWindow>
class QSerialPort;
class QPushButton;
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

   void sendKeyDriverControl();
   void sendDriverControlDetails();
   void sendFaults();
   void sendBatteryData();
   void sendCmuData();
   void sendMpptData();
   void sendAll();

private:
   void setupUi();

private:
   QSerialPort& serialPort_;
   TelemetryReporting& telemetryReporting_;

   QPushButton* connectButton_;
   QLineEdit* comPortLineEdit_;
   QLabel* connectionStatusLabel_;

   QPushButton* sendKeyDriverControlButton_;
   QPushButton* sendDriverControlDetailsButton_;
   QPushButton* sendFaultsButton_;
   QPushButton* sendBatteryDataButton_;
   QPushButton* sendCmuDataButton_;
   QPushButton* sendMpptDataButton_;
   QPushButton* sendAllButton_;
};
