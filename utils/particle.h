#ifndef PARTICLE_H
#define PARTICLE_H

#include <cstdlib>

class Particle
{
    const double MAX_X = 6;
    const double MAX_Y = 6;
    const double MAX_Z = 6;
    double x;
    double y;
    double z;
    double speed_x;
    double speed_y;
    double speed_z;

public:
    Particle(double x, double y, double z, double speed_x, double speed_y, double speed_z);
    void update();
    double getX();
    double getY();
    double getZ();
};

#endif // PARTICLE_H
