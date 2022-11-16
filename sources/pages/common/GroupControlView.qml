import QtQuick 2.0

Rectangle {
    id: current
    color: "#e4e4e4"

    property string title
    default property alias contentItem: content.data

    Rectangle {
        id: header
        color: "#b8b8b8"
        height: txt.height + 8
        anchors.left: parent.left
        anchors.right: parent.right

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: { header.color = "#a8a8a8" }
            onExited: { header.color = "#b8b8b8" }

            Rectangle {
                id: rect
                color: "transparent"
                anchors.fill: parent
                anchors.leftMargin: 10

                Text {
                    id: txt
                    text: title
                    font.pointSize: 12
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

     Column {
        id: content
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
     }
}
