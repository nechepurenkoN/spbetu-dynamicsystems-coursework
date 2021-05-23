#ifndef PLANE_H
#define PLANE_H

#include <QEntity>
#include <QObject>
#include <QPhongMaterial>
#include <QPlaneMesh>
#include <QTransform>



class Plane: public QObject
{
    Q_OBJECT
public:
    Plane(Qt3DCore::QEntity* rootEntity, double x, double y, double z, double angle);
    ~Plane();
private:
    Qt3DExtras::QPlaneMesh* mesh;
    Qt3DCore::QTransform* transform;
    Qt3DExtras::QPhongMaterial* material;
    Qt3DCore::QEntity* entity;
};

#endif // PLANE_H
