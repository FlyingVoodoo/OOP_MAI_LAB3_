# pragma once

#include <figure.h>

class Rhombus : public Figure {
public:
    Rhombus();
    ~Rhombus() override;
    Rhombus(Point, Point, Point, Point);
    long double Area() override;
    Point Center();
};