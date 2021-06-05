#include "particle.h"

Particle::Particle(double x, double y, double z): x(x), y(y), z(z)
    {}


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

void Particle::setX(double val)
{
        x = val;
}

void Particle::setY(double val)
{
        y = val;
}

void Particle::setZ(double val)
{
        z = val;
}

Particle::~Particle()
{
}

