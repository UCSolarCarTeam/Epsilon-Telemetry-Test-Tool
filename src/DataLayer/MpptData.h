#pragma once

struct MpptData
{
   MpptData()
   : mpptNumber(0)
   , alive(true)
   , arrayVoltage(71)
   , arrayCurrent(72)
   , batteryVoltage(73)
   , temperature(74)
   {}

   /* has to be between 0 and 2 (inclusive) */
   unsigned char mpptNumber;
   bool alive;
   unsigned short arrayVoltage;
   unsigned short arrayCurrent;
   unsigned short batteryVoltage;
   unsigned short temperature;
};
