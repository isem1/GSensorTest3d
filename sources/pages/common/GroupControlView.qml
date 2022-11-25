import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    property bool expanded: true
    property bool collapsable: true
    property string title: "#title"

    property Component contentDelegate: null
    readonly property Item contentItem: loader.item

    id: root
    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    ColumnLayout {
        id: layout
        spacing: 0
        anchors.fill: parent

        Rectangle {
            id: headerRect
            color: "#a2a2a2"
            Layout.fillWidth: true
            Layout.minimumHeight: txt.height

            MouseArea {
                id: msarea
                anchors.fill: parent
                hoverEnabled: true

                onPressed: {
                    headerRect.color = "#676767"
                }

                onReleased: {
                    headerRect.color = "#a2a2a2"

                    if (root.collapsable)
                        root.expanded = !root.expanded
                }

                onExited: {
                    headerRect.color = "#a2a2a2"
                }

                Text {
                    id: txt
                    padding: 5
                    text: title
                    font.pointSize: 12
                }
            }
        }

        Item {
            id: clipper
            clip: true
            visible: root.expanded
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: root.expanded ? root.contentItem.implicitHeight : 0

            Rectangle {
                id: bodyRect
                color: "#dddddd"
                anchors.fill: parent

                Loader {
                    id: loader
                    active: true
                    anchors.fill: parent
                    sourceComponent: root.contentDelegate
                }
            }
        }
    }
}
