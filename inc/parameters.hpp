#ifndef __PARAMETERS_HPP__
#define __PARAMETERS_HPP__

/******************************************************************************/

#include<QColor>

/******************************************************************************/

namespace ProjOpt {

/******************************************************************************/

constexpr const char * windowTitle = "3D Cube";

constexpr int windowWidth = 640;

constexpr int windowHeight = 480;

/******************************************************************************/

constexpr const char * defaultComName = "COM6";

constexpr const char * defaultComBaudRate = "115200";

/******************************************************************************/

constexpr float cuboidScale = 3.f;

const QColor cuboidColor = QRgb(0x7c43bd);

const QColor sceneAppearanceColor = 0xd7ccc8;

/******************************************************************************/

constexpr int packageSize = 2;

constexpr int coordEps = 2;

/******************************************************************************/

} // namespace projOpt

/******************************************************************************/

#endif // __PARAMETERS_HPP__
