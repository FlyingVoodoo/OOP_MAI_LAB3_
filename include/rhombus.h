#pragma once

#include <figure.h>

class Rhombus : public Figure {
public:
    static constexpr size_t POINTS_COUNT = 4;
    
    Rhombus();
    ~Rhombus() override;
    Rhombus(Point, Point, Point, Point);
    long double Area() override;
    Point Center();
};