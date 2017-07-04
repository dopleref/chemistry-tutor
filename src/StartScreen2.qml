import QtQuick 2.0

Item {
    FontLoader { id: localFont; source: "10615.ttf" }

    RoundLabeledButton {
        font.family: localFont.name
        font.pointSize: 48
    }
}
