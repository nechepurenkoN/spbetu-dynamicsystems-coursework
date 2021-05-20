#include "canvas.h"
#include <iostream>
Canvas::Canvas(Particle* part)
{
    particle = part;
    scene = new Scene();
    timer = new QTimer();
    init();
}

void Canvas::init()
{
    setFixedSize(450, 450);
    setScene(scene);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(10);
}

void Canvas::slotAlarmTimer(){
    scene->clear();
    scene->drawBG();
    scene->drawParticle(particle);
}


Canvas::~Canvas()
{
    delete scene;
    delete timer;
    delete particle;
}
