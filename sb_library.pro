#-------------------------------------------------
#
# Project created by QtCreator 2016-11-12T20:29:56
#
#-------------------------------------------------

QT       -= core

QT       -= gui

TARGET = safeboard_library_qt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    visitor.cpp \
    book.cpp \
    controler.cpp \
    consoleui.cpp \
    model.cpp

HEADERS += \
    visitor.h \
    book.h \
    controler.h \
    consoleui.h \
    model.h

INCLUDEPATH += D:/boost_1_62_0_2
LIBS += "-LD:\boost_1_62_0_2\lib64-msvc-12.0"
