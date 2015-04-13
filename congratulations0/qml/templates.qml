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
                text: qsTr("Шаблоны")
                wrapMode: Text.NoWrap
                font.bold: true
                font.family: "FreeSans"
                font.pointSize: 25
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }


        Rectangle {
            id: template_1
            x: 2
            y: 199
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            border.width: 4
            border.color: "#dddddd"

            Image {
                id: delete_template_1
                x: 8
                y: 8
                width: 32
                height: 32
                MouseArea {
                    id: delete_template_mousearea_1
                    x: 0
                    y: 0
                    width: 32
                    height: 32
                }
                source: "../src/delete.png"
            }

            Text {
                id: template_name_1
                x: 53
                y: 10
                text: qsTr("Шаблон 1")
                font.bold: true
                font.pointSize: 14
                font.pixelSize: 12
            }

            Text {
                id: template_text_1
                x: 8
                y: 51
                text: qsTr("С ДР!")
                font.pointSize: 11
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: search
            x: 0
            y: 99
            width: 480
            height: 100
            color: "#a64fb3"

            Image {
                id: search_icon
                x: 0
                y: 0
                width: 100
                height: 100
                source: "../src/search.png"

                TextInput {
                    id: search_input
                    x: 113
                    y: 16
                    width: 253
                    height: 58
                    text: qsTr("")
                    echoMode: TextInput.Normal
                    font.pixelSize: 12

                    Image {
                        id: add_new_template
                        x: 236
                        y: 35
                        width: 100
                        height: 100
                        z: 1
                        source: "../src/add_template.png"

                        MouseArea {
                            id: add_new_template_mousearea
                            x: 0
                            y: 1
                            width: 100
                            height: 100
                        }
                    }

                    Rectangle {
                        id: to_be_deleted
                        x: 256
                        y: 55
                        width: 55
                        height: 61
                        color: "#ffffff"
                        z: 0
                    }
                }
            }
        }

        Rectangle {
            id: template_2
            x: 2
            y: 285
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Image {
                id: delete_template_2
                x: 8
                y: 8
                width: 32
                height: 32
                MouseArea {
                    id: delete_template_mousearea_2
                    x: 0
                    y: 0
                    width: 32
                    height: 32
                }
                source: "../src/delete.png"
            }

            Text {
                id: template_name_2
                x: 53
                y: 10
                text: qsTr("Шаблон 2")
                font.pixelSize: 12
                font.bold: true
                font.pointSize: 14
            }

            Text {
                id: template_text_2
                x: 8
                y: 51
                text: qsTr("Поздравляю с Днем Рождения! Счастья, Здоровья!")
                font.pixelSize: 12
                font.pointSize: 11
            }
            border.width: 4
            border.color: "#dddddd"
        }

        Rectangle {
            id: template_3
            x: 2
            y: 371
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Image {
                id: delete_template_3
                x: 8
                y: 8
                width: 32
                height: 32
                MouseArea {
                    id: delete_template_mousearea_3
                    x: 0
                    y: 0
                    width: 32
                    height: 32
                }
                source: "../src/delete.png"
            }

            Text {
                id: template_name_3
                x: 53
                y: 10
                text: qsTr("Шаблон 3")
                font.family: "DejaVu Sans Mono"
                font.pixelSize: 12
                font.bold: true
                font.pointSize: 14
            }

            Text {
                id: template_text_3
                x: 8
                y: 51
                text: qsTr("Поздравляю с днем Рождения!")
                font.pixelSize: 12
                font.pointSize: 12
            }
            border.width: 4
            border.color: "#dddddd"
        }

        Rectangle {
            id: template_4
            x: 2
            y: 455
            width: 476
            height: 85
            color: "#eeeeee"
            radius: 0
            Image {
                id: delete_template_4
                x: 8
                y: 8
                width: 32
                height: 32
                MouseArea {
                    id: delete_template_mousearea_4
                    x: 0
                    y: 0
                    width: 32
                    height: 32
                }
                source: "../src/delete.png"
            }

            Text {
                id: template_name_4
                x: 53
                y: 10
                text: qsTr("Шаблон тест")
                font.pixelSize: 12
                font.bold: true
                font.pointSize: 14
            }

            Text {
                id: template_text_4
                x: 8
                y: 51
                text: qsTr("Привет! С Днем Рождения!")
                font.pixelSize: 12
                font.pointSize: 11
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
            id: templates_icon_disabled
            x: 0
            y: 0
            width: 100
            height: 100
            source: "../src/templates_selected.png"
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
