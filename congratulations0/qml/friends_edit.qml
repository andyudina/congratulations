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
                x: 173
                y: 32
                color: "#ffffff"
                text: qsTr(" Друзья")
                wrapMode: Text.NoWrap
                font.bold: true
                font.family: "FreeSans"
                font.pointSize: 25
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }



        Rectangle {
            id: bday_2
            x: 2
            y: 319
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
                x: 116
                y: 48
                color: "#383838"
                text: qsTr("Аня Ахматова")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Image {
                id: delete_friend_2
                x: 376
                y: 2
                width: 100
                height: 100
                MouseArea {
                    id: delete_friend_mousearea_2
                    x: 0
                    y: 0
                    width: 100
                    height: 100
                }
                source: "../src/disable.png"
            }
        }
        Rectangle {
            id: bday_3
            x: 2
            y: 430
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
                source: "../src/3.jpg"
            }

            Text {
                id: friends_name_3
                x: 116
                y: 42
                color: "#383838"
                text: qsTr("Саша Блок")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Image {
                id: delete_friend_3
                x: 376
                y: 2
                width: 100
                height: 100
                MouseArea {
                    id: delete_friend_mousearea_3
                    x: 0
                    y: 0
                    width: 100
                    height: 100
                }
                source: "../src/disable.png"
            }
        }

        Rectangle {
            id: bday_1
            x: 2
            y: 98
            width: 476
            height: 215
            color: "#ffffff"
            radius: 0
            Image {
                id: friend_photo_1
                x: 8
                y: 15
                width: 86
                height: 83
                source: "../src/1.jpg"
            }

            Text {
                id: friends_name_1
                x: 111
                y: 15
                color: "#383838"
                text: qsTr("Анна Анна")
                font.pixelSize: 12
                font.pointSize: 14
            }

            Image {
                id: delete_friend_1
                x: 376
                y: -4
                width: 100
                height: 100
                source: "../src/disable.png"

                MouseArea {
                    id: delete_friend_mousearea_1
                    x: 0
                    y: 0
                    width: 100
                    height: 100
                }
            }

            Text {
                id: bday_date_1
                x: 111
                y: 65
                width: 65
                height: 22
                color: "#d32f2f"
                text: qsTr("вчера")
                font.bold: true
                wrapMode: Text.NoWrap
                font.pixelSize: 12
                font.pointSize: 14
            }

            Image {
                id: missed_bday_warning
                x: 177
                y: 51
                width: 51
                height: 51
                source: "../src/alert.png"
            }

            Text {
                id: template
                x: 8
                y: 114
                color: "#9c27b0"
                text: qsTr("Шаблон")
                wrapMode: Text.NoWrap
                font.pixelSize: 12
                font.pointSize: 14
            }

            Text {
                id: template_name
                x: 111
                y: 114
                color: "#838383"
                text: qsTr("нет шаблона")
                font.bold: true
                font.pointSize: 14
                wrapMode: Text.NoWrap
                font.pixelSize: 12
            }

            Image {
                id: template_edit
                x: 376
                y: 102
                width: 100
                height: 100
                MouseArea {
                    id: template_edit_mousearea_1
                    x: 2
                    y: -1
                    width: 100
                    height: 100
                }
                source: "../src/edit_template.png"
            }

            Image {
                id: vk_link_1
                x: 111
                y: 153
                width: 48
                height: 52
                source: "../src/vk.jpg"
            }

            Text {
                id: link
                x: 8
                y: 172
                color: "#9c27b0"
                text: qsTr("Ссылка")
                font.pixelSize: 12
                wrapMode: Text.NoWrap
                font.pointSize: 14
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
            source: "../src/friends_selected.png"
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
