import QtQuick 1.1

Rectangle {
    width: 480
    height: 640
    color: "#eeeeee"

    Rectangle {
        id: main_area
        x: 0
        y: 0
        width: 480
        height: 540
        color: "#ffffff"
        z: 2

        Rectangle {
            id: header
            x: 0
            y: 0
            width: 480
            height: 100
            color: "#a64fb3"

            Text {
                id: window_name
                x: 174
                y: 32
                color: "#ffffff"
                text: "Настройки"
                wrapMode: Text.NoWrap
                font.bold: true
                font.family: "FreeSans"
                font.pointSize: 25
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }


        Rectangle {
            id: setting_1
            x: 2
            y: 200
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            border.width: 4
            border.color: "#dddddd"

            Text {
                id: setting_text_1
                x: 16
                y: 35
                color: "#757575"
                text: qsTr("Кого поздравлять")
                font.bold: true
                font.pointSize: 14
                font.pixelSize: 12
            }

            MouseArea {
                id: setting_mousearea_1
                x: -2
                y: -4
                width: 478
                height: 89
            }
        }

        Rectangle {
            id: subheader
            x: 0
            y: 99
            width: 480
            height: 100
            color: "#9575cd"

            Text {
                id: settings_name
                x: 181
                y: 32
                color: "#ffffff"
                text: "Общие"
                font.bold: true
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                font.family: "FreeSans"
                wrapMode: Text.NoWrap
                font.pointSize: 25
            }
        }

        Rectangle {
            id: setting_2
            x: 2
            y: 285
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Text {
                id: setting_text_2
                x: 16
                y: 35
                color: "#757575"
                text: qsTr("Работать в фоне")
                font.pixelSize: 12
                font.bold: true
                font.pointSize: 14
            }

            Image {
                id: check_mark
                x: 428
                y: 30
                width: 24
                height: 26
                source: "../src/mark.png"
            }

            MouseArea {
                id: setting_check_mousearea_2
                x: 376
                y: 0
                width: 100
                height: 85
            }
            border.width: 4
            border.color: "#dddddd"
        }

        Rectangle {
            id: setting_3
            x: 2
            y: 371
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Text {
                id: setting_text_3
                x: 16
                y: 35
                color: "#757575"
                text: qsTr("Когда предупреждать")
                font.bold: true
                font.pixelSize: 12
                font.pointSize: 14
            }

            MouseArea {
                id: setting_mousearea_2
                x: -2
                y: -4
                width: 478
                height: 89
            }
            border.width: 4
            border.color: "#dddddd"
        }

        Rectangle {
            id: setting_4
            x: 2
            y: 455
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Text {
                id: setting_text_4
                x: 16
                y: 35
                color: "#757575"
                text: qsTr("Как поздравлять")
                font.pixelSize: 12
                font.bold: true
                font.pointSize: 14
            }

            MouseArea {
                id: setting_mousearea_3
                x: -2
                y: -4
                width: 478
                height: 89
            }
            border.width: 4
            border.color: "#dddddd"
        }
    }

    Rectangle {
        id: footer
        x: 0
        y: 540
        width: 480
        height: 100
        color: "#a64fb3"

        Image {
            id: templates_icon
            x: 0
            y: 0
            width: 100
            height: 100
            source: "../src/templates.png"

            MouseArea {
                id: templates_icon_1
                x: 0
                y: 0
                width: 100
                height: 100
            }
        }

        Image {
            id: friends_icon
            x: 126
            y: 0
            width: 100
            height: 100
            source: "../src/friends.png"

            MouseArea {
                id: edit_friends_mousearea
                x: 0
                y: 0
                width: 100
                height: 100
            }
        }

        Image {
            id: bdays_icon
            x: 254
            y: 0
            width: 100
            height: 100
            source: "../src/bdays.png"

            MouseArea {
                id: edit_bdays_mousearea
                x: 0
                y: 0
                width: 100
                height: 100
            }
        }

        Image {
            id: settings_icon
            x: 380
            y: 0
            width: 100
            height: 100
            source: "../src/settings_selected.png"
        }


    }


}
