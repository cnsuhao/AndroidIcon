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
DESTDIR      = $$PWD/../bin/

MOC_DIR     += ./bin/moc/
UI_DIR      += ./bin/ui/
RCC_DIR     += ./bin/rcc/
OBJECTS_DIR += ./bin/obj

SOURCES +=  $$PWD/main.cpp\
            $$PWD/dialogmain.cpp \
            $$PWD/PublicDialog/publicdialog.cpp

HEADERS  += $$PWD/dialogmain.h \
            $$PWD/PublicDialog/publicdialog.h

FORMS    += $$PWD/dialogmain.ui

RESOURCES += \
            $$PWD/AndroidIcon.qrc

mac {
    ICON =  $$PWD/Resource/icon.icns
}
