#pragma once

struct MpptData
{
   MpptData()
   : arrayVoltage(71)
   , arrayCurrent(72)
   , batteryVoltage(73)
   , temperature(74)
   {}

   unsigned short arrayVoltage;
   unsigned short arrayCurrent;
   unsigned short batteryVoltage;
   unsigned short temperature;
};
