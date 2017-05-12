TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../UILayer/ $$PWD/

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/InternetView.h \
    $$PWD/SerialView.h

SOURCES += \
    $$PWD/InternetView.cpp \
    $$PWD/SerialView.cpp
