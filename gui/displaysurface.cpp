#include "displaysurface.h"

DisplaySurface::DisplaySurface(Qt3DCore::QEntity* rootEntity, QVector3D normal, QVector3D translation, int color):
    Plane(rootEntity, normal, color) {
    transform_front->setTranslation(translation);
    transform_back->setTranslation(translation);
    transform_front->setScale(5.0f);
    transform_back->setScale(5.0f);
}
