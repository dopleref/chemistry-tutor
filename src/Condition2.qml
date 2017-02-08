import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

GridLayout {
    id: condition2
    Layout.alignment: Qt.AlignCenter
    columns: 2

    Label {
        text: "m(вещества)"
    }
    TextField {
        Layout.fillWidth: true
    }

    Label {
        text: "m(CO2)"
    }
    TextField {
        Layout.fillWidth: true
    }

    Label {
        text: "m(H20)"
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
