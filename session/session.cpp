//
// Created by 79612 on 23.05.2021.
//

#include "session.h"

void solverRunnable(std::vector<Particle*> particles, std::shared_ptr<RhsFunction> ptr, QLabel *lb1, QLabel *lb2) {
    double d1 = 0.2;
    double d2 = 0.2;
    EMFieldMovingFunction *rhs = dynamic_cast<EMFieldMovingFunction *>(ptr.get());
    double mFieldValue1 = rhs->getMagneticFields()[1]->value;
    int i = 0;
    for (auto &particle : particles) {
        auto s = std::shared_ptr<Solver>(new AB3(
                ptr,
                [&particle](State state) -> void {
                    particle->setX(state.coordinate.x);
                    particle->setY(state.coordinate.y);
                    particle->setZ(state.coordinate.z);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }, 0.001, 10000
        ));
        State state(Point3D(particle->getX(), particle->getY(), particle->getZ()), Point3D(0, 0, 0), 1);
        try {
            s->solve(state);
        } catch (int &e){}
        rhs->getMagneticFields()[1]->value += d1;
        i++;
        if (i >= 11){
            rhs->getMagneticFields()[1]->value = mFieldValue1;
            rhs->getMagneticFields()[0]->value += d2;
            i = 0;
        }
        lb1->setText(QString::number(round(rhs->getMagneticFields()[0]->value * 100) / 100.));
        lb2->setText(QString::number(round(rhs->getMagneticFields()[1]->value * 100) / 100.));
    }

}

void Session::start(std::vector<Particle*> &particles, std::shared_ptr<RhsFunction> ptr, QLabel *lb1, QLabel *lb2) {
    solverThread = std::thread(solverRunnable, particles, ptr, lb1, lb2);
}

void Session::stop() {
    if (solverThread.native_handle())
        pthread_cancel(solverThread.native_handle());
    solverThread.join();
}

