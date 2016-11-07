#ifndef FAST_H
#define FAST_H

#include "point.h"
#include <iostream>
#include <vector>

using std::vector;

class PointWithOrigin: public Point {
public:
  PointWithOrigin();
  ~PointWithOrigin();

  PointWithOrigin(const Point& origin, const Point& p);

private:
  Point* p;
  Point* origin;
}

class Fast {
public:
  Fast();
  ~Fast();

  void addPoint(const Point& p);
  void addPoint(int x, int y);

  vector<vector<Point>> getColinearPoints();

private:
  void sort();
  vector<vector<Point>> getColinearPointsWithOrigin(const Point& origin);
  vector<Point> points;
};

#endif
