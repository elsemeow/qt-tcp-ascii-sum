QT += core
QT += network
QT -= gui

TARGET = HwClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hwclientapp.cpp

HEADERS += \
    hwclientapp.h

RC_FILE = clientico.rc

