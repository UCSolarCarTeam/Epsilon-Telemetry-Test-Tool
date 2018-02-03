TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/Window.h \
    $$PWD/InternetWindow.h \
    $$PWD/SerialWindow.h \
    $$PWD/PacketWindow.h \

SOURCES += \
    $$PWD/Window.cpp \
    $$PWD/InternetWindow.cpp \
    $$PWD/SerialWindow.cpp \
    $$PWD/PacketWindow.cpp \

FORMS += \
    PacketWindow.ui
