#pragma once

struct CmuData
{
   CmuData()
   : pcbTemperature_(47)
   , cellTemperature_({48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62})
   , cellVoltage_({63, 64, 65, 66, 67, 68, 69, 70})
   {}

   float pcbTemperature_;
   float cellTemperature_[];
   float cellVoltage_[];
};
