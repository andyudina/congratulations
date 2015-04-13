#include "dbmanager.h"

DBManager* BdaysDBManager::_self = nullptr;
DBManager* FriendsDBManager::_self = nullptr;
DBManager* SettingsDBManager::_self = nullptr;
DBManager* TemplatesDBManager::_self = nullptr;

//DBManager methods:

bool DBManager::deleteElements(const QList<int>& deletedElements) {
    return true;
}

QHash<int, QList<AbstractListEntry*>*>* DBManager::getRecentlyUpdatedElements(const uint& timestamp) {
    return nullptr;
}

bool DBManager::updateElements(QList<AbstractListEntry*>* changesList) {
    if (changesList != nullptr) {
        for (int iter = 0; iter < changesList->size(); ++iter)
            delete changesList->at(iter);
        delete changesList;
    }
    return true;
}

bool DBManager::insertElements(QList<AbstractListEntry*>*  changesList) {
    if (changesList != nullptr) {
        for (int iter = 0; iter < changesList->size(); ++iter)
            delete changesList->at(iter);
        delete changesList;
    }
    return true;
}


//BdaysBDManager functions:
QList<AbstractListEntry*>* BdaysDBManager::getAllElements(int* state) {
    if (state != nullptr)
        *state = 2;
    QList<AbstractListEntry*> * bdays = new QList<AbstractListEntry*>;
    bdays->append(new BdayEntry("qrc:///src/6.jpg","#eeeeee","#dddddd","#383838","Катя Новикова","5 марта", true));
    bdays->append(new BdayEntry("qrc:///src/5.jpg","#eeeeee","#dddddd","#383838","Саша Булгаков","21 марта", false));
    bdays->append(new BdayEntry("qrc:///src/1.jpg","#d32f2f","#c93838","#ffffff","Анна Анна","сегодня", false));
    bdays->append(new BdayEntry("qrc:///src/2.jpg","#eeeeee","#dddddd","#383838","Саша Блок","12 мая", false));
    bdays->append(new BdayEntry("qrc:///src/3.jpg","#eeeeee","#dddddd","#383838","Аня Ахматова","1 июня", false));
    bdays->append(new BdayEntry("qrc:///src/4.jpg","#eeeeee","#dddddd","#383838","Антон Просто","7 июня", false));
    return bdays;
}

DBManager* BdaysDBManager::Instance() {
    if (_self == nullptr) {
        _self = new BdaysDBManager();
    }
    return _self;
}

bool BdaysDBManager::updateBdaysHistory() {
    return true;
}

void BdaysDBManager::logSuccessfullCongratulation(const FriendEntry&) {}

//FRiendsDbManager functions
QList<AbstractListEntry*>* FriendsDBManager::getAllElements(int* state) {
    QList<AbstractListEntry*> * friends = new QList<AbstractListEntry*>;
    friends->append(new FriendEntry("qrc:///src/6.jpg","Катя Новикова", "5 марта",/* "нет шаблона",*/ false , true, QList<int>({1,2,0})));
    friends->append(new FriendEntry("qrc:///src/5.jpg","Саша Булгаков", "21 марта",/* "шаблон 1",*/false, false, QList<int>({3,2})));
    friends->append(new FriendEntry("qrc:///src/1.jpg","Анна Анна","сегодня", /*"шаблон 2",*/ false, false, QList<int>({1,0})));
    friends->append(new FriendEntry("qrc:///src/2.jpg","Саша Блок", "12 мая", /*"шаблон 3",*/false, false, QList<int>()));
    friends->append(new FriendEntry("qrc:///src/3.jpg","Аня Ахматова","1 июня",/*"нет шаблона",*/ true, false, QList<int>({1,2,3})));
    friends->append(new FriendEntry("qrc:///src/4.jpg", "Антон Просто","7 июня", /*"нет шаблона",*/ true, true, QList<int>()));
    return friends;
}

bool FriendsDBManager::updateFriendsList(QList<FriendEntry*>* friendsList) {
    if (friendsList == nullptr) {
        return false;
    }

    for (int iter = 0; iter < friendsList->size(); ++ iter) {
        delete friendsList->at(iter);
    }

    delete friendsList;
    return true;
}

bool FriendsDBManager::checkIfFriendIsActive(const FriendEntry& friendEntry) {
    return true;
}

static DBManager* FriendsDBManager::Instance() {
    if (_self == nullptr) {
        _self = new FriendsDBManager();
    }
    return _self;
}

//TemplatesDBManager functions:
QList<AbstractListEntry*>* TemplatesDBManager::getAllElements(int* state) {
    QList<AbstractListEntry*> * templates = new QList<AbstractListEntry*>;
    templates->append(new TemplateEntry("Шаблон 1","С ДР!"));
    templates->append(new TemplateEntry("Шаблон 2", "Поздравляю с Днем Рождения!"));
    templates->append(new TemplateEntry("Шаблон 3", "С Днем Рождения. Счастья, здоровья!"));
    templates->append(new TemplateEntry("Шаблон 4", "Happy Bday!zccccccccccccccccccc zczcknzczcz\nvxvkkxvjxkvxv\nzcnzjcnzcnzcnzc\nsdsdsds\nsdsdsds\ndzczczczczczczc"));
    return templates;
}

DBManager* TemplatesDBManager::Instance() {
    if (_self == nullptr) {
        _self = new TemplatesDBManager();
    }
    return _self;
}

//SettingsDBManager functions
QList<AbstractListEntry*>* SettingsDBManager::getAllElements(int* state) {
    QList<AbstractListEntry*> * settings = new QList<AbstractListEntry*>;
    settings->append(new SettingsEntry("Общие"));
    settings->append(new ListSettingsEntry("Кого поздравлять",
                                           QList<QString>({"Всех", "Никого"}),
                                           0));
    settings->append(new ListSettingsEntry("Как поздравлять",
                                           QList<QString>({"На стену", "В личку"}),
                                           1));
    settings->append(new ListSettingsEntry("Когда напоминать",
                                           QList<QString>({"За неделю", "За день", "Никогда"}),
                                           1));
    settings->append(new SettingsEntry("Системные"));
    settings->append(new OffOnSettingsEntry("Работать в фоне",
                                            true
                                            ));
    return settings;
}

bool  SettingsDBManager::getMessageDestination() {
    return true;
}

//интервал ожидания между попытками отправки сообщения
int SettingsDBManager::getCongratulateInterval() {
    return TEST_INTERVAL; //тестовое значение
}

//интервал ожидания между попытками обновить инфу
int SettingsDBManager::getUpdateInterval() {
    return TEST_INTERVAL; //тестовое значение
}


DBManager* SettingsDBManager::Instance() {
    if (_self == NULL) {
        _self = new SettingsDBManager();
    }
    return _self;
}
