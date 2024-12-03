#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "reportwindow.h"

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



void MainWindow::on_exitButton_clicked()
{
    this->close();
}


void MainWindow::on_reportButton_clicked()
{
    reportWindow reportwindow;
    reportwindow.setModal(true);
    reportwindow.exec();
}

