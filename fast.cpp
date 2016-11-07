#include "fast.h"
#include <algorithm>
#include "helpers.h"

PointWithOrigin::PointWithOrigin() {}

PointWithOrigin::~PointWithOrigin() {}

PointWithOrigin::PointWithOrigin(const Point& origin, const Point p):Point(p.getX()-origin.getX(), p.getY()-origin.getY()), p(&p), origin(&origin) {}

Fast::Fast() {}

Fast::~Fast() {}

void Fast::addPoint(const Point& p) {
  vector<Point>::iterator it=find(points.begin(), points.end(), p);

  if (it!=points.end()) {
    cout<<"Detect repeatation in the points inputed"<<endl;
  }else {
    points.push_back(p);
  };
}

void Fast::addPoint(int x, int y) {
  addPoint(Point(x,y));
}

vector<vector<Point>> Fast::getColinearPoints() {
  sort();
  vector<Point>::iterator itr_o;
  vector<vector<Point>> lines;

  for (itr_o = points.begin(); ite_o != points.end(); itr_o++) {
    vector<Point> line;
    line = getColinearPointsWithOrigin(itr_o);
  }
}

/*
vector<vector<Line>> Fast::getColinearPoints() {
  sort();
  vector<Point>::iterator itr, itr2;
  vector<vector<Point>> lines;

  for (itr = points.begin(); itr != points.end(); ++itr){
    vector<Point> a;

    for(itr2 = points.begin(); itr != points.end(); ++itr2){
      if(itr2 != itr) {
        Point v(itr->getX() - itr2->getX(), itr->getY() - itr2->getY());
        a.push_back(v);
      }
    }

    std::sort(a.begin(), a.end(), Vector2D::slopeLargerFirst);

    double slope;
    int count = 0;
    vector<Point> line;
    for (itr2 = a.begin(); itr != a.end(); ++itr2) {
      if(!isEqual(slope, itr2->getSlope()) || itr2 == a.begin()){

        if(count>=3) {
          std::sort(line.begin(), line.end());
          lines.push_back(line);
          break;
        }else{
          slope = itr2->getSlope();
          count = 1;
          line.clear();
          line.push_back(*itr2);
        }
      }else {
        count ++;
        line.push_back(*itr2);
      }
    }
  }
}
*/
vector<vector<Point>> Fast::getColinearPointsWithOrigin(const Point& origin) {
  for
}

void Fast::sort() {
  std::sort(points.begin(), points.end());
}
