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

  //return the angle between two points.
  double measureAngle (const Point&);

  //format cout.
  void print() const;

  //draw this points. Need QPainter input.
  void draw(QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const;

  //draw line from this Point to another.
  void drawTo(const Point& p, QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const;

  //format output used in ostream.
  friend ostream& operator<<(ostream& os, const Point& p);
};

#endif
