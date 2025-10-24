#include <rectangle.h>

Rectangle::Rectangle() {
    for (int i = 0; i < 4; ++i) {
        v.push(Point(0, 0));
    }
}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

long double Rectangle::Area() {
    return CalcArea(v);
}

Point Rectangle::Center() {
    return CalcCenter(v);
}

Rectangle::~Rectangle() {}