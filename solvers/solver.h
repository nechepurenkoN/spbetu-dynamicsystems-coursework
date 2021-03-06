//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H

#include <memory>
#include <functional>
#include <deque>
#include "../utils/rhsfunction.h"

class Solver {
public:
    virtual void solve(State initialState) = 0;

    virtual ~Solver() {}
};

class AbstractSolver : public Solver {
protected:
    std::deque<State> previousStates;
    std::shared_ptr<RhsFunction> rhsFunction;
    std::function<void(State)> onUpdateConsumer;
    double h;
    long long maxIterations = 0;

    virtual State step(double time) = 0;

public:
    AbstractSolver(
            std::shared_ptr<RhsFunction> rhsFunction,
            std::function<void(State)> onUpdateConsumer_,
            double h_ = 0.01, long long maxIterations_ = 10000);


    void solve(State initialState) override;

    ~AbstractSolver() override = default;
};

#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
