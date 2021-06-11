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


void Runner::run() {
    test_point_addition();
    test_point_crossing();
}



