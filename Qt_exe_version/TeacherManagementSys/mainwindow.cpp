#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_StartSys_clicked()
{
    this->hide();
    menu secondwin;
    secondwin.show();
    secondwin.exec();
}


void MainWindow::on_Quit1_clicked()
{
   return;
}

