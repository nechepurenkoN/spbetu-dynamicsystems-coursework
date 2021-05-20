#include "canvas.h"
#include <iostream>
Canvas::Canvas()
{
    setFixedSize(450, 450);
    scene = new QGraphicsScene;
    setScene(scene);
    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(1000);
}

void Canvas::slotAlarmTimer(){
    initBackground();
    scene->addEllipse(10, 10, 10, 10);
}

void Canvas::initBackground(){
    QPen pen(Qt::black, 3);
    QBrush brush(Qt::black, Qt::Dense5Pattern);
    scene->addRect(0, 0, 440, 440, pen, brush);
}

Canvas::~Canvas()
{
    delete scene;
    delete timer;
}
