#pragma once

#include <figure.h>

class Trapezoid : public Figure {
public:
    static constexpr size_t POINTS_COUNT = 4;
    
    Trapezoid();
    ~Trapezoid() override;
    Trapezoid(Point, Point, Point, Point);
    long double Area() override;
    Point Center();
};
