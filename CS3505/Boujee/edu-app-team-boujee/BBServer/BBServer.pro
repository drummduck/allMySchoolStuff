QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = BBServer
CONFIG += console
CONFIG -= app_bundle

LIBS+=-L$$PWD/SFML-2.3.2/lib

LIBS += $$PWD/SFML-2.3.2/lib/libsfml-audio-s.a\
        $$PWD/SFML-2.3.2/lib/libsfml-window-s.a\
        $$PWD/SFML-2.3.2/lib/libsfml-graphics-s.a\
        $$PWD/SFML-2.3.2/lib/libsfml-network-s.a\
        $$PWD/SFML-2.3.2/lib/libsfml-system-s.a\
        -lX11\
        -lxcb\
        -ljpeg\
        -lGL\
        -ldl\
        -lxcb-randr\
        -lX11-xcb\
        -lfreetype\
        -lxcb-shm\
        $$PWD/libxcb-image.a\
        $$PWD/libxcb-util.a\
        $$PWD/libudev.a


INCLUDEPATH+=$$PWD/SFML-2.3.2/include


TEMPLATE = app

SOURCES += main.cpp \
    bbserver.cpp

HEADERS += \
    bbserver.h


unix:!macx: LIBS += -L$$PWD/usr/lib64/ -lmysqlcppconn-static

INCLUDEPATH += $$PWD/usr/include
DEPENDPATH += $$PWD/usr/include

unix:!macx: PRE_TARGETDEPS += $$PWD/usr/lib64/libmysqlcppconn-static.a
