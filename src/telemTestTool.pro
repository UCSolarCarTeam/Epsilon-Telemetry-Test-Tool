! include( common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app
TARGET = telemTestApp

HEADERS += *.h
SOURCES += *.cpp
