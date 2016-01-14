#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T18:06:35
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LingProg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    help.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    health.cpp \
    counter.cpp

HEADERS  += mainwindow.h \
    about.h \
    help.h \
    player.h \
    bullet.h \
    enemy.h \
    score.h \
    game.h \
    health.h \
    counter.h

FORMS    += mainwindow.ui \
    about.ui \
    help.ui

RESOURCES += \
    resources.qrc

CONFIG+=static
