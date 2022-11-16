import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2

import "pages"

ApplicationWindow {
    id: mainWindow
    title: qsTr("GSensorTest3d")
    visible: true
    minimumWidth: 800
    minimumHeight: 480

    RowLayout {
        spacing: 0
        anchors.fill: parent

        Rectangle {
            id: controlPanel

            Layout.fillHeight: true
            Layout.preferredWidth: 350

            ColumnLayout {
                spacing: 10

                anchors {
                    left: parent.left
                    right: parent.right
                }

                PortSettingsView {
                    id: portSettigns
                    Layout.fillWidth: true
                    Layout.preferredHeight: 72
                }
            }
        }

        ApplicationScene3dView {
            id: scene3d

            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
