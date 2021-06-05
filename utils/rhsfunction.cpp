//
// Created by 79612 on 23.05.2021.
//

#include "rhsfunction.h"

bool terminatePredicate(Point3D &coord) {
    return coord.y < -3.;
}

State EMFieldMovingFunction::apply(State state) {
    Point3D dVelocity = electricFieldValue * electricFieldDirection +
                        magneticFieldValue * state.velocity.cross(magneticFieldDirection);
    if (terminatePredicate(state.coordinate))
        throw 1;
    state.coordinate = state.velocity + dVelocity;
    State newState(state.coordinate, dVelocity, state.charge);
    return newState;
}


EMFieldMovingFunction::EMFieldMovingFunction(const Point3D &electricFieldDirection_,
                                             const Point3D &magneticFieldDirection_,
                                             double electricFieldValue_, double magneticFieldValue_)
        : electricFieldValue(electricFieldValue_),
          magneticFieldValue(magneticFieldValue_),
          electricFieldDirection(electricFieldDirection_),
          magneticFieldDirection(magneticFieldDirection_) {}

void EMFieldMovingFunction::setElectricFieldValue(double electricFieldValue) {
    this->electricFieldValue = electricFieldValue;
}

void EMFieldMovingFunction::setMagneticFieldValue(double magneticFieldValue) {
    this->magneticFieldValue = magneticFieldValue;
}

void EMFieldMovingFunction::setElectricFieldDirection(const Point3D &electricFieldDirection) {
    this->electricFieldDirection = electricFieldDirection;
}

void EMFieldMovingFunction::setMagneticFieldDirection(const Point3D &magneticFieldDirection) {
    this->magneticFieldDirection = magneticFieldDirection;
}