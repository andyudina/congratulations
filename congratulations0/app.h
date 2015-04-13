#ifndef APP_H
#define APP_H


#include "qmlapplicationviewer.h"
#include "BdayManager.h"
#include "friendsmanager.h"
#include "templatemanager.h"
#include "personaltemplatemanager.h"
#include "settingsmanager.h"
#include "dbusconnector.h"

#include <QApplication>
#include <QtDeclarative>


class App: public QApplication
{
public:
    App(int& argc, char * argv[]);
    ~App();

    //инициализация моделей для вьюшек
    //инициализация ApplicationViewer
    //запуск event loop
    int startGUI();

private:
    //для взаимодействия по dbus с процессом демона
    DBusConnector* connector;

};

#endif // APP_H
