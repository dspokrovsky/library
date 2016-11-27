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

QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp \
    model.cpp \
    view.cpp \
    controler.cpp

HEADERS += \
    visitor.h \
    book.h \
    controler.h \
    model.h \
    view.h \
    observer.h \
    databaseinterface.hpp


