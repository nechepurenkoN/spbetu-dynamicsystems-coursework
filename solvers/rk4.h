//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H

#include "solver.h"

class RK4Solver : public AbstractSolver {
protected:
    State step(double time) override;

public:
    RK4Solver(const std::shared_ptr<RhsFunction> &rhsFunction, const std::function<void(State)> &onUpdateConsumer,
              double h, long long maxIterations);
};

class Ralston3Solver : public AbstractSolver {
protected:
    State step(double time) override;

public:
    Ralston3Solver(const std::shared_ptr<RhsFunction> &rhsFunction, const std::function<void(State)> &onUpdateConsumer,
              double h, long long maxIterations);

    ~Ralston3Solver();
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H
