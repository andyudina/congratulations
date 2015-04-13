#include "friendsmanager.h"



FriendsManager::FriendsManager(TemplateIdTranslator* translator_, QObject *parent):
    Manager(parent), translator(translator_) {
    firstDisplayedElement = STATE_IS_NOT_SELECTED;
    dbManager = FriendsDBManager::Instance();
    roles[PhotoRole] = "photo";
    roles[NameRole] = "name";
    roles[DateRole] = "date";
    roles[TemplateRole] = "template";
    roles[DeletedFlagRole] = "friendIsDeleted";
    roles[MissedFlagRole] = "friendIsMissed";
}

FriendsManager::~FriendsManager() {
    auto updatedList = dbCommunicationStrategy.getChangedEntries(listEntries);
    if (updatedList != nullptr) {
        clearQList(updatedList);
    }
}

QHash<int, QByteArray> FriendsManager::roleNames() const{
    return roles;
}


QVariant FriendsManager::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || listEntries == nullptr || index.row() >= listEntries->size())
        return QVariant();

    FriendEntry *friendEntry = reinterpret_cast<FriendEntry*>(listEntries->at(index.row()));
    switch(role) {
    case PhotoRole:
        return friendEntry->photo;
        break;
    case NameRole:
        return friendEntry->name;
        break;
    case DateRole:
        return friendEntry->date;
        break;
    case TemplateRole:
        if (friendEntry->templateIds.isEmpty() == true)
            return "нет шаблона";
        else {
            int realId = translator->getRealIndex(friendEntry->templateIds.at(0));
            return getTemplateById(realId);
        }
        break;
    case DeletedFlagRole:
        return friendEntry->isDeleted;
        break;
    case MissedFlagRole:
        return friendEntry->isMissed;
        break;
    }
    return QVariant();
}


void FriendsManager::initialize(QmlApplicationViewer& viewer, QString modelName) {
    Manager::initialize(viewer, modelName);
    //для обработик сигналов из QML
    QObject::connect(this, SIGNAL(editTemplate(int)),this, SLOT(onEditTemplate(int)));
}



void FriendsManager::onDeleteElement(int index){
    if (index < 0 || listEntries == nullptr || index >= listEntries->size())
        return;
    FriendEntry * currentFriendEntry = reinterpret_cast<FriendEntry*>(listEntries->at(index));
    currentFriendEntry->isDeleted = !currentFriendEntry->isDeleted;
    dbCommunicationStrategy.addUpdatedId(index);
}


void FriendsManager::showVkPage(int friendsIndex) {
    if (friendsIndex < 0 || listEntries == nullptr || friendsIndex >= listEntries->size())
        return;
    firstDisplayedElement = friendsIndex;
    //здесь нужен код запуска приложения вк
}

void FriendsManager::onEditTemplate(int friendsIndex) {
    if (friendsIndex < 0 || listEntries == nullptr ||friendsIndex >= listEntries->size())
        return;
    firstDisplayedElement = friendsIndex;
    emit createEditTemplateView(reinterpret_cast<FriendEntry*>(listEntries->at(friendsIndex)));
}

void FriendsManager::onDeleteTemplate(int templateIndex) {
    if (listEntries == nullptr)
        return;

    for (int iter = 0; iter < listEntries->size(); ++iter) {
        int deletedTemplateIndex = reinterpret_cast<FriendEntry*>(listEntries->at(iter))->templateIds.indexOf(templateIndex);
        if (deletedTemplateIndex >= 0) {
            reinterpret_cast<FriendEntry*>(listEntries->at(iter))->templateIds.removeAt(deletedTemplateIndex);
            dbCommunicationStrategy.addUpdatedId(iter);
        }
    }
}


void FriendsManager::onDbaseInfoGetChanged() {
    //сохраняем список измененных элементов
    auto changedList = dbCommunicationStrategy.getChangedEntries(listEntries);
    dbCommunicationStrategy.clearChanges();
    //скачиваем изменения из БД
    uint lastChangedTimestamp = dbCommunicationStrategy.getLastTimestamp();
    auto recentlyUpdatedListHash = dbManager->getRecentlyUpdatedElements(lastChangedTimestamp);
    if (recentlyUpdatedListHash != nullptr) {
        dbCommunicationStrategy.updateCurrentList(
               listEntries,
               recentlyUpdatedListHash,
               FriendEntry::nameIsLess);
        clearQHash(recentlyUpdatedListHash);
    }
    //вносим в БД собственные изменения
    dbManager->updateElements(changedList);
    clearQList(changedList);

}

void FriendsManager::onFriendEntryChangedTemplate(AbstractListEntry* friendEntryPtr) {
    if (friendEntryPtr == nullptr || listEntries == nullptr)
        return;
    int changedId = listEntries->indexOf(friendEntryPtr);
    if (changedId >= 0) {
        dbCommunicationStrategy.addUpdatedId(changedId);
    }
}
