//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//drawboard.cpp
//implementation for the DrawBoard class.
#include "drawboard.h"

DrawBoard::DrawBoard()
:left_x(0 + WINDOW_MARGIN), bottom_y(BOARD_HEIGHT - WINDOW_MARGIN), scale_x(BOARD_WIDTH / 32768.0), scale_y(BOARD_HEIGHT / 32768.0) {
  background = new QImage(BOARD_WIDTH + 2 * WINDOW_MARGIN, BOARD_HEIGHT + 2 * WINDOW_MARGIN, QImage::Format_RGB32);
  painter = new QPainter(background);
  this->setMinimumSize(50,50);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  this->setScaledContents(true);

  this->setPixmap(QPixmap::fromImage(*background));
  this->show();
  repaint();
}

DrawBoard::~DrawBoard() {
  delete background;
  delete painter;
}

void DrawBoard::drawPoints(const vector<Point>& ps) {
  vector<Point>::const_iterator itr;
  for (itr = ps.begin(); itr != ps.end(); itr++){
    itr->draw(painter, left_x, bottom_y, scale_x, scale_y);
  }
  this->setPixmap(QPixmap::fromImage(*background));
  this->show();
}

void DrawBoard::drawLines(const vector<vector<Point> >& ls) {
  vector<vector<Point> >::const_iterator out_itr;
  vector<Point>::const_iterator in_itr;

  for(out_itr = ls.begin(); out_itr != ls.end(); out_itr++) {
    for (in_itr = out_itr->begin(); in_itr+1 != out_itr->end(); in_itr++) {
      in_itr->drawTo(*(in_itr+1), painter, left_x, bottom_y, scale_x, scale_y);
    }
  }
  this->setPixmap(QPixmap::fromImage(*background));
  this->show();
}

void DrawBoard::repaint(){
  painter->setBrush(Qt::white);
  painter->drawRect(0,0,BOARD_WIDTH + 2 * WINDOW_MARGIN, BOARD_HEIGHT + 2 * WINDOW_MARGIN);
  this->setPixmap(QPixmap::fromImage(*background));
  this->show();
}
