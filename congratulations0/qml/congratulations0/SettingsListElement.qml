import QtQuick 1.1

Item {
    id: settingsListElement;
    width: 480
    implicitHeight: 100
    property alias settingsText: settingsText.text
    Rectangle {
        id: settingsMainRect
        color: "#eeeeee"
        border {color: "#cccccc"; width: 4}
        width: parent.width
        height: 100

        signal editSettings(int optionIndex);
        onEditSettings: {
            //console.log(index)
            //console.log(optionIndex)
            SettingsManager.editSettings(index, optionIndex);
        }

        Rectangle {
            id: settingsTitleRect;
            width: parent.width
            height: parent.height

            Text {
                id: settingsText
                anchors {verticalCenter: parent.verticalCenter; leftMargin: 10}
                color: "#777777"
                font.pointSize: 15
                Component.onCompleted: {
                    if (settingsListElement.state != "headerElement") {
                        settingsText.anchors.left = parent.left
                    }
                }
            }

            Icon {
                id: isCheckedIcon
                height: 24
                width: 24
                property bool isOnFlag: isOn
                anchors {verticalCenter: parent.verticalCenter; right: parent.right; rightMargin: 10}
                //проблема: нужна нормальная иконка!!!
                iconImage: (isOnFlag == true)? "qrc:///src/mark.png" : "qrc:///src/ic_check.png"
                visible: false
                function sendSignal() {}
            }

            MouseArea {
                id:  settingsTitleRectMousearea;
                width: parent.width;
                height: parent.height;
            }

            Component.onCompleted: {
                settingsMainRect.height = settingsTitleRect.height
            }

        }

        Rectangle {
            id: listSettingsInfo
            visible: false
            width: parent.width
            anchors {top: settingsTitleRect.bottom}
            ListView {
                id: listViewSettingsInf
                anchors {top: parent.top}
                width: parent.width
                height: parent.height
                model: settingsOptions

                property variant iconsList: ["qrc:///", "qrc:///", "qrc:///"]
                property int selectedOptionId: selectedOption

                //ужасный код!!!
                function updateCheckedOptionMarks() {
                    var tmpIconList = listViewSettingsInf.iconsList;
                    for (var iter = 0; iter < 3; ++iter)  {
                        tmpIconList[iter] = ((iter  == listViewSettingsInf.selectedOptionId)? "qrc:///src/checked.png" : "qrc:///src/ic_check.png");
                        //console.log(tmpIconList[iter])
                    }
                    listViewSettingsInf.iconsList = tmpIconList;
                }

                delegate: Rectangle {
                    id: optionRect
                    width: parent.width;
                    height: 40;



                    Icon {
                        id: checkOptionIcon
                        height: 32;
                        width: 32;
                        anchors {verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 8}
                        iconImage: listViewSettingsInf.iconsList[index]//(index == selectedOption)? "qrc:///src/checked.png" : "qrc:///src/ic_check.png"
                    }

                    Text {
                        text: settingsOptions[index]
                        anchors {verticalCenter: parent.verticalCenter; left: checkOptionIcon.right;leftMargin: 8}
                    }

                    MouseArea {
                        height: parent.height
                        width: parent.width
                        anchors {top: parent.top; left: parent.left}
                        onClicked: {
                            listViewSettingsInf.selectedOptionId = index
                            settingsMainRect.editSettings(index);
                            listViewSettingsInf.updateCheckedOptionMarks();

                        }
                    }

                    Component.onCompleted: {
                        listViewSettingsInf.updateCheckedOptionMarks()
                    }

                }

            }

        }
        states:[ State {
                    name: "openInfoState"
                    PropertyChanges { target: listSettingsInfo; visible: true; height: listViewSettingsInf.count * 40 + 10}
                    PropertyChanges { target: settingsListElement; height: listViewSettingsInf.count * 40 + 110;}
                    PropertyChanges {target: settingsTitleRectMousearea;
                        onClicked: {
                            settingsMainRect.state = ' '
                        }
                    }
            }

        ]
    }

    states: [
        State {
            name: "listSettingsElement"
            PropertyChanges { target: isCheckedIcon; visible: false}
            PropertyChanges { target: settingsTitleRectMousearea;
                onClicked: {
                    settingsMainRect.state = "openInfoState"
                }
            }
        },

        State {
            name: "offOnSettingsElement"
            PropertyChanges { target: isCheckedIcon; visible: true}
            PropertyChanges { target: settingsTitleRectMousearea;
                onClicked: {
                    //console.log("called")
                    isCheckedIcon.isOnFlag = !isCheckedIcon.isOnFlag
                    SettingsManager.editSettings(index, !isOn);
                    //isCheckedIcon.iconImage = (isCheckedIcon.isOnFlag == true)? "qrc:///src/mark.png" : "qrc:///src/ic_check.png"
                    //console.log(newIsOnFlag)
                }
            }
        },
        State {
            name: "headerElement"
            PropertyChanges { target: settingsTitleRect; color: "#9575cd"; }
            PropertyChanges { target: settingsText; color: "#ffffff"; font.pixelSize: 25; anchors {verticalCenter: settingsTitleRect.verticalCenter; horizontalCenter: settingsTitleRect.horizontalCenter;}}
        }


    ]
}
