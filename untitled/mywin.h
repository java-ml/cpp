#ifndef MYWIN_H
#define MYWIN_H

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QDesktopWidget>
#include <QLabel>
#include <QPainter>
class MyWin : public QWidget
{
    Q_OBJECT
public:
    explicit MyWin(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    QDesktopWidget *desktop;
    QLabel label;
    int w,h;
    ~MyWin();
private:
    void FindWorkerW();
    HWND dwndparent;
    signals:

public slots:
    void checkfullwin();
};



#endif // MYWIN_H
