#ifndef FAST_H
#define FAST_H

#include "point.h"
#include <iostream>
#include <vector>

using std::vector;

class Fast {
public:
  Fast();
  ~Fast();

  void addPoint(Point& p);
  void addPoint(int x, int y);

  vector<vector<Point>> getColinearPoints();

private:
  void sort();
  vector<Point> points;
};

#endif
