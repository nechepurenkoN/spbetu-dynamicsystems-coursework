#ifndef CANVAS_H
#define CANVAS_H

#include "scene.h"

#include <QGraphicsView>
#include <QTimer>
#include <cstdlib>

#include <utils/particle.h>

class Canvas: public QGraphicsView
{
    Q_OBJECT

    Scene *scene;
    QTimer* timer;
    Particle* particle;
    void init();
    void initBackground();
public:
    Canvas(Particle* part);
    ~Canvas();
protected slots:
    void slotAlarmTimer();
};

#endif // CANVAS_H
