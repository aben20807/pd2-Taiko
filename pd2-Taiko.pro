#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T20:46:21
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia #sound
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    hit.cpp \
    num.cpp \
    other.cpp \
    hitr.cpp \
    hitb.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    hit.h \
    num.h \
    other.h \
    hitr.h \
    hitb.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
