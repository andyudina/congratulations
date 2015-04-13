#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "manager.h"

//ListModel для настроек
class SettingsManager : public Manager
{
    Q_OBJECT
    Q_PROPERTY(int count READ count)
    
public:
    enum settingsRoles {
        TextRole = Qt::DisplayRole,
        StateRole = Qt::DisplayRole + 1,
        OptionsRole = Qt::DisplayRole + 2,
        SelectedOptionRole = Qt::DisplayRole + 3,
        IsOnFlagRole = Qt::DisplayRole + 4
    };

    explicit SettingsManager(QObject *parent=0);
    ~SettingsManager();

    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() {return listEntries->size();}

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void editSettings(int, int);


protected:
    PushUpdatesStrategy dbCommunicationStrategy; //задает способ коммуникации с БД
                                                 //вносит изменения в БД при удалении
                                                 //только UPDATE
};


#endif // SETTINGSMANAGER_H
