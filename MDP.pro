#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T17:50:59
#
#-------------------------------------------------

QT       += testlib
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        maindialog.cpp \
    shapes/arrow.cpp \
    shapes/bar.cpp \
    shapes/block.cpp \
    shapes/entrance.cpp \
    shapes/exit.cpp \
    shapes/ifblock.cpp \
    shapes/shape.cpp \
    scene.cpp \
    creatediagramform.cpp \
    qtserialization.cpp \
    serializeshape.cpp \
    shapetests/block_test.cpp

HEADERS  += maindialog.h \
    allocator/allocator.h \
    shapes/arrow.h \
    shapes/bar.h \
    shapes/block.h \
    shapes/entrance.h \
    shapes/exit.h \
    shapes/ifblock.h \
    shapes/shape.h \
    diagram.h \
    scene.h \
    shapes/shapetype.h \
    creatediagramform.h \
    shapes/arrowdirection.h \
    qtserialization.h \
    serializeshape.h \
    shapetests/block_test.h

FORMS    += maindialog.ui \
    creatediagramform.ui
