import QtQuick 1.1

AbstractTemplateListView {
    id: personaleTemplateListView
    listView.model: PersonalTemplateManagerProxy
    listView.delegate: PersonalTemplateListElement {templateTitle: title; templateText: text; isSelectedFlag: isSelected}
    mainWindowHeaderText: "Шаблон для\n" + PersonalTemplateManager.personName;
    templatesIconImgPath: "qrc:///src/templates.png";
    function addTemplate(title, text) {
        PersonalTemplateManager.addTemplate(title, text);
    }
}
