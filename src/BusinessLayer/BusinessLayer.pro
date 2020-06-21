TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

INCLUDEPATH += ../DataLayer/ ../ViewLayer/ ../Peripherals/

DESTDIR = .lib

HEADERS += \
    $$PWD/CrcCalculator.h \
    $$PWD/SerialReporting.h \
    $$PWD/InternetReporting.h \
    $$PWD/I_CommunicationService.h \
    $$PWD/CommunicationService.h \
    $$PWD/Util.h \
    $$PWD/Packet/MpptReporting.h \
    $$PWD/PacketReporting.h \
    $$PWD/Packet/BatteryReporting.h \
    $$PWD/Packet/BatteryFaultsReporting.h \
    $$PWD/Packet/DriverControlsReporting.h \
    $$PWD/Packet/LightsReporting.h \
    $$PWD/Packet/KeyMotorReporting.h \
    $$PWD/Packet/MotorDetailsReporting.h \
    $$PWD/Packet/MotorFaultsReporting.h \
    $$PWD/Packet/AuxBmsReporting.h

SOURCES += \
    $$PWD/CrcCalculator.cpp \
    $$PWD/SerialReporting.cpp \
    $$PWD/InternetReporting.cpp \
    $$PWD/CommunicationService.cpp \
    $$PWD/Util.cpp \
    $$PWD/Packet/MpptReporting.cpp \
    $$PWD/PacketReporting.cpp \
    $$PWD/Packet/BatteryReporting.cpp \
    $$PWD/Packet/BatteryFaultsReporting.cpp \
    $$PWD/Packet/DriverControlsReporting.cpp \
    $$PWD/Packet/LightsReporting.cpp \
    $$PWD/Packet/KeyMotorReporting.cpp \
    $$PWD/Packet/MotorDetailsReporting.cpp \
    $$PWD/Packet/MotorFaultsReporting.cpp \
    $$PWD/Packet/AuxBmsReporting.cpp
