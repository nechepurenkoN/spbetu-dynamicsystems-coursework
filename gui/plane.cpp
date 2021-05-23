#include "plane.h"

Plane::Plane(Qt3DCore::QEntity* rootEntity, double x, double y, double z, double angle)
{
    mesh = new Qt3DExtras::QPlaneMesh();
    mesh->setWidth(2);
    mesh->setHeight(2);
    transform = new Qt3DCore::QTransform();
    transform->setScale(10.0f);
    transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(x, y, z),angle));
//    transform->setTranslation(QVector3D(x, y, z));
    material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(QRgb(0x0000ff)));
    entity = new Qt3DCore::QEntity(rootEntity);
    entity->addComponent(mesh);
    entity->addComponent(material);
    entity->addComponent(transform);
    entity->setEnabled(true);
}

Plane::~Plane()
{
    delete mesh;
    delete transform;
    delete entity;
    delete material;
}
