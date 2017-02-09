import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

GridLayout {
    Layout.alignment: Qt.AlignCenter
    columns: 2

    Label {
        text: "m(вещества)"
    }
    TextField {
        Layout.fillWidth: true
        text: "130"
    }

    Label {
        text: "m(CO2)"
    }
    TextField {
        Layout.fillWidth: true
        text: "44"
    }

    Label {
        text: "m(H20)"
    }
    TextField {
        Layout.fillWidth: true
        text: "18"
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
        text: "39"
    }
}
