import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

GridLayout {
    Layout.alignment: Qt.AlignTop
//    Layout.alignment: Qt.AlignCenter
    columns: 2

    Label {
        text: "Доля водорода H, %:"
    }
    TextField {
        Layout.fillWidth: true
        text: "25"
    }

    Label {
        text: "Доля углерода С, %:"
    }
    TextField {
        Layout.fillWidth: true
        text: "75"
    }

    Label {
        text: "Вещество:"
    }
    ComboBox {
        Layout.fillWidth: true
        model: ["водород", "кислород", "воздух"]
        currentIndex: 1
    }

    Label {
        text: "Плотность P:"
    }
    TextField {
        Layout.fillWidth: true
        text: "0,5"
    }
}
