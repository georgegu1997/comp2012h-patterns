#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <vector>
#include "brute.h"
#include "fast.h"
#include "point.h"

using std::vector;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0, const char* name = 0);
  ~MainWindow();

  void loadFile(char *);

public slots:
  void onActionExit();

private:
  void plotPoints();

  vector<Point> points;

  QMenuBar* menubar;

  QMenu* file_menu;
  QMenu* help_menu;

  QAction* action_brute;
  QAction* action_fast;
  QAction* action_exit;
  QAction* action_about;

  QLabel* draw_board;

};


#endif
