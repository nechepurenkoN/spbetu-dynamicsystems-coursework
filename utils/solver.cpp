//
// Created by 79612 on 22.05.2021.
//

#include "solver.h"

State operator*(double h, State state) {
    return state;
}

EulerSolver::EulerSolver(std::function<State(State)> rhsFunction_,
                         std::function<void(State)> onUpdateConsumer_,
                         double h_, int maxIterations_)
        :
        onUpdateConsumer(std::move(onUpdateConsumer_)),
        rhsFunction(std::move(rhsFunction_)),
        h(h_),
        maxIterations(maxIterations_) {}

void EulerSolver::solve(State initialState) {
    State currentState = initialState;
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        onUpdateConsumer(currentState);
        previousStates.push(step());
    }
}

State EulerSolver::step() {
    State nextState = h * rhsFunction(previousStates.back());
    previousStates.pop();
    return nextState;
}