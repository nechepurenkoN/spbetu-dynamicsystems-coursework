#include "particle.h"

Particle::Particle(double x, double y, double z, double speed_x, double speed_y, double speed_z): x(x), y(y), z(z),
    speed_x(speed_x), speed_y(speed_y), speed_z(speed_z){}

void Particle::update()
{
    if (x > MAX_X){
        speed_x = -speed_x;
    }
    if (x < -MAX_X){
        speed_x = -speed_x;
    }
    if (y > MAX_Y){
        speed_y = -speed_y;
    }
    if (y < -MAX_Y){
        speed_y = -speed_y;
    }
    if (z > MAX_Z){
        speed_z = -speed_z;
    }
    if (z < -MAX_Z){
        speed_z = -speed_z;
    }
    x += speed_x;
    y += speed_y;
    z += speed_z;
}

double Particle::getX()
{
    return x;
}

double Particle::getY()
{
    return y;
}

double Particle::getZ()
{
    return z;
}

Particle::~Particle()
{
}

int sign(double val){
    return (val > 0) ? 1: -1;
}

void Particle::setXSpeed(int value)
{
    speed_x = value / 100.0 * sign(speed_x);
}

void Particle::setYSpeed(int value)
{
    speed_y = value / 100.0 * sign(speed_y);
}

void Particle::setZSpeed(int value)
{
    speed_z = value / 100.0 * sign(speed_z);
}
