import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Universal 2.1
import Qt.labs.settings 1.0

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    title: qsTr("Репетитор по химии")

    Column {
        anchors.topMargin: 10
        spacing:  10
        anchors.fill: parent

        Text {
            horizontalAlignment: Qt.AlignHCenter
            width: parent.width
            text: "Выберите тип задачи"
        }

        ComboBox {
            model: ["формула углеводорода", "формула вещества"]
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TabBar {
            id: tabBar
            width: parent.width

            TabButton {
                text: "Решение"               
            }
            TabButton {
                text: "Задачи"
            }
            TabButton {
                text: "Теория"
            }
        }

        solution1 {}
    }




}
