import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import QtQuick.Window 2.3

import "pages"
import "pages/common"
import app 1.0

Window {
    id: mainWindow
    title: qsTr("GSensorTest3d")
    visible: true
    minimumWidth: 800
    minimumHeight: 480

    SerialPortReader {
        id: reader
    }

    PortSettingsModel {
        id: modelPS
    }

    RowLayout {
        spacing: 0
        anchors.fill: parent

        ScrollView {
            id: settings
            Layout.fillHeight: true
            Layout.preferredWidth: 350

            ColumnLayout {
                anchors.left: parent.left
                anchors.right: parent.right

                GroupControlView {
                    expanded: true
                    title: qsTr("Port Settings")
                    Layout.fillWidth: true

                    contentDelegate: PortSettingsView {
                        id: portSettigns
                        serialPortList: modelPS.serialPortList

                        Connections {
                            target: portSettigns
                            function onOnSerialOpenClicked(name, speed) {
                                reader.openSerialPort(name, speed)
                            }
                        }
                    }
                }

                GroupControlView {
                    expanded: false
                    title: qsTr("Gyroscope Settings")
                    Layout.fillWidth: true

                    contentDelegate: GyroscopeSettingsView {
                        id: gyroSettings

                        Connections {
                            target: reader
                            function onNewGyroscopeData(x, y, z) {
                                if (gyroSettings.gscEnabled) {
                                    gyroSettings.update(x, y, z)
                                }
                            }
                        }
                    }
                }

                GroupControlView {
                    expanded: false
                    title: qsTr("Accelerometer Settings")
                    Layout.fillWidth: true

                    contentDelegate: GyroscopeSettingsView {
                        id: accelSettigns

                        Connections {
                            target: reader
                            function onNewAccelerometerData(x, y, z) {
                                if (accelSettigns.gscEnabled) {
                                    accelSettigns.update(x, y, z)
                                }
                            }
                        }
                    }
                }

                GroupControlView {
                    expanded: false
                    title: qsTr("DMP Settings")
                    Layout.fillWidth: true

                    contentDelegate: GyroscopeSettingsView {
                        id: dmpSettings

                        Connections {
                            target: reader
                            function onNewAngleDataC2(x, y, z) {
                                if (dmpSettings.gscEnabled) {
                                    dmpSettings.update(x, y, z)
                                }
                            }
                        }
                    }
                }
            }

        }

        Connections {
            target: reader

            function onNewAngleDataC2(yaw, pitch, roll) {
                //scene3d.setRotation1(0.0 - pitch, roll)
                scene3d.setRotation12(0.0 - yaw, roll, pitch)
            }

            function onNewAngleDataG(pitch, roll) {
                scene3d.setRotation3(pitch, roll)
            }

            function onNewAngleDataA(pitch, roll) {
                scene3d.setRotation2(pitch, roll)
            }
        }

        ApplicationScene3dView {
            id: scene3d

            Layout.fillWidth: true
            Layout.fillHeight: true


        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
