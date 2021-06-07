//
// Created by 79612 on 23.05.2021.
//

#include "session.h"

class MagneticGunManager {
    EMFieldMovingFunction *rhs;
    UniformField *firstField;
    UniformField *secondField;
    QLabel *lbl1;
    QLabel *lbl2;
    const double d1 = 0.2;
    const double d2 = 0.2;
    int iteration = 0;
    double secondFieldValue;
public:
    explicit MagneticGunManager(std::shared_ptr<RhsFunction> ptr, QLabel *lb1, QLabel *lb2) {
        rhs = dynamic_cast<EMFieldMovingFunction *>(ptr.get());
        firstField = rhs->getMagneticFields()[0];
        secondField = rhs->getMagneticFields()[1];
        this->lbl1 = lb1;
        this->lbl2 = lb2;
        secondFieldValue = secondField->value;
    }

    void next() {
        secondField->value += d1;
        iteration++;
        if (iteration >= 11){
            secondField->value = secondFieldValue;
            firstField->value += d2;
            iteration = 0;
        }
        lbl1->setText(QString::number(round(firstField->value * 100) / 100.));
        lbl2->setText(QString::number(round(secondField->value * 100) / 100.));
    }
};


void solverRunnable(std::vector<Particle*> particles, std::shared_ptr<RhsFunction> ptr, QLabel *lb1, QLabel *lb2) {
    MagneticGunManager manager(ptr, lb1, lb2);
    for (auto &particle : particles) {
        auto solver = std::shared_ptr<Solver>(new RK4Solver(
                ptr,
                [&particle](State state) -> void {
                    particle->setX(state.coordinate.x);
                    particle->setY(state.coordinate.y);
                    particle->setZ(state.coordinate.z);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }, 0.001, 100000
        ));
        State state(Point3D(particle->getX(), particle->getY(), particle->getZ()), Point3D(0, 0, 0), 1);
        try {
            solver->solve(state);
        } catch (int &e){}
        manager.next();
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

