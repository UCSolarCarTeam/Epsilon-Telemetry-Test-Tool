/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include "TestApplication.h"

int main(int argc, char** argv)
{
    #if QT_VERSION >= 0x050600
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    TestApplication a(argc, argv);
    return a.exec();
}
