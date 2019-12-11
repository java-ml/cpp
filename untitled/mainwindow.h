#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QWindow>
#include <QMenu>
#include <QApplication>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *a,QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    void setWinParent(HWND mywin);
private:
    QSystemTrayIcon* mSysTrayIcon;
    QMenu *m_menu ;
    QApplication *a;
signals:

private slots:
    void slotActivated(QSystemTrayIcon::ActivationReason reason);
    void exit();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
