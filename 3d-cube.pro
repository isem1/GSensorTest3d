greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3d-cube
TEMPLATE = app

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
    C++14 \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
