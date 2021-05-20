#ifndef PARTICLE_H
#define PARTICLE_H

#include <cstdlib>

class Particle
{
    const int MAX_X = 430;
    const int MAX_Y = 430;
    int x;
    int y;
    int speed_x;
    int speed_y;

public:
    Particle(int x, int y, int speed_x, int speed_y);
    void update();
    int getX();
    int getY();
};

#endif // PARTICLE_H
