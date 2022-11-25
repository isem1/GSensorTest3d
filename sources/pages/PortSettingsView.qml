import QtQuick 2.9
import QtQuick.Controls 2.4

Item {
    id: root
    implicitHeight: 50

    property var serialPortList: null
    signal onSerialOpenClicked(string name, int speed)

    Row {
        id: row

        spacing: 10
        padding: 10
        anchors.verticalCenter: parent.verticalCenter

        Label {
            text: qsTr("Port:")
            anchors.verticalCenter: parent.verticalCenter
        }

        ComboBox {
            id: cbComPort
            width: 70

            model: root.serialPortList
            enabled: root.serialPortList? true : false
        }

        Label {
            text: qsTr("Rate:")
            anchors.verticalCenter: parent.verticalCenter
        }

        ComboBox {
            id: cbBaudRate
            width: 70
            currentIndex: 7

            model: ListModel {
                ListElement { text: "1200" }
                ListElement { text: "2400" }
                ListElement { text: "4800" }
                ListElement { text: "9600" }
                ListElement { text: "19200" }
                ListElement { text: "38400" }
                ListElement { text: "57600" }
                ListElement { text: "115200" }
            }
        }

        Button {
            id: btnDataStart
            width: 50
            text: qsTr("Open")
            enabled: root.serialPortList? true : false

            onReleased: {
                root.onSerialOpenClicked(cbComPort.currentText,
                    parseInt(cbBaudRate.currentText))
            }
        }
    }
}
