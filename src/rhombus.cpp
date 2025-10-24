#include <rhombus.h>

Rhombus::Rhombus() {
    for (int i = 0; i < 4; ++i) {
        v.push(Point(0, 0));
    }
}

Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

long double Rhombus::Area() {
    return CalcArea(v);
}

Point Rhombus::Center() {
    return CalcCenter(v);
}

Rhombus::~Rhombus() {}