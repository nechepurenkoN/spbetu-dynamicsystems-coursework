#ifndef PARTICLE_H
#define PARTICLE_H

#include <QObject>
#include <cstdlib>

class Particle: public QObject
{
    Q_OBJECT

    const double MAX_X = 6;
    const double MAX_Y = 6;
    const double MAX_Z = 6;
    double x;
    double y;
    double z;


public:
    Particle(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    void setX(double val);
    void setY(double val);
    void setZ(double val);
    ~Particle();

public slots:

};

#endif // PARTICLE_H
