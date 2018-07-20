#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    int screenW = 1024;
    int screenH = 640;
    w.setGeometry(wid.screen()->width()/2-(screenW/2),wid.screen()->height()/2-(screenH/2),screenW,screenH);
    w.setFixedSize(screenW , screenH);
    w.show();

    return a.exec();
}
