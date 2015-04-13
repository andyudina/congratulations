#ifndef PERSONALTEMPLATEMANAGER_H
#define PERSONALTEMPLATEMANAGER_H


#include "templatemanager.h"
#include "friendsmanager.h"

//ListModel для шаблонов конкретного пользователя
class PersonalTemplateManager : public TemplateManager
{
    Q_OBJECT
    Q_PROPERTY(QString personName READ getPersonName)

public:
    explicit PersonalTemplateManager(const TemplateManager&);
    ~PersonalTemplateManager() = default;

    enum personalTemplateRoles {
        IsSelectedFlagRole = Qt::DisplayRole + 2
    };

    QString getPersonName();

    virtual QVariant data(const QModelIndex &index, int role) const;

    virtual void connectWithFriendManager(FriendsManager* friendManager);

    //добавить шаблон
    Q_INVOKABLE void addTemplate(const QString&, const QString&);
    //изменить шаблон
    Q_INVOKABLE void editTemplate (int, const QString&, const QString&);
    //выбрать или отменить выбор шаблона
    Q_INVOKABLE void checkElement (int);

signals:
    //послать сигнал при изменении пользователем шаблонов
    void friendEntryChangedTemplate(AbstractListEntry*);

public slots:
    //смена шаблона при выборе конктретного друга
    void onCreateTemplateView(FriendEntry*);


private:
    FriendEntry* friendEntry; //может нужен умный указатель?

};

#endif // PERSONALTEMPLATEMANAGER_H
