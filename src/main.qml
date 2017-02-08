import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

//ApplicationWindow {
//    id: window
//    visible: true
//    width: 480
//    height: 640

//    ColumnLayout {
////        Layout.fillHeight: true
////        Layout.fillWidth: true
//        anchors.fill: parent

//        Rectangle {
//            Layout.alignment: Qt.AlignCenter
//            color: "red"
//            Layout.preferredWidth: 40
//            Layout.preferredHeight: 40
//        }

//        Rectangle {
//                Layout.alignment: Qt.AlignRight
//                color: "green"
//                Layout.preferredWidth: 40
//                Layout.preferredHeight: 70
//            }

//        Rectangle {
//            Layout.alignment: Qt.AlignBottom
//            Layout.fillHeight: true
//            color: "blue"
//            Layout.preferredWidth: 70
//            Layout.preferredHeight: 40
//        }

//    }
//}

ApplicationWindow {
    id: window
    visible: true
    title: "Репетитор по химии"
    property int margin: 10
    width: 480
    height: 640

    function init() {
        console.log("init!");
    }

    Connections {
        target: appCore
        onInit: {
            window.init()
            theory1.text = appCore.getTheory1()
        }
    }

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
                id: taskType
                Layout.fillWidth: true
                model: ["формула углеводорода", "формула вещества"]
                onCurrentIndexChanged: {
                    condition.currentIndex = taskType.currentIndex
                }
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
                anchors.fill: parent

                StackLayout {
                    Layout.fillHeight: false
                    id: condition
                    currentIndex: 0
                    Condition1 {

//                        Layout.alignment: Qt.AlignCenter
                    }
                    Condition2 {}
                }

                Button {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignTop
                    //Layout.alignment: Qt.AlignCenter
                    text: "Решить"
                }

                GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    TextArea {
                        text: ""
                    }
                }
            }

            ColumnLayout {
                Button {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignCenter
                    text: "Сгенерировать задачу"
                }
                GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    TextArea {text: "" }
                    Text {
                        id: task
                        text: "Task1"
                    }
                }
            }

            Flickable {
                id: flickTheory
                clip: true
                contentHeight: theory1.height
                Theory1 {
                    id: theory1
                }
                ScrollBar.vertical: ScrollBar { }
            }
        }
    }
}
