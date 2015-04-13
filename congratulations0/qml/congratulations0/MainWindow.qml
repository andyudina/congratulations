import QtQuick 1.1

Rectangle {
    width: 480;
    height: 540;

    property alias headerText: headerText.text
    property alias loaderSource: loader.source

    Rectangle {
        id: header;
        width: 480;
        height: 100;
        anchors.top: parent.top;
        color: "#a64fb3";

        property alias headerText: headerText.text

        Text {
            id: headerText;
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter:  parent.verticalCenter
            color: "#ffffff"
            font {bold: true; pixelSize: 25}
        }
    }

   Loader {
       anchors.bottom: parent.bottom
       id: loader;
       Component.onCompleted: {
           loader.source = "BdayListView.qml"
       }
   }





}
