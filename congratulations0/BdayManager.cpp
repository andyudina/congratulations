#include "BdayManager.h"


BdayManager::BdayManager(QObject *parent): Manager(parent) {
    dbManager = BdaysDBManager::Instance();
    roles[PhotoRole] = "photo";
    roles[ColorRole] = "backgroundColor";
    roles[BorderColorRole] = "borderColor";
    roles[TextColorRole] = "textColor";
    roles[NameRole] = "name";
    roles[DateRole] = "date";
    roles[MissedFlagRole] = "isMissed";
}



QHash<int, QByteArray> BdayManager::roleNames() const {
    return roles;
}



QVariant BdayManager::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() > listEntries->count()) {
        return QVariant();
     }
    BdayEntry *bdayEntry = reinterpret_cast<BdayEntry*>(listEntries->at(index.row()));
    QVariant result;
    switch(role) {
    case PhotoRole:
        result = QVariant::fromValue(bdayEntry->photo);
        break;
    case ColorRole:
        result = QVariant::fromValue(bdayEntry->color);
        break;
    case BorderColorRole:
        result = QVariant::fromValue(bdayEntry->borderColor);
        break;
    case TextColorRole:
        result = QVariant::fromValue(bdayEntry->textColor);
        break;
    case NameRole:
        result = QVariant::fromValue(bdayEntry->name);
        break;
    case DateRole:
        result = QVariant::fromValue(bdayEntry->date);
        break;
    case MissedFlagRole:
        result = QVariant::fromValue(bdayEntry->isMissed);
        break;
    }
    return result;
}

void BdayManager::onDbaseInfoGetChanged() {
    //получить время последнего обновления
    uint lastUpdatedTimestamp = dbCommunicationStrategy.getLastTimestamp();

    //получить список новых обновлений
    auto recentlyUpdatedListHash = dbManager->getRecentlyUpdatedElements(lastUpdatedTimestamp);

    if (recentlyUpdatedListHash != nullptr) {
        dbCommunicationStrategy.updateCurrentList(
               listEntries,
               recentlyUpdatedListHash,
               BdayEntry::dateIsLess); //функция сортировки элементов
                                       //влияет на порядок добавления обновлений

        //очистить recentlyUpdatedListHash
        clearQHash(recentlyUpdatedListHash);
    }
}

