import QtQuick 1.1

AbstractTemplateListElement {
    id: simpleTemplateListElement
    actionImage: "qrc:///src/delete.png"

    function templateAction(index) {
        TemplateManager.deleteElement(index);
    }

    function editAndSaveTemplate(index, title, text) {
        TemplateManager.editTemplate(index, title, text);
    }
}

/*Item {

    id: templateListElementMain
    property alias templateText: templateText.text
    property alias templateTitle: templateTitle.text

    width: 480;
    function tuneImplicitHeight() {
        var currentHeight = templateText.lineCount * 20 + 48;
        implicitHeight = (currentHeight > 110 ) ? currentHeight: 110;
        templateListElement.implicitHeight = implicitHeight

    }

    Rectangle {
        id: templateListElement
        width: 480
        border.width: 4
        color: "#eeeeee"
        border.color: "#dddddd"
        implicitHeight: 110
        visible: true

        Icon {
            id: deleteTemplate
            width: 32
            height: 32
            iconImage: "qrc:///src/delete.png"
            anchors {top: parent.top; topMargin: 8; left: parent.left; leftMargin: 8}
            function sendSignal() {
                TemplateManager.deleteElement(index)

            }

        }

       Text {
            id: templateTitle
            font.pointSize: 14
            anchors {verticalCenter: deleteTemplate.verticalCenter; left: deleteTemplate.right; leftMargin: 8}
            font.bold: true

        }

        Text {
            id: templateText
            anchors {left: parent.left; leftMargin: 8; top: deleteTemplate.bottom; topMargin: 8 }
            font.pointSize: 11

        }


        MouseArea {
            id: editAnonymousTemplate
            height: parent.height;
            width: 380;
            anchors {horizontalCenter: parent.horizontalCenter; top: parent.top}
            onClicked: {
                //console.log("send signal edit");
                templateListElementMain.state = "editTemplate"
            }

        }
    }

    Component.onCompleted: {
        templateListElementMain.tuneImplicitHeight()
    }

    EditTemplateElement {
        id: editOldTemplateElement
        visible:false;
        //anchors {top: templateListElement.top }
        templateTitleEdit.text: templateTitle.text
        templateTextEdit.text: templateText.text
        function saveTemplate() {
            TemplateManager.editTemplate(index, templateTitleEdit.text, templateTextEdit.text);
            templateListElementMain.tuneImplicitHeight()
            templateText.text = templateTextEdit.text;
            templateTitle.text = templateTitleEdit.text;
            templateListElementMain.state = " ";
        }

        function cancelAdding() {
            templateListElementMain.tuneImplicitHeight()
            templateListElementMain.state = " ";

        }
    }

    states: State {
        name: "editTemplate"
        PropertyChanges { target: templateListElement; visible: false;}
        PropertyChanges { target: editOldTemplateElement; visible: true; height: 210;}

        StateChangeScript {
            name: "changeTemplatePosition";
            script: {
                var currentTextHeight = templateText.lineCount * 30;
                currentTextHeight = (currentTextHeight < 95)? 95 : currentTextHeight;
                editOldTemplateElement.textContainerHeight = currentTextHeight;
                var currentEditorHeight = currentTextHeight + 120;
                currentEditorHeight = (currentEditorHeight < 210)? 210 : currentEditorHeight;
                templateListElementMain.implicitHeight = currentEditorHeight;
                templateList.positionViewAtIndex(index, ListView.Beginning);
            }
        }
    }
}*/
