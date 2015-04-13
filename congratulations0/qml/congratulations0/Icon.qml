import QtQuick 1.1

Item {
    property alias iconImage : iconImage.source;
    property string name;

    function sendSignal() {}
    Image {
        id: iconImage
        width: parent.width
        height: parent.height
    }

    MouseArea {
        id: iconMousearea
        width: parent.width
        height: parent.height
        onClicked: {
            parent.sendSignal();
        }
    }
}
