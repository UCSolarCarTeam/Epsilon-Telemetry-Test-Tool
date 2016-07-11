#pragma once
/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/
#include <QObject>

class VehicleData;
class I_CommPeripheral;
class QIODevice;
class View;

class TelemetryReporting : public QObject
{
    Q_OBJECT
public:
   TelemetryReporting(I_CommPeripheral& peripheral,
                      VehicleData& vehicleData,
                      View& view);

private slots:
   void sendKeyDriverControlTelemetry();
   void sendDriverControlDetails();
   void sendFaults();
   void sendBatteryData();
   void sendCmuData();
   void sendMpptData();
   void sendAll();

private:
   // Will return length of framed data
   unsigned int frameData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* frameData);
   // Will return length of encoded data
   unsigned int stuffData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* encodedData);
   // Add checksum into data at index length and length + 1
   void addChecksum(unsigned char* data, unsigned int length);
   void writeFloatIntoArray(unsigned char* data, int index, const float& value);

private:
   I_CommPeripheral& outputPeripheral_;
   VehicleData& vehicleData_;
   View& view_;
};
