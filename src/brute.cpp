//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//brute.cpp
//implementation for brute class.
#include "brute.h"
#include <algorithm>
#include "helpers.h"


Brute::Brute() {}

Brute::Brute(const vector<Point> ps)
:points(ps) {}

Brute::~Brute() {}

void Brute::addPoint(const int x, const int y) {
  addPoint(Point(x, y));
}

void Brute::addPoint(const Point& p) {
  vector<Point>::iterator it=find(points.begin(), points.end(), p);

  if (it!=points.end()) {
    //cout<<"Detect repeatation in the points inputed"<<endl;
  }else {
    points.push_back(p);
  };
}

vector<vector<Point> > Brute::getColinearPoints() {
  //int counter = 0;
  vector<vector<Point> > lines;
  vector<Point> line;
  sort();

  int n = points.size();

  int l1, l2, l3, l4;
  for (l1 = 0; l1 < n-3; l1 ++) {
    for (l2 = l1+1; l2 < n-2; l2 ++) {
      for (l3 = l2+1; l3 < n-1; l3 ++) {
        for (l4 = l3+1; l4 < n; l4 ++) {
          if(check4Colinear(l1,l2,l3,l4)) {
            line.clear();
            line.push_back(points[l1]);
            line.push_back(points[l2]);
            line.push_back(points[l3]);
            line.push_back(points[l4]);

            lines.push_back(line);
          }
        }
      }
    }
  }
  printInFormat(lines);
  return lines;
}

void Brute::printColinearPoints() {
  printInFormat(getColinearPoints());
}

void Brute::sort() {
  std::sort(points.begin(), points.end());
}

bool Brute::check4Colinear(int i1, int i2 ,int i3, int i4) {
  //cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;
  double slope1 = points[i2].measureAngle(points[i1]);
  double slope2 = points[i3].measureAngle(points[i1]);
  double slope3 = points[i4].measureAngle(points[i1]);
  //cout <<slope1<<"  "<<slope2<<"  "<<slope3<<endl;
  return doubleEqual(slope1, slope2) && doubleEqual(slope2, slope3);
}

void Brute::printLine(int i1, int i2, int i3, int i4) {
  cout << points[i1] <<"->"<<points[i2]<<"->"<<points[i3]<<"->"<<points[i4]<<endl;
}

void Brute::printInFormat(vector<vector<Point> > a) {
  vector<Point>::iterator in_itr;
  vector<vector<Point> >::iterator out_itr;
  
  cout<<"Using Brute Algorithm:"<<endl;

  for (out_itr = a.begin(); out_itr != a.end(); out_itr++) {
    for(in_itr = out_itr->begin(); in_itr != out_itr->end(); in_itr++){
      if(in_itr != out_itr->begin()){
        cout<<"->";
      }
      cout<<*in_itr;
    }
    cout<<endl;
  }
}
