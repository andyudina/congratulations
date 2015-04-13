import QtQuick 1.1

Rectangle {
    id: addNewTemplate
    visible: false
    width: 480;   
    color: "#eeeeee";
    property alias templateTitleEdit: templateTitleEdit
    property alias templateTextEdit: templateTextEdit
    property alias textContainerHeight: templatetext.height

    Rectangle {
        id: templateTitle;
        anchors {top: parent.top; margins: 5; horizontalCenter: parent.horizontalCenter}
        height: (parent.height == 0)? 0 : 40;
        width: parent.width - 10;
        color: "#ffffff"

        TextEdit {
            id: templateTitleEdit;
            height: parent.height
            width: parent.width
            anchors {top: parent.top; left: parent.left; margins: 2}
            font.pointSize: 18
            focus: true;
            wrapMode: TextEdit.Wrap;
            text: "Заголовок шаблона"
            selectByMouse: true;
        }
    }

    Rectangle {
        id: templatetext;
        anchors {top: templateTitle.bottom; margins: 5; horizontalCenter: parent.horizontalCenter}
        height: (parent.height == 0)? 0 : 95;
        width: parent.width - 10;
        color: "#ffffff"
        TextEdit {
            id: templateTextEdit;
            height: parent.height
            width: parent.width
            anchors {top: parent.top; left: parent.left; margins: 2}
            //color: "#ffffff"
            font.pointSize: 18
            focus: true;
            wrapMode: TextEdit.Wrap;
            text: "Текст шаблона"
            selectByMouse: true;
        }
    }

    Rectangle {
        id: saveTemplate;
        anchors {bottom: parent.bottom}
        width: parent.width
        height: 60
        Row {
            width: parent.width
            height: parent.height
            anchors {top: parent.top; left: parent.left}

            //иправь на нормальную иконку!!
            Icon {
                id: saveTemplateIcon;
                height: 60
                width: 60
                anchors {verticalCenter:parent.verticalCenter; right: parent.right; rightMargin: 10}
                //сравь!!!
                iconImage: "qrc:///src/enable.png"
                function sendSignal() {
                    addNewTemplate.saveTemplate();
                }
            }


            Icon {
                id: deleteTemplateIcon;
                height: 60
                width: 60
                anchors {verticalCenter:parent.verticalCenter; left: parent.left; leftMargin: 10 }
                iconImage: "qrc:///src/delete.png"
                function sendSignal() {
                    //console.log("Delete");
                    addNewTemplate.cancelAdding();

                }
            }
        }
    }
}
