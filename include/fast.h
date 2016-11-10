//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//fast.h
//The header file for fast.
#ifndef FAST_H
#define FAST_H

#include "point.h"
#include "helpers.h"
#include <iostream>
#include <vector>

using std::vector;

//A helper class to handle change in corrdinates.
//It stores the information of the Point and origin.
//The base class Point is initialized use the x and y of point relative to the origin.
class PointWithOrigin: public Point {
public:
  //default constructor and destructor
  PointWithOrigin();
  ~PointWithOrigin();

  //conversion constructor
  PointWithOrigin(const Point& origin, const Point& p);

  //compare the slope here.
  bool operator==(const PointWithOrigin& p)const;

  //getter function.
  Point getOrigin()const;
  Point getPoint()const;

private:
  const Point* p;
  const Point* origin;
};

class Fast {
public:
  //default constructor and destructor
  Fast();
  ~Fast();

  //conversion constructor
  Fast(const vector<Point>);

  //add point(from Point instance and coordinates)
  void addPoint(const Point& p);
  void addPoint(int x, int y);

  //print out the lines.
  void printColinearPoints();

  //return the lines as vector of vector of Point.
  vector<vector<Point> > getColinearPoints();

private:
  //pre-sort the points.
  void sort();

  //change the corrdinate system to origin, compute and compare the slope there.
  vector<vector<Point> > getColinearPointsWithOrigin(const Point& origin);

  //go back to the origin coordinate.
  vector<vector<Point> > returnToOriginalCoordinate(vector<vector<PointWithOrigin> >&);

  //print the line.
  void printInFormat(vector<vector<Point> >);

  //the Points in vector.
  vector<Point> points;
};

#endif
