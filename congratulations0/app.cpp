#include "app.h"
#include <QDebug>



App::App(int& argc, char * argv[]): QApplication(argc, argv),
    connector(new DBusConnector(GUI_SERVICE_NAME,
                                DBUS_OBJECT_NAME,
                                DAEMON_SERVICE_NAME,
                                DBUS_OBJECT_NAME)) {
}

App::~App() {
    if (connector != nullptr) {
        delete connector;
    }
}

int App::startGUI() {

    QmlApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    //создать и проинициализирвоать ListModels
    BdayManager bdayManager;
    bdayManager.initialize(viewer, "BdayManager");

    TemplateIdTranslator translator;

    FriendsManager friendManager(&translator);
    friendManager.initialize(viewer, "FriendManager");


    TemplateManager templateManager;
    templateManager.initialize(viewer, "TemplateManager", &friendManager);

    PersonalTemplateManager personalTemplateManager(templateManager);
    personalTemplateManager.initialize(viewer, "PersonalTemplateManager",&friendManager);

    SettingsManager settingsManager;
    settingsManager.initialize(viewer, "SettingsManager");

    //соединить ListModels с соответствующим сигналом изменения БД демоном
    if (connector != nullptr) {
        QObject::connect(connector, SIGNAL(friendsInfoHasChanged()), &friendManager, SLOT(onDbaseInfoGetChanged()));
        QObject::connect(connector, SIGNAL(bdaysInfoHasChanged()), &bdayManager, SLOT(onDbaseInfoGetChanged()));
    }

    viewer.setMainQmlFile(QLatin1String("qml/congratulations0/main.qml"));
    viewer.showExpanded();

    return QApplication::exec();
}





