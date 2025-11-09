#include <figure.h>

Figure::Figure() {}

Figure::Figure(size_t pointsCount) : points(pointsCount) {}

long double Figure::CalcArea(const VectorPoints& t) {
    long double res{0.0};
    for (size_t i = 0; i + 1 < t.len(); ++i) {
        res += (long long)t.get(i).x * (long long)t.get(i + 1).y;
        res -= (long long)t.get(i + 1).x * (long long)t.get(i).y;
    }
    res += (long long)t.get(t.len() - 1).x * (long long)t.get(0).y;
    res -= (long long)t.get(0).x * (long long)t.get(t.len() - 1).y;
    return std::abs(res / 2.0L);
}

long double Figure::Area() { return CalcArea(points); }

Point Figure::CalcCenter(const VectorPoints& t) {
    int x = 0, y = 0;
    for (size_t i = 0; i < t.len(); ++i) {
        x += t.get(i).x;
        y += t.get(i).y;
    }
    return Point(x / t.len(), y / t.len());
}

void Figure::ReadPoints(std::istream& is) {
    for (size_t i = 0; i < points.len(); ++i) {
        is >> points[i];
    }
}

void Figure::PrintPoints(std::ostream& os) const {
    for (size_t i = 0; i < points.len(); ++i) {
        os << points[i];
    }
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.ReadPoints(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.PrintPoints(os);
    return os;
}

bool operator==(const Figure& a, const Figure& b) {
  if (a.points.len() != b.points.len()) {
    return false;
  }
  for (size_t i = 0; i < a.points.len(); ++i) {
    if (a.points.get(i) != b.points.get(i)) {
      return false;
    }
  }
  return true;
}

bool operator!=(const Figure& a, const Figure& b) { return !(a == b); }

Figure::~Figure() {}