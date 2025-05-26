TEMPLATE = app
TARGET = VPN
INCLUDEPATH += . include/

DEFINES += QT_DEPRECATED_WARNINGS

QT += gui core widgets

HEADERS += \
    include/mainwindow.h

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

RESOURCES += \
    resources.qrc
