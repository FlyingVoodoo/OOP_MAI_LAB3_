#pragma once

#include <figure.h>

class Trapezoid : public Figure {
public:
    Trapezoid();
    ~Trapezoid() override;
    Trapezoid(Point, Point, Point, Point);
    long double Area() override;
    Point Center();
};
