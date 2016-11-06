#ifndef BRUTE_H
#define BRUTE_H

#include <vector>
#include <iostream>
#include "point.h"

using std::vector;
using std::cout;
using std::endl;

class Brute {
public:
  //Deafault constructor
  Brute();
  ~Brute();

  void addPoint(const int x, const int y);
  void addPoint(const Point& p);
  void printColinearPoints();

private:
  void sort();
  bool check4Colinear(int, int , int, int);
  void printLine(int, int, int, int);
  vector<Point> points;
};

#endif
