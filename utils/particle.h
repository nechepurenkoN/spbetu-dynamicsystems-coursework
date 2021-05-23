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
    double speed_x;
    double speed_y;
    double speed_z;

public:
    Particle(double x, double y, double z, double speed_x, double speed_y, double speed_z);
    void update();
    double getX();
    double getY();
    double getZ();
    void setX(double val);
    void setY(double val);
    void setZ(double val);
    ~Particle();

public slots:
    void setXSpeed(int value);
    void setYSpeed(int value);
    void setZSpeed(int value);
};

#endif // PARTICLE_H
