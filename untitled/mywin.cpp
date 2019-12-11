#include "mywin.h"
#include "utils.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QWidget>
#include <stdlib.h>
#include <QPoint>
#include <QRect>
#include <QApplication>
#include <QDebug>
#include <QBuffer>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <windows.h>
#include <QMovie>
MyWin::MyWin(QWidget *parent) : QWidget(parent),label(this)
{
    desktop=QApplication::desktop();
    setGeometry(0,0,w=desktop->width(),h=desktop->height());
    FindWorkerW();
    QMovie *movie = new QMovie("../file/m.gif");
    movie->setScaledSize(desktop->size());
    label.setMovie(movie);
    movie->start();
}

void MyWin::paintEvent(QPaintEvent *)
{

}

void MyWin::checkfullwin()
{   if(!dwndparent)FindWorkerW();
     HWND hWnd = GetForegroundWindow();
     RECT rcApp, rcDesk;
     GetWindowRect((HWND)desktop->winId(), &rcDesk);
      if (hWnd != (HWND)desktop->winId() && hWnd != GetShellWindow() ) {
         GetWindowRect(hWnd, &rcApp);
         if (rcApp.left <= rcDesk.left  && rcApp.top <= rcDesk.top  &&
               rcApp.right >= rcDesk.right   && rcApp.bottom >= rcDesk.bottom-35 && hWnd != dwndparent)  {
               label.movie()->setPaused(true);

        }else {
                    label.movie()->setPaused(false);
                }
      }
}
void MyWin::FindWorkerW(){

    HWND dwndviem=nullptr;
    dwndparent =FindWindowEx(nullptr,nullptr,L"WorkerW",L"");
    for(int i=1000;(!dwndviem)&&dwndparent&&i>0;i--) {
        dwndviem=FindWindowEx(dwndparent,nullptr,L"SHELLDLL_DefView",nullptr);
        if(dwndviem)break;
        dwndparent=FindWindowEx(0,dwndparent,L"WorkerW",L"");
    }
}
MyWin::~MyWin(){
   // capture.release();
    qDebug()<<"exit";
}
