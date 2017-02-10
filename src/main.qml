import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

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
//            condition.changeIndex()
//            solution.init()
//            appCore.test(Condition1.)
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
                id: solveLayout
                anchors.fill: parent

                StackLayout {
                    Layout.fillHeight: false
                    id: condition
                    currentIndex: 0
//                    function changeIndex() {
//                        if (condition.currentIndex == 0) {
//                            Layout.preferredHeight = condition1.height
//                            solution.resize(condition1.height)
//                        }
//                        else {
//                            Layout.preferredHeight = condition2.height
//                            solution.resize(condition2.height)
//                        }

//                    }

//                    onCurrentIndexChanged: {
//                        condition.changeIndex()
//                    }

                    Condition1 {
                        id: condition1
                    }
                    Condition2 {
                        id: condition2
                    }
                }

//                Button {
//                    id: btnSolve
//                    Layout.fillWidth: true
//                    Layout.alignment: Qt.AlignTop
//                    text: "Решить"
//                    onClicked: {
//                        if (condition.currentIndex == 0)
//                            solution.text = condition1.solve()
//                        else
//                            solution.text = condition2.solve()
//                    }
//                }

//                GroupBox {
//                    Layout.fillWidth: true
//                    Layout.fillHeight: true
//                    TextArea {
//                        id: solution
//                        text: ""
//                    }

//                    function init() {
//                        Layout.fillHeight = true
//                    }

////                    function resize(height) {
////                        Layout.fillHeight = false
////                        var h = solveLayout.height - height - btnSolve.height - 11
////                        Layout.preferredHeight = h
////                    }
//                    }
            }

            ColumnLayout {
                Button {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignCenter
                    text: "Сгенерировать задачу"
                    onClicked: {
                        if (taskLayout.currentIndex < 2) {
                            taskLayout.currentIndex++;
                        }
                        else {
                            taskLayout.currentIndex = 0;
                        }
                    }
                }
                GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    StackLayout {
                        width: parent.width
                        id: taskLayout
                        currentIndex: 0
                        TextArea {
                            width: parent.width
                            text: "Доля водорода 20 %, плотность по водороду 15, найти формулу вещества"
                            readOnly: true
                            wrapMode: TextEdit.WordWrap
                        }
                        TextArea {
                            width: parent.width
                            text: "Доля углерода 80 %, плотность по водороду 1,034, найти формулу вещества"
                            readOnly: true
                            wrapMode: TextEdit.WordWrap
                        }
                        TextArea {
                            width: parent.width
                            text: "Доля водорода 14 %, плотность по водороду 21, найти формулу вещества"
                            readOnly: true
                            wrapMode: TextEdit.WordWrap
                        }

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
