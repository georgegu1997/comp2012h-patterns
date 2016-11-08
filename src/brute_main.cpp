#include "brute.h"
#include <iostream>
#include <string>

using std::cin;

int main() {
  int size;
  cin >> size;

  Brute b;

  int x, y;

  while(!cin.eof()){
    cin >> x;
    cin >> y;
    if(cin.eof())break;
    b.addPoint(x,y);
  }

  b.printColinearPoints();
}
