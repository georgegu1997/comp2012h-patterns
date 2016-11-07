#ifndef FAST_H
#define FAST_H

#include "point.h"
#include "helpers.h"
#include <iostream>
#include <vector>

using std::vector;

class PointWithOrigin: public Point {
public:
  PointWithOrigin();
  ~PointWithOrigin();

  PointWithOrigin(const Point& origin, const Point& p);

  bool operator==(const PointWithOrigin& p)const;

  Point getOrigin()const;
  Point getPoint()const;

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

  void printColinearPoints();
  vector<vector<Point>> getColinearPoints();

private:
  void sort();
  vector<vector<Point>> getColinearPointsWithOrigin(const Point& origin);
  vector<vector<Point>> returnToOriginalCoordinate(const vector<vector<PointWithOrigin>>&);
  void printInFormat(vector<vector<Point>>);
  vector<Point> points;
};

#endif
