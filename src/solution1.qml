import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {

    GridLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 50
        rows: 2
        columns: 5

        Label {
            text: "Доля водорода H, %:"
            Layout.row: 1
            Layout.column: 1
        }
        TextField {
            Layout.row: 1
            Layout.column: 2
        }

        Label {
            text: "Доля углерода С, %:"
            Layout.row: 2
            Layout.column: 1
        }
        TextField {
            Layout.row: 2
            Layout.column: 2
        }

        Label {
            text: "Вещество:"
            Layout.row: 3
            Layout.column: 1
        }
        ComboBox {
            model: ["водород", "кислород", "воздух"]
            Layout.row: 3
            Layout.column: 2
        }

        Label {
            text: "Плотность P:"
            Layout.row: 4
            Layout.column: 1
        }
        TextField {
            id : density
            Layout.row: 4
            Layout.column: 2
        }
    }

}

