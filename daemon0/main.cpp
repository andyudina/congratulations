#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnectionInterface>
#include <QDebug>
#include <iostream>
#include <QObject>
#include "daemon.h"

int main(int argc, char *argv[])
{
    Daemon daemon(argc, argv);
    daemon.initialize();
    return daemon.exec();
}
