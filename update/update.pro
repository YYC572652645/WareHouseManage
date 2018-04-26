#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T09:32:19
#
#-------------------------------------------------

QT       += core gui network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = update
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlebar/titlebar.cpp \
    qreadwrite/qreadwriteini.cpp

HEADERS  += mainwindow.h \
    titlebar/titlebar.h \
    globaldef.hpp \
    qreadwrite/qreadwriteini.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc

TRANSLATIONS += english.ts\
                chinese.ts
