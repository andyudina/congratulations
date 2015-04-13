#include "templatemanager.h"


TemplateManager::TemplateManager(QObject *parent): Manager(parent) {
    dbManager = TemplatesDBManager::Instance();
    templateFilterProxy = new QSortFilterProxyModel();
    roles[TextRole] = "text";
    roles[TitleRole] = "title";
}

TemplateManager::~TemplateManager() {
    //внести изменения в базу данных.
    auto deleteIds = dbCommunicationStrategy.getDeletedIds();
    dbManager->deleteElements(deleteIds);

    auto updatedElements = dbCommunicationStrategy.getUpdatedEntries(listEntries, translator);
    if (updatedElements != nullptr) {
        dbManager->updateElements(updatedElements);
        clearQList(updatedElements);
    }

    auto insertedElements = dbCommunicationStrategy.getInsertedEntries(listEntries, translator);
    if (insertedElements != nullptr) {
        dbManager->insertElements(insertedElements);
        clearQList(insertedElements);
    }

    delete templateFilterProxy;
    delete dbManager;

}

QHash<int, QByteArray> TemplateManager::roleNames() const{
    return roles;
}

 void TemplateManager::connectWithFriendManager(FriendsManager* friendManager) {
     if (friendManager == nullptr)
         return;
     QObject::connect(friendManager, SIGNAL(getTemplateById(int)), this, SLOT(onGetTemplateById(int)));
     QObject::connect(this, SIGNAL(deleteTemplate(int)), friendManager, SLOT(onDeleteTemplate(int)));
     translator = friendManager->getCurrentTranslator();
     translator->initialize(listEntries->size());
 }

void TemplateManager::initialize(QmlApplicationViewer& viewer, const QString& modelName, FriendsManager* friendManager) {
    Manager::initialize(viewer, modelName);
    connectWithFriendManager(friendManager);

    //настроить фильр
    tuneFilterProxy();

    //зарегистрировать фильтр
    viewer.rootContext()->setContextProperty(modelName + "Proxy", templateFilterProxy);
}


void TemplateManager::onDeleteElement(int index) {
    if (index < 0 || listEntries == nullptr || index >= listEntries->size()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    int friendIndex = translator->deleteRealIndex(index);
    dbCommunicationStrategy.addDeletedId(listEntries->at(index)->id);
    delete listEntries->at(index);
    listEntries->removeAt(index);
    emit endRemoveRows();
    if (friendIndex >= 0)
        emit deleteTemplate(friendIndex);
    emit templateListHasChanged();
 }

void TemplateManager::addTemplate(const QString& title, const QString& text) {
    emit beginInsertRows(QModelIndex(),listEntries->size(), listEntries->size());
    listEntries->append(new TemplateEntry(title, text));
    int newTranslatedId = translator->addWithRealIndex(listEntries->size() - 1);
    dbCommunicationStrategy.addInsertedId( newTranslatedId);
    emit endInsertRows();
    emit templateListHasChanged();
}

void TemplateManager::editTemplate (int index,const QString& title, const QString& text) {
    if( index < 0 || listEntries == nullptr || index >= listEntries->size()) {
        return;
    }
    reinterpret_cast<TemplateEntry*>(listEntries->at(index))->text = text;
    reinterpret_cast<TemplateEntry*>(listEntries->at(index))->title = title;
    int translatedId = translator->getFriendIndex(index);
    dbCommunicationStrategy.addUpdatedId(translatedId);
}

void  TemplateManager::tuneFilterProxy() {
    templateFilterProxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    templateFilterProxy->setFilterRole(TextRole);
    templateFilterProxy->setSourceModel(this);
}



QVariant TemplateManager::data(const QModelIndex &index, int role) const {
    //
    if (index.row() < 0 || listEntries == nullptr || index.row() >= listEntries->size()) {
        return QVariant();
     }
    TemplateEntry * templateEntry = reinterpret_cast<TemplateEntry*>(listEntries->at(index.row()));

    switch(role) {
    case TextRole:
        return templateEntry->text;
        break;
    case TitleRole:
        return templateEntry->title;
        break;

    }
    return QVariant();
}

QString TemplateManager::onGetTemplateById(int realIndex) const {
    if (realIndex < 0 || listEntries == nullptr || realIndex >= listEntries->size())
        return "нет шаблона";
    return (reinterpret_cast<TemplateEntry*>(listEntries->at(realIndex)))->title;
}


void TemplateManager::onTemplateListHasChanged() {
    emit beginResetModel();
    emit endResetModel();
}
