#include "network.h"

const QString  Network::VK_API_SERVER ;//= "http://";

bool Network::ChekNetworkConnection() {
    return true;
}

QJsonObject Network::Post(const QHash<QString, QString>& postArgs) {
    QJsonObject resultJSONObject;
    return resultJSONObject;
}

QJsonObject Network::Get(const QHash<QString, QString>& getArgs) {
    QJsonObject resultJSONObject;
    return resultJSONObject;
}


int Network::UploadImage(const QString& request) {
    return 0;
}

QBitmap Network::DownloadBitmap(const QString& request) {
    QBitmap result;
    return result;
}

bool Network::sendCongratulations(const FriendEntry& friendEntry, bool messageDest) {return true;}

QList<FriendEntry*>* Network::getFriends() {return nullptr;}



