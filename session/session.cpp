//
// Created by 79612 on 23.05.2021.
//

#include "session.h"

void solverRunnable(Particle *particle, std::shared_ptr<RhsFunction> ptr) {
    auto s = std::shared_ptr<Solver>(new EulerSolver(
            ptr,
            [&particle](State state) -> void {
                particle->setX(state.coordinate.x);
                particle->setY(state.coordinate.y);
                particle->setZ(state.coordinate.z);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }, 0.01, 10000
    ));
    State state(Point3D(particle->getX(), particle->getY(), particle->getZ()), Point3D(0, 0, 0), 1);
    s->solve(state);
}

void Session::start(Particle *particle, std::shared_ptr<RhsFunction> ptr) {
    solverThread = std::thread(solverRunnable, particle, ptr);
}

void Session::stop() {
    if (solverThread.native_handle())
        pthread_cancel(solverThread.native_handle());
    solverThread.join();
}

