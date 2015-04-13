import QtQuick 1.1

AbstractTemplateListElement {
    id: personalTemplateListElement
    property bool isSelectedFlag : isSelected
    actionImage: (isSelectedFlag == true)? "qrc:///src/checked.png" : "qrc:///src/ic_check.png"

    function templateAction(index) {
        isSelectedFlag = !isSelectedFlag;
        PersonalTemplateManager.checkElement(index);
    }

    function editAndSaveTemplate(index, title, text) {
        isSelectedFlag = true;
        PersonalTemplateManager.editTemplate(index, title, text);
    }
}
