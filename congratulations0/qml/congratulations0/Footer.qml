import QtQuick 1.1

Rectangle {
    width: 480;
    height: 100;
    color: "#a64fb3";
    property alias templatesIconImg : templatesIcon.iconImage
    property alias friendsIconImg : friendsIcon.iconImage
    property alias bdaysIconImg : bdaysIcon.iconImage
    property alias settingsIconImg : settingsIcon.iconImage
    Row {
        id: icons_row
        spacing: 26
        Icon {id: templatesIcon; height: 100; width: 100; function sendSignal() {footerMenu.iconClicked("Template")} }
        Icon {id: friendsIcon; height: 100; width: 100;  function sendSignal() {footerMenu.iconClicked("Friend")}}
        Icon {id: bdaysIcon; height: 100; width: 100; function sendSignal() {footerMenu.iconClicked("Bday")}}
        Icon {id: settingsIcon; height: 100; width: 100; function sendSignal() {footerMenu.iconClicked("Settings")}}
    }
}
