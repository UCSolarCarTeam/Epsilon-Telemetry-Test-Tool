TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = runTestSuite

# If google test is installed locally using a package manager it might be necessary to add -lgtest -lgtest_main -lgmock (use configuration 2)
# Configuration 1: manually compiled in the same folder (travis build config)
LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lgmock
# Configuration 2: locally installed google test and google mock
#LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lgmock -lgtest -lgtest_main

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../BusinessLayer/

PRE_TARGETDEPS += \
   ../../build/.lib/*

HEADERS += \
    BusinessLayer/MockCommunicationService.h \
    BusinessLayer/TestUtils.h \


SOURCES += \
    testmain.cpp \
    BusinessLayer/TestUtils.cpp \
    BusinessLayer/UtilTest.cpp \
    BusinessLayer/SerialReportingTest.cpp


!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../../build/tests
