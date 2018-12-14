#ifndef __SCENEMODIFIER_HPP__
#define __SCENEMODIFIER_HPP__

/******************************************************************************/

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

/******************************************************************************/

class SceneModifier
    : public QObject
{

/******************************************************************************/

    Q_OBJECT

/******************************************************************************/

public:

/******************************************************************************/

    explicit SceneModifier( Qt3DCore::QEntity* rootEntity );

    ~SceneModifier() = default;

/******************************************************************************/

    void enableCuboid( bool enabled ) noexcept;

    void setCuboidRotationX( float _angle ) noexcept;

    void setCuboidRotationY( float _angle ) noexcept;

    float getCuboidRotationX() noexcept;

    float getCuboidRotationY() noexcept;

/******************************************************************************/

private:

/******************************************************************************/

    Qt3DCore::QEntity* m_cuboidEntity;

    Qt3DCore::QTransform* m_transformData;

/******************************************************************************/

}; // class SceneModifier

/******************************************************************************/

#endif // __SCENEMODIFIER_HPP__
