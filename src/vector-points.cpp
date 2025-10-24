#include "vector-points.h"
#include <algorithm>

VectorPoints::VectorPoints() 
    : size(0), capacity(1), v(new Point[capacity]) {}

VectorPoints::VectorPoints(size_t n) 
    : size(n), capacity(2 * n), v(new Point[capacity]) {}

VectorPoints::VectorPoints(const VectorPoints& other)
    : size(other.size), capacity(other.capacity), v(new Point[capacity]) {
  std::copy(other.v, other.v + size, v);
}

VectorPoints::VectorPoints(VectorPoints&& other) noexcept
    : size(other.size), capacity(other.capacity), v(other.v) {
  other.clear();
}

VectorPoints::~VectorPoints() { delete[] v; }

void VectorPoints::resize(size_t newsize) {
  capacity = newsize;
  Point* t = new Point[capacity];
  std::copy(v, v + size, t);
  delete[] v;
  v = t;
}

void VectorPoints::push(Point c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void VectorPoints::pop() {
  if (size) {
    --size;
  }
}

void VectorPoints::set(size_t i, Point p) { v[i] = p; }

Point VectorPoints::get(size_t i) const { return v[i]; }

size_t VectorPoints::len() const { return size; }

void VectorPoints::clear() {
  size = 0;
  capacity = 1;
  delete[] v;
  v = new Point[capacity];
}