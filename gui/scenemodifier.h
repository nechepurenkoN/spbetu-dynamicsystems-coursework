#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>

#include <utils/particle.h>

#include <QTimer>

class SceneModifier : public QObject
{
    Q_OBJECT

public:
    explicit SceneModifier(Qt3DCore::QEntity *rootEntity, Particle* part);
    ~SceneModifier();

private slots:
    void timerAlarm();
private:
    QTimer *timer;
    Qt3DCore::QEntity *rootEntity;
    Qt3DCore::QEntity *sphereEntity;
    Qt3DCore::QTransform *sphereTransform;
    Qt3DExtras::QSphereMesh *sphereMesh;
    Qt3DExtras::QPhongMaterial *sphereMaterial;
    Particle *particle;

};

#endif // SCENEMODIFIER_H

