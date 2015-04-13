#ifndef FRIENDSMANAGER_H
#define FRIENDSMANAGER_H

#include "manager.h"
#include "templateidtranslator.h"

#define STATE_IS_NOT_SELECTED -1

//ListModel для списка друзей
class FriendsManager : public Manager {
    Q_OBJECT
    Q_PROPERTY (int firstDisplayedElement READ getFirstDisplayedElement() WRITE setFirstDisplayedElement())

public:
    explicit FriendsManager(TemplateIdTranslator* translator_, QObject *parent = 0);
    ~FriendsManager();

    enum friendRoles {
        PhotoRole = Qt::DisplayRole,
        NameRole = Qt::DisplayRole + 1,
        DateRole = Qt::DisplayRole + 2,
        TemplateRole = Qt::DisplayRole + 3,
        DeletedFlagRole = Qt::DisplayRole + 4,
        MissedFlagRole = Qt::DisplayRole + 5
    };

    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const override;

    virtual void initialize(QmlApplicationViewer& viewer, QString modelName);

    Q_INVOKABLE void showVkPage(int);

    TemplateIdTranslator* getCurrentTranslator() { return translator; }

    void setFirstDisplayedElement(int firstDisplayedElement_) {
        firstDisplayedElement = firstDisplayedElement_;
    }

public slots:
    void onEditTemplate(int friendsIndex);
    void onDeleteElement(int index);
    void onDeleteTemplate(int deletedTemplateIndex);

    //ловит сигналы демона о внесении изменений в БД
    void onDbaseInfoGetChanged();
    //ловит сигналы от ListModel списка шаблонов об изменении шаблона
    void onFriendEntryChangedTemplate(AbstractListEntry*);

signals:
    void editTemplate(int friendsIndex);
    //инициализировать и показать вьюшку с шаблонами для конкретного друга
    void createEditTemplateView(FriendEntry*);
    //получить имя шаблона по его id
    QString getTemplateById(int id) const;

private:
    TemplateIdTranslator* translator; //для согласования id шаблонов с учетом удаленных
                                      //в течении одного сеанса
                                      //другое решение - постоянно дергать БД?
    class FriendsCommunicationStrategy: public PushUpdatesStrategy, public PullChangesStrategy {
    } dbCommunicationStrategy;       //задает способ коммуникации с БД
                                     //скачивать изменения из БД по сигналу
                                     //перед обновлением списка залить свои собственные обновления в БД
};



#endif // FRIENDSMANAGER_H
