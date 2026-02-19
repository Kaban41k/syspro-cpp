#include <iostream>
#include "tests.h"
#include "planelib.h"

int n = 0;

void assert(bool x) {
  if (x) return;
  std::cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << std::endl;
}

void test0() {
  n = 0;

  Line l1 = Line(Point(0, 0), Point(0, 1));
  Line l2 = Line(Point(0, 0), Point(1, 0));
  
  Point p = intersection(l1, l2);

  assert(p == Point(0, 0));
}

void test1() {
  n = 1;

  Line l1 = Line(Point(0, 0), Point(1, 1));
  Line l2 = Line(Point(0.02f, 0), Point(0.02f, 2));
  
  Point p = intersection(l1, l2);

  assert(p == Point(0.02f, 0.02f));
}

void test2() {
  n = 2;

  Line l = Line(Point(0, 0), Vector2D(0, 1));
  Line lp = perp(l, Point(0, 42));

  Point p = intersection(l, lp);

  assert(p == Point(0, 42));
  assert(lp.dir == Vector2D(-1, 0));
  assert(lp.point == Point(0, 42));
}
