#include "displaysurface.h"

DisplaySurface::DisplaySurface(Qt3DCore::QEntity* rootEntity, QVector3D normale, QVector3D translation, int color): Plane(rootEntity, normale, color) {
    transform_front->setTranslation(translation);
    transform_back->setTranslation(translation);
}
