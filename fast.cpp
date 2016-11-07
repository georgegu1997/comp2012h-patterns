#include "fast.h"
#include <algorithm>

using std::cout;
using std::endl;

PointWithOrigin::PointWithOrigin() {}

PointWithOrigin::~PointWithOrigin() {}

PointWithOrigin::PointWithOrigin(const Point& origin, const Point& p):Point(p.getX()-origin.getX(), p.getY()-origin.getY()), p(&p), origin(&origin) {}

bool PointWithOrigin::operator==(const PointWithOrigin& p)const {
  return doubleEqual(this->getSlope(), p.getSlope());
}

Point PointWithOrigin::getOrigin() const {
  return *origin;
}

Point PointWithOrigin::getPoint() const {
  return *p;
}

Fast::Fast() {}

Fast::~Fast() {}

void Fast::addPoint(const Point& p) {
  vector<Point>::iterator it=find(points.begin(), points.end(), p);

  if (it!=points.end()) {
    cout<<"Detect repeatation in the points inputed"<<endl;
  }else {
    points.push_back(p);
    points_backup.push_back(p);
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

void Fast::printInFormat(vector<Point> a) {
  vector<Point>::iterator in_itr;
  for(in_itr = a.begin(); in_itr != a.end(); in_itr++){
    if(in_itr != a.begin()){
      cout<<"->";
    }
    cout<<*in_itr;
  }
  cout<<endl;
}

void Fast::printInFormat(vector<PointWithOrigin> out_itr) {
  vector<PointWithOrigin>::iterator in_itr;
  for(in_itr = out_itr.begin(); in_itr != out_itr.end(); in_itr++){
    if(in_itr != out_itr.begin()){
      cout<<"->";
    }
    cout<<*in_itr;
  }
  cout<<endl;
}

vector<vector<Point> > Fast::getColinearPoints() {
  sort();
  vector<Point>::iterator itr_o;
  vector<vector<Point> > lines;

  for (itr_o = points_backup.begin(); itr_o != points_backup.end(); itr_o++) {
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
  points = points_backup;

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
  //printInFormat(a);
  vector<PointWithOrigin>::iterator itr_o;

  for (itr_o = a.begin(); itr_o != a.end(); itr_o++) {
    //cout<<itr_o->getSlope()<<endl;
    if (line.empty()) {
      line.push_back(*itr_o);
    }else {
      //cout<<"front:"<<line.front().getSlope()<<endl;
      if(line.front() == *itr_o) {

        //cout<<"add point"<<endl;
        line.push_back(*itr_o);
      }else {
        if(line.size()>=2){
          lines.push_back(line);
          //cout<<"found"<<endl;
        }
        line.clear();
        line.push_back(*itr_o);
      }
    }
  }

  if(line.size()>=2){
    lines.push_back(line);
    //cout<<"found"<<endl;
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
  std::sort(points_backup.begin(), points_backup.end());
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
      if(!doubleEqual(slope, itr2->getSlope()) || itr2 == a.begin()){

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
