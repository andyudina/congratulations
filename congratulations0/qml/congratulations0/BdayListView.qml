import QtQuick 1.1

ListView {
    id: bdayList;
    width: 480;
    height: 440;
    anchors.bottom: parent.bottom
    clip: true
    highlightFollowsCurrentItem: true

    model: BdayManager
    currentIndex: BdayManager.firstDisplayedElement
    delegate: BdayListElement {friendsPhoto: photo; friendsName: name; bdayDate: date;
                               color: backgroundColor; border.color: borderColor;  textNameColor:  textColor;
                               textDateColor: textColor; bdayIsMissed: isMissed}
    Component.onCompleted: {
        bdayList.positionViewAtIndex(BdayManager.firstDisplayedElement, ListView.Beginning)
        //console.log(BdayManager.firstDisplayedElement)
        mainWindow.headerText = "Дни Рождения"
        footerMenu.templatesIconImg = "qrc:///src/templates.png"
        footerMenu.friendsIconImg = "qrc:///src/friends.png"
        footerMenu.bdaysIconImg = "qrc:///src/bdays_selected.png"
        footerMenu.settingsIconImg = "qrc:///src/settings.png"
    }
}
