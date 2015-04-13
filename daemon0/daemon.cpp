#include "daemon.h"

Daemon::Daemon(int& argc, char * argv[]):
    QCoreApplication(argc, argv),
    connector(new DBusConnector(DAEMON_SERVICE_NAME,
                                DBUS_OBJECT_NAME,
                                GUI_SERVICE_NAME,
                                DBUS_OBJECT_NAME)),
    todayBdays(nullptr)
{
    //а если телефон включили в 23.50??
    //следующее обновление будет слишком поздно - можно не успеть всех поздравить
    reinitializeTimer.setInterval(CALENDAR_DAY);
    connect(&reinitializeTimer, SIGNAL(timeout()), this, SLOT(onTimeToReinitialize()));
    reinitializeTimer.start();
}

Daemon::~Daemon() {
    if (connector != nullptr)
        delete connector;
    if (todayBdays != nullptr) {
        clearQList(todayBdays);
    }
}

void Daemon::initializeTimers() {
    int updateInterval = SettingsDBManager::getUpdateInterval();
    updateTimer.setInterval(updateInterval);
    if (updateTimer.isActive() == false) {
        connect(&updateTimer, SIGNAL(timeout()), this, SLOT(onTimeToUpdate()));
        updateTimer.start();
    }

    //если сегодня никого не надо поздравлять, таймер запускать тоже нет смысла
    //но нужно активировать таймер, если пользователь добавил друга с ДР сегодня - не реализовано
    if (getTodayBdays() == true) {
        //получить интервал между обновлениями
        int congratulateInterval = SettingsDBManager::getCongratulateInterval();
        if (congratulateTimer.isActive() == false) {
            congratulateTimer.setInterval(congratulateInterval);
            connect(&congratulateTimer, SIGNAL(timeout()), this, SLOT(onTimeToCongratulate()));
        }

    }
}

//возвращает true, если список для поздравления не пустой
bool Daemon::getTodayBdays() {
    todayBdays = FriendsDBManager::getBdaysByDate(QDate::currentDate());
    if (todayBdays != nullptr)
        return true;
    else
        return false;
}


void Daemon::sendCongratulations() {
    if (todayBdays == nullptr)
        return;

    for (int iter = todayBdays->size(); iter >= 0; -- iter) {
        FriendEntry currentFriendEntry = *todayBdays->at(iter);
        //проверить, активен ли друг
        bool friendIsActiveFlag = FriendsDBManager::checkIfFriendIsActive(currentFriendEntry);
        if (friendIsActiveFlag == false) {
            delete todayBdays->at(iter);
            todayBdays->removeAt(iter);
        }

        //проверить, куда отправлять сообщение (стена = true, личка = false)
        bool messageDest = SettingsDBManager::getMessageDestination();
        bool resultFlag = Network::sendCongratulations(currentFriendEntry, messageDest);

        if (resultFlag == true) {
            BdaysDBManager::logSuccessfullCongratulation(currentFriendEntry);
            delete todayBdays->at(iter);
            todayBdays->removeAt(iter);

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(TIMEOUT));
    }
    //если всех поздравили - отановить таймер
    if (todayBdays->isEmpty()) {
        congratulateTimer.stop();
    }
}


void Daemon::updateFriendsInfo() {
    QList<FriendEntry*>* friends = Network::getFriends();
    if (friends != nullptr) {
        //нужно проверять наличие новых друзей с ДР сегодня и добавлять их в список для поздравления
        //для корректной работы нужно ловить уведомлений об изменении шаблонов пользователем
        bool friendsHadChanged = FriendsDBManager::updateFriendsList(friends);
        if (friendsHadChanged == true) {
            connector->connectAndAnnounce("Friends");
        }
    }
}

void Daemon::updateMissedBdaysInfo() {
    bool hadChanges = BdaysDBManager::updateBdaysHistory();
    if (hadChanges == true)
        connector->connectAndAnnounce("Bdays");
}

void Daemon::onTimeToUpdate() {
    updateFriendsInfo();
}

void Daemon::onTimeToCongratulate() {
    sendCongratulations();
}

void Daemon::onTimeToReinitialize() {
    initialize();
}

 void Daemon::initialize() {
     initializeTimers();
     updateMissedBdaysInfo();
 }



