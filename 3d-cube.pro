greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3d-cube
TEMPLATE = app

VERSION = 0.9.0.1
RC_ICONS = res/icon.ico

INCLUDEPATH += inc
QT += 3dcore 3drender 3dinput 3dextras
QT += widgets
QT += serialport

SOURCES += \
    src/main.cpp \
    src/scenemodifier.cpp \
    src/inputdialog.cpp \
    src/serialport.cpp \
    src/mainwindow.cpp

HEADERS += \
    inc/scenemodifier.hpp \
    inc/inputdialog.hpp \
    inc/serialport.hpp \
    inc/parameters.hpp \
    inc/mainwindow.hpp

DEFINES += \
    QT_DEPRECATED_WARNINGS

CONFIG += \
    C++14
