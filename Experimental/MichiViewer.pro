#-------------------------------------------------
#
# Project created by QtCreator 2014-02-27T22:25:38
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MichiViewer
TEMPLATE = app


SOURCES += main.cpp\
    mediawidget.cpp \
    widget.cpp \
    controlpanel.cpp

HEADERS  += \
    mediawidget.h \
    widget.h \
    controlpanel.h

FORMS    += widget.ui \
    mediawidget.ui \
    controlpanel.ui
