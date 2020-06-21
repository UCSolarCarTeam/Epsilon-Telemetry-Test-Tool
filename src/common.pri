INCLUDEPATH += .
QT+=widgets serialport

CONFIG += c++11 debug

!win32 {
}

CONFIG += conan_basic_setup
! include($$OUT_PWD/../conanbuildinfo.pri) {
    error("Could not find conanbuildinfo.pri file!")
}

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui
