#include "plane.h"

Plane::Plane(Qt3DCore::QEntity* rootEntity, double x, double y, double z)
{
    mesh = new Qt3DExtras::QPlaneMesh();
    mesh->setWidth(2);
    mesh->setHeight(2);
    transform_front = new Qt3DCore::QTransform();
    transform_front->setScale(10.0f);
//    transform_front->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(x, y, z), angle));

    transform_front->setRotation(QQuaternion::rotationTo(QVector3D(0, 1, 0), QVector3D(x, y, z)));

    transform_back = new Qt3DCore::QTransform();
    transform_back->setScale(10.0f);
    transform_back->setRotation(QQuaternion::rotationTo(QVector3D(0, 1, 0) ,QVector3D(-x, -y, -z)));

    material = new Qt3DExtras::QPhongAlphaMaterial();
    material->setDiffuse(QColor(QRgb(0x0000ff)));
    material->setAlpha(0.5);
    entity_front = new Qt3DCore::QEntity(rootEntity);
    entity_front->addComponent(mesh);
    entity_front->addComponent(material);
    entity_front->addComponent(transform_front);
    entity_front->setEnabled(true);

    entity_back = new Qt3DCore::QEntity(rootEntity);
    entity_back->addComponent(mesh);
    entity_back->addComponent(material);
    entity_back->addComponent(transform_back);
    entity_back->setEnabled(true);
}

Plane::~Plane()
{
    delete mesh;
    delete transform_front;
    delete entity_front;
    delete entity_back;
    delete material;
}
