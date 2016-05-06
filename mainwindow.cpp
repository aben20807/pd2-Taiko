#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    //禁止視窗放大
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(890,600);//禁止視窗大小改變

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,0,850,537);//畫面調整，數字越大向...移動(左,上,左,上)
    settingBg(10,630);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::settingBg(int x_start , int y_end)
{
    QImage bg;
    bg.load(":image/img/bg_start.png");
    //bg = bg.scaled(870,550);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for Taiko */
    scene->Init(x_start);
}
