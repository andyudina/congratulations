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
                x: 111
                y: 32
                color: "#ffffff"
                text: qsTr("Ближайшие ДР")
                wrapMode: Text.NoWrap
                font.bold: true
                font.family: "FreeSans"
                font.pointSize: 25
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }




        Rectangle {
            id: bday_1
            x: 2
            y: 102
            width: 476
            height: 110
            color: "#d32f2f"
            radius: 0
            border.width: 4
            border.color: "#c93838"

            Image {
                id: friend_photo_1
                x: 8
                y: 15
                width: 80
                height: 80
                source: "../src/1.jpg"
            }

            Text {
                id: friends_name_1
                x: 115
                y: 15
                color: "#ffffff"
                text: qsTr("Анна Анна")
                font.pointSize: 14
                font.pixelSize: 12
            }

            Text {
                id: bday_date_1
                x: 115
                y: 72
                color: "#ffffff"
                text: qsTr("сегодня")
                font.pointSize: 14
                font.pixelSize: 12
            }
        }
        Rectangle {
            id: bday_2
            x: 2
            y: 218
            width: 476
            height: 110
            color: "#eeeeee"
            radius: 0
            border.width: 4
            border.color: "#dddddd"

            Image {
                id: friend_photo_2
                x: 8
                y: 15
                width: 80
                height: 80
                source: "../src/2.jpg"
            }

            Text {
                id: friends_name_2
                x: 115
                y: 15
                color: "#383838"
                text: qsTr("Аня Ахматова")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Text {
                id: bday_date_2
                x: 115
                y: 72
                color: "#383838"
                text: qsTr("1 апреля")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Image {
                id: image1
                x: 275
                y: 6
                width: 39
                height: 42
                source: "../src/alert.png"
            }
        }
        Rectangle {
            id: bday_3
            x: 2
            y: 321
            width: 476
            height: 110
            color: "#eeeeee"
            radius: 0
            border.width: 4
            border.color: "#dddddd"

            Image {
                id: friend_photo_3
                x: 8
                y: 13
                width: 80
                height: 80
                source: "../src/4.jpg"
            }

            Text {
                id: friends_name_3
                x: 115
                y: 13
                color: "#383838"
                text: qsTr("Саша Блок")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Text {
                id: bday_date_3
                x: 115
                y: 72
                color: "#383838"
                text: qsTr("16 апреля")
                font.pixelSize: 12
                font.pointSize: 14
            }
        }
        Rectangle {
            id: bday_4
            x: 2
            y: 424
            width: 476
            height: 110
            color: "#eeeeee"
            radius: 0
            border.width: 4
            border.color: "#dddddd"

            Image {
                id: friend_photo_4
                x: 8
                y: 15
                width: 80
                height: 80
                source: "../src/3.jpg"
            }

            Text {
                id: friends_name_4
                x: 115
                y: 13
                color: "#383838"
                text: qsTr("Просто Катя")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Text {
                id: bday_date_4
                x: 115
                y: 71
                color: "#383838"
                text: qsTr("5 мая")
                font.pixelSize: 12
                font.pointSize: 15
            }
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
                id: edit_templates_mousearea
                x: 0
                y: 0
                width: 100
                height: 100
            }
        }

        Image {
            id: friends_icon_disabled
            x: 126
            y: 0
            width: 100
            height: 100
            source: "../src/friends.png"
        }

        Image {
            id: bdays_icon
            x: 254
            y: 0
            width: 100
            height: 100
            source: "../src/bdays_selected.png"

            MouseArea {
                id: edit_bdays_mousearea
                x: -128
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
            source: "../src/settings.png"

            MouseArea {
                id: edit_settings_mousearea
                x: -4
                y: 0
                width: 100
                height: 100
            }
        }





    }


}
