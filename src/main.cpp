/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include "TestApplication.h"

int main(int argc, char** argv)
{
    QScopedPointer<KeyMotorData> aa(new KeyMotorData());
    QScopedPointer<MotorDetailsData> b(new MotorDetailsData());
    QScopedPointer<MotorDetailsData> c(new MotorDetailsData());
    QScopedPointer<DriverControlsData> d (new DriverControlsData());
    QScopedPointer<MotorFaultsData> e (new MotorFaultsData());
    QScopedPointer<BatteryFaultsData> f (new BatteryFaultsData());
    QScopedPointer<BatteryData> g(new BatteryData());
    QScopedPointer<CmuData> h (new CmuData());
    QScopedPointer<MpptData> i (new MpptData());
    QScopedPointer<LightsData> j( new LightsData());

    QScopedPointer<InternetReporting> test(new InternetReporting(*aa, *b, *c, *d, *e, *f, *g ,*h ,*i, *j));

    test->sendAll();

    TestApplication a(argc, argv);
    return a.exec();
}
