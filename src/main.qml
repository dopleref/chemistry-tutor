import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

//ApplicationWindow {
//    visible: true
//    title: "Test interaction"
//    width: 480
//    height: 640

//    Connections {
//        target: appCore
//        onSendToQml: {
//            text1.text = count
//        }
//    }

//    ColumnLayout {
//        Button { text: "button1" }
//        Button {
//            text: "button2"
//            onClicked: appCore.receiveFromQml()
//        }
//        Text {
//            id: text1
//            text: "sometext"
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

                Condition1 {
                    Layout.alignment: Qt.AlignCenter
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

            GroupBox {
                Layout.fillWidth: true
                Layout.fillHeight: true
                TextArea {text: "" }
                Task1 {}
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
