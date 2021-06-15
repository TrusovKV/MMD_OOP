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
                ui->N_text,
                ui->From_text,
                ui->To_text,
                ui->Time_text,
                ui->Adibatic_text,
                ui->p1_text,
                ui->rho1_text,
                ui->v1_text,
                ui->p2_text,
                ui->rho2_text,
                ui->v2_text,

                numberDivisions,
                step);
}

