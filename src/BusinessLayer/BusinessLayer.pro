TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/CrcCalculator.h \
    $$PWD/TelemetryReporting.h \
    $$PWD/I_CommunicationService.h \
    $$PWD/CommunicationService.h \

SOURCES += \
    $$PWD/CrcCalculator.cpp \
    $$PWD/TelemetryReporting.cpp \
    $$PWD/CommunicationService.cpp \
