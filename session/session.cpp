//
// Created by 79612 on 23.05.2021.
//

#include "session.h"

void solverRunnable(std::vector<Particle*> particles, std::shared_ptr<RhsFunction> ptr) {
    for (auto &particle : particles) {
        EMFieldMovingFunction *rhs = dynamic_cast<EMFieldMovingFunction *>(ptr.get());
        auto s = std::shared_ptr<Solver>(new RK4Solver(
                ptr,
                [&particle](State state) -> void {
                    particle->setX(state.coordinate.x);
                    particle->setY(state.coordinate.y);
                    particle->setZ(state.coordinate.z);
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }, 0.01, 10000
        ));
        State state(Point3D(particle->getX(), particle->getY(), particle->getZ()), Point3D(0, 0, 0), 1);
        try {
            s->solve(state);
        } catch (int &e){}
    }

}

void Session::start(std::vector<Particle*> &particles, std::shared_ptr<RhsFunction> ptr) {
    solverThread = std::thread(solverRunnable, particles, ptr);
}

void Session::stop() {
    if (solverThread.native_handle())
        pthread_cancel(solverThread.native_handle());
    solverThread.join();
}

