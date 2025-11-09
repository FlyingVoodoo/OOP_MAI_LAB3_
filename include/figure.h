#pragma once

#include <iostream>

#include "vector-points.h"

class Figure {
public:
    virtual ~Figure();
    void ReadPoints(std::istream& is);
    void PrintPoints(std::ostream& os) const;
    virtual long double Area() = 0;
    friend bool operator==(const Figure&, const Figure&);
    friend bool operator!=(const Figure&, const Figure&);
protected:
    Figure();
    Figure(size_t pointsCount);
    VectorPoints points;
    static long double CalcArea(const VectorPoints&);
    static Point CalcCenter(const VectorPoints&);
    
};
std::istream& operator>>(std::istream&, Figure&);
std::ostream& operator<<(std::ostream&, const Figure&);