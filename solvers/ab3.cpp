//
// Created by 79612 on 06.06.2021.
//

#include "ab3.h"
#include "rk4.h"

AB3::AB3(const std::shared_ptr<RhsFunction> &rhsFunction,
         const std::function<void(State)> &onUpdateConsumer, double h, long long maxIterations) : AbstractSolver(
        rhsFunction, onUpdateConsumer, h, maxIterations) {
    coefficients = new double[3]{5 / 12., -4 / 3., 23 / 12.};
}

State AB3::step(double time) {
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
    std::deque<State> oneStepStates;
    Solver *oneStepSolver = new Ralston3Solver(rhsFunction, [&oneStepStates](State state) -> void {
        oneStepStates.push_back(state);
    }, h, 3);
    State currentState = previousStates.back();
    oneStepSolver->solve(currentState);
    oneStepStates.pop_front();
    for (auto &s : oneStepStates) {
        onUpdateConsumer(s);
        previousStates.push_back(s);
    }
    delete oneStepSolver;
}

AB3::~AB3() noexcept {
    delete coefficients;
}
