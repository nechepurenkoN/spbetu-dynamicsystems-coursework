//
// Created by 79612 on 06.06.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H

#include "solver.h"

class AB3 : public AbstractSolver {
private:
    double *coefficients;

    void prepareStates();

protected:
    State step(double time) override;

public:
    AB3(const std::shared_ptr<RhsFunction> &rhsFunction, const std::function<void(State)> &onUpdateConsumer,
        double h, long long maxIterations);

    ~AB3() noexcept override;
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_AB3_H
