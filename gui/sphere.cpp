#include "sphere.h"

Sphere::Sphere(Qt3DCore::QEntity* rootEntity, Particle *particle): particle(particle)
{
    mesh = new Qt3DExtras::QSphereMesh();
    mesh->setRings(10);
    mesh->setSlices(10);
    mesh->setRadius(2);
    transform = new Qt3DCore::QTransform();
    transform->setScale(0.2f);
    transform->setTranslation(QVector3D(particle->getX(), particle->getY(), particle->getZ()));
    material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(QRgb(0xff0000)));
    entity = new Qt3DCore::QEntity(rootEntity);
    entity->addComponent(mesh);
    entity->addComponent(material);
    entity->addComponent(transform);
    entity->setEnabled(true);
}

void Sphere::update()
{
    transform->setTranslation(QVector3D(particle->getX(), particle->getY(), particle->getZ()));
}

Sphere::~Sphere()
{
    delete particle;
    delete mesh;
    delete transform;
    delete entity;
    delete material;
}
