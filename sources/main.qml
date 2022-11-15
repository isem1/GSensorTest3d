import QtQuick 2.9
import QtQuick.Controls 2.4

import "pages"

ApplicationWindow {
    id: mainWindow
    title: qsTr("GSensorTest3d")
    visible: true
    minimumWidth: 640
    minimumHeight: 480

    ApplicationScene3dView {
        id: scene3d
        anchors.fill: parent
    }
}
