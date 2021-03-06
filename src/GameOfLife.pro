#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T12:56:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

#.win32
#{
#    QMAKE_LFLAGS_RELEASE += -static -static-libgcc
#}

win32 {
        RC_FILE += winres.rc
        OTHER_FILES += winres.rc
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lifecell.cpp \
    processing.cpp \
    lifescene.cpp \
    lifeview.cpp \
    lifematrix.cpp \
    graphicsitemmatrix.cpp \
    settingsdialog.cpp \
    aboutdialog.cpp

HEADERS += \
        mainwindow.h \
    lifecell.h \
    processing.h \
    lifescene.h \
    lifeview.h \
    basematrix.h \
    lifematrix.h \
    graphicsitemmatrix.h \
    settingsdialog.h \
    aboutdialog.h

FORMS += \
        mainwindow.ui \
    settingsdialog.ui \
    aboutdialog.ui

RESOURCES += \
    resourses.qrc
