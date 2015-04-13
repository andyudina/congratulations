import QtQuick 1.1

ListView {
    id: friendList;
    width: 480;
    height: 440;
    anchors.bottom: parent.bottom
    clip: true
    highlightFollowsCurrentItem: true
    //highlight: FriendListElement {state: "Details"}
    model: FriendManager
    delegate: FriendListElement {friendsPhoto: photo; friendsName: name;
                                 isDeleted: friendIsDeleted; isMissed: friendIsMissed;
                                 bdayDate: date; templateName: template;
                                 state: (index == FriendManager.firstDisplayedElement)? "Details": " ";}

    Component.onCompleted: {
        mainWindow.headerText = "Друзья"
        if (FriendManager.firstDisplayedElement >= 0) {
            friendList.positionViewAtIndex(FriendManager.firstDisplayedElement, ListView.Beginning)
        }
        footerMenu.templatesIconImg = "qrc:///src/templates.png"
        footerMenu.friendsIconImg = "qrc:///src/friends_selected.png"
        footerMenu.bdaysIconImg = "qrc:///src/bdays.png"
        footerMenu.settingsIconImg = "qrc:///src/settings.png"
    }
}
