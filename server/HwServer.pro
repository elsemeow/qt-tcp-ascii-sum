QT += core
QT += network
QT -= gui

TARGET = HwServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hwclientproc.cpp \
    hwserverproc.cpp

HEADERS += \
    hwclientproc.h \
    hwserverproc.h

RC_FILE = serverico.rc
