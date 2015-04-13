import QtQuick 1.1

AbstractTemplateListView {
    id: simpleTemplateListView
    listView.model: TemplateManagerProxy
    listView.delegate: TemplateListElement {templateTitle: title; templateText: text}
    mainWindowHeaderText: "Шаблоны";
    templatesIconImgPath: "qrc:///src/templates_selected.png";
    function addTemplate(title, text) {
        TemplateManager.addTemplate(title, text);
    }
}

/*//Нужна обработка ошибок пользователя и фильтрация по поиску
Item {
    id: templateMainListView

    width: 480;
    height: 440;
    anchors.top: parent.top

    Rectangle {
        id: searchRect;
        anchors.top: templateMainListView.top;
        width: 480;
        height: 100;
        color: "#a64fb3";
        z: 1
        Row {
            height: parent.height;
            width: parent.width;
            anchors {top: parent.top; left: parent.left}
            Icon {
                id: searchIcon
                height: 100
                width: 100
                iconImage: "qrc:///src/search.png"
                anchors {left:parent.left; verticalCenter: parent.verticalCenter}
                function sendSignal() {
                    //console.log(searchText.text)
                    //console.log(".*" + searchText.text + ".*")
                    templateMainListView.state = "searchTemplateState"
                    TemplateManagerProxy.setFilterRegExp(".*" + searchText.text + ".*");
                }
            }

            Rectangle {
                height: 60
                width: 260
                color: "#ba68c6"
                anchors {verticalCenter: parent.verticalCenter; horizontalCenter: parent.horizontalCenter}
                TextEdit {
                    id: searchText
                    height: parent.height
                    width: parent.width
                    anchors {top: parent.top; left: parent.left}
                    color: "#ffffff"
                    font.pointSize: 18
                    focus: true;
                    wrapMode: TextEdit.Wrap;
                    selectByMouse: true;

                }
            }

            Icon {
                id: disableSearchMode;
                height: 100
                width: 100
                visible: false
                anchors {right: parent.right; bottom: parent.bottom}
                iconImage : "qrc:///src/delete.png" //белым цветом!
                function sendSignal() {
                    TemplateManagerProxy.setFilterRegExp("");
                    templateMainListView.state = " "
                }
            }

            Icon {
                id: createNewTemplate;
                height: 64
                width: 64
                visible: true
                z: 11
                anchors {right: parent.right; rightMargin: 10; verticalCenter: parent.bottom}
                iconImage : "qrc:///src/add_template.png"
                function sendSignal() {
                    //console.log("add new template")
                    templateMainListView.state = "addTemplateState"

                }
            }

        }
    }

    EditTemplateElement {
        id: addNewTemplateElement
        anchors {top: searchRect.bottom;}
        function saveTemplate() {
            if (templateTextEdit.text != "Текст шаблона" && templateTitleEdit.text != "Заголовок шаблона") {
                TemplateManager.addTemplate(templateTitleEdit.text, templateTextEdit.text);
            }
            templateMainListView.state = " ";
        }

        function cancelAdding() {
            templateMainListView.state = " ";

        }

    }

    ListView {
        id: templateList;
        width: 480;
        height: 340;
        anchors.top: addNewTemplateElement.bottom
        clip: true
        highlightFollowsCurrentItem: true

        model: TemplateManagerProxy
        delegate: TemplateListElement {templateTitle: title; templateText: text}
        Component.onCompleted: {
           mainWindow.headerText = "Шаблон"
           footerMenu.templatesIconImg = "qrc:///src/templates_selected.png"
           footerMenu.friendsIconImg = "qrc:///src/friends.png"
           footerMenu.bdaysIconImg = "qrc:///src/bdays.png"
           footerMenu.settingsIconImg = "qrc:///src/settings.png"
        }

   }

    states: [
        State {
            name: "addTemplateState"
            PropertyChanges { target: addNewTemplateElement; height: 210; visible: true; }
            PropertyChanges { target: createNewTemplate; visible: false}
        },
        State {
            name: "searchTemplateState"
            PropertyChanges { target: createNewTemplate; visible: false}
            PropertyChanges { target: disableSearchMode; visible: true}
        }

    ]

}*/
