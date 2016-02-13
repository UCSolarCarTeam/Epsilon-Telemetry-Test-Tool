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
    UILayer/Window.h


SOURCES += \
    main.cpp \
    TestApplication.cpp \
    BusinessLayer/CrcCalculator.cpp \
    BusinessLayer/TelemetryReporting.cpp \
    DataLayer/CcsDefines.cpp \
    DataLayer/CmuData.cpp \
    DataLayer/MpptData.cpp \
    DataLayer/VehicleData.cpp \
    UILayer/Window.cpp
