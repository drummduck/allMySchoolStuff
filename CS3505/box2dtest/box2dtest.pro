#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T17:18:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = box2dtest
TEMPLATE = app

INCLUDEPATH += Box2d-master/Box2D
LIBS += -L"/Box2d-master/Box2D/Build/Box2D"


SOURCES += main.cpp\
        boomchicka.cpp

HEADERS  += boomchicka.h

FORMS    += boomchicka.ui
