#include <trapezoid.h>

Trapezoid::Trapezoid() {
    for (int i = 0; i < 4; ++i) {
        v.push(Point(0, 0));
    }
}
Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

long double Trapezoid::Area() {
    return CalcArea(v);
}

Point Trapezoid::Center() {
    return CalcCenter(v);
}

Trapezoid::~Trapezoid() {}
