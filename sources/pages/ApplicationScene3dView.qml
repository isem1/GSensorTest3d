import QtQuick.Scene3D 2.4

import Qt3D.Input 2.4
import Qt3D.Render 2.4
import Qt3D.Extras 2.4
import Qt3D.Core 2.4

Scene3D {
    id: current
    focus: true
    antialiasing: true
    aspects: ["render", "logic", "input"]
    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

    function setRotation1(pitch, roll) {
        transform3d.setRotationX(pitch)
        transform3d.setRotationZ(roll)
    }

    function setRotation12(yaw, pitch, roll) {
        transform3d.setRotationY(yaw)
        transform3d.setRotationX(pitch)
        transform3d.setRotationZ(roll)
    }

    function setRotation2(pitch, roll) {
        transform3d2.setRotationX(pitch)
        transform3d2.setRotationZ(roll)
    }

    function setRotation3(pitch, roll) {
        transform3d3.setRotationX(pitch)
        transform3d3.setRotationZ(roll)
    }

    Entity {
        id: sceneRoot

        Camera {
            id: camera
            projectionType: CameraLens.PerspectiveProjection
            fieldOfView: 45.0
            nearPlane : 0.1
            farPlane : 1000.0
            position: Qt.vector3d(10.0, 10.0, 10.0)
            upVector: Qt.vector3d(0.0, 1.0, 0.0)
            viewCenter: Qt.vector3d(0.0, 0.0, -4.0)
        }

        OrbitCameraController {
            id: controller
            camera: camera
        }

        components: [
            RenderSettings {
                id: renderSettings
                activeFrameGraph: ForwardRenderer {
                    camera: camera
                }
            },
            InputSettings {}
        ]

        Entity {
            id: meshEnt

            components: [
                PhongAlphaMaterial {
                    id: material
                    ambient: "red"
                },
                Transform {
                    id: transform3d
                    scale: 2.5
                    translation: Qt.vector3d(5.0, 5.0, 5.0)
                },
                CuboidMesh {
                    id: mesh
                    xExtent: 1.25
                    yExtent: 0.35
                }
            ]
        }

        Entity {
            id: meshEnt2

            components: [
                PhongAlphaMaterial {
                    id: material2
                    ambient: "green"
                },
                Transform {
                    id: transform3d2
                    scale: 2.5
                    translation: Qt.vector3d(5.0, 5.0, 1.0)
                },
                CuboidMesh {
                    id: mesh2
                    xExtent: 1.25
                    yExtent: 0.35
                }
            ]
        }

        Entity {
            id: meshEnt3

            components: [
                PhongAlphaMaterial {
                    id: material3
                    ambient: "blue"
                },
                Transform {
                    id: transform3d3
                    scale: 2.5
                    translation: Qt.vector3d(5.0, 5.0, -3.0)
                },
                CuboidMesh {
                    id: mesh3
                    xExtent: 1.25
                    yExtent: 0.35
                }
            ]
        }
    }
}
