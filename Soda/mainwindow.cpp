#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Hub *hb, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

