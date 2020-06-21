TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = runTestSuite

LIBS += \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../ViewLayer/.lib -lViewLayer \
    -L../UILayer/.lib -lUILayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../thirdparty/googletest/.lib -lgmock

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../BusinessLayer/ ../UILayer/

HEADERS += \
    BusinessLayer/MockCommunicationService.h \
    BusinessLayer/TestUtils.h \


SOURCES += \
    testmain.cpp \
    BusinessLayer/TestUtils.cpp \
    BusinessLayer/UtilTest.cpp \
    BusinessLayer/SerialReportingTest.cpp


!win32 {
}

DESTDIR = ../bin/tests
