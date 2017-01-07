TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = runTestSuite

#If google test is installed locally using a package manager it might be necessary to add -lgtest -lgtest_main -lgmock
LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lgmock

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../BusinessLayer/

PRE_TARGETDEPS += \
   ../../build/.lib/*

HEADERS += \
    BusinessLayer/MockCommunicationService.h \


SOURCES += \
    testmain.cpp \
    BusinessLayer/TelemetryReportingTest.cpp \


!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../../build/tests
