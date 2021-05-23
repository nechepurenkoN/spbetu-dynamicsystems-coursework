//
// Created by 79612 on 23.05.2021.
//

#include "rhsfunction.h"
State EMFieldMovingFunction::apply(State state) {
    state.velocity = state.charge * (electricFieldValue * electricFieldDirection +
                                     magneticFieldValue * state.velocity.cross(magneticFieldDirection));
    state.coordinate = state.coordinate + state.velocity;
    return state;
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