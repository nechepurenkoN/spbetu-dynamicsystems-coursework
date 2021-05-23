//
// Created by 79612 on 22.05.2021.
//

#include "solver.h"
#include <iostream>

State operator*(double h, State state) {
    state.velocity = h * state.velocity;
    state.coordinate = h * state.coordinate;
    return state;
}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << "State coordinate [" << state.coordinate.x << " " << state.coordinate.y << " " << state.coordinate.z << "]" << std::endl;
    return os;
}


EulerSolver::EulerSolver(std::shared_ptr<RhsFunction> rhsFunction_,
                         std::function<void(State)> onUpdateConsumer_,
                         double h_, int maxIterations_)
        :
        rhsFunction(rhsFunction_),
        onUpdateConsumer(std::move(onUpdateConsumer_)),
        h(h_),
        maxIterations(maxIterations_) {}

void EulerSolver::solve(State initialState) {
    previousStates.push(initialState);
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        onUpdateConsumer(previousStates.back());
        previousStates.push(step());
    }
}

State EulerSolver::step() {
    State nextState = h * rhsFunction->apply(previousStates.back());
    previousStates.pop();
    return nextState;
}

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

State::State(const Point3D &coordinate, const Point3D &velocity, double charge) : coordinate(coordinate),
                                                                                  velocity(velocity), charge(charge) {}
