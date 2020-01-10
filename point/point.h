#ifndef POINT_H
#define POINT_H

#include<iostream>

class Point{
    double _x, _y, _z;
public:
    Point(double=0, double=0, double=0);
    double getX() const;
    double getY() const;
    double getZ() const;
    void negate();
    double norm() const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif