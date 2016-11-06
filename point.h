//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//point.h
// header file for the class Point.

#ifndef POINT_H
#define POINT_H

#include <QtGui>
#include <iostream>
#include "vector2D.h"

using std::ostream;

class Point:public Vector2D {
public:
  //Deafault constructor and destructor
  Point();
  ~Point();

  //Conversion constructor
  Point(double px, double py);

  double measureAngle (const Point&);

  void print() const;
  void draw(QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const;
  void drawTo(const Point& p, QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const;

  friend ostream& operator<<(ostream& os, const Point& p);
};

#endif
