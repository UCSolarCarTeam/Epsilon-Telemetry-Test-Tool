TEMPLATE = app

LIBS += \
    -L../ViewLayer/.lib -lViewLayer \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../UILayer/.lib -lUILayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../Peripherals/.lib -lPeripherals \

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

LIBS += -ldl

PRE_TARGETDEPS += \
    ../ViewLayer/.lib/* \
    ../BusinessLayer/.lib/* \
    ../UILayer/.lib/* \
    ../DataLayer/.lib/* \
    ../Peripherals/.lib/* 

TARGET = telemTestApp
DESTDIR = ../bin

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/ ../BusinessLayer/ ../UILayer/

HEADERS  += \
    $$PWD/TestApplication.h \

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/TestApplication.cpp \
