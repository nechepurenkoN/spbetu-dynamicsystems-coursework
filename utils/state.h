//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_STATE_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_STATE_H


#include "point3d.h"
#include <iostream>

class State {
public:
    Point3D coordinate;
    Point3D velocity;
    double charge;

    State(const Point3D &coordinate, const Point3D &velocity, double charge);

};

State operator+(const State &lhs, const State &rhs);
State operator*(double h, State state);
std::ostream &operator<<(std::ostream &os, const State &state);


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_STATE_H
