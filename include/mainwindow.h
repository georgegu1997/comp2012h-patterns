//For Patterns of COMP 2012H @HKUST
//Author: GU QIao
//Email: georgegu1997@gmail.com
//
//All rights reserved.
//
//mainwindow.h
//The header file for the MainWindow
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <vector>
#include "brute.h"
#include "fast.h"
#include "point.h"
#include "drawboard.h"

using std::vector;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  //default constructor and destructor.
  MainWindow();
  ~MainWindow();

  //load file from the txt and store the point as Point instances in points.
  void loadFile(char *);

public slots:
  //handling different action.
  //Exit the program.
  void onActionExit();

  //Use Brute to find lines.
  void onActionBrute();

  //Use Fast to find lines.
  void onActionFast();

  //pop up a message bos to give the info of author.
  void onActionAbout();

private:
  //vector to store the Point.
  vector<Point> points;

  //About the menu of the mainwindow
  QMenuBar* menubar;
  QMenu* file_menu;
  QMenu* help_menu;

  //QActions
  QAction* action_brute;
  QAction* action_fast;
  QAction* action_exit;
  QAction* action_about;

  //DrawBoard to draw points and lines.
  DrawBoard* draw_board;

};


#endif
