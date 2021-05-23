//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H


class Point3D {
public:
    double x;
    double y;
    double z;
    Point3D(double x, double y, double z);

    Point3D cross(const Point3D &);
};

Point3D operator*(double scalar, const Point3D &rhs);
double operator*(const Point3D &lhs, const Point3D &rhs);
Point3D operator+(const Point3D &lhs, const Point3D &rhs);

#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_POINT3D_H
