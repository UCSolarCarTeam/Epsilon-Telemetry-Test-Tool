#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
: QApplication(argc, argv)
, serialPort_(new QSerialPort())
, vehicleData_(new VehicleData())
, telemetryReporting_(new TelemetryReporting(*serialPort_,*serialPort_, *vehicleData_))
{
}

TestApplication::~TestApplication()
{
}
