import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Rectangle {
    //width: 200
    height: 100
    //color: "blue"


    Label {
        id: label
        //width: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 8
        text: "Теория"
    }

    RoundMouseArea {
        id: roundMouseArea1
        width: 100
        height: 100
        //anchors.horizontalCenter: parent.horizontalCenter
        //anchors.horizontalCenterOffset: 100
        anchors.left: label.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 8
        //anchors.centerIn: parent

        onClicked:  print("clicked")

        Rectangle {
            color: roundMouseArea1.pressed ? "darkorange" : "transparent"
            border.color: "darkorange"
            radius: width / 2
            anchors.fill: parent
        }
    }

}
