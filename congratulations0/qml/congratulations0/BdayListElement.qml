import QtQuick 1.1

Rectangle {
    width: 480
    height: 110
    border.width: 4


    property alias friendsPhoto: friendsPhoto.source
    property alias friendsName: friendsName.text
    property alias bdayDate: bdayDate.text
    //property alias borderColor: border.color
    property alias textNameColor: friendsName.color
    property alias textDateColor: bdayDate.color
    property alias bdayIsMissed: missedBday.isUsed

    Image {
        id: friendsPhoto
        anchors.verticalCenter: parent.verticalCenter
        x: 6
        width: 80
        height: 80
    }

    Text {
        id: friendsName
        font.pointSize: 14
        x: 96
        anchors.top: friendsPhoto.top
    }

    Text {
        id: bdayDate
        font.pointSize: 14
        anchors.bottom: friendsPhoto.bottom
        x: 96
    }

    Image {
        id: missedBday
        property bool isUsed : false
        width: 40
        height: 40
        source : isUsed == true ? 'qrc:///src/alert.png': 'None'
        anchors.verticalCenter: friendsName.verticalCenter
        anchors.left: friendsName.right
        anchors.leftMargin: 6
    }
}
