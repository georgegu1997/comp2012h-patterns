#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent = 0, const char* name = 0)
:QMainWindow(parent, name), min_x(0), max_x(32768), min_y(0), max_y(32768) {
  setMinimumSize(600,600);

  menubar = this->menuBar();
  file_menu = menubar->addMenu(tr("File"));
  help_menu = menubar->addMenu(tr("Help"));

  action_brute = new QAction(tr("Use Brute Algo"), this);
  action_fast = new QAction(tr("Use Fast Algo"), this);
  action_exit = new QAction(tr("Exit"), this);
  action_about = new QAction(tr("About"), this);

  file_menu->addAction(action_brute);
  file_menu->addAction(action_fast);
  file_menu->addSeperator();
  file_menu->addAction(action_exit);

  help_menu->addAction(action_about);

  connect(action_exit, SIGNAL(triggered()), this, SLOT(onActionExit()));
}

void MainWindow::onActionExit() {
  this->close();
}
