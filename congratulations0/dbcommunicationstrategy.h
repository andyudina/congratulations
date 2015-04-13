#ifndef DBCOMMUNICATIONSTRATEGY_H
#define DBCOMMUNICATIONSTRATEGY_H


#include <QObject>
#include <QtAlgorithms>
#include <QDateTime>

#include <stdlib.h>
#include "dbmanager.h"
#include "listelement.h"
#include "templateidtranslator.h"

//определяет способ и функции взаимодействия с базой данных

//для менеджеров, подтягивающих обновленную инфу из БД по сигналу
//пользователь не изменяет данные, только демон
class PullChangesStrategy {

public:
    PullChangesStrategy();
    ~PullChangesStrategy() = default;

    uint getLastTimestamp();
    //обновить исходный список
    void updateCurrentList(QList<AbstractListEntry*>*,                        //исходный список, куда нужно добавить изменения
                           QHash<int, QList<AbstractListEntry*>*>*,           //хэш со списками измененных, удаленных и добавленных элементов
                           bool (*)(AbstractListEntry*, AbstractListEntry*)); //функция сортировки, влияющая на порядок добавления элементов

private:
    uint lastChangedTimestamp;
};

//для случая, когда пользователь может изменять существующие данные
//но не удалять или добавлять новые
//можно комдинирвоать с pull стратегией
class PushUpdatesStrategy {
public:
    PushUpdatesStrategy() = default;
    ~PushUpdatesStrategy() = default;

    //получить изменившиеся элементы
    QList<AbstractListEntry*>* getChangedEntries(QList<AbstractListEntry*>*,   //исходный список
                                                 QList<int>* id_list=nullptr); //результирующий список


    virtual void clearChanges();

    void addUpdatedId(int);

protected:
    QList<int> updated_ids;

};

//пользователь может удалять и добалвять новые записи
//нужен транслятор
//нельзя комбинировать с pull стратегией без изменений
class PushChangesStrategy: public PushUpdatesStrategy {
public:
     PushChangesStrategy() = default;
     ~PushChangesStrategy() = default;
     //получить список измененных элементов
     QList<AbstractListEntry*>* getUpdatedEntries(QList<AbstractListEntry*>*, //исходный список
                                                  TemplateIdTranslator *);    //транслятор для согласования id
     //получить список вставленных элементов
     QList<AbstractListEntry*>* getInsertedEntries(QList<AbstractListEntry*>*, //исходный список
                                                   TemplateIdTranslator *);   //транслятор для соглсования id

     QList<int> &getDeletedIds();

     void addDeletedId(int);

     void addInsertedId(int);

     virtual void clearChanges();

private:
    //хранят id без учета смещений из-за удалений
    QList<int> deleted_ids;
    QList<int> inserted_ids;

};

#endif // DBCOMMUNICATIONSTRATEGY_H
