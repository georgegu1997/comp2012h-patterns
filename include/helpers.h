//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//helpers.h
//
#ifndef HELPERS_H
#define HELPERS_H

//An inline function to test whether two doubles are equal.
inline bool doubleEqual(const double d1, const double d2){
  return ((d1-d2 < 1e-5) && (d2-d1 < 1e-5));
}

#endif
