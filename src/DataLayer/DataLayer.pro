TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../UILayer/ $$PWD/

DESTDIR = ../../build/.lib

HEADERS += \
    $$PWD/BatteryData.h \
    $$PWD/BatteryFaultsData.h \
    $$PWD/DriverControlsData.h \
    $$PWD/KeyMotorData.h \
    $$PWD/LightsData.h \
    $$PWD/MotorDetailsData.h \
    $$PWD/MotorFaultsData.h \
    $$PWD/MpptData.h \
    AuxBmsData.h

SOURCES += \
    BatteryData.cpp \
    BatteryFaultsData.cpp \
    DriverControlsData.cpp \
    KeyMotorData.cpp \
    LightsData.cpp \
    MotorDetailsData.cpp \
    MotorFaultsData.cpp \
    MpptData.cpp \
    AuxBmsData.cpp

