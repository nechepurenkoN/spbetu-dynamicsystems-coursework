//
// Created by 79612 on 23.05.2021.
//

#include "state.h"

State::State(const Point3D &coordinate, const Point3D &velocity, double charge) : coordinate(coordinate),
                                                                                  velocity(velocity), charge(charge) {}

State operator*(double h, State state) {
    state.velocity = h * state.velocity;
    state.coordinate = h * state.coordinate;
    return state;
}

State operator+(const State &lhs, const State &rhs) {
    return State(lhs.coordinate + rhs.coordinate, lhs.velocity + rhs.velocity, lhs.charge);
}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << "State coordinate " << state.coordinate  << std::endl;
    os << "State velocity " << state.velocity << std::endl;
    return os;
}