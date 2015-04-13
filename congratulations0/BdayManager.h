#ifndef BDAYMANAGER_H
#define BDAYMANAGER_H

#include "manager.h"

//ListModel для истории поздравлений
class BdayManager : public Manager {
    Q_OBJECT
    Q_PROPERTY(int firstDisplayedElement READ getFirstDisplayedElement)

public:
    explicit BdayManager(QObject *parent = 0);
    ~BdayManager() = default;

    enum bdayRoles {
        PhotoRole = Qt::DisplayRole,
        ColorRole = Qt::DisplayRole + 1,
        BorderColorRole = Qt::DisplayRole + 2,
        TextColorRole = Qt::DisplayRole + 3,
        NameRole = Qt::DisplayRole + 4,
        DateRole = Qt::DisplayRole + 5,
        MissedFlagRole = Qt::DisplayRole + 6
    };

    QHash<int, QByteArray> roleNames() const override;
    virtual QVariant data(const QModelIndex &index, int role) const;

public slots:
    //ловит сигналы о внесении изменений в БД демоном
    void onDbaseInfoGetChanged();

private:
    PullChangesStrategy dbCommunicationStrategy; //задает способ коммуникации с БД
                                                 //скачивать изменения из БД по сигналу

};

#endif // BDAYMANAGER_H
