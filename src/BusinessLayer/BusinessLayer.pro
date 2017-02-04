TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/CrcCalculator.h \
    $$PWD/SerialReporting.h \
    $$PWD/InternetReporting.h \
    $$PWD/I_CommunicationService.h \
    $$PWD/CommunicationService.h \
    $$PWD/Util.h \

SOURCES += \
    $$PWD/CrcCalculator.cpp \
    $$PWD/SerialReporting.cpp \
    $$PWD/InternetReporting.cpp \
    $$PWD/CommunicationService.cpp \
    $$PWD/Util.cpp \
