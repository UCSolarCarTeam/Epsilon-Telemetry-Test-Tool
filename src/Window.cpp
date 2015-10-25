#include "Window.h"
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QVBoxLayout>
#include "TelemetryReporting.h"

namespace
{
   const int BAUDRATE = 9600;
   const int NUMBER_OF_CMUS = 4;
   const int NUMBER_OF_MPPTS = 7;
}

Window::Window(QSerialPort& serialPort, TelemetryReporting& telemetryReporting)
: serialPort_(serialPort)
, telemetryReporting_(telemetryReporting)
{
   setWindowTitle("Telem Test Program");
   setupUi();
   show();
}

Window::~Window()
{
}

void Window::attemptConnection()
{
   serialPort_.setPortName(comPortLineEdit_->text());
   serialPort_.setBaudRate(BAUDRATE);

   if (serialPort_.open(QIODevice::ReadWrite))
   {
      connectionStatusLabel_->setText("Connected");
   }
   else
   {
      connectionStatusLabel_->setText("Connection Failed.");
   }
}

void Window::sendKeyDriverControl()
{
   telemetryReporting_.sendKeyDriverControlTelemetry();
}

void Window::sendDriverControlDetails()
{
   telemetryReporting_.sendDriverControlDetails();
}

void Window::sendFaults()
{
   telemetryReporting_.sendFaults();
}

void Window::sendBatteryData()
{
   telemetryReporting_.sendBatteryData();
}

void Window::sendCmuData()
{
   for (int i = 0; i < NUMBER_OF_CMUS; ++i)
   {
      telemetryReporting_.sendCmuData(i);
   }
}

void Window::sendMpptData()
{
   for (int i = 0; i < NUMBER_OF_MPPTS; ++i)
   {
      telemetryReporting_.sendMpptData(i);
   }
}

void Window::sendAll()
{
   sendKeyDriverControl();
   sendDriverControlDetails();
   sendFaults();
   sendBatteryData();
   sendCmuData();
   sendMpptData();
}

void Window::setupUi()
{
   QWidget* mainWidget = new QWidget(this);
   QVBoxLayout* layout = new QVBoxLayout;

   QPushButton* connectButton = new QPushButton("&Connect", this);
   connect(connectButton, SIGNAL(clicked()), this, SLOT(attemptConnection()));
   comPortLineEdit_ = new QLineEdit("/dev/ttyUSB0", this);
   connectionStatusLabel_ = new QLabel("Not connected", this);

   QPushButton* sendKeyDriverControlButton = new QPushButton("Send Key Driver Control", this);
   connect(sendKeyDriverControlButton, SIGNAL(clicked()), this, SLOT(sendKeyDriverControl()));

   QPushButton* sendDriverControlDetailsButton = new QPushButton("Send Driver Control Details", this);
   connect(sendDriverControlDetailsButton, SIGNAL(clicked()), this, SLOT(sendDriverControlDetails()));

   QPushButton* sendFaultsButton = new QPushButton("Send Faults", this);
   connect(sendFaultsButton, SIGNAL(clicked()), this, SLOT(sendFaults()));

   QPushButton* sendBatteryDataButton = new QPushButton("Send Battery Data", this);
   connect(sendBatteryDataButton, SIGNAL(clicked()), this, SLOT(sendBatteryData()));

   QPushButton* sendCmuDataButton = new QPushButton("Send Cmu Data", this);
   connect(sendCmuDataButton, SIGNAL(clicked()), this, SLOT(sendCmuData()));

   QPushButton* sendMpptDataButton = new QPushButton("Send Mppt Data", this);
   connect(sendMpptDataButton, SIGNAL(clicked()), this, SLOT(sendMpptData()));

   QPushButton* sendAllButton = new QPushButton("Send All", this);
   connect(sendAllButton, SIGNAL(clicked()), this, SLOT(sendAll()));

   layout->addWidget(connectButton);
   layout->addWidget(comPortLineEdit_);
   layout->addWidget(connectionStatusLabel_);

   layout->addWidget(sendKeyDriverControlButton);
   layout->addWidget(sendDriverControlDetailsButton);
   layout->addWidget(sendFaultsButton);
   layout->addWidget(sendBatteryDataButton);
   layout->addWidget(sendCmuDataButton);
   layout->addWidget(sendMpptDataButton);
   layout->addWidget(sendAllButton);
   mainWidget->setLayout(layout);
   setCentralWidget(mainWidget);
}
