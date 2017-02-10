import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

ColumnLayout {
    anchors.fill: parent
    GridLayout {
    //    property var data: []
//        Layout.alignment: Qt.AlignTop
    //    Layout.alignment: Qt.AlignCenter
        columns: 2

        Label {
            text: "Доля водорода H, %:"
        }
        TextField {
            id: propH
            Layout.fillWidth: true
            text: "25"
        }

        Label {
            text: "Доля углерода С, %:"
        }
        TextField {
            id: propC
            Layout.fillWidth: true
            text: "75"
        }

        Label {
            text: "Вещество:"
        }
        ComboBox {
            id: subM
            Layout.fillWidth: true
            model: ["водород", "кислород", "воздух"]
            currentIndex: 1
        }

        Label {
            text: "Плотность P:"
        }
        TextField {
            id: p
            Layout.fillWidth: true
            text: "0.5"
        }
    }

    Button {
        id: btnSolve
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignTop
        text: "Решить"
        onClicked: {
            if (condition.currentIndex == 0)
                solution.text = condition1.solve()
            else
                solution.text = condition2.solve()
        }
    }

    GroupBox {
        Layout.fillWidth: true
//        Layout.fillHeight: true
        TextArea {
            width: parent.width
            id: solution
            text: ""


            readOnly: true
            wrapMode: TextEdit.WordWrap
        }
    }

//    Flickable {

//        ColorAnimation {
//            from: "white"
//            to: "black"
//            duration: 200
//        }

//        id: flickCond1
//        clip: true
//        contentHeight: solution.height
//        TextArea {
//            id: solution
//            text: "flick me!"
//        }
//        ScrollBar.vertical: ScrollBar { }
//    }

    function solve() {
        var m = 2;
        if (subM.currentIndex == 0)
            m = 2;
        else if (subM.currentIndex == 1)
            m = 32
        else if (subM.currentIndex == 2)
            m = 29

        return appCore.type1(propH.text, propC.text, m, p.text)
    }

}
