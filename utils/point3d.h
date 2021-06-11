//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H

#include <iostream>

class Point3D {
public:
    double x;
    double y;
    double z;

    Point3D(double x = 0., double y = 0., double z = 0.);

    Point3D cross(const Point3D &);

    double absoluteValue();

    Point3D normalize();
};

Point3D operator*(double scalar, const Point3D &rhs);

double operator*(const Point3D &lhs, const Point3D &rhs);

Point3D operator+(const Point3D &lhs, const Point3D &rhs);

std::ostream &operator<<(std::ostream &os, const Point3D &point);

bool operator==(const Point3D &lhs, const Point3D &rhs);


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H
