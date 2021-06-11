//
// Created by 79612 on 06.06.2021.
//

#include "ab3.h"
#include "rk4.h"

AB3::AB3(const std::shared_ptr<RhsFunction> &rhsFunction,
         const std::function<void(State)> &onUpdateConsumer, double h, long long maxIterations) : AbstractSolver(
        rhsFunction, onUpdateConsumer, h, maxIterations) {
    oneStepSolver = new Ralston3Solver(rhsFunction, [this](State state) -> void {
        this->previousStates.push_back(state);
    }, h, 2);
    coefficients = new double[3]{5 / 12., -4 / 3., 23 / 12.};
}

State AB3::step() {
    if (previousStates.size() < 3) {
        prepareStates();
    }

    State currentState = previousStates.back();
    int idx = 0;
    for (auto &state : previousStates) {
        currentState = currentState + h * coefficients[idx] * rhsFunction->apply(state);
        idx++;
    }

    return currentState;
}

void AB3::prepareStates() {
    State currentState = previousStates.back();
    oneStepSolver->solve(currentState);
}

AB3::~AB3() noexcept {
    delete oneStepSolver;
    delete coefficients;
}
