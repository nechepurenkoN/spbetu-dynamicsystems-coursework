//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H

#include "solver.h"

class RK4Solver : public AbstractSolver {
protected:
    State step() override;

public:
    RK4Solver(const std::shared_ptr<RhsFunction> &rhsFunction, const std::function<void(State)> &onUpdateConsumer,
              double h, int maxIterations);
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_RK4_H
