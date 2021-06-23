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


void MainWindow::setGraphPoints(    QVector<QPointF> const & pointsP,
QVector<QPointF> const & pointsT,
    QVector<QPointF> const & pointsU,
        QVector<QPointF> const & pointsR)
{/*int numberDivisions = 25;
    ui->P->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->T->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->rho->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->u->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));

    ui->P->setGraphPoints(pointsP);
    ui->T->setGraphPoints(pointsT);
    ui->u->setGraphPoints(pointsU);
    ui->rho->setGraphPoints(pointsR);*/
}

void MainWindow::drawGraphs(/*std::vector<double> P, std::vector<double> T, std::vector<double> U, std::vector<double> R*/)
{/*
    for(int k = 0; k< ui->N_text->text().toDouble(); k++)
    {
        pointsP.push_back(QPointF(k,P.at(k)));
        pointsT.push_back(QPointF(k,T.at(k)));
        pointsU.push_back(QPointF(k,U.at(k)));
        pointsR.push_back(QPointF(k,R.at(k)));
    }*/
    //setgraph points
    int numberDivisions = 25;
        ui->P->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
        ui->T->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
        ui->rho->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
        ui->u->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
/*
        ui->P->setGraphPoints(pointsP);
        ui->T->setGraphPoints(pointsT);
        ui->u->setGraphPoints(pointsU);
        ui->rho->setGraphPoints(pointsR);
        ui->P->paintE();
        ui->T->paintE();
        ui->u->paintE();
        ui->rho->paintE();*/

}

void MainWindow::on_pushButton_clicked()
{
    hb->transmittData(            /*    ui->N_text->text().toDouble(),
                                            ui->From_text->text().toDouble(),
                                            ui->To_text->text().toDouble(),
                                            ui->Time_text->text().toDouble(),
                                            ui->Adibatic_text->text().toDouble(),
                                            ui->p1_text->text().toDouble(),
                                            ui->rho1_text->text().toDouble(),
                                            ui->v1_text->text().toDouble(),
                                            ui->p2_text->text().toDouble(),
                                            ui->rho2_text->text().toDouble(),
                                            ui->v2_text->text().toDouble()*/
                                            );
}

