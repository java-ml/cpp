#include "mainwindow.h"
#include <QApplication>
#include "mywin.h"
#include "utils.h"
#include <windows.h>
#include <QDebug>
#include<qdesktopwidget.h>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QWindow>
#include <QMenu>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow wid(&a);


    MyWin w;
    w.setWindowTitle("mywin");
    w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    QTimer _timer ;
    _timer.setInterval(20000);
    QObject::connect(&_timer, SIGNAL(timeout()),& w, SLOT(checkfullwin()));


    wid.setWinParent((HWND)w.winId());
    w.show();
    _timer.start();
    //wid.show();
   // wid.MakeFile();
    return a.exec();
}
