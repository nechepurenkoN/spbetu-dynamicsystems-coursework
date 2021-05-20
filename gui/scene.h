#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

#include <utils/particle.h>



class Scene: public QGraphicsScene
{
public:
    void drawBG();
    void drawParticle(Particle* particle);
};

#endif // SCENE_H
