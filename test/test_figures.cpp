#include <gtest/gtest.h>
#include <point.h>
#include <rectangle.h>
#include <rhombus.h>
#include <trapezoid.h>

// Тест для Rectangle: прямоугольник 4x3 должен иметь площадь 12
TEST(RectangleTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);
    Rectangle rect(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(rect.Area()), 12.0, 1e-10);
}

// Тест для Rectangle: квадрат 2x2 должен иметь площадь 4
TEST(RectangleTest, SquareArea) {
    Point p1(1, 1);
    Point p2(3, 1);
    Point p3(3, 3);
    Point p4(1, 3);
    Rectangle rect(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(rect.Area()), 4.0, 1e-10);
}

// Тест для Rectangle: центр прямоугольника
TEST(RectangleTest, CenterCalculation) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 2);
    Point p4(0, 2);
    Rectangle rect(p1, p2, p3, p4);
    Point center = rect.Center();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 1);
}

// Тест для Rhombus: ромб с диагоналями 6 и 4 имеет площадь 12
TEST(RhombusTest, AreaCalculation) {
    Point p1(3, 0);
    Point p2(6, 2);
    Point p3(3, 4);
    Point p4(0, 2);
    Rhombus rhomb(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(rhomb.Area()), 12.0, 1e-10);
}

// Тест для Rhombus: центр ромба
TEST(RhombusTest, CenterCalculation) {
    Point p1(3, 0);
    Point p2(6, 2);
    Point p3(3, 4);
    Point p4(0, 2);
    Rhombus rhomb(p1, p2, p3, p4);
    Point center = rhomb.Center();
    EXPECT_EQ(center.x, 3);
    EXPECT_EQ(center.y, 2);
}

// Тест для Trapezoid: трапеция с основаниями 5 и 3, высотой 3 имеет площадь 12
TEST(TrapezoidTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(5, 0);
    Point p3(4, 3);
    Point p4(1, 3);
    Trapezoid trap(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(trap.Area()), 12.0, 1e-10);
}

// Тест для Trapezoid: простая трапеция
TEST(TrapezoidTest, SimpleArea) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(3, 2);
    Point p4(1, 2);
    Trapezoid trap(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(trap.Area()), 6.0, 1e-10);
}

// Тест сравнения фигур
TEST(FigureTest, EqualityOperator) {
    Rectangle rect1(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Rectangle rect2(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Rectangle rect3(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3));
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
    EXPECT_TRUE(rect1 != rect3);
}