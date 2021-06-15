#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Solver.h"

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


void MainWindow::on_pushButton_clicked(bool checked)
{
    Solver s(1,1,1,1,1,1,1,1,1,1,1);
}

