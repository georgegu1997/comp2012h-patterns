//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//The header file for MainWindow class of the PointPllotter.
#include "mainwindow.h"
#include <fstream>
#include <algorithm>
#include "assert.h"
#include <QTimer>
#include <QMessageBox>
#include <QString>

using std::ifstream;

MainWindow::MainWindow() {

  menubar = this->menuBar();
  file_menu = menubar->addMenu(tr("File"));
  help_menu = menubar->addMenu(tr("Help"));

  action_brute = new QAction(tr("Use Brute Algo"), this);
  action_fast = new QAction(tr("Use Fast Algo"), this);
  action_exit = new QAction(tr("Exit"), this);
  action_about = new QAction(tr("About"), this);

  file_menu->addAction(action_brute);
  file_menu->addAction(action_fast);
  file_menu->addSeparator();
  file_menu->addAction(action_exit);

  help_menu->addAction(action_about);

  connect(action_exit, SIGNAL(triggered()), this, SLOT(onActionExit()));
  connect(action_fast, SIGNAL(triggered()), this, SLOT(onActionFast()));
  connect(action_brute, SIGNAL(triggered()), this, SLOT(onActionBrute()));
  connect(action_about, SIGNAL(triggered()), this, SLOT(onActionAbout()));

  draw_board = new DrawBoard();

  setCentralWidget(draw_board);
}

MainWindow::~MainWindow() {
  delete action_exit;
  delete action_brute;
  delete action_fast;
  delete action_about;
  delete draw_board;
}

void MainWindow::loadFile(char * file_name) {
  ifstream fin(file_name);
  assert (fin.is_open());

  int size;
  fin >> size;

  int x, y;

  while(!fin.eof()) {
    fin >> x;
    fin >> y;
    Point p(x, y);

    if(points.size() > 1){
      if(std::find(points.begin(), points.end(), p) != points.end()){
        //cout<< "repeatation in point input detected"<<endl;
      }else{
        points.push_back(p);
      }
    }else {
      points.push_back(p);
    }
  }
  fin.close();

  draw_board->drawPoints(points);
}

void MainWindow::onActionExit() {
  this->close();
}

void MainWindow::onActionAbout() {
  QMessageBox msg_box;
  msg_box.setText("Written by GU, Qiao  ");
  msg_box.exec();
}

void MainWindow::onActionBrute() {
  QTime t;
  QMessageBox msg_box;
  t.start();
  Brute b(points);
  vector<vector<Point> > lines = b.getColinearPoints();
  draw_board->drawLines(lines);
  msg_box.setText(QString("Time used: %1 ms  ").arg(t.elapsed()));
  msg_box.exec();
}

void MainWindow::onActionFast() {
  QMessageBox msg_box;
  QTime t;
  t.start();
  Fast f(points);
  vector<vector<Point> > lines = f.getColinearPoints();
  draw_board->drawLines(lines);
  msg_box.setText(QString("Time used: %1 ms  ").arg(t.elapsed()));
  msg_box.exec();
}
