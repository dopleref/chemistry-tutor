import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    width: 480
    height: 640
    anchors.fill: parent

    GridLayout {
        anchors.fill: parent

        columns: 2

        Label {
            text: "Теория"
        }

        RoundMouseArea {
            id: roundMouseArea1
            width: 100
            height: 100
            //anchors.centerIn: parent

            onClicked:  print("clicked")

            Rectangle {
                color: roundMouseArea1.pressed ? "darkorange" : "transparent"
                border.color: "darkorange"
                radius: width / 2
                anchors.fill: parent
            }
        }

        RoundMouseArea {
            id: roundMouseArea2
            width: 100
            height: 100
            //anchors.centerIn: parent

            onClicked:  print("clicked")

            Rectangle {
                color: roundMouseArea2.pressed ? "green" : "transparent"
                border.color: "green"
                radius: width / 2
                anchors.fill: parent
            }
        }

        Label {
            text: "Практика"
        }

        Label {
            text: "Видео"
        }

        RoundMouseArea {
            id: roundMouseArea3
            width: 100
            height: 100
            //anchors.centerIn: parent

            onClicked:  print("clicked")

            Rectangle {
                color: roundMouseArea3.pressed ? "blue" : "transparent"
                border.color: "blue"
                radius: width / 2
                anchors.fill: parent
            }
        }

    }
}
