//
// Created by 79612 on 23.05.2021.
//

#include "rk4.h"
RK4Solver::RK4Solver(const std::shared_ptr<RhsFunction> &rhsFunction,
                     const std::function<void(State)> &onUpdateConsumer, double h, int maxIterations) : AbstractSolver(
        rhsFunction, onUpdateConsumer, h, maxIterations) {}

State RK4Solver::step() {
    State currentState = previousStates.back();
    State k1 = rhsFunction->apply(currentState);
    State k2 = rhsFunction->apply(currentState + h / 2. * k1);
    State k3 = rhsFunction->apply(currentState + h / 2. * k2);
    State k4 = rhsFunction->apply(currentState + h * k3);
    return currentState + h * (1/6. * k1 + 1/3. * k2 + 1/3 * k3 + 1/6. * k4);
}