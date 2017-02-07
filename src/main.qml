import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    title: "Репетитор по химии"
    property int margin: 10
    width: 480
    height: 640

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: margin

        RowLayout {
            Layout.alignment: Qt.AlignCenter
            Text {
                text: "Тип задачи: "
            }

            ComboBox {
                Layout.fillWidth: true
                model: ["формула углеводорода", "формула вещества"]
            }
        }

        TabBar {
            id: tabBar
            Layout.fillWidth: true
            TabButton {
                text: "Решение"
                onClicked: stack.currentIndex = 0
            }
            TabButton {
                text: "Задачи"
                onClicked: stack.currentIndex = 1
            }
            TabButton {
                text: "Теория"
                onClicked: stack.currentIndex = 2
            }
        }

        StackLayout {
            id: stack
            currentIndex: 0
            ColumnLayout {
                GridLayout {
                    id: gridLayout
                    Layout.alignment: Qt.AlignCenter
                    columns: 2

                    Label {
                        text: "Доля водорода H, %:"
                    }
                    TextField {
                        Layout.fillWidth: true
                    }

                    Label {
                        text: "Доля углерода С, %:"
                    }
                    TextField {
                        Layout.fillWidth: true
                    }

                    Label {
                        text: "Вещество:"
                    }
                    ComboBox {
                        Layout.fillWidth: true
                        model: ["водород", "кислород", "воздух"]
                    }

                    Label {
                        text: "Плотность P:"
                    }
                    TextField {
                        Layout.fillWidth: true
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignCenter
                    text: "Решить"
                }

                GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    TextArea {text: "" }
                }
            }
        }
    }
}
