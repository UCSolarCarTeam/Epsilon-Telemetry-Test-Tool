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
#    BusinessLayer/CommunicationServiceTestWrapper.h \
    BusinessLayer/MockCommunicationService.h \


SOURCES += \
    testmain.cpp \
    BusinessLayer/TelemetryReportingTest.cpp \
#    BusinessLayer/CommunicationServiceTestWrapper.cpp \

DESTDIR = ../../build/tests
#DESTDIR = ../../build/.tests

