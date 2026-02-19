#ifndef PLANELIB
#define PLANELIB

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
public:
  const Point point;
  const Vector2D dir;

  Line(double ax, double b) : point(0, b), dir(ax, ax + b) {};
  Line(Point a, Point b) : point(a), dir(b.x - a.x, b.y - a.y) {};
  Line(Point a, Vector2D v) : point(a), dir(v) {};
};

bool eq(double a, double b);
bool peq(Point a, Point b);

Point intersection(Line l1, Line l2);
Line perp(Line l, Point p);

#endif
