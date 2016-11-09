#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include <QLabel>
#include <QPainter>
#include <vector>
#include "point.h"

const int BOARD_WIDTH = 800;
const int BOARD_HEIGHT = 800;
const int WINDOW_MARGIN = 30;

using std::vector;

class DrawBoard: public QLabel {
public:
  DrawBoard();
  ~DrawBoard();

  void drawPoints(const vector<Point>& ps);

  void drawLines(const vector<vector<Point> >& ls);

private:
  void repaint();
  int left_x, bottom_y;
  double scale_x, scale_y;

  QImage* background;
  QPainter* painter;
};

#endif
