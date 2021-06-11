//
// Created by 79612 on 11.06.2021.
//

#define ITERATIONS 10000

#include "energyequilibrium.h"

void dump_inv(std::vector<State> &s) {
    int it = 0;
    for (auto &p : s) {
        double absVelocity = p.velocity.absoluteValue();
        double kinetic = absVelocity * absVelocity / 2.;
        double potential = -p.coordinate.x * 1;
//        std::cout << kinetic << " " << potential << " " << kinetic + potential  << std::endl;
        std::cout << it << "\t" << std::abs((potential + kinetic) - 0.5) << "\n";
        ++it;
    }
}

void test_euler(RhsFunction *ptr, State initialState) {
    double step = 0.0001;
    std::vector<State> v;
    EulerSolver a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state);
        if (v.size() == ITERATIONS)
            dump_inv(v);
    }, step, ITERATIONS);
    a.solve(initialState);
}

void test_ab3(RhsFunction *ptr, State initialState) {
    double step = 0.001;
    std::vector<State> v;
    AB3 a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state);
        if (v.size() == ITERATIONS)
            dump_inv(v);
    }, step, ITERATIONS);
    a.solve(initialState);
}

void test_rk4(RhsFunction *ptr, State initialState) {
    double step = 0.01;
    std::vector<State> v;
    RK4Solver a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state);
        if (v.size() == ITERATIONS)
            dump_inv(v);
    }, step, ITERATIONS);
    a.solve(initialState);
}

void energyequilibrium::run() {
    State initialState(Point3D(0, 0, 0), Point3D(1, 0, 0), 1);
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(1, Point3D(1, 0, 0)));
    ptr->addMagneticField(new UniformField(2, Point3D(0, 1, 0)));

    //test_euler(ptr, initialState);
//    test_ab3(ptr, initialState);
    test_rk4(ptr, initialState);
}