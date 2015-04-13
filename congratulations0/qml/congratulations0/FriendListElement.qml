import QtQuick 1.1

Rectangle {
    id: friendsMainRect
    width: 480
    height: 110
    border.width: 4


    property alias friendsPhoto: friendsPhoto.source
    property alias friendsName: friendsName.text
    property alias bdayDate: dateText.text
    property alias templateName: templateName.text
    property bool isDeleted: false
    property bool isMissed: false

    color : (friendsMainRect.isDeleted == true)? "#757575" : "#eeeeee";
    border.color: (friendsMainRect.isDeleted == true)? "#383838":"#dddddd";

    Image {
        id: friendsPhoto
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        x: 6
        width: 80
        height: 80
    }

    Text {
        id: friendsName
        font.pointSize: 14
        x: 96
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        color: (friendsMainRect.isMissed == true && friendsMainRect.isDeleted == false)? "#d32f2f":"#383838"
    }

    Item {
        id: date;
        visible: false;
        anchors.bottom : friendsPhoto.bottom

        Text {
            id: dateText;
            color: (friendsMainRect.isMissed == true)?"#d32f2f":"#383838";
            font.pixelSize:  14
            x: 96
            anchors.verticalCenter: missedDateImage.verticalCenter
        }

        Image {
            id: missedDateImage;
            height: 40
            width: 40
            source: "qrc:///src/alert.png"
            visible: (friendsMainRect.isMissed == true)? true: false

            anchors.left: dateText.right;
            anchors.bottom: parent.bottom;
        }
    }

    Item {
        id: friendExtraInfo;
        height: 110
        width: 480
        anchors.bottom: parent.bottom
        visible: false
        Row {
            id: templateRow;
            spacing: 20;
            anchors {top: parent.top; topMargin: 5; left: parent.left; leftMargin: 6}
            Text {
                id: templateHeader;
                text: "Шаблон";
                color: "#9c27b0"
                wrapMode: Text.NoWrap
                font.pointSize: 14
            }

            Text {
                id: templateName;
                color: "#838383"
                font.bold: true
                font.pointSize: 14
                wrapMode: Text.NoWrap

            }
        }
        Row {
            id: linkRow;
            spacing: 20;
            anchors {bottom: parent.bottom; bottomMargin: 10; left: parent.left; leftMargin: 6}
            Text {
                id: linkHeader;
                anchors.verticalCenter: vkLink.verticalCenter
                text: "Ссылка";
                color: "#9c27b0"
                wrapMode: Text.NoWrap
                font.pointSize: 14
            }

            Icon {
                id: vkLink
                width: 50
                height: 50
                iconImage: "qrc:///src/vk.jpg"
                function sendSignal() {
                    FriendManager.showVkPage(index)
                }
            }
        }

        Icon {
            id: editTemplate
            width: 100
            height: 100
            anchors {bottom: parent.bottom; right: parent.right}
            iconImage: "qrc:///src/edit_template.png"
            function sendSignal() {
                FriendManager.editTemplate(index);
                loaderSource = "PersonalTemplateListView.qml";
            }
        }
    }

    Icon {
        id: editFriendIcon
        anchors {right: parent.right; verticalCenter: parent.verticalCenter}
        width: 100
        height: 100
        iconImage: (friendsMainRect.isDeleted == true)? "qrc:///src/enable.png" : "qrc:///src/disable.png"

        function sendSignal() {
            isDeleted = !isDeleted
            FriendManager.deleteElement(index);
            if(isDeleted) {
                friendsMainRect.state = ' ';
            }
        }
    }

    MouseArea {
        id: expandFriendInfo
        anchors {left: friendsMainRect.left; top: parent.top}
        height: 110;
        width: 370
        onClicked: {
            if (friendsMainRect.isDeleted == false) {
                friendsMainRect.state = "Details";
            }
        }
    }


    states: State{
        name: "Details"
        PropertyChanges { target: friendsMainRect; height: 220; color: "#ffffff"}
        PropertyChanges { target: expandFriendInfo; onClicked: {friendsMainRect.state = ' '; FriendManager.state = -1;}}
        PropertyChanges { target: friendsPhoto; anchors.verticalCenterOffset: -55;}
        PropertyChanges { target: friendsName; anchors.verticalCenterOffset: -85;}
        PropertyChanges { target: editFriendIcon; anchors.verticalCenterOffset: -55;}
        PropertyChanges { target: date; visible: true}
        PropertyChanges {
            target: friendExtraInfo;
            visible: true;
        }
        PropertyChanges {
            target: dateText
            font.pointSize: 14
        }
    }

}
