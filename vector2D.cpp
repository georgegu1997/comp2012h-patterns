//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//vector2D.cpp

#include "vector2D.h"

Vector2D::Vector2D() {}

Vector2D::~Vector2D() {}

Vector2D::Vector2D(int px, int py): x(px), y(py) {}

void Vector2D::setX(int px) {
  x = px;
}

void Vector2D::setY(int py) {
  y = py;
}

int Vector2D::getX() const{
  return x;
}

int Vector2D::getY() const{
  return y;
}

double Vector2D::getSlope() const {
  if (x == 0) {
    return 1e10;
  } else {
    return (y / x);
  }
}

bool Vector2D::operator==(const Vector2D& v) const{
  return x == v.getX() && y == v.getY();
}

bool Vector2D::operator<(const Vector2D& v) const {
  if (*this == v){
    return false;
  }else if (x == v.getX()){
    return y < v.getY();
  }else {
    return x < v.getX();
  }
}

bool Vector2D::operator>(const Vector2D& v) const {
  if (*this == v){
    return false;
  }else if (x == v.getX()){
    return y > v.getY();
  }else {
    return x > v.getX();
  }
}

int Vector2D::operator*(const Vector2D& v) const {
  return (x * v.getX() + y * v.getY());
}
