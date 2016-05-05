#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,0,840,540);
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
    bg = bg.scaled(870,550);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init(x_start);
}
