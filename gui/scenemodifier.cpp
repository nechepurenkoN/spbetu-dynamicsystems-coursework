#include "scenemodifier.h"

#include <QtCore/QDebug>

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity, Particle* part)
    : timer(new QTimer), rootEntity(rootEntity), particle(part)
{
    // Sphere shape data
    sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(10);
    sphereMesh->setSlices(10);
    sphereMesh->setRadius(2);

    // Sphere mesh transform
    sphereTransform = new Qt3DCore::QTransform();

    sphereTransform->setScale(0.2f);
    sphereTransform->setTranslation(QVector3D(particle->getX(), particle->getY(), particle->getZ()));

    sphereMaterial = new Qt3DExtras::QPhongMaterial();
    sphereMaterial->setDiffuse(QColor(QRgb(0xff0000)));

    // Sphere
    sphereEntity = new Qt3DCore::QEntity(rootEntity);
    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(sphereMaterial);
    sphereEntity->addComponent(sphereTransform);

    sphereEntity->setEnabled(true);

    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, &SceneModifier::timerAlarm);
    timer->start(100);

}

SceneModifier::~SceneModifier()
{
    delete rootEntity;
    delete sphereEntity;
    delete sphereMesh;
    delete sphereMaterial;
    delete sphereTransform;
    delete particle;
}

void SceneModifier::timerAlarm()
{
    particle->update();
    sphereTransform->setTranslation(QVector3D(particle->getX(), particle->getY(), particle->getZ()));
}
