//
// Created by 79612 on 06.06.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H

#include "solver.h"

class AB3 : public AbstractSolver {
private:
    Solver *oneStepSolver;
    double *coefficients;

    void prepareStates();

protected:
    State step() override;

public:
    AB3(const std::shared_ptr<RhsFunction> &rhsFunction, const std::function<void(State)> &onUpdateConsumer,
        double h, int maxIterations);

    ~AB3() noexcept;
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H
