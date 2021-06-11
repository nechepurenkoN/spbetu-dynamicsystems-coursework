//
// Created by 79612 on 23.05.2021.
//

#include "rhsfunction.h"
#include "cmath"

bool EMFieldMovingFunction::terminatePredicate(Point3D &coord) {
    return coord.x * coord.x + coord.y * coord.y + coord.z * coord.z > 100;
}

void EMFieldMovingFunction::addDisplay(QVector3D trans, QVector3D normal)
{
    displayTranspose = Point3D(trans.x(), trans.y(), trans.z());
    displayNormal = Point3D(normal.x(), normal.y(), normal.z());
}

State EMFieldMovingFunction::apply(State state) {
    Point3D dVelocity(0,0,0);
    for (auto &electricField : electricFields) {
        dVelocity = dVelocity + electricField->value * electricField->direction;
    }

    Point3D magneticAccumulator(0,0,0);
    for (auto &magneticField : magneticFields) {
        magneticAccumulator = magneticAccumulator + (magneticField->value * magneticField->direction);
    }
    double magneticValue = std::sqrt(magneticAccumulator.x*magneticAccumulator.x + magneticAccumulator.y*magneticAccumulator.y + magneticAccumulator.z * magneticAccumulator.z);
    magneticAccumulator = (1/magneticValue) * magneticAccumulator;
    dVelocity = dVelocity + magneticValue * state.velocity.cross(magneticAccumulator);

    if (terminatePredicate(state.coordinate))
        throw 1;
    state.coordinate = state.velocity + dVelocity;
    State newState(state.coordinate, dVelocity, state.charge);
    return newState;
}


UniformField::UniformField(double value, const Point3D &direction)
        : value(value),
          direction(direction) {}

void EMFieldMovingFunction::addElectricField(UniformField *field) {
    electricFields.push_back(field);
}

std::vector<UniformField *> &EMFieldMovingFunction::getElectricFields() {
    return electricFields;
}

std::vector<UniformField *> &EMFieldMovingFunction::getMagneticFields() {
    return magneticFields;
}

void EMFieldMovingFunction::addMagneticField(UniformField *field) {
    magneticFields.push_back(field);
}

EMFieldMovingFunction::~EMFieldMovingFunction() noexcept {
    for (auto &e : electricFields) {
        delete e;
    }
    for (auto &m : magneticFields) {
        delete m;
    }
}
