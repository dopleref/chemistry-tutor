import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Rectangle {
    //color: "darkorange"
    id: root
    height: 150 + layout.anchors.margins * 2
    width: label.width + roundButton.width +
           layout.spacing + layout.anchors.margins * 2
    signal clicked
    onClicked:  print(root.text)

    property string ccolor: "darkorange"
    property alias direction: layout.layoutDirection
    property alias font: label.font
    property alias text: label.text


    RowLayout {
        id: layout
        anchors.fill: parent
        anchors.margins: 10
        spacing: 50

        Label {
            id: label
            font.pointSize: 32
            text: "текст"
        }

        Rectangle {
            id: roundButton
            width: 150
            height: 150
            radius: width / 2
            border.color: root.ccolor
            border.width: 5
            color: pressed ? root.ccolor : "transparent"

            readonly property bool pressed: roundMouseArea.containsMouse() &&
                                            roundMouseArea.pressed

            MouseArea {
                id: roundMouseArea
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked:  if (roundMouseArea.containsMouse()) root.clicked()

                function containsMouse() {
                    var x1 = width / 2;
                    var y1 = height / 2;
                    var x2 = roundMouseArea.mouseX;
                    var y2 = roundMouseArea.mouseY;
                    var distanceFromCenter = Math.pow(x1 - x2, 2) +
                            Math.pow(y1 - y2, 2);
                    var radiusSquared = Math.pow(Math.min(width, height) / 2, 2);
                    var isWithinOurRadius = distanceFromCenter < radiusSquared;
                    return isWithinOurRadius;
                }
            }
        }
    }
}
