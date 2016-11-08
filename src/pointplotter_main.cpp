#include "mainwindow.h"
#include <QApplication>

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  if(argc < 2) {
    cout<<"usage: "<< argv[0]<< " "<< "input.txt"<<endl;
    exit(0);
  }

  QApplication a(argc, argv);
  QWidget* w = new MainWindow();
  w.loadFile(argv[1]);

  w->show();

  return a.exec();
}
