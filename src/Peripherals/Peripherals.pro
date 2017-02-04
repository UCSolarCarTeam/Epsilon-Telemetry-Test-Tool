TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/SerialPortPeripheral.h \
    $$PWD/InternetPeripheral.h \

SOURCES += \
    $$PWD/SerialPortPeripheral.cpp \
    $$PWD/InternetPeripheral.cpp \
