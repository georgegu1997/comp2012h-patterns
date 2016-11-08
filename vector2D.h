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

  Vector2D(int px, int py);

  void setX(int px);
  void setY(int py);
  int getX() const;
  int getY() const;

  double getSlope() const;

  bool operator==(const Vector2D& v) const;
  bool operator!=(const Vector2D& v) const;
  bool operator<(const Vector2D& v) const;
  bool operator>(const Vector2D& v) const;

  int operator*(const Vector2D& v) const;

  int operator^(const Vector2D& v) const;

  static bool slopeLargerFirst(const Vector2D& v1, const Vector2D& v2) {
    return v1.getSlope() > v2.getSlope();
  };
protected:
  int x;
  int y;
};

#endif
