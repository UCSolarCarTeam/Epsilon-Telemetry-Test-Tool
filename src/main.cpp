/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include "TestApplication.h"
#include "TestApplication_json.h"

int main(int argc, char** argv)
{
   TestApplication a(argc, argv);         //Serial data
   //TestApplication_json b(argc, argv);  //JSON data
   return a.exec();
   //return b.exec();
}
