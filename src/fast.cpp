//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//fast.cpp
//implementation for fast class.
#include "fast.h"
#include <algorithm>

using std::cout;
using std::endl;

PointWithOrigin::PointWithOrigin() {}

PointWithOrigin::~PointWithOrigin() {}

PointWithOrigin::PointWithOrigin(const Point& origin, const Point& p):Point(p.getX()-origin.getX(), p.getY()-origin.getY()), p(&p), origin(&origin) {}

bool PointWithOrigin::operator==(const PointWithOrigin& p)const {
  return (*this ^ p) == 0;
}

Point PointWithOrigin::getOrigin() const {
  return *origin;
}

Point PointWithOrigin::getPoint() const {
  return *p;
}

Fast::Fast() {}

Fast::Fast(const vector<Point> ps)
:points(ps) {}

Fast::~Fast() {}

void Fast::addPoint(const Point& p) {
  vector<Point>::iterator it=find(points.begin(), points.end(), p);

  if (it!=points.end()) {
    //cout<<"Detect repeatation in the points inputed"<<endl;
  }else {
    points.push_back(p);
  };
}

void Fast::addPoint(int x, int y) {
  addPoint(Point(x,y));
}

void Fast::printColinearPoints() {
  printInFormat(getColinearPoints());
}

void Fast::printInFormat(vector<vector<Point> > a) {
  vector<Point>::iterator in_itr;
  vector<vector<Point> >::iterator out_itr;
  
  cout<<"Using Fast Algorithm: "<<endl;

  for (out_itr = a.begin(); out_itr != a.end(); out_itr++) {
    cout<<out_itr->size()<<": ";
    for(in_itr = out_itr->begin(); in_itr != out_itr->end(); in_itr++){
      if(in_itr != out_itr->begin()){
        cout<<"->";
      }
      cout<<*in_itr;
    }
    cout<<endl;
  }
}

vector<vector<Point> > Fast::getColinearPoints() {
  sort();
  vector<Point>::iterator itr_o;
  vector<vector<Point> > lines;

  for (itr_o = points.begin(); itr_o != points.end(); itr_o++) {
    vector<vector<Point> > lines_o;
    lines_o = getColinearPointsWithOrigin(*itr_o);

    vector<vector<Point> >::iterator itr_line;
    for (itr_line = lines_o.begin(); itr_line != lines_o.end(); itr_line ++) {
      if(std::find(lines.begin(), lines.end(), *itr_line) == lines.end()) {
        lines.push_back(*itr_line);
      }
    }
    //points.erase(points.begin());
  }
  
  printInFormat(lines);

  return lines;
}

vector<vector<Point> > Fast::getColinearPointsWithOrigin(const Point& origin) {
  vector<PointWithOrigin> line;
  vector<vector<PointWithOrigin> > lines;

  vector<Point>::iterator itr;
  vector<PointWithOrigin> a;

  //cout<<origin<<endl;
  //printInFormat(points);

  for (itr = points.begin(); itr != points.end(); itr++) {
    if(*itr != origin) {
      a.push_back(PointWithOrigin(origin, *itr));
    }
  }

  std::sort(a.begin(), a.end(), Vector2D::slopeLargerFirst);
  vector<PointWithOrigin>::iterator itr_o;

  for (itr_o = a.begin(); itr_o != a.end(); itr_o++) {
    if (line.empty()) {
      line.push_back(*itr_o);
    }else {
      //test slopes of two PointWithOrigin are equal
      if(line.front() == *itr_o) {
        line.push_back(*itr_o);
      }else {
        if(line.size()>=3){
          lines.push_back(line);
        }
        line.clear();
        line.push_back(*itr_o);
      }
    }
  }

  if(line.size()>=3){
    lines.push_back(line);
  }
  line.clear();

  return returnToOriginalCoordinate(lines);
}

vector<vector<Point> > Fast::returnToOriginalCoordinate(vector<vector<PointWithOrigin> >& a) {
  vector<PointWithOrigin>::iterator in_itr;
  vector<vector<PointWithOrigin> >::iterator out_itr;

  vector<vector<Point> > result;

  for (out_itr = a.begin(); out_itr != a.end(); out_itr++) {
    vector<Point> line;
    line.push_back(out_itr->begin()->getOrigin());
    for(in_itr = out_itr->begin(); in_itr != out_itr->end(); in_itr++){
      line.push_back(in_itr->getPoint());
    }
    std::sort(line.begin(), line.end());
    result.push_back(line);
  }
  return result;
}


void Fast::sort() {
  std::sort(points.begin(), points.end());
}
