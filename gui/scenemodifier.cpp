#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity, QVector3D efc, QVector3D mfc)
    : timer(new QTimer), rootEntity(rootEntity)
{
    ePlane = new Plane(rootEntity, efc, 0x00ff00);
    mPlane = new Plane(rootEntity, mfc, 0x0000ff);
    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, &SceneModifier::timerAlarm);
    timer->start(10);
}

void SceneModifier::timerAlarm(){
    for (auto &sphere: spheres)
        sphere->update();
}

void SceneModifier::addSphere(Sphere *sphere) {
    spheres.push_back(sphere);
}

SceneModifier::~SceneModifier()
{
    delete rootEntity;
    delete ePlane;
    delete mPlane;
    for (auto &sphere: spheres)
        delete sphere;
}
