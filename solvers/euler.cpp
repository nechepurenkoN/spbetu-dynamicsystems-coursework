//
// Created by 79612 on 23.05.2021.
//

#include "euler.h"

EulerSolver::EulerSolver(std::shared_ptr<RhsFunction> rhsFunction, std::function<void(State)> onUpdateConsumer_,
                         double h_, long long maxIterations_) : AbstractSolver(rhsFunction, onUpdateConsumer_, h_,
                                                                         maxIterations_) {}

State EulerSolver::step() {
    State currentState = previousStates.back();
    State nextState = currentState + h * rhsFunction->apply(currentState);
    return nextState;
}