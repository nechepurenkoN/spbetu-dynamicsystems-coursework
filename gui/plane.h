#ifndef PLANE_H
#define PLANE_H

#include <QEntity>
#include <QObject>
#include <QPhongAlphaMaterial>
#include <QPlaneMesh>
#include <Qt3DCore/qtransform.h>



class Plane: public QObject
{
    Q_OBJECT
public:
    Plane(Qt3DCore::QEntity* rootEntity, QVector3D coords, int color);
    Plane(Qt3DCore::QEntity* rootEntity, double x, double y, double z, int color);
    ~Plane();
protected:
    Qt3DExtras::QPlaneMesh* mesh;
    Qt3DCore::QTransform* transform_front;
    Qt3DCore::QTransform* transform_back;
    Qt3DExtras::QPhongAlphaMaterial* material;
    Qt3DCore::QEntity* entity_front;
    Qt3DCore::QEntity* entity_back;
};

#endif // PLANE_H
