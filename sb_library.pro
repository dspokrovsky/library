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
    controler.cpp \
    model.cpp \
    view.cpp

HEADERS += \
    visitor.h \
    book.h \
    controler.h \
    model.h \
    view.h \
    observer.h

INCLUDEPATH += D:/boost_1_62_0_2
LIBS += "-LD:\boost_1_62_0_2\lib64-msvc-12.0"
