#include "planelib.h"

#define EPSILON 1e-8

Point Point::operator+(const Vector2D& other) const {
  return Point(x + other.x, y + other.y);
}

bool Point::operator==(const Point& other) const {
  return eq(x, other.x) && eq(y, other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
  return Vector2D(x * scalar, y * scalar);
}

bool Vector2D::operator==(const Vector2D& other) const {
  return eq(x, other.x) && eq(y, other.y);
}

bool eq(double a, double b) {return a - EPSILON < b && b < a + EPSILON;}
bool peq(Point a, Point b) {return eq(a.x, b.x) && eq(a.y, b.y);}

std::optional<Point> intersection(Line l1, Line l2) {
  double d = l1.dir.x * l2.dir.y - l1.dir.y * l2.dir.x;

  if (d == 0) {
    return std::nullopt;
  }

  double t = ((l2.point.x - l1.point.x) * l2.dir.y - 
              (l2.point.y - l1.point.y) * l2.dir.x) /
              d;

  return l1.point + l1.dir * t;
}

std::optional<Line> perp(Line l, Point p) {
  return Line::createLine(p, Vector2D(-l.dir.y, l.dir.x));
}
