//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <math.h>

#include <QLabel>
#include <QString>

#include "../utils/point3d.h"
#include "../utils/state.h"
#include "../utils/particle.h"
#include "../solvers/solver.h"
#include "../solvers/rk4.h"
#include "../solvers/euler.h"
#include "../solvers/ab3.h"

class Session {
    std::thread solverThread;
public:
    void start(std::vector<Particle*>&, std::shared_ptr<RhsFunction>, QLabel *lb1, QLabel *lb2);

    void stop();
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
