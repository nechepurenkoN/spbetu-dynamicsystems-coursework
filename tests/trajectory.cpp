#include "trajectory.h"


void dump_trajectory(std::vector<Point3D> &v, double step, std::string fname) {
    std::ofstream fout;
    fout.open("logs/" + fname);
    for (int i = 0; i < v.size(); ++i) {
        double cx = -std::sin(step * i) + step * i, cy = -std::cos(step * i) + 1;
        fout << v[i].z << "\t" <<
                v[i].x << "\t" <<
                cx << "\t" <<
                cy << "\t" <<
                i * step << "\t" <<
                std::sqrt(std::pow(v[i].z - cx, 2) + std::pow(v[i].x - cy, 2)) << "\t" << "\n";
//        std::cout << v[i].z << "\t" << v[i].x << "\t" << cx << "\t" << cy << "\n";
    }
    fout.close();
}

void test_RK4(int maxIterations, double step){
    State initialState(Point3D(0, 0, 0), Point3D(0, 0, 0), 1);
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(1, Point3D(1, 0, 0)));
    ptr->addMagneticField(new UniformField(1, Point3D(0, 1, 0)));
    std::vector<Point3D> v;
    RK4Solver a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            dump_trajectory(v, step, "rk4_" + std::to_string(step) + "_" + std::to_string(maxIterations) + ".txt");
    }, step, maxIterations);
    a.solve(initialState);
}

void test_AB3(int maxIterations, double step){
    State initialState(Point3D(0, 0, 0), Point3D(0, 0, 0), 1);
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(1, Point3D(1, 0, 0)));
    ptr->addMagneticField(new UniformField(1, Point3D(0, 1, 0)));
    std::vector<Point3D> v;
    AB3 a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            dump_trajectory(v, step, "ab3_" + std::to_string(step) + "_" + std::to_string(maxIterations) + ".txt");
    }, step, maxIterations);
    a.solve(initialState);
}

void test_Euler(int maxIterations, double step){
    State initialState(Point3D(0, 0, 0), Point3D(0, 0, 0), 1);
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(1, Point3D(1, 0, 0)));
    ptr->addMagneticField(new UniformField(1, Point3D(0, 1, 0)));
    std::vector<Point3D> v;
    EulerSolver a(std::shared_ptr<RhsFunction>(ptr), [&](State state) -> void {
        v.push_back(state.coordinate);
        if (v.size() == maxIterations)
            dump_trajectory(v, step, "euler_" + std::to_string(step) + "_" + std::to_string(maxIterations) + ".txt");
    }, step, maxIterations);
    a.solve(initialState);
}


void Trajectory::run()
{
    test_Euler(300, 0.1);
    test_Euler(3000, 0.01);
    test_Euler(30000, 0.001);
    test_AB3(300, 0.1);
    test_AB3(3000, 0.01);
    test_AB3(30000, 0.001);
    test_RK4(300, 0.1);
    test_RK4(3000, 0.01);
    test_RK4(30000, 0.001);
}
