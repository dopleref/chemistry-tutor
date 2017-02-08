import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

GridLayout {
    id: condition1
    Layout.alignment: Qt.AlignCenter
    columns: 2

    Label {
        text: "Доля водорода H, %:"
    }
    TextField {
        Layout.fillWidth: true
    }

    Label {
        text: "Доля углерода С, %:"
    }
    TextField {
        Layout.fillWidth: true
    }

    Label {
        text: "Вещество:"
    }
    ComboBox {
        Layout.fillWidth: true
        model: ["водород", "кислород", "воздух"]
    }

    Label {
        text: "Плотность P:"
    }
    TextField {
        Layout.fillWidth: true
    }
}
