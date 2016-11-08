#include "fast.h"
#include <iostream>

using std::cin;

int main() {
  int size;
  cin >> size;

  Fast f;

  int x, y;

  while(!cin.eof()) {
    cin >> x;
    cin >> y;
    if(cin.eof())break;
    f.addPoint(x,y);
  }

  f.printColinearPoints();
}
