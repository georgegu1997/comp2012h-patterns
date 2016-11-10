//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//brute.h
//the header file for brute.
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
  //Deafault constructor and destructor
  Brute();
  ~Brute();

  //conversion constructor
  Brute(const vector<Point>);

  //add a point from its corrdinates
  void addPoint(const int x, const int y);

  //add a point from a Point class.
  void addPoint(const Point& p);

  //compute the colinear points and return in lines vector<vector<Point> >
  vector<vector<Point> > getColinearPoints();

  //print the result out.
  void printColinearPoints();

private:
  //print a line using "->"
  void printInFormat(vector<vector<Point> > ps);
  void printLine(int, int, int, int);

  //pre-sort for the points vector.
  void sort();

  //check whether 4 points are colinear at a time.
  bool check4Colinear(int, int , int, int);

  //a vector storing all the poiints input.
  vector<Point> points;
};

#endif
