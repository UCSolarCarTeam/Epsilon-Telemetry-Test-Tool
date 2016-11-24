! include( common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets
QT += network
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
    BusinessLayer/CommunicationService.h \
    DataLayer/BatteryData.h \
    DataLayer/BatteryFaultsData.h \
    DataLayer/CcsDefines.h \
    DataLayer/CmuData.h \
    DataLayer/DriverControlsData.h \
    DataLayer/KeyMotorData.h \
    DataLayer/LightsData.h \
    DataLayer/MotorDetailsData.h \
    DataLayer/MotorFaultsData.h \
    DataLayer/MpptData.h \
    UILayer/Window.h \
    ViewLayer/View.h \
    Peripherals/SerialPortPeripheral.h \
    Peripherals/I_CommPeripheral.h \
    BusinessLayer/InternetReporting.h \
    BusinessLayer/SerialReporting.h

SOURCES += \
    main.cpp \
    TestApplication.cpp \
    BusinessLayer/CrcCalculator.cpp \
    BusinessLayer/CommunicationService.cpp \
    UILayer/Window.cpp \
    ViewLayer/View.cpp \
    Peripherals/SerialPortPeripheral.cpp \
    BusinessLayer/InternetReporting.cpp \
    BusinessLayer/SerialReporting.cpp
