INCLUDEPATH += .
QT+=widgets serialport

CONFIG += c++11 debug

!win32 {
}

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

LIBS += -lSimpleAmqpClient -lrabbitmq
