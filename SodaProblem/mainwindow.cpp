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
    double nD = numberDivisions;
    double st = step;

    Hub hb(
                ui->N_text->text().toDouble(),
                ui->From_text->text().toDouble(),
                ui->To_text->text().toDouble(),
                ui->Time_text->text().toDouble(),
                ui->Adibatic_text->text().toDouble(),
                ui->p1_text->text().toDouble(),
                ui->rho1_text->text().toDouble(),
                ui->v1_text->text().toDouble(),
                ui->p2_text->text().toDouble(),
                ui->rho2_text->text().toDouble(),
                ui->v2_text->text().toDouble(),

                nD,
                st);
}

