//
// Created by 79612 on 11.06.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_ENERGYEQUILIBRIUM_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_ENERGYEQUILIBRIUM_H

#include <vector>
#include <cmath>
#include "../utils/state.h"
#include "../utils/rhsfunction.h"
#include "../solvers/rk4.h"
#include "../solvers/ab3.h"
#include "../solvers/solver.h"
#include "../solvers/euler.h"
class energyequilibrium {
public:
    void run();
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_ENERGYEQUILIBRIUM_H
