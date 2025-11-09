#include <trapezoid.h>

Trapezoid::Trapezoid() : Figure(POINTS_COUNT) {
    for (size_t i = 0; i < POINTS_COUNT; ++i) {
        points.push(Point(0, 0));
    }
}

Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4) : Figure(POINTS_COUNT) {
    points.push(p1);
    points.push(p2);
    points.push(p3);
    points.push(p4);
}

long double Trapezoid::Area() {
    return CalcArea(points);
}

Point Trapezoid::Center() {
    return CalcCenter(points);
}

Trapezoid::~Trapezoid() {}
