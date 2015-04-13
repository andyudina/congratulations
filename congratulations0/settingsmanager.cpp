#include "settingsmanager.h"


SettingsManager::SettingsManager(QObject *parent): Manager(parent) {
    dbManager = SettingsDBManager::Instance();
    roles[TextRole] = "settingsText";
    roles[StateRole] = "settingsState";
    roles[OptionsRole] = "settingsOptions";
    roles[SelectedOptionRole] = "selectedOption";
    roles[IsOnFlagRole] = "isOn";
}

//внести изменения в базу данных.
SettingsManager::~SettingsManager() {
    auto recentlyUpdatedElements = dbCommunicationStrategy.getChangedEntries(listEntries);
    dbManager->updateElements(recentlyUpdatedElements);
    clearQList(recentlyUpdatedElements);

}


QHash<int, QByteArray> SettingsManager::roleNames() const{
    return roles;
}

void SettingsManager::editSettings(int index, int option) {
    if (index < 0 || listEntries == nullptr || index >= listEntries->size())
        return;
    dbCommunicationStrategy.addUpdatedId(index);
    reinterpret_cast<SettingsEntry*>(listEntries->at(index))->editSettings(option);
}


QVariant SettingsManager::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || listEntries == nullptr || index.row() > listEntries->count()) {
        return QVariant();
     }
    SettingsEntry * settingsEntry = reinterpret_cast<SettingsEntry*>(listEntries->at(index.row()));
    ListSettingsEntry * listSettingsEntry = nullptr;
    OffOnSettingsEntry * offOnSettingsEntry = nullptr;

    if (settingsEntry->state == LIST_ENTRY_STATE)
        listSettingsEntry = reinterpret_cast<ListSettingsEntry *>(settingsEntry);
    else
        offOnSettingsEntry = reinterpret_cast<OffOnSettingsEntry *>(settingsEntry);

    switch(role) {
    case TextRole:
        return settingsEntry->text;
        break;
    case StateRole:
        return settingsEntry->state;
        break;
    case OptionsRole:
        if (settingsEntry->state == LIST_ENTRY_STATE)
            return listSettingsEntry->optionsList;
        else
            return QVariant();
        break;
    case SelectedOptionRole:
        if (settingsEntry->state == LIST_ENTRY_STATE)
            return listSettingsEntry->selectedOption;
        else
            return QVariant();
        break;
    case IsOnFlagRole:
        if (settingsEntry->state == OFF_ON_ENTRY_STATE)
            return offOnSettingsEntry->isOn;
        else
            return QVariant();
        break;

    }
    return QVariant();
}
