TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../UILayer/ $$PWD/

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/View.h

SOURCES += \
    $$PWD/View.cpp
