#include <gtest/gtest.h>
#include <vector-points.h>
#include <vector-figure.h>
#include <point.h>
#include <rectangle.h>
#include <rhombus.h>
#include <trapezoid.h>

TEST(VectorPointsTest, DefaultConstructor) {
    VectorPoints vp;
    EXPECT_EQ(vp.len(), 0);
}

TEST(VectorPointsTest, AddAndGetPoints) {
    VectorPoints vp;
    Point p1(1, 2);
    Point p2(3, 4);
    vp.push(p1);
    vp.push(p2);
    EXPECT_EQ(vp.len(), 2);
    EXPECT_TRUE(vp.get(0) == p1);
    EXPECT_TRUE(vp.get(1) == p2);
}

TEST(VectorPointsTest, PopPoint) {
    VectorPoints vp;
    vp.push(Point(1, 2));
    vp.push(Point(3, 4));
    vp.pop();
    EXPECT_EQ(vp.len(), 1);
}

TEST(VectorPointsTest, SetAndGet) {
    VectorPoints vp;
    vp.push(Point(0, 0));
    vp.push(Point(0, 0));
    vp.set(0, Point(5, 5));
    vp.set(1, Point(7, 9));
    EXPECT_EQ(vp.get(0).x, 5);
    EXPECT_EQ(vp.get(0).y, 5);
    EXPECT_EQ(vp.get(1).x, 7);
    EXPECT_EQ(vp.get(1).y, 9);
}

TEST(VectorFigureTest, DefaultConstructor) {
    VectorFigure vf;
    EXPECT_EQ(vf.len(), 0);
}

TEST(VectorFigureTest, AddAndGetFigures) {
    VectorFigure vf;
    Rectangle* rect = new Rectangle(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Rhombus* rhomb = new Rhombus(Point(3, 0), Point(6, 2), Point(3, 4), Point(0, 2));
    
    vf.push(rect);
    vf.push(rhomb);
    
    EXPECT_EQ(vf.len(), 2);
    EXPECT_NEAR(static_cast<double>(vf.get(0)->Area()), 4.0, 1e-10);
    EXPECT_NEAR(static_cast<double>(vf.get(1)->Area()), 12.0, 1e-10);
}

TEST(VectorFigureTest, EraseFunction) {
    VectorFigure vf;
    vf.push(new Rectangle(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
    vf.push(new Rhombus(Point(3, 0), Point(6, 2), Point(3, 4), Point(0, 2)));
    vf.push(new Trapezoid(Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3)));
    
    EXPECT_EQ(vf.len(), 3);
    
    vf.erase(1); // Удаляем ромб
    EXPECT_EQ(vf.len(), 2);
    
    // Проверяем, что остались правильные фигуры
    EXPECT_NEAR(static_cast<double>(vf.get(0)->Area()), 4.0, 1e-10);   // Rectangle
    EXPECT_NEAR(static_cast<double>(vf.get(1)->Area()), 12.0, 1e-10);  // Trapezoid
}

TEST(VectorFigureTest, TotalAreaCalculation) {
    VectorFigure vf;
    vf.push(new Rectangle(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));  // S = 4
    vf.push(new Rhombus(Point(3, 0), Point(6, 2), Point(3, 4), Point(0, 2)));    // S = 12
    vf.push(new Trapezoid(Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3)));  // S = 12
    
    long double totalArea = 0;
    for (size_t i = 0; i < vf.len(); ++i) {
        totalArea += vf.get(i)->Area();
    }
    
    EXPECT_NEAR(static_cast<double>(totalArea), 28.0, 1e-10);
}