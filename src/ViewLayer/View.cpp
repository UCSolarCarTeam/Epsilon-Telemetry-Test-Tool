#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include "View.h"
#include "TelemetryReporting.h"
#include "Window.h"

namespace
{
   const int BAUDRATE = 9600;
   const int NUMBER_OF_CMUS = 4;
   const int NUMBER_OF_MPPTS = 7;
}

View::View(QSerialPort& serialPort, TelemetryReporting& telemetryReporting)
: serialPort_(serialPort)
, telemetryReporting_(telemetryReporting)
{
    window_ = new Window();
    connectToUi();
}

void View::connectToUi()
{
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SLOT(attemptConnection()));
    window_->connect(&(window_->getModeSelectionComboBox()), SIGNAL(editTextChanged(QString)),
                     this, SLOT(differentModeSelected()));
    window_->connect(&(window_->getSendKeyDriverControlButton()), SIGNAL(clicked(bool)),
                     this, SLOT(sendKeyDriverControl()));
    window_->connect(&(window_->getSendDriverControlDetailsButton()), SIGNAL(clicked()),
                     this, SLOT(sendDriverControlDetails()));
    window_->connect(&(window_->getSendFaultsButton()), SIGNAL(clicked()),
                     this, SLOT(sendFaults()));
    window_->connect(&(window_->getSendBatteryDataButton()), SIGNAL(clicked()),
                     this, SLOT(sendBatteryData()));
    window_->connect(&(window_->getSendCmuDataButton()), SIGNAL(clicked()),
                     this, SLOT(sendCmuData()));
    window_->connect(&(window_->getSendMpptDataButton()), SIGNAL(clicked()),
                     this, SLOT(sendMpptData()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SLOT(sendAll()));
}

void View::attemptConnection()
{
    if (telemetryReporting_.attemptConnection(serialPort_,window_->getComPortLineEdit().text()) == true)
    {
        window_->setConnectionStatusText("Connected");
    }
    else
    {
        window_->setConnectionStatusText("Connection Failed.");
    }
}

void View::differentModeSelected()
{
    QString testingMode = window_->getModeSelectionComboBox().currentText();
    qDebug() << testingMode;
}

void View::sendKeyDriverControl()
{
   telemetryReporting_.sendKeyDriverControlTelemetry();
}

void View::sendDriverControlDetails()
{
   telemetryReporting_.sendDriverControlDetails();
}

void View::sendFaults()
{
   telemetryReporting_.sendFaults();
}

void View::sendBatteryData()
{
   telemetryReporting_.sendBatteryData();
}

void View::sendCmuData()
{
   for (int i = 0; i < NUMBER_OF_CMUS; ++i)
   {
      telemetryReporting_.sendCmuData(i);
   }
}

void View::sendMpptData()
{
   for (int i = 0; i < NUMBER_OF_MPPTS; ++i)
   {
      telemetryReporting_.sendMpptData(i);
   }
}

void View::sendAll()
{
   sendKeyDriverControl();
   sendDriverControlDetails();
   sendFaults();
   sendBatteryData();
   sendCmuData();
   sendMpptData();
}
