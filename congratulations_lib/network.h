#ifndef NETWORK_H
#define NETWORK_H

#include <QJsonObject>
#include <QtNetwork>
#include <map>
#include <QHash>
#include <QBitmap>

#include "congratulations_lib_global.h"
#include "listelement.h"

class CONGRATULATIONS_LIBSHARED_EXPORT Network {
//интерфейс для работы с сетью
//(использует демон)
public:
    Network();
    //отправить поздравления для конкретного друга
    static bool sendCongratulations(const FriendEntry&, bool);

    //получить всех друзей
    static QList<FriendEntry*>* getFriends();


//реализует работу с сетью
private:
    static const QString VK_API_SERVER ;//= "http://";
    //check network connection
    static bool ChekNetworkConnection();

    //используется для отправки Post and Get запросов
    static QJsonObject Post(const QHash<QString, QString>&);
    static QJsonObject Get(const QHash<QString, QString>&);

    //uploads file to vk server and returns error code;
    static int UploadImage(const QString&);

    //downloads image from vk server and save as file
    static QBitmap DownloadBitmap(const QString&);
};

#endif // NETWORK_H
