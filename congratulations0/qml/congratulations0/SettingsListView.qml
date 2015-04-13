import QtQuick 1.1

ListView {
    id: simpleSettingsList;
    width: 480;
    height: 440
    clip: true
    model: SettingsManager;


    delegate: SettingsListElement {settingsText: model.settingsText;
                                   state: (settingsState == 0)? "listSettingsElement": ((settingsState == 1)? "offOnSettingsElement": "headerElement")}

    Component.onCompleted: {
        mainWindow.headerText = "Настройки"
        footerMenu.templatesIconImg = "qrc:///src/templates.png"
        footerMenu.friendsIconImg = "qrc:///src/friends.png"
        footerMenu.bdaysIconImg = "qrc:///src/bdays.png"
        footerMenu.settingsIconImg = "qrc:///src/settings_selected.png"

    }
}


