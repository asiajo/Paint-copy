#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T09:59:04
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        paint.cpp \
    scribblearea.cpp \
    drawable.cpp \
    scribble.cpp \
    line.cpp \
    rectangle.cpp \
    ellipse.cpp

HEADERS += \
        paint.h \
    scribblearea.h \
    drawable.h \
    scribble.h \
    line.h \
    rectangle.h \
    ellipse.h

FORMS += \
        paint.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    Resources/copy.png \
    Resources/cut.png \
    Resources/new.png \
    Resources/open.png \
    Resources/paste.png \
    Resources/print.png \
    Resources/redo.png \
    Resources/save.png \
    Resources/undo.png
