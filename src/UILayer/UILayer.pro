TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/InternetWindow.h \
    $$PWD/SerialWindow.h

SOURCES += \
    $$PWD/InternetWindow.cpp \
    $$PWD/SerialWindow.cpp
