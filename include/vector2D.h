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
  //default constructor and destructor.
  Vector2D();
  ~Vector2D();

  //conversion constructor from coordinates.
  Vector2D(int px, int py);

  //the setter functions
  void setX(int px);
  void setY(int py);

  //the getter functions.
  int getX() const;
  int getY() const;
  //calculate the slope of the vector.
  double getSlope() const;

  //ovecload these operators.
  //x and y should be both equal
  bool operator==(const Vector2D& v) const;
  bool operator!=(const Vector2D& v) const;
  //compared by x first and y second.
  bool operator<(const Vector2D& v) const;
  bool operator>(const Vector2D& v) const;

  //compute the inner product fo two vectors.
  int operator*(const Vector2D& v) const;

  //compute the cross product of two vectors.
  int operator^(const Vector2D& v) const;

  //a static function used as pointer in std::sort to sort the vectors by slopes.
  static bool slopeLargerFirst(const Vector2D& v1, const Vector2D& v2) {
    return v1.getSlope() > v2.getSlope();
  };
protected:
  //the coordinates.
  int x;
  int y;
};

#endif
