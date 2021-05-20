#include "particle.h"

Particle::Particle(int x, int y, int speed_x, int speed_y): x(x), y(y), speed_x(speed_x), speed_y(speed_y){}

void Particle::update()
{
    if (x > MAX_X){
        speed_x = -speed_x;
    }
    if (x <= 0){
        speed_x = -speed_x;
    }
    if (y > MAX_Y){
        speed_y = -speed_y;
    }
    if (y <= 0){
        speed_y = -speed_y;
    }
    x += speed_x;
    y += speed_y;
}

int Particle::getX()
{
    return x;
}

int Particle::getY()
{
    return y;
}
