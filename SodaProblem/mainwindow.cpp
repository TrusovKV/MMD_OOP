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
    QVector<QPointF> pointsP; // to hub
        QVector<QPointF> pointsT;
            QVector<QPointF> pointsU;
                QVector<QPointF> pointsR;

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
    bool b = false;
    b = hb.getVector();

    for(int k = 0; k< ui->N_text->text().toDouble(); k++)
    {
        pointsP.push_back(QPointF(k,hb.tellPdat(k)));
        pointsT.push_back(QPointF(k,hb.tellTdat(k)));
        pointsU.push_back(QPointF(k,hb.tellUdat(k)));
        pointsR.push_back(QPointF(k,hb.tellRdat(k)));
    }

   ui->p->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
   ui->T->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
   ui->rho->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
   ui->v->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));

   ui->p->setGraphPoints(pointsP);
   ui->T->setGraphPoints(pointsT);
   ui->v->setGraphPoints(pointsU);
   ui->rho->setGraphPoints(pointsR);

   ui->p->getFlag(b);
   ui->T->getFlag(b);
   ui->v->getFlag(b);
   ui->rho->getFlag(b);

update();
b = false;
}



