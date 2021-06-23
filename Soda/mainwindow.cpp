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
{
    ui->P->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->T->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->rho->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));
    ui->u->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));

    ui->P->setGraphPoints(pointsP);
    ui->T->setGraphPoints(pointsT);
    ui->u->setGraphPoints(pointsU);
    ui->rho->setGraphPoints(pointsR);
}
