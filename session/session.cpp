//
// Created by 79612 on 23.05.2021.
//

#include "session.h"

void solverRunnable(Particle* particle) {
    auto ptr = std::shared_ptr<RhsFunction>(new EMFieldMovingFunction(
            Point3D(1, 0, 0),
            Point3D(0, 0, 1), 2, 3));
    auto s = std::shared_ptr<Solver>(new RK4Solver(
            ptr,
            [&particle](State state) -> void {
                std::cout << state << std::endl;
                particle->setX(state.coordinate.x);
                particle->setY(state.coordinate.y);
                particle->setZ(state.coordinate.z);
                std::this_thread::sleep_for(std::chrono::milliseconds(70));
            }, 0.01, 1000
    ));
    State state(Point3D(1,0,0), Point3D(1,1,1), 1);
    s->solve(state);
}

std::thread Session::start(Particle* particle) {
    std::thread solvingThread(solverRunnable, particle);
    return solvingThread;
}

