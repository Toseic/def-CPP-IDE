#-------------------------------------------------
#
# Project created by QtCreator 2022-05-10T19:16:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DEF_PLUS
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
        mainwindow.cpp \
    texteditor.cpp \
    settings.cpp \
    compileinf.cpp \
    settingstore.cpp

HEADERS  += mainwindow.h \
    texteditor.h \
    settings.h \
    compileinf.h \
    settingstore.h

FORMS    += mainwindow.ui \
    settings.ui \
    compileinf.ui

INCLUDEPATH += $$PWD/QScintilla/Qsci
CONFIG(debug, debug|release):LIBS += -L$$PWD/QScintilla/ -lqscintilla2_qt5d
#else::CONFIG(release, debug|release):LIBS += -L$$PWD/QScintilla/ -lqscintilla2_qt5

DISTFILES += \
    icon.png \

RESOURCES += \
    theme.qrc

