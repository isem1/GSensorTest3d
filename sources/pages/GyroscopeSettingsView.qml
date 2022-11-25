import QtQuick 2.9
import QtQuick.Controls 6.3

Item {
    id: root
    implicitHeight: 70

    property alias gscEnabled: swGyro.checked

    function update(x, y, z) {
        textFieldx.text = x.toFixed(2)
        textFieldy.text = y.toFixed(2)
        textFieldz.text = z.toFixed(2)
    }

    Column {
        id: column
        spacing: 5

        Row {
            Switch {
                id: swGyro
                text: qsTr("Enable receiving data")

                onClicked: {
                    if (!root.gscEnabled) {
                        textFieldx.text = 0
                        textFieldy.text = 0
                        textFieldz.text = 0
                    }
                }
            }
        }

        Row {
            spacing: 10
            leftPadding: 10

            Label {
                text: "X:"
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: textFieldx
                width: 60
                enabled: swGyro.checked
                text: "0"
            }

            Label {
                text: "Y:"
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: textFieldy
                width: 60
                enabled: swGyro.checked
                text: "0"
            }

            Label {
                text: "Z:"
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: textFieldz
                width: 60
                enabled: swGyro.checked
                text: "0"
            }
        }
    }
}
