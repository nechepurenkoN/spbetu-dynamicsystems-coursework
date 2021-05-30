#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity, Particle* particle, QVector3D efc, QVector3D mfc)
    : timer(new QTimer), rootEntity(rootEntity)
{
    sphere = new Sphere(rootEntity, particle);
    ePlane = new Plane(rootEntity, efc, 0x00ff00);
    mPlane = new Plane(rootEntity, mfc, 0x0000ff);
    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, &SceneModifier::timerAlarm);
    timer->start(100);
}

void SceneModifier::timerAlarm(){
    sphere->update();
}

SceneModifier::~SceneModifier()
{
    delete rootEntity;
    delete sphere;
    delete ePlane;
    delete mPlane;
}
