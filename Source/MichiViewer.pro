#-------------------------------------------------
#
# Project created by QtCreator 2014-02-27T22:25:38
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MichiViewer
TEMPLATE = app

RC_FILE = michiviewer.rc

SOURCES += main.cpp\
        widget.cpp \
    mediawidget.cpp

HEADERS  += widget.h \
    mediawidget.h

FORMS    += widget.ui \
    mediawidget.ui

OTHER_FILES += \
    michiviewer.rc
