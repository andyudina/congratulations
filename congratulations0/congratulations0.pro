# Add more folders to ship with the application, here
folder_01.source = qml/congratulations0
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QT+= dbus
# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    BdayManager.cpp \
    friendsmanager.cpp \
    templatemanager.cpp \
    personaltemplatemanager.cpp \
    settingsmanager.cpp \
    templateidtranslator.cpp \
    app.cpp \
    dbusconnector.cpp \
    manager.cpp \
    dbcommunicationstrategy.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qml/friends.qml \
    qml/friends_edit.qml \
    qml/template_for_friend.qml \
    qml/templates.qml \
    qml/settings.qml \
    qml/bdays.qml \
    qml/MainWindow.qml \
    android/version.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-et/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-de/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-it/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/AndroidManifest.xml

HEADERS += \
    BdayManager.h \
    manager.h \
    friendsmanager.h \
    templatemanager.h \
    personaltemplatemanager.h \
    settingsmanager.h \
    templateidtranslator.h \
    app.h \
    dbcommunicationstrategy.h \
    dbusconnector.h

RESOURCES += \
    res.qrc

QMAKE_CFLAGS_DEBUG += -std=c++11 -fpermissive
QMAKE_LFLAGS += -std=c++11 -fpermissive
QMAKE_CXXFLAGS += -std=c++11 -fpermissive

QDBUS_DEBUG = 1


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/release/ -lcongratulations_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/debug/ -lcongratulations_lib
else:unix: LIBS += -L$$PWD/../build-congratulations_lib-Desktop_Qt_5_1_1_GCC_64bit-Debug/ -lcongratulations_lib

INCLUDEPATH += $$PWD/../congratulations_lib
DEPENDPATH += $$PWD/../congratulations_lib
