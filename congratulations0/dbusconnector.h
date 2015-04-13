#ifndef DBUSCONNECTOR_H
#define DBUSCONNECTOR_H

#include <QObject>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnectionInterface>
#include <QDebug>

#define GUI_SERVICE_NAME "org.congratulator.Congratulations.GUI.QtDBus"
#define DBUS_OBJECT_NAME "/"
#define DBUS_INTERFACE_NAME "congratulator.dbus"
#define DAEMON_SERVICE_NAME "org.congratulator.Congratulations.DAEMON.QtDBus"
#define PARTNER_FUNCTION_TEMPLATE "announce%Changes"

//реализует стратегию взаимодействия с демоном по DBUS
//класс должен предоставлять сигналы:
//friendsInfoHasChanged()
//bdaysInfoHasChanged()

class DBusConnector : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", DBUS_INTERFACE_NAME)

public:
    explicit DBusConnector(QString&& ownServiceName,
                           QString&& ownObjectName,
                           QString&& patnerServiceName,
                           QString&& partnerObjectName,
                           QString&& partnerInterfaceName = DBUS_INTERFACE_NAME,
                           QObject *parent = 0);

    ~DBusConnector() = default;

public slots:
    //вызываемые другим процессом функции
    //по одной функции для каждой модели
    Q_SCRIPTABLE void announceFriendsChanges() {
        emit friendsInfoHasChanged();
    }

    Q_SCRIPTABLE void announceBdaysChanges() {
        emit bdaysInfoHasChanged();
    }

    Q_SCRIPTABLE void announceSettingsChanges() {
        emit settingsInfoHasChanged();
    }

    Q_SCRIPTABLE void announceTemplatesChanges() {
        emit templatesInfoHasChanged();
    }

    //подсоединиться к сервису и отправить запрос
    void connectAndAnnounce(const QString&);


signals:
    void friendsInfoHasChanged();
    void bdaysInfoHasChanged();
    void settingsInfoHasChanged();
    void templatesInfoHasChanged();

private:
    QString partnerServiceName;   //название сервиса, которому планируется отправлять запросы
    QString partnerInterfaceName; //название интерфейса сервиса
    QString partnerObjectName;    //название объекта

    //шаблон функции, которую вызывает dbus
    //должен содержать % на месте названия менеджера
    //который или которому посылается оповещение об изменении
    QString partnerFunctionTemplate = PARTNER_FUNCTION_TEMPLATE;

};

#endif // DBUSCONNECTOR_H
