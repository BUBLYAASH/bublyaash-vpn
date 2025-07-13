TEMPLATE = app
TARGET = VPN
INCLUDEPATH += . include/ /opt/homebrew/opt/boost/include
LIBS += -L/opt/homebrew/opt/boost/lib -lboost_system

DEFINES += QT_DEPRECATED_WARNINGS

QT += gui core widgets network

HEADERS += \
    include/main_window.h

SOURCES += \
    src/main.cpp \
    src/main_window.cpp

RESOURCES += resources.qrc
