#ifndef DISPLAYSURFACE_H
#define DISPLAYSURFACE_H

#include "plane.h"

#include <QObject>

class DisplaySurface: public Plane
{
    Q_OBJECT
public:
    DisplaySurface(Qt3DCore::QEntity* rootEntity, QVector3D normal, QVector3D translation, int color);
};

#endif // DISPLAYSURFACE_H
