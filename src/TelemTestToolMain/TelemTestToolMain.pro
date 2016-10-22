! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

! include( ../core.pri ) {
    error( "Couldn't find the core.pri file!" )
}

QT += widgets
TEMPLATE = app
TARGET = telemTestApp

# LIBS += -L../../build/.lib -lBusinessLayer -lDataLayer -lPeripherals

HEADERS  += \
    TestApplication.h \

SOURCES += \
    main.cpp \
    TestApplication.cpp \

#DESTDIR = ../build/.lib
DESTDIR = ../../build/
