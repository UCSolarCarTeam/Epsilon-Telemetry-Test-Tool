TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = runTestSuite

#LIBS += -L../../build/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lInfrastructureLayer -lgmock
LIBS += -L../../build/.lib -lgtest -lgtest_main -lgmock

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

! include( ../core.pri ) {
    error( "Couldn't find the core.pri file!" )
}


HEADERS += \
    ../DataLayer/KeyMotorData.h
#    CommunicationLayer/CommDeviceControl/MockMessageForwarder.h \
#    InfrastructureLayer/Settings/MockSettings.h \
#    DataLayer/BatteryData/MockBatteryData.h \
#    DataLayer/FaultsData/MockFaultsData.h \
#    DataLayer/PowerData/MockPowerData.h \
#    DataLayer/VehicleData/MockVehicleData.h

SOURCES += \
    testmain.cpp \
    BusinessLayer/TelemetryReportingTest.cpp

DESTDIR = ../../build/tests
#DESTDIR = ../../build/.tests

