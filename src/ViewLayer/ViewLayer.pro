TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../UILayer/ $$PWD/

DESTDIR = .lib

HEADERS += \
    $$PWD/InternetView.h \
    $$PWD/SerialView.h \
    PacketView.h

SOURCES += \
    $$PWD/InternetView.cpp \
    $$PWD/SerialView.cpp \
    PacketView.cpp
