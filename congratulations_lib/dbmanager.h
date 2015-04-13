#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "listelement.h"
#include <QHash>

#define TEST_INTERVAL 1000 //тестовый интервал между обращениями к сети в мс
                           //удалить перед релизом!

//классы для работы с БД
//в БД должны быть следующие сущности:

//Друзья id(vk), имя, дата рождения, флаг активности (если сброшен - друга не поздравлять)
//Шаблоны id, название, текст
//Настройки id, текст настройки, выбранный id варианта
//Варианты настроек id, текст
//История поздравлений id, id друга, дата поздравления

//Связи
//Друзья-Шаблоны один ко многим
//Настройки - Варианты настроек один ко многим

//для упрощения работы с БД ввести избыточность:
//хранить в таблице друзей флаг пропуска БД. Если выставлен - предыдущий ДР был пропущен


class CONGRATULATIONS_LIBSHARED_EXPORT DBManager
{
public:
    static enum elementTypesEnum {
       insertedElements = 1,
       updatedElements = 2,
       deletedElements = 3
    } elementTypes;


    virtual ~DBManager() = default;

    //возвращает список всех элементов соответсвующей таблицы
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr)=0;

    //возвращают true, если загрузка данных была успешна
    virtual bool updateElements(QList<AbstractListEntry*>*);
    virtual bool insertElements(QList<AbstractListEntry*>*);
    virtual bool deleteElements(const QList<int>&);
    virtual QHash<int, QList<AbstractListEntry*>*>* getRecentlyUpdatedElements(const uint& timestamp);

protected:
    DBManager() = default;

private:
    DBManager(const DBManager&);
    DBManager& operator=(const DBManager&);

};


class CONGRATULATIONS_LIBSHARED_EXPORT BdaysDBManager: public  DBManager {
public:
    static DBManager* Instance();
    virtual ~BdaysDBManager() = default;

    //все события за один текущий год
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);

    //обновить пропуски БД
    //должна вызывать хранимую процедуру
    //возвращает true, если изменения были, иначе - false
    static bool updateBdaysHistory();

    //добавить успешное поздравление в таблицу истории поздравлений
    static void logSuccessfullCongratulation(const FriendEntry&);

private:
    static DBManager* _self;
    BdaysDBManager() = default;

};



class CONGRATULATIONS_LIBSHARED_EXPORT FriendsDBManager: public  DBManager {
public:
    virtual ~FriendsDBManager() = default;
    static DBManager* Instance();

    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);

    //функция выбора друзей с др по дате
    static QList<FriendEntry*>* getBdaysByDate(const QDate&) { return nullptr; }

    //функция добавления изменений в БД (обновить инфу из БД в соответсвии с полученным списком)
    //возвращает true, если изменения произошли
    static bool updateFriendsList(QList<FriendEntry*>*);

    //проверить, активен ли друг
    static bool checkIfFriendIsActive(const FriendEntry&);



private:
    static DBManager* _self;
    FriendsDBManager() = default;

};

class CONGRATULATIONS_LIBSHARED_EXPORT TemplatesDBManager: public  DBManager {
public:
    virtual ~TemplatesDBManager() = default;
    static DBManager* Instance();
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);

private:
    static DBManager* _self;
    TemplatesDBManager() = default;

};

class CONGRATULATIONS_LIBSHARED_EXPORT SettingsDBManager: public  DBManager {
public:
    virtual ~SettingsDBManager() = default;
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);
    static DBManager* Instance();

    //узнать, куда посылать сообщение
    //true - на стену, false -  личку
    static bool getMessageDestination();

    //интервал ожидания между попытками отправки сообщения
    static int getCongratulateInterval();

    //интервал ожидания между попытками обновить инфу
    static int getUpdateInterval();

private:
    static DBManager* _self;
    SettingsDBManager() = default;

};

#endif // DBMANAGER_H
