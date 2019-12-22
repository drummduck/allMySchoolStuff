#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T16:08:50
#
#-------------------------------------------------

QT       += core gui sql multimedia webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = BoujeeBall
TEMPLATE = app
DEFINES += SFML_STATIC


unix: CONFIG += std=c++11
QMAKE_CXXFLAGS += -std=c++11


unix:!macx: LIBS += -L$$PWD/Box2D-master/Box2D/Build/Box2D/ -lBox2D

INCLUDEPATH += $$PWD/Box2D-master/Box2D

DEPENDPATH += $$PWD/Box2D-master/Box2D

unix:!macx: PRE_TARGETDEPS += $$PWD/Box2D-master/Box2D/Build/Box2D/libBox2D.a


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
        -lxcb-randr\
        -lX11-xcb\
        -lfreetype\
        -lxcb-shm\
        $$PWD/libxcb-image.a\
        $$PWD/libxcb-util.a\
        $$PWD/libudev.a




INCLUDEPATH+=$$PWD/SFML-2.3.2/include


SOURCES += main.cpp\
        BoujeeBall.cpp \
        level.cpp \
        WorldObject.cpp \
    GameWorld.cpp \
    ContactListener.cpp \
    qsfmlcanvas.cpp \
    mycanvas.cpp \
    loginform.cpp \
    levelselector.cpp \
    textbox.cpp \
    game.cpp \
    networkmonitor.cpp \
    soundsystem.cpp

HEADERS  += BoujeeBall.h \
        level.h \
        WorldObject.h \
    GameWorld.h \
    ContactListener.h \
	qsfmlcanvas.h \
    mycanvas.h \
    loginform.h \
    levelselector.h \
    textbox.h \
    game.h \
    networkmonitor.h \
    soundsystem.h

RESOURCES += \
    levels.qrc \
    textures.qrc

DISTFILES += \
    textures/court.png \
    textures/ball.png \
    lessons/lesson2.txt \
    lessons/lesson3.txt \
    levels/level3.txt \
    lessons/lesson6.txt
FORMS    += BoujeeBall.ui \
    loginform.ui \
    levelselector.ui \
    game.ui
