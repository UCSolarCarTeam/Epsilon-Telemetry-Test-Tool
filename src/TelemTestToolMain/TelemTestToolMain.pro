TEMPLATE = app

LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lDataLayer -lPeripherals

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../../build/.lib/*

TARGET = telemTestApp
DESTDIR = ../../build

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/ ../BusinessLayer/ ../UILayer/

HEADERS  += \
    $$PWD/TestApplication.h \

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/TestApplication.cpp \
