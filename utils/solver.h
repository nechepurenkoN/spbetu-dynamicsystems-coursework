//
// Created by 79612 on 22.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H

#include <functional>
#include <queue>
#include <utility>


class State {

public:

};

class Solver {
public:
    virtual void solve(State initialState) = 0;
};

class EulerSolver : public Solver {
    std::queue<State> previousStates;
    std::function<void(State)> onUpdateConsumer;
    std::function<State(State)> rhsFunction;
    double h;
    int maxIterations = 0;
protected:
    State step();

//    EulerSolver(const EulerSolver &es) {
//        if (&es != this) {
//            previousStates = es.previousStates;
//            onUpdateConsumer = es.onUpdateConsumer;
//            rhsFunction = es.rhsFunction;
//            h = es.h;
//            maxIterations = es.maxIterations;
//        }
//    }

public:
    EulerSolver(
            std::function<State(State)> rhsFunction_,
            std::function<void(State)> onUpdateConsumer_,
            double h_ = 0.01, int maxIterations_ = 10000);


    void solve(State initialState) override;
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
