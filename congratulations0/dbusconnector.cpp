#include "dbusconnector.h"


DBusConnector::DBusConnector(QString&& ownServiceName,
                             QString&& ownObjectName,
                             QString&& patnerServiceName_,
                             QString&& partnerObjectName_,
                             QString&& partnerInterfaceName_,
                             QObject *parent): QObject(parent) {

    QDBusConnection::sessionBus().registerService(ownServiceName);
    QDBusConnection::sessionBus().registerObject(ownObjectName, this, QDBusConnection::ExportAllSlots);
    partnerServiceName = std::move(patnerServiceName_);
    partnerObjectName = std::move(partnerObjectName_);
    partnerInterfaceName = std::move(partnerInterfaceName_);
}

void DBusConnector::connectAndAnnounce(const QString& changedManager) {
    QStringList serviceNames = QDBusConnection::sessionBus().interface()->registeredServiceNames();

    if (serviceNames.indexOf(partnerServiceName) != -1) { //проверить наличие вызываемого сревиса в списке

        QDBusInterface partnerDbusInterface(partnerServiceName, partnerObjectName, partnerInterfaceName);

        if (partnerDbusInterface.isValid()) { //если нужный интерфейс доступен
            QString methodName = partnerFunctionTemplate.replace("%", changedManager); //получаем имя метода
            partnerDbusInterface.call(methodName);  //вызываем метод по имени
        }

    }

}
