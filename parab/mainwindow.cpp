#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Hub.h"
#include "Solver.h"


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


void MainWindow::on_calc_button_clicked(bool checked)
{
    // 1. Aquire data
    // 2. Send data to solver
    // 3. When data is_done<>, send ready signal and data
    // 4. Give signal to render area and points to ... wherever they're needed


    QVector<QPointF> points; // to hub

    qreal step = 0.05; // to plotter

    //_________
    Hub hb(ui->coef_a->text().toDouble(), ui->coef_b->text().toDouble(), ui->coef_c->text().toDouble(), numberDivisions, double(step) );
    Solver parasol(hb.tellA(), hb.tellB(), hb.tellC(), hb.tellNumDiv(), hb.tellStep()) ;

    hb.getVector();


    for (int p = 0; p < parasol.tellLength(); p++)
     {points.push_back(QPointF(hb.tellX(p), hb.tellY(p)));}


    ui->render_area->setAxes(renderArea::Axis("x", numberDivisions), renderArea::Axis("y", numberDivisions));

    ui->render_area->setGraphPoints(points); // to Plotter
}

