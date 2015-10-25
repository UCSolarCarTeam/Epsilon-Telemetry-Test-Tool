#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
: QApplication(argc, argv)
, serialPort_(new QSerialPort())
, vehicleData_(new VehicleData())
, telemetryReporting_(new TelemetryReporting(*serialPort_, *vehicleData_))
, window_(new Window(*serialPort_, *telemetryReporting_))
{
}

TestApplication::~TestApplication()
{
}
