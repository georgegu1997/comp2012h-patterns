//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//point.cpp
//implementation file for class Point.

#include "point.h"

using namespace std;

Point::Point() {}
Point::~Point() {}

Point::Point(double px, double py): Vector2D(px, py) {}

double Point::measureAngle(const Point& origin) {
  if(x == origin.getX()) {
    return 1e10;
  }
  //cout <<x<<"  "<<y<<"  "<<origin.getX()<<"  "<<origin.getY()<<endl;
  double angle = ((double)y - (double)origin.getY())/((double)x - (double)origin.getX());
  //cout<<(y - origin.getY())/(x - origin.getX())<<endl;
  return angle;
}

void Point::print() const {
  cout<<"("<<x<<", "<<y<<")"<<endl;
}

void Point::draw(QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const {
  //painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setBrush(Qt::black);
  painter->setPen(Qt::black);
  painter->drawEllipse(QPointF(left_x + scale_x * x, bottom_y - scale_y * y), 2, 2);
  //cout<<"draw at"<<"(" <<left_x + scale_x * x <<", "<<bottom_y - scale_y * y<< ") "<<endl;
}

void Point::drawTo(const Point& p, QPainter* painter,  int left_x, int bottom_y, double scale_x, double scale_y) const {
  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setPen(QColor(0,0,0));
  painter->drawLine(QPointF(left_x + scale_x * x, bottom_y - scale_y * y), QPointF(left_x + scale_x * p.x, bottom_y - scale_y * p.y));
}

ostream& operator<<(ostream& os, const Point& p) {
  os<<" ("<<p.x<<", "<<p.y<<") ";
  return os;
}
