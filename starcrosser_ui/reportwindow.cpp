#include "reportwindow.h"
#include "ui_reportwindow.h"

reportWindow::reportWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reportWindow)
{
    ui->setupUi(this);
}

reportWindow::~reportWindow()
{
    delete ui;
}

void reportWindow::on_pushButton_clicked()
{
    this->close();
}

