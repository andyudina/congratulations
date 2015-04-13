#ifndef TEMPLATEMANAGER_H
#define TEMPLATEMANAGER_H


#include "friendsmanager.h"
#include <QSortFilterProxyModel>

class PersonalTemplateManager;

//ListModel для шаблонов
class TemplateManager : public Manager
{
    Q_OBJECT
    
friend class PersonalTemplateManager;

public:
    enum templateRoles {
        TitleRole = Qt::DisplayRole,
        TextRole = Qt::DisplayRole + 1
    };

    QSortFilterProxyModel * templateFilterProxy; //для поиска по шаблонам

    explicit TemplateManager(QObject *parent = 0);
    ~TemplateManager();

    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const override;

    virtual void initialize(QmlApplicationViewer&, const QString&, FriendsManager* friendsManager);
    virtual void connectWithFriendManager(FriendsManager*);

    Q_INVOKABLE void addTemplate(const QString&, const QString&);
    Q_INVOKABLE void editTemplate (int, const QString&, const QString&);

public slots:
   virtual void onDeleteElement(int index);
   QString onGetTemplateById(int index) const;
   void onTemplateListHasChanged();

signals:
    void deleteTemplate(int index);
    void templateListHasChanged();

protected:
    TemplateIdTranslator* translator; //для согласования id шаблонов с учетом удаленных
                                      //в течении одного сеанса

    PushChangesStrategy dbCommunicationStrategy; //задает способ коммуникации с БД
                                                 //вносит изменения в БД при удалении
                                                 //UPDATE, INSERT, DELETE

    void tuneFilterProxy();  //настроить прокси для поиска по шаблонам
};

#endif // TEMPLATEMANAGER_H
