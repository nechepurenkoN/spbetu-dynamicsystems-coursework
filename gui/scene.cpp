#include "scene.h"

void Scene::drawBG() {
    QPen pen(Qt::black, 3);
    QBrush brush(Qt::black, Qt::Dense7Pattern);
    addRect(0, 0, 440, 440, pen, brush);
}

void Scene::drawParticle(Particle* particle) {
    QPen pen(Qt::red, 3);
    QBrush brush(Qt::red, Qt::SolidPattern);
    addEllipse(particle->getX(), particle->getY(), 10, 10, pen, brush);
    particle->update();
}
