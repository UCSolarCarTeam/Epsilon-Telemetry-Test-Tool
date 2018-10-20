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
    $$PWD/AuxBmsData.h \
    DataContainer.h
    
SOURCES += \
    $$PWD/BatteryData.cpp \
    $$PWD/BatteryFaultsData.cpp \
    $$PWD/DriverControlsData.cpp \
    $$PWD/KeyMotorData.cpp \
    $$PWD/LightsData.cpp \
    $$PWD/MotorDetailsData.cpp \
    $$PWD/MotorFaultsData.cpp \
    $$PWD/MpptData.cpp \
    $$PWD/AuxBmsData.cpp \
    DataContainer.cpp
    