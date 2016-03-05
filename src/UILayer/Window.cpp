#include "Window.h"
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QVBoxLayout>
#include "TelemetryReporting.h"
#include <QFormLayout>
#include <QComboBox>
#include <QString>
#include <iostream>
#include "CommunicationServer.h"

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
    CommunicationServer communicationServer(serialPort_,comPortLineEdit_->text());

   if (communicationServer.attemptConnection() == true) {
      connectionStatusLabel_->setText("Connected");
   }
   else {
      connectionStatusLabel_->setText("Connection Failed.");
   }
}

void Window::differentModeSelected()
{
    std::string testingMode = modeSelectionComboBox_->currentText().toStdString();
    std::cout << testingMode;
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

void Window::keyDriverControlDetails()
{
    QWidget* keyDriverControlDetailsWidget = new QWidget(this);
    QGridLayout* keyDriverControlLayout = new QGridLayout;

    QLabel* keyDriverSpeedLabel = new QLabel("Speed(rpm)", this);
    QLineEdit* keyDriverSpeedInput = new QLineEdit();
    QLabel* keyDriverCurrentLabel = new QLabel("Current(A)", this);
    QLineEdit* keyDriverCurrentInput = new QLineEdit();
    QLabel* keyDriverBusCurrentLabel = new QLabel("Bus Current(A)", this);
    QLineEdit* keyDriverBusCurrentInput = new QLineEdit();
    QLabel* keyDriverVoltageLabel = new QLabel("Bus Voltage(V)", this);
    QLineEdit* keyDriverVoltageInput = new QLineEdit();
    QLabel* keyDriverVelocityLabel = new QLabel("Current(A)", this);
    QLineEdit* keyDriverVelocityInput = new QLineEdit();

    QPushButton* keyDriverControlDoneButton = new QPushButton("Done", this);
    connect(keyDriverControlDoneButton, SIGNAL(clicked()), keyDriverControlDetailsWidget, SLOT(close()));


    keyDriverControlLayout->addWidget(keyDriverSpeedLabel,0,0);
    keyDriverControlLayout->addWidget(keyDriverSpeedInput,0,1);
    keyDriverControlLayout->addWidget(keyDriverCurrentLabel,1,0);
    keyDriverControlLayout->addWidget(keyDriverCurrentInput,1,1);
    keyDriverControlLayout->addWidget(keyDriverBusCurrentLabel,2,0);
    keyDriverControlLayout->addWidget(keyDriverBusCurrentInput,2,1);
    keyDriverControlLayout->addWidget(keyDriverVoltageLabel,3,0);
    keyDriverControlLayout->addWidget(keyDriverVoltageInput,3,1);
    keyDriverControlLayout->addWidget(keyDriverVelocityLabel,4,0);
    keyDriverControlLayout->addWidget(keyDriverVelocityInput,4,1);
    keyDriverControlLayout->addWidget(keyDriverControlDoneButton,5,0);

    keyDriverControlDetailsWidget->setLayout(keyDriverControlLayout);
    keyDriverControlDetailsWidget->setWindowFlags(Qt::Window);
    keyDriverControlDetailsWidget->show();
}

void Window::driverControlDetails()
{    
    QWidget* driverControlDetailsWidget = new QWidget(this);
    QGridLayout* driverControlLayout = new QGridLayout;

    QLabel* driverMotorVelocityLabel = new QLabel("Motor Velocity(rpm)", this);
    QLineEdit* driverMotorVelocityInput = new QLineEdit();
    QLabel* driverMotorVoltageLabel = new QLabel("Motor Voltage(V)", this);
    QLineEdit* driverMotorVoltageInput = new QLineEdit();
    QLabel* driverMotorCurrentLabel = new QLabel("Motor Current(A)", this);
    QLineEdit* driverMotorCurrentInput = new QLineEdit();
    QLabel* driverEMFImaginaryLabel = new QLabel("Back EMF Imaginary", this);
    QLineEdit* driverEMFImaginaryInput = new QLineEdit();
    QLabel* driverDSPBoardLabel = new QLabel("DSP Board Temp", this);
    QLineEdit* driverDSPBoardInput = new QLineEdit();
    QLabel* driverDcBusLabel = new QLabel("DC Bus(AmpHours)", this);
    QLineEdit* driverDcBusInput = new QLineEdit();
    QLabel* driverOdometerLabel = new QLabel("Odometer", this);
    QLineEdit* driverOdometerInput = new QLineEdit();

    QPushButton* driverControlDoneButton = new QPushButton("Done", this);
    connect(driverControlDoneButton, SIGNAL(clicked()), driverControlDetailsWidget, SLOT(close()));

    driverControlLayout->addWidget(driverMotorVelocityLabel,0,0);
    driverControlLayout->addWidget(driverMotorVelocityInput,0,1);
    driverControlLayout->addWidget(driverMotorVoltageLabel,1,0);
    driverControlLayout->addWidget(driverMotorVoltageInput,1,1);
    driverControlLayout->addWidget(driverMotorCurrentLabel,2,0);
    driverControlLayout->addWidget(driverMotorCurrentInput,2,1);
    driverControlLayout->addWidget(driverEMFImaginaryLabel,3,0);
    driverControlLayout->addWidget(driverEMFImaginaryInput,3,1);
    driverControlLayout->addWidget(driverDSPBoardLabel,4,0);
    driverControlLayout->addWidget(driverDSPBoardInput,4,1);
    driverControlLayout->addWidget(driverDcBusLabel,5,0);
    driverControlLayout->addWidget(driverDcBusInput,5,1);
    driverControlLayout->addWidget(driverOdometerLabel,6,0);
    driverControlLayout->addWidget(driverOdometerInput,6,1);
    driverControlLayout->addWidget(driverControlDoneButton,7,0);

    driverControlDetailsWidget->setLayout(driverControlLayout);
    driverControlDetailsWidget->setWindowFlags(Qt::Window);
    driverControlDetailsWidget->show();
}



void Window::setupUi()
{
   QWidget* mainWidget = new QWidget(this);
   QFormLayout* layout = new QFormLayout;

   QPushButton* connectButton = new QPushButton("&Connect", this);
   connect(connectButton, SIGNAL(clicked()), this, SLOT(attemptConnection()));
   comPortLineEdit_ = new QLineEdit("/dev/ttyUSB0", this);
   connectionStatusLabel_ = new QLabel("Not connected", this);

   QComboBox* modeSelectionComboBox = new QComboBox();
   modeSelectionComboBox->addItem("Random");
   modeSelectionComboBox->addItem("Specified");
   connect(modeSelectionComboBox, SIGNAL(editTextChanged(QString)), this, SLOT(differentModeSelected()));

   QPushButton* sendKeyDriverControlButton = new QPushButton("Send Key Driver Control", this);
   connect(sendKeyDriverControlButton, SIGNAL(clicked()), this, SLOT(sendKeyDriverControl()));
   QPushButton* keyDriverControlDetailsButton = new QPushButton("Details", this);
   connect(keyDriverControlDetailsButton, SIGNAL(clicked()), this, SLOT(keyDriverControlDetails()));

   QPushButton* sendDriverControlDetailsButton = new QPushButton("Send Driver Control Details", this);
   connect(sendDriverControlDetailsButton, SIGNAL(clicked()), this, SLOT(sendDriverControlDetails()));
   QPushButton* driverControlDetailsButton = new QPushButton("Details", this);
   connect(driverControlDetailsButton, SIGNAL(clicked()), this, SLOT(driverControlDetails()));

   QPushButton* sendFaultsButton = new QPushButton("Send Faults", this);
   connect(sendFaultsButton, SIGNAL(clicked()), this, SLOT(sendFaults()));
   QPushButton* faultsDetailsButton = new QPushButton("Details", this);

   QPushButton* sendBatteryDataButton = new QPushButton("Send Battery Data", this);
   connect(sendBatteryDataButton, SIGNAL(clicked()), this, SLOT(sendBatteryData()));
   QPushButton* batteryDataDetailsButton = new QPushButton("Details", this);

   QPushButton* sendCmuDataButton = new QPushButton("Send Cmu Data", this);
   connect(sendCmuDataButton, SIGNAL(clicked()), this, SLOT(sendCmuData()));
   QPushButton* cmuDataDetailsButton = new QPushButton("Details", this);

   QPushButton* sendMpptDataButton = new QPushButton("Send Mppt Data", this);
   connect(sendMpptDataButton, SIGNAL(clicked()), this, SLOT(sendMpptData()));
   QPushButton* mpptDataDetailsButton = new QPushButton("Details", this);

   QPushButton* sendAllButton = new QPushButton("Send All", this);
   connect(sendAllButton, SIGNAL(clicked()), this, SLOT(sendAll()));

   layout->addRow(modeSelectionComboBox, connectButton);
   layout->addRow(comPortLineEdit_);
   layout->addRow(connectionStatusLabel_);
   layout->addRow(keyDriverControlDetailsButton, sendKeyDriverControlButton);
   layout->addRow(driverControlDetailsButton, sendDriverControlDetailsButton);
   layout->addRow(faultsDetailsButton, sendFaultsButton);
   layout->addRow(batteryDataDetailsButton, sendBatteryDataButton);
   layout->addRow(cmuDataDetailsButton, sendCmuDataButton);
   layout->addRow(mpptDataDetailsButton, sendMpptDataButton);
   layout->addRow(sendAllButton);
   mainWidget->setLayout(layout);
   setCentralWidget(mainWidget);
}
