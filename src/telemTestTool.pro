! include( common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets
TEMPLATE = app
TARGET = telemTestApp
INCLUDEPATH = BusinessLayer \
    DataLayer \
    UILayer \
    ViewLayer \
    Peripherals

HEADERS  += \
    TestApplication.h \
    BusinessLayer/CrcCalculator.h \
    BusinessLayer/TelemetryReporting.h \
    DataLayer/CcsDefines.h \
    DataLayer/CmuData.h \
    DataLayer/MpptData.h \
    DataLayer/VehicleData.h \
    UILayer/Window.h \
    BusinessLayer/CommunicationServer.h \
    Peripherals/SerialPortPeripheral.h \
    ViewLayer/View.h


SOURCES += \
    main.cpp \
    TestApplication.cpp \
    BusinessLayer/CrcCalculator.cpp \
    BusinessLayer/TelemetryReporting.cpp \
    DataLayer/CmuData.cpp \
    DataLayer/MpptData.cpp \
    DataLayer/VehicleData.cpp \
    UILayer/Window.cpp \
    BusinessLayer/CommunicationServer.cpp \
    Peripherals/SerialPortPeripheral.cpp \
    ViewLayer/View.cpp
