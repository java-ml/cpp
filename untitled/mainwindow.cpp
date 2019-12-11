#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QMenuBar>
#include "utils.h"
#include <windows.h>
#include <QFileDialog>
MainWindow::MainWindow(QApplication *a,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->a=a;
    QMenuBar* pMenuBar = menuBar();
    QMenu* m_menu = pMenuBar->addMenu("&File");
    mSysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/inc.png");
    mSysTrayIcon->setIcon(icon);
    mSysTrayIcon->setToolTip(QString::fromUtf8("动态壁纸"));
    m_menu->addAction(icon,"&open",this,SLOT(show()),QKeySequence::Open);
    m_menu->addAction(icon,"&close",this,SLOT(exit()),QKeySequence::Close);
    QObject::connect(mSysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                     this, SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));
    mSysTrayIcon->show();
    mSysTrayIcon->setContextMenu(m_menu);
}
void MainWindow::closeEvent(QCloseEvent *ev){
        ev->ignore();
        this->hide();
}
void MainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
    {
        if(this->isHidden()) this->show();
        else this->hide();
    }
}

void MainWindow::setWinParent(HWND mywin){
    HWND workerW =Utils::GetWorkerW();
    SetParent(mywin,workerW);
}

void MainWindow::exit(){
    a->quit();
}
MainWindow::~MainWindow()
{
    delete ui;
}


