#include "mainwindow.h"
#include <fstream>
#include <algorithm>
#include "assert.h"

MainWindow::MainWindow(QWidget *parent, const char* name) {
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
  file_menu->addSeparator();
  file_menu->addAction(action_exit);

  help_menu->addAction(action_about);

  connect(action_exit, SIGNAL(triggered()), this, SLOT(onActionExit()));
}

MainWindow::~MainWindow() {}

void MainWindow::loadFile(char * file_name) {
  ifstream fin(file_name);
  assert (fin.is_open());

  int size;
  fin >> size;

  int x, y;

  while(!cin.eof()) {
    cin >> x;
    cin >> y;
    Point p(x, y);

    if(points.size() > 1){
      if(std::find(points.begin(), points.end(), p) != points.end()){
        cout<< "repeatation in point input detected"<<endl;
      }else{
        points.push_back(p);
      }
    }else {
      points.push_back(p);
    }
  }

}

void MainWindow::plotPoints() {
  vector<Point>::Iterator itr;
  for (itr = points.begin(); itr != points.end(); itr++) {
    
  }
}

void MainWindow::onActionExit() {
  this->close();
}
