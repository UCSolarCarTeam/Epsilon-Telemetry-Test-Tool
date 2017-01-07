TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = runTestSuite

LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lgmock #-libgmock.a #-lgtest -lgtest_main -lgmock

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
