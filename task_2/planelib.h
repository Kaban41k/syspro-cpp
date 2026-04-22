#ifndef PLANELIB
#define PLANELIB

#include <optional>

#define EPSILON 1e-8

class Point;
class Vector2D;
class Line;

class Point {
public:
  const double x, y;
  
  Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

  Point operator+(const Vector2D& other) const;
  bool operator==(const Point& other) const;
};

class Vector2D {
public:
  const double x, y;

  Vector2D(double x_coord, double y_coord) : x(x_coord), y(y_coord) {};
  Vector2D(Point p) : x(p.x), y(p.y) {};

  Vector2D operator*(double scalar) const;
  bool operator==(const Vector2D& other) const;
};

class Line {
private:
  Line(Point a, Vector2D v) : point(a), dir(v) {};
  Line(double ax, double b) : point(0, b), dir(ax, ax + b) {};
  Line(Point a, Point b) : point(a), dir(b.x - a.x, b.y - a.y) {};

public:
  const Point point;
  const Vector2D dir;
  
  static std::optional<Line> createLine(const Point& a, const Vector2D v) {
    if (std::abs(v.x) < EPSILON && std::abs(v.y) < EPSILON) {
      return std::nullopt;
    } else {
      return Line{a, v};
    }
  };

  static std::optional<Line> createLine(double ax, double b) {
    if (std::abs(ax) < EPSILON && std::abs(b) < EPSILON) {
      return std::nullopt;
    } else {
      return Line{ax, b};
    }
  };
  
  static std::optional<Line> createLine(const Point& a, const Point& b) {
    if (std::abs(a.x - b.x) < EPSILON && std::abs(a.y - b.y) < EPSILON) {
      return std::nullopt;
    } else {
      return Line{a, b};
    }
  };
};

bool eq(double a, double b);
bool peq(Point a, Point b);

std::optional<Point> intersection(Line l1, Line l2);
std::optional<Line> perp(Line l, Point p);

#endif
