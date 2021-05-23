//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_EULER_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_EULER_H
#include "solver.h"

class EulerSolver : public AbstractSolver {
protected:
    State step() override;
public:
    EulerSolver(
            std::shared_ptr<RhsFunction> rhsFunction,
            std::function<void(State)> onUpdateConsumer_,
            double h_ = 0.01, int maxIterations_ = 10000);
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_EULER_H
