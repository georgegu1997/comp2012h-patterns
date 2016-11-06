#include "vector2D.h"

bool isEqual(const double d1, const double d2){
  return ((d1-d2 < 1e-5) && (d2-d1 < 1e-5));
}

bool isEqual(const double d1, const int d2){
  return ((d1-d2 < 1e-5) && (d2-d1 < 1e-5));
}

Vector2D::Vector2D() {}

Vector2D::~Vector2D() {}

Vector2D::Vector2D(double px, double py): x(px), y(py) {}

void Vector2D::setX(double px) {
  x = px;
}

void Vector2D::setY(double py) {
  y = py;
}

double Vector2D::getX() const{
  return x;
}

double Vector2D::getY() const{
  return y;
}

double Vector2D::getSlope() const {
  if (isEqual(x, 0)) {
    return 1e10;
  } else {
    return (y / x);
  }
}

bool Vector2D::operator==(const Vector2D& v) const{
  return isEqual(x, v.getX()) && isEqual(y, v.getY());
}

bool Vector2D::operator<(const Vector2D& v) const {
  if (*this == v){
    return false;
  }else if (isEqual(x, v.getX())){
    return y < v.getY();
  }else {
    return x < v.getX();
  }
}

bool Vector2D::operator>(const Vector2D& v) const {
  if (*this == v){
    return false;
  }else if (isEqual(x, v.getX())){
    return y > v.getY();
  }else {
    return x > v.getX();
  }
}

double Vector2D::operator*(const Vector2D& v) const {
  return (x * v.getX() + y * v.getY());
}
