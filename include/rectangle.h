#pragma once

#include <figure.h>

class Rectangle : public Figure {
public:
    static constexpr size_t POINTS_COUNT = 4;
    
    Rectangle();
    ~Rectangle() override;
    Rectangle(Point, Point, Point, Point);
    long double Area() override;
    Point Center();
};