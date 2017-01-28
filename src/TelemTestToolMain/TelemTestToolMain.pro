TEMPLATE = app

LIBS += -L../../build/.lib -lBusinessLayer -lViewLayer -lUILayer -lPeripherals

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../../build/.lib/*

TARGET = telemTestApp
DESTDIR = ../../build

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/ ../BusinessLayer/ 

HEADERS  += \
    $$PWD/TestApplication.h \

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/TestApplication.cpp \
