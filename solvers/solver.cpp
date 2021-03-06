//
// Created by 79612 on 23.05.2021.
//

#include "solver.h"
AbstractSolver::AbstractSolver(std::shared_ptr<RhsFunction> rhsFunction_,
                               std::function<void(State)> onUpdateConsumer_,
                               double h_, long long maxIterations_)
        :
        rhsFunction(rhsFunction_),
        onUpdateConsumer(std::move(onUpdateConsumer_)),
        h(h_),
        maxIterations(maxIterations_) {}

void AbstractSolver::solve(State initialState) {
    previousStates.push_back(initialState);
    for (long long iteration = 0; iteration < maxIterations; iteration++) {
        onUpdateConsumer(previousStates.back());
        State nextState = step(iteration);
        previousStates.push_back(nextState);
        previousStates.pop_front();
    }
}