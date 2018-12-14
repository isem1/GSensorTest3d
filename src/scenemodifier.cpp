#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>

#include <memory>

#include "scenemodifier.hpp"
#include "parameters.hpp"

/******************************************************************************/

SceneModifier::SceneModifier( Qt3DCore::QEntity* rootEntity )
{
    // Cuboid shape data
    Qt3DExtras::QCuboidMesh* cuboid = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    m_transformData = new Qt3DCore::QTransform();
    m_transformData->setScale( ProjOpt::cuboidScale );
    m_transformData->setTranslation( QVector3D( 5.0f, -4.0f, 0.0f ) );

    // Cuboid material init
    Qt3DExtras::QPhongMaterial *cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    cuboidMaterial->setDiffuse( QColor( QRgb( ProjOpt::cuboidColor ) ) );;

    // Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity( rootEntity );
    m_cuboidEntity->addComponent( cuboid );
    m_cuboidEntity->addComponent( cuboidMaterial );
    m_cuboidEntity->addComponent( m_transformData );
}

/******************************************************************************/

void
SceneModifier::enableCuboid( bool enabled ) noexcept
{
    m_cuboidEntity->setEnabled( enabled );
}

/******************************************************************************/

void
SceneModifier::setCuboidRotationX( float _angle ) noexcept
{
    m_transformData->setRotationX( _angle );
}

/******************************************************************************/

void
SceneModifier::setCuboidRotationY( float _angle ) noexcept
{
    m_transformData->setRotationZ( _angle );
}

/******************************************************************************/

float
SceneModifier::getCuboidRotationX() noexcept
{
    return m_transformData->rotationX();
}

/******************************************************************************/

float
SceneModifier::getCuboidRotationY() noexcept
{
    return m_transformData->rotationZ();
}

/******************************************************************************/
