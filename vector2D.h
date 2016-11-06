//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//vector2D.h
//The base class for the Point

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
  Vector2D();
  ~Vector2D();

  Vector2D(double px, double py);

  void setX(double px);
  void setY(double py);
  double getX() const;
  double getY() const;

  double getSlope() const;

  bool operator==(const Vector2D& v) const;
  bool operator<(const Vector2D& v) const;
  bool operator>(const Vector2D& v) const;

  double operator*(const Vector2D& v) const;

  static bool slopeLargerFirst(const Vector2D& v1, const Vector2D& v2);
protected:
  double x;
  double y;
};

bool Vector2D::slopeLargerFirst(const Vector2D& v1, const Vector2D& v2) {
  return v1.getSlope() > v2.getSlope();
}

#endif
