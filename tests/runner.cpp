//
// Created by 79612 on 30.05.2021.
//

#include "runner.h"
#include <cassert>
#include "../utils/point3d.h"
#include "../utils/state.h"
#include <memory>
#include <cmath>
#include "../utils/rhsfunction.h"
#include "../session/session.h"

void test_point_addition() {
    Point3D zero(0, 0, 0);
    Point3D one(1, 1, 1);
    Point3D z(1.5, 2.5, -1.5);

    assert(("z + 0 should be equal to z", (zero + z) == z));
    assert(("1 + 0 should be equal to 1", (one + zero) == one));
    assert(("(1.5, 2.5, -1.5) + (1,1,1) should be equal to (2.5, 3.5, 1.5)", (z + one) == Point3D(2.5, 3.5, -0.5)));
}

void test_point_crossing() {
    Point3D zero(0, 0, 0);
    Point3D one(1, 1, 1);
    Point3D z(1.5, 2.5, -1.5);
    Point3D y(-0.666, 3.4343, 5.51);

    assert(("1 x 0 should be equal to 0", (one.cross(zero)) == zero));
    assert(("0 x 1 should be equal to 0", (zero.cross(one)) == zero));
    assert(("(1.5, 2.5, -1.5) x 1 should be equal to (4,-3,-1)", (z.cross(one)) == Point3D(4, -3, -1)));
    assert(("1 x (1.5, 2.5, -1.5) should be equal to (-4,3,1)", (one.cross(z)) == Point3D(-4, 3, 1)));
    assert(("1 x (1.5, 2.5, -1.5) should be equal to (-4,3,1)", (one.cross(z)) == Point3D(-4, 3, 1)));
    assert(("(1.5,2.5,-1.5) x (-0.666, 3.4343, 5.51) should be equal to (18.92645, -7.266, 6.81645)",
            (z.cross(y)) == Point3D(18.92645, -7.266, 6.81645)));
}

double calc_trajectory_dev(std::vector<Point3D> &lhs, std::vector<Point3D> &rhs) {
    int size = std::min(lhs.size(), rhs.size());
    double dev = 0.;
    for (int i = 0; i < size; i++) {
        dev += std::sqrt((lhs[i].x - rhs[i].x) * (lhs[i].x - rhs[i].x) + (lhs[i].y - rhs[i].y) * (lhs[i].y - rhs[i].y) +
                         (lhs[i].z - rhs[i].z) * (lhs[i].z - rhs[i].z));
    }
    return dev / size;
}

void calculate_magnetic_trajectory_deviation(std::vector<Point3D> &v) {
    bool is_neg = false;
    std::vector<int> trajectoryStartPoints;
    trajectoryStartPoints.push_back(0);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].x < 0 && v[i].z < 0)
            is_neg = true;
        if (is_neg && v[i].x > 0 && v[i].z > 0) {
            is_neg = false;
            trajectoryStartPoints.push_back(i);
        }
    }
    std::cout << "Size:" << trajectoryStartPoints.size() << std::endl;
    std::vector<Point3D> firstTrajectory = {v.begin(), v.begin() + trajectoryStartPoints[1]};
    std::vector<Point3D> secondTrajectory = {v.begin() + trajectoryStartPoints[1],
                                             v.begin() + trajectoryStartPoints[2]};
    std::vector<Point3D> lastTrajectory = {v.begin() + trajectoryStartPoints[trajectoryStartPoints.size() - 2],
                                           v.begin() + trajectoryStartPoints[trajectoryStartPoints.size() - 1]};
    std::cout << "Dev between first and second: " << calc_trajectory_dev(firstTrajectory, secondTrajectory)
              << std::endl;
    std::cout << "Dev between first and last: " << calc_trajectory_dev(firstTrajectory, lastTrajectory) << std::endl;
}

void test_magnetic_field_invariant() {
    State initialState(Point3D(0, 0, 0), Point3D(0.5, 0, 0), 1);
    long long maxIterations = 300000;
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(0, Point3D(1, 0, 0)));
    ptr->addMagneticField(new UniformField(0.5, Point3D(0, 1, 0)));
    std::vector<Point3D> v;
    AB3 a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            calculate_magnetic_trajectory_deviation(v);
    }, 0.001, maxIterations);
    std::cout << "Solving on " << maxIterations << " iterations" << std::endl;
    std::cout << "AB3 method" << std::endl;
    a.solve(initialState);
    v.clear();
    RK4Solver r(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            calculate_magnetic_trajectory_deviation(v);
    }, 0.001, maxIterations);
    std::cout << "RK4 method" << std::endl;
    r.solve(initialState);
    v.clear();
    EulerSolver e(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            calculate_magnetic_trajectory_deviation(v);
    }, 0.001, maxIterations);
    std::cout << "Euler's method" << std::endl;
    e.solve(initialState);
}

void Runner::run() {
    test_point_addition();
    test_point_crossing();
    //test_magnetic_field_invariant();
    std::cout << "All tests passed" << std::endl;
}



