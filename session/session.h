//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
#include <chrono>
#include <thread>
#include <iostream>

#include "../utils/solver.h"
#include "../utils/particle.h"

class Session {
public:
    std::thread start(Particle*);
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SESSION_H
