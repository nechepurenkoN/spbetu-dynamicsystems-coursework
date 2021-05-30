#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity, Particle* particle)
    : timer(new QTimer), rootEntity(rootEntity)
{
    sphere = new Sphere(rootEntity, particle);
    plane = new Plane(rootEntity, 1, 0, 0);
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
    delete plane;
}
