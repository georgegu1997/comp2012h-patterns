//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//drawboard.h
//the header file for DrawBoard class, which is used as the board to draw points and lines.
#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include <QLabel>
#include <QPainter>
#include <vector>
#include "point.h"

//some constants about the DrawBoard
const int BOARD_WIDTH = 600;
const int BOARD_HEIGHT = 600;
const int WINDOW_MARGIN = 30;

using std::vector;

class DrawBoard: public QLabel {
public:
  //default constructor and destructor.
  DrawBoard();
  ~DrawBoard();

  //draw the points on the board.
  void drawPoints(const vector<Point>& ps);

  //draw the lines.
  void drawLines(const vector<vector<Point> >& ls);

private:
  // clear the board.
  void repaint();

  //some parameters used to paint(Passed to the )
  int left_x, bottom_y;
  double scale_x, scale_y;

  QImage* background;
  QPainter* painter;
};

#endif
