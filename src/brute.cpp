#include "brute.h"
#include <algorithm>
#include "helpers.h"


Brute::Brute() {}

Brute::~Brute() {}

void Brute::addPoint(const int x, const int y) {
  addPoint(Point(x, y));
}

void Brute::addPoint(const Point& p) {
  vector<Point>::iterator it=find(points.begin(), points.end(), p);

  if (it!=points.end()) {
    cout<<"Detect repeatation in the points inputed"<<endl;
  }else {
    points.push_back(p);
  };
}

void Brute::printColinearPoints() {
  sort();
  vector<int> indexes(4);
  int k;
  int n = points.size();
  vector<bool> v(n);
  std::fill(v.end() - 4, v.end(), true);

  do {
    k = 0;
    for(int i = 0; i < n; ++i) {
      if(v[i]) {
        indexes[k] = i;
        k++;
      }
    }
    if(check4Colinear(indexes[0],indexes[1],indexes[2],indexes[3])) {
      printLine(indexes[0],indexes[1],indexes[2],indexes[3]);
    }
  } while (std::next_permutation(v.begin(), v.end()));
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
