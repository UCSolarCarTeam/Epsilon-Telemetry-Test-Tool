#pragma once

struct MpptData
{
   MpptData()
   : arrayVoltage_(71)
   , arrayCurrent_(72)
   , batteryVoltage_(73)
   , temperature_(74)
   {}

   float arrayVoltage_;
   float arrayCurrent_;
   float batteryVoltage_;
   float temperature_;
};
