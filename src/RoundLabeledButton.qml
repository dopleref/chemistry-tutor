import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    id: root
    height: 150
    signal clicked
    onClicked:  print("clicked")

    property string color: "darkorange"
    property alias direction: layout.layoutDirection

    RowLayout {
        id: layout
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            id: label
            //font.family: "Ubuntu"
            font.pointSize: 24
            text: "Теория"
        }

        Rectangle {
            id: roundButton
            width: 150
            height: 150
            radius: width / 2
            border.color: root.color
            border.width: 3
            color: pressed ? root.color : "transparent"

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

//                onPressed: if (roundMouseArea.containsMouse()) {
//                               roundButton.color = root.color
//                           }

//                onReleased: if (roundMouseArea.containsMouse()) {
//                                roundButton.color = "transparent"
//                            }
            }
        }
    }
}
