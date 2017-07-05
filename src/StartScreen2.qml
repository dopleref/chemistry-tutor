import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Rectangle {
    //color: "blue"
    width: 480
    height: 640
   // anchors.fill: parent

    FontLoader { id: localFont; source: "10615.ttf" }

    ColumnLayout {
        //anchors.fill: parent
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter

        spacing: 20
        //anchors.fill: parent
        RoundLabeledButton {
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: localFont.name
            //font.pointSize: 48
            ccolor: "lightblue"
            text: "теория"
        }

        RoundLabeledButton {
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: localFont.name
            //font.pointSize: 48
            ccolor: "green"
            text: "практика"
            direction: Qt.RightToLeft
        }

        RoundLabeledButton {
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: localFont.name
            //font.pointSize: 48
            //ccolor: "red"
            ccolor: "darkorange"
            text: "рейтинг"
        }
    }
}


















