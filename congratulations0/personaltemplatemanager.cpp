#include "personaltemplatemanager.h"


#define INVALID_INDEX -1

PersonalTemplateManager::PersonalTemplateManager(const TemplateManager& templateManager)
{
    listEntries = templateManager.listEntries;
    roles = templateManager.roles;
    translator = templateManager.translator;
    roles[IsSelectedFlagRole] = "isSelected";

    QObject::connect(&templateManager, SIGNAL(templateListHasChanged()), this, SLOT(onTemplateListHasChanged()));
    QObject::connect(this, SIGNAL(templateListHasChanged()), &templateManager, SLOT(onTemplateListHasChanged()));
}

QString PersonalTemplateManager::getPersonName() {
    return friendEntry->name;
}

 void PersonalTemplateManager::connectWithFriendManager(FriendsManager* friendManager) {
     if (friendManager == nullptr)
         return;

     TemplateManager::connectWithFriendManager(friendManager);
     QObject::connect(friendManager, SIGNAL(createEditTemplateView(FriendEntry*)), this, SLOT(onCreateTemplateView(FriendEntry*)));
     QObject::connect(this, SIGNAL(friendEntryChangedTemplate(AbstractListEntry*)), friendManager, SLOT(onFriendEntryChangedTemplate(AbstractListEntry*)));
 }



void PersonalTemplateManager::addTemplate(const QString& title, const QString& text) {
    if (listEntries == nullptr)
        return;
    emit beginInsertRows(QModelIndex(),listEntries->size(), listEntries->size());
    listEntries ->append(new TemplateEntry(title, text));
    int friendIndex = translator->addWithRealIndex(listEntries ->size() - 1);
    dbCommunicationStrategy.addInsertedId(friendIndex);
    //добавить шаблон в список шаблонов друга
    friendEntry->templateIds.append(friendIndex);
    emit friendEntryChangedTemplate(friendEntry);;
    emit endInsertRows();
    emit templateListHasChanged();
}

void PersonalTemplateManager::editTemplate (int index, const QString& title, const QString& text) {
    if( index < 0 || listEntries == nullptr || index >= listEntries->size()) {
        return;
    }
    TemplateManager::editTemplate (index, title,  text);
    int friendIndex = translator->getFriendIndex(index);
    if (friendIndex > 0 && friendEntry->templateIds.indexOf(friendIndex) == -1) {
        friendEntry->templateIds.append(index);
    }
}


QVariant PersonalTemplateManager::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || listEntries == nullptr || index.row() > listEntries->count()) {
        return QVariant();
    }

    if (role == IsSelectedFlagRole) {
        //true если шаблон с id == index пристуствует в списке текущего пользователя
        int friendIndex = translator->getFriendIndex(index.row());
        return (friendEntry->templateIds.indexOf(friendIndex) != INVALID_INDEX);
    }
    else
        return TemplateManager::data(index, role);
}


void PersonalTemplateManager::checkElement (int index) {
    int friendIndex = translator->getFriendIndex(index);
    int checkedTemplateIndex = friendEntry->templateIds.indexOf(friendIndex);
    if (checkedTemplateIndex >= 0) {  //если элемент был выбран
                                      //удаляем его из списка
        friendEntry->templateIds.removeAt(checkedTemplateIndex);
    }
    else {                           //иначе добавлем в списко
        friendEntry->templateIds.append(friendIndex);
    }
    emit friendEntryChangedTemplate(friendEntry);

}


void PersonalTemplateManager::onCreateTemplateView(FriendEntry* currentFriendEntry) {
    if (currentFriendEntry == nullptr)
        return;
    friendEntry = currentFriendEntry;
}


