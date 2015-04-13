#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T19:25:05
#
#-------------------------------------------------

QT       += core network gui
QT += dbus


TARGET = daemon0
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    daemon.cpp \
    ../congratulations0/dbusconnector.cpp

HEADERS += \
    daemon.h \
    ../congratulations0/dbusconnector.h

QDBUS_DEBUG = 1

QMAKE_CFLAGS_DEBUG += -std=c++11 -fpermissive
QMAKE_LFLAGS += -std=c++11 -fpermissive
QMAKE_CXXFLAGS += -std=c++11 -fpermissive

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/release/ -lcongratulations_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/debug/ -lcongratulations_lib
else:unix: LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/ -lcongratulations_lib

INCLUDEPATH += $$PWD/../congratulations_lib
DEPENDPATH += $$PWD/../congratulations_lib
