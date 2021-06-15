#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Hub.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     numberDivisions(25)
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
    QVector<QPointF> points; // to hub

    qreal step = 0.05; // to plotter

    Hub hb(
                int N,
                double x0,
                double xN,
                double t,
                double gamma,
                double p1,
                double rho1,
                double u1,
                double p4,
                double rho4,
                double u4,

                double NumDiv,
                double st);
}

