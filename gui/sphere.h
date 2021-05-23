#ifndef SPHERE_H
#define SPHERE_H

#include <QEntity>
#include <QObject>
#include <QPhongMaterial>
#include <QSphereMesh>
#include <QTransform>

#include "utils/particle.h"



class Sphere : public QObject
{
    Q_OBJECT
public:
    Sphere(Qt3DCore::QEntity* rootEntity, Particle *particle);
    ~Sphere();
    void update();

private:
    Particle* particle;
    Qt3DExtras::QSphereMesh* mesh;
    Qt3DCore::QTransform* transform;
    Qt3DExtras::QPhongMaterial* material;
    Qt3DCore::QEntity* entity;
};

#endif // SPHERE_H
