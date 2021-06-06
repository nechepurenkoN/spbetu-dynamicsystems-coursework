#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity, QVector3D efc, std::vector<QVector3D> mfc)
    : timer(new QTimer), rootEntity(rootEntity)
{
    ePlane = new Plane(rootEntity, efc, 0x00ff00);
    for (auto field: mfc){
        mPlanes.push_back(new Plane(rootEntity, field, 0x0000ff));
    }
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
    for (auto plane: mPlanes)
        delete plane;
    for (auto &sphere: spheres)
        delete sphere;
}
