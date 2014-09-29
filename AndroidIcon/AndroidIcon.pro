#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T18:42:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET       = AndroidIcon
TEMPLATE     = app
CONFIG      += c++11
DESTDIR      = ../bin/

MOC_DIR     += ./bin/moc/
UI_DIR      += ./bin/ui/
RCC_DIR     += ./bin/rcc/
OBJECTS_DIR += ./bin/obj

SOURCES += main.cpp\
        dialogmain.cpp

HEADERS  += dialogmain.h

FORMS    += dialogmain.ui

RESOURCES += \
    AndroidIcon.qrc

mac {
    ICON = ./Resource/icon.icns
}
