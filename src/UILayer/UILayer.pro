TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = .lib

HEADERS += \
    $$PWD/Window.h \
    $$PWD/InternetWindow.h \
    $$PWD/SerialWindow.h \
    $$PWD/PacketWindow.h \
    $$PWD/Packet/DriverControlsTab.h \
    $$PWD/Packet/MotorTab.h \
    $$PWD/Packet/BatteryTab.h \
    $$PWD/Packet/BatteryFaultsTab.h \
    $$PWD/Packet/LightsTab.h \
    $$PWD/Packet/MpptTab.h \
    $$PWD/Packet/MotorFaultsTab.h \
    $$PWD/Packet/AuxBmsTab.h

SOURCES += \
    $$PWD/Window.cpp \
    $$PWD/InternetWindow.cpp \
    $$PWD/SerialWindow.cpp \
    $$PWD/PacketWindow.cpp \
    $$PWD/Packet/DriverControlsTab.cpp \
    $$PWD/Packet/MotorTab.cpp \
    $$PWD/Packet/BatteryTab.cpp \
    $$PWD/Packet/BatteryFaultsTab.cpp \
    $$PWD/Packet/LightsTab.cpp \
    $$PWD/Packet/MpptTab.cpp \
    $$PWD/Packet/MotorFaultsTab.cpp \
    $$PWD/Packet/AuxBmsTab.cpp

FORMS += \
    $$PWD/Packet/DriverControlsTab.ui \
    $$PWD/Packet/MotorTab.ui \
    $$PWD/Packet/BatteryTab.ui \
    $$PWD/Packet/BatteryFaultsTab.ui \
    $$PWD/Packet/LightsTab.ui \
    $$PWD/Packet/MpptTab.ui \
    $$PWD/Packet/MotorFaultsTab.ui \
    $$PWD/Packet/AuxBmsTab.ui
