# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = QTserver
DESTDIR = ./Win32/Debug
QT += core network
CONFIG += debug console
DEFINES += QT_DLL QT_NETWORK_LIB
INCLUDEPATH += . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./MyTcpServer.h
SOURCES += ./main.cpp \
    ./MyTcpServer.cpp
