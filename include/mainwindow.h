#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0, const char* name = 0);
  ~MainWindow();

public slots:
  void onActionExit();

private:
  QMenuBar* menubar;

  QMenu* file_menu;
  QMenu* help_menu;

  QAction* action_brute;
  QAction* action_fast;
  QAction* action_exit;
  QAction* action_about;

};


#endif
